#include "transactionservice.h"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>


// constructor
TransactionService::TransactionService(QSqlDatabase database)
    : m_database(database)
{
}

// -------------------- VALIDATION --------------------

bool TransactionService::validateTransaction(const Transaction &t, QString &error)
{
    if (t.getTitle().isEmpty()) {
        error = "Title cannot be empty";
        return false;
    }

    if (t.getAmount() <= 0) {
        error = "Amount must be greater than 0";
        return false;
    }

    if (t.getType() != "income" && t.getType() != "expense") {
        error = "Invalid transaction type";
        return false;
    }

    return true;
}

// -------------------- ADD --------------------

bool TransactionService::addTransaction(const Transaction &t, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        INSERT INTO transactions
        (title, description, notes, amount, type, category_id, user_id, date)
        VALUES
        (:title, :description, :notes, :amount, :type, :categoryId, :userId, :date)
    )");

    query.bindValue(":title",       t.getTitle());
    query.bindValue(":description", t.getDescription());
    query.bindValue(":notes",       t.getNotes());
    query.bindValue(":amount",      t.getAmount());
    query.bindValue(":type",        t.getType());
    query.bindValue(":categoryId",  t.getCategoryId());
    query.bindValue(":userId",      userId);
    query.bindValue(":date",        t.getDate());

    if (!query.exec()) {
        qDebug() << "Add transaction error:" << query.lastError().text();
        return false;
    }
    return true;
}

// -------------------- GET ALL --------------------

QList<Transaction> TransactionService::getAllTransactions(int userId)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId
        ORDER BY date DESC
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            Transaction t(
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes  ← new
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                );

            list.append(t);
        }
    }

    return list;
}

// -------------------- BY TYPE --------------------

QList<Transaction> TransactionService::getTransactionsByType(int userId, const QString &type)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId AND type = :type
        ORDER BY date DESC
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":type", type);

    if (query.exec()) {
        while (query.next()) {
            list.append(Transaction (
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes  ← new
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                ));
        }
    }

    return list;
}

// -------------------- DELETE --------------------

bool TransactionService::deleteTransaction(int id, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        DELETE FROM transactions
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    return query.exec();
}

// -------------------- UPDATE --------------------

bool TransactionService::updateTransaction(const Transaction &t, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        UPDATE transactions
        SET title       = :title,
            description = :description,
            notes       = :notes,
            amount      = :amount,
            type        = :type,
            category_id = :categoryId,
            date        = :date
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":title",       t.getTitle());
    query.bindValue(":description", t.getDescription());
    query.bindValue(":notes",       t.getNotes());
    query.bindValue(":amount",      t.getAmount());
    query.bindValue(":type",        t.getType());
    query.bindValue(":categoryId",  t.getCategoryId());
    query.bindValue(":date",        t.getDate());
    query.bindValue(":id",          t.getId());
    query.bindValue(":userId",      userId);

    return query.exec();
}

// -------------------- COUNT --------------------

int TransactionService::getTransactionsCount(int userId)
{
    QSqlQuery query(m_database);

    query.prepare("SELECT COUNT(*) FROM transactions WHERE user_id = :userId");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toInt();

    return 0;
}

int TransactionService::countTransactionsByType(int userId, const QString &type)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT COUNT(*)
        FROM transactions
        WHERE user_id = :userId AND type = :type
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":type", type);

    if (query.exec() && query.next())
        return query.value(0).toInt();

    return 0;
}

// -------------------- SEARCH --------------------

QList<Transaction> TransactionService::searchTransactions(int userId, const QString &text)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId
        AND (title LIKE :text OR description LIKE :text)
        ORDER BY date DESC
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":text", "%" + text + "%");

    if (query.exec()) {
        while (query.next()) {
            list.append(Transaction(
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes  ← new
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                ));
        }
    }

    return list;
}

// -------------------- BY ID --------------------

Transaction TransactionService::getTransactionById(int id, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description,notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    if (query.exec() && query.next()) {
        return Transaction (
            query.value(0).toInt(),     // id
            query.value(1).toString(),  // title
            query.value(2).toString(),  // description
            query.value(3).toString(),  // notes  ← new
            query.value(4).toDouble(),  // amount
            query.value(5).toString(),  // type
            query.value(6).toInt(),     // categoryId
            query.value(7).toInt(),     // userId
            query.value(8).toString()   // date
            );
    }

    return Transaction();
}

// -------------------- CATEGORY --------------------

QList<Transaction> TransactionService::getTransactionsByCategory(int userId, int categoryId)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId AND category_id = :categoryId
        ORDER BY date DESC
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":categoryId", categoryId);

    if (query.exec()) {
        while (query.next()) {
            list.append(Transaction (
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes  ← new
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                ));
            }
    }

    return list;
}

// -------------------- DATE RANGE --------------------

QList<Transaction> TransactionService::getTransactionsByDateRange(int userId, const QDate &start, const QDate &end)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId
        AND date BETWEEN :start AND :end
        ORDER BY date DESC
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":start", start.toString("yyyy-MM-dd"));
    query.bindValue(":end", end.toString("yyyy-MM-dd"));

    if (query.exec()) {
        while (query.next()) {
            list.append(Transaction (
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                ));
        }
    }

    return list;
}

// -------------------- RECENT --------------------

QList<Transaction> TransactionService::getRecentTransactions(int userId, int limit)
{
    QList<Transaction> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type, category_id, user_id, date
        FROM transactions
        WHERE user_id = :userId
        ORDER BY date DESC
        LIMIT :limit
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":limit", limit);

    if (query.exec()) {
        while (query.next()) {
            list.append(Transaction (
                query.value(0).toInt(),     // id
                query.value(1).toString(),  // title
                query.value(2).toString(),  // description
                query.value(3).toString(),  // notes
                query.value(4).toDouble(),  // amount
                query.value(5).toString(),  // type
                query.value(6).toInt(),     // categoryId
                query.value(7).toInt(),     // userId
                query.value(8).toString()   // date
                ));
        }
    }

    return list;
}

// -------------------- FINANCIAL --------------------

double TransactionService::getTotalIncome(int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT SUM(amount)
        FROM transactions
        WHERE user_id = :userId AND type = 'income'
    )");

    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toDouble();

    return 0;
}

double TransactionService::getTotalExpense(int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT SUM(amount)
        FROM transactions
        WHERE user_id = :userId AND type = 'expense'
    )");

    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toDouble();

    return 0;
}

double TransactionService::getBalance(int userId)
{
    return getTotalIncome(userId) - getTotalExpense(userId);
}

// -------------------- CATEGORY STATS --------------------

QMap<int, int> TransactionService::getCategoryCounts(int userId)
{
    QMap<int, int> map;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT category_id, COUNT(*)
        FROM transactions
        WHERE user_id = :userId
        GROUP BY category_id
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            map[query.value(0).toInt()] = query.value(1).toInt();
        }
    }

    return map;
}

QMap<int, double> TransactionService::getCategoryTotals(int userId)
{
    QMap<int, double> map;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT category_id, SUM(amount)
        FROM transactions
        WHERE user_id = :userId AND type = 'expense'
        GROUP BY category_id
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            map[query.value(0).toInt()] = query.value(1).toDouble();
        }
    }

    return map;
}
