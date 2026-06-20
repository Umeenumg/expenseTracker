#include "services/RecurringTransactionService.h"
#include <QDebug>

RecurringTransactionService::RecurringTransactionService(QSqlDatabase db)
    : m_db(db)
{
}

// ─────────────────────────────────────────────
// ADD
// ─────────────────────────────────────────────

bool RecurringTransactionService::addRecurring(
    const RecurringTransaction &r)
{
    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO recurring_transactions
        (title, description, notes, amount, type,
         category_id, user_id, frequency, next_due_date, is_active)
        VALUES
        (:title, :description, :notes, :amount, :type,
         :categoryId, :userId, :frequency, :nextDueDate, :isActive)
    )");

    query.bindValue(":title",       r.getTitle());
    query.bindValue(":description", r.getDescription());
    query.bindValue(":notes",       r.getNotes());
    query.bindValue(":amount",      r.getAmount());
    query.bindValue(":type",        r.getType());
    query.bindValue(":categoryId",  r.getCategoryId());
    query.bindValue(":userId",      r.getUserId());
    query.bindValue(":frequency",   r.getFrequency());
    query.bindValue(":nextDueDate", r.getNextDueDate());
    query.bindValue(":isActive",    r.isActive() ? 1 : 0);

    if (!query.exec()) {
        qDebug() << "addRecurring error:" << query.lastError().text();
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────
// UPDATE
// ─────────────────────────────────────────────

bool RecurringTransactionService::updateRecurring(
    const RecurringTransaction &r)
{
    QSqlQuery query(m_db);

    query.prepare(R"(
        UPDATE recurring_transactions
        SET title       = :title,
            description = :description,
            notes       = :notes,
            amount      = :amount,
            type        = :type,
            category_id = :categoryId,
            frequency   = :frequency,
            next_due_date = :nextDueDate,
            is_active   = :isActive
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":title",       r.getTitle());
    query.bindValue(":description", r.getDescription());
    query.bindValue(":notes",       r.getNotes());
    query.bindValue(":amount",      r.getAmount());
    query.bindValue(":type",        r.getType());
    query.bindValue(":categoryId",  r.getCategoryId());
    query.bindValue(":frequency",   r.getFrequency());
    query.bindValue(":nextDueDate", r.getNextDueDate());
    query.bindValue(":isActive",    r.isActive() ? 1 : 0);
    query.bindValue(":id",          r.getId());
    query.bindValue(":userId",      r.getUserId());

    return query.exec();
}

// ─────────────────────────────────────────────
// DELETE
// ─────────────────────────────────────────────

bool RecurringTransactionService::deleteRecurring(int id, int userId)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        DELETE FROM recurring_transactions
        WHERE id = :id AND user_id = :userId
    )");
    query.bindValue(":id",     id);
    query.bindValue(":userId", userId);
    return query.exec();
}

// ─────────────────────────────────────────────
// TOGGLE ACTIVE
// ─────────────────────────────────────────────

bool RecurringTransactionService::toggleActive(
    int id, int userId, bool active)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        UPDATE recurring_transactions
        SET is_active = :active
        WHERE id = :id AND user_id = :userId
    )");
    query.bindValue(":active", active ? 1 : 0);
    query.bindValue(":id",     id);
    query.bindValue(":userId", userId);
    return query.exec();
}

// ─────────────────────────────────────────────
// GET ALL
// ─────────────────────────────────────────────

QList<RecurringTransaction>
RecurringTransactionService::getAllRecurring(int userId)
{
    QList<RecurringTransaction> list;
    QSqlQuery query(m_db);

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type,
               category_id, user_id, frequency,
               next_due_date, is_active
        FROM recurring_transactions
        WHERE user_id = :userId
        ORDER BY next_due_date ASC
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            list.append(RecurringTransaction(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toDouble(),
                query.value(5).toString(),
                query.value(6).toInt(),
                query.value(7).toInt(),
                query.value(8).toString(),
                query.value(9).toString(),
                query.value(10).toInt() == 1
                ));
        }
    }

    return list;
}

// ─────────────────────────────────────────────
// GET DUE
// ─────────────────────────────────────────────

QList<RecurringTransaction>
RecurringTransactionService::getDueRecurring(int userId)
{
    QList<RecurringTransaction> list;
    QSqlQuery query(m_db);

    QString today = QDate::currentDate().toString("yyyy-MM-dd");

    query.prepare(R"(
        SELECT id, title, description, notes, amount, type,
               category_id, user_id, frequency,
               next_due_date, is_active
        FROM recurring_transactions
        WHERE user_id = :userId
          AND is_active = 1
          AND next_due_date <= :today
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":today",  today);

    if (query.exec()) {
        while (query.next()) {
            list.append(RecurringTransaction(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toString(),
                query.value(4).toDouble(),
                query.value(5).toString(),
                query.value(6).toInt(),
                query.value(7).toInt(),
                query.value(8).toString(),
                query.value(9).toString(),
                query.value(10).toInt() == 1
                ));
        }
    }

    return list;
}

// ─────────────────────────────────────────────
// NEXT DUE DATE HELPER
// ─────────────────────────────────────────────

QString RecurringTransactionService::nextDueDate(
    const QString &currentDate, const QString &frequency)
{
    QDate date = QDate::fromString(currentDate, "yyyy-MM-dd");

    if (frequency == "daily")   date = date.addDays(1);
    if (frequency == "weekly")  date = date.addDays(7);
    if (frequency == "monthly") date = date.addMonths(1);
    if (frequency == "yearly")  date = date.addYears(1);

    return date.toString("yyyy-MM-dd");
}

// ─────────────────────────────────────────────
// PROCESS DUE — auto-creates transactions
// ─────────────────────────────────────────────

int RecurringTransactionService::processDueRecurring(
    int userId, QSqlDatabase db)
{
    auto dueList = getDueRecurring(userId);
    int  count   = 0;

    for (const RecurringTransaction &r : dueList) {

        // insert into transactions table
        QSqlQuery insert(db);
        insert.prepare(R"(
            INSERT INTO transactions
            (title, description, notes, amount, type,
             category_id, user_id, date)
            VALUES
            (:title, :description, :notes, :amount, :type,
             :categoryId, :userId, :date)
        )");

        insert.bindValue(":title",       r.getTitle());
        insert.bindValue(":description", r.getDescription());
        insert.bindValue(":notes",       r.getNotes());
        insert.bindValue(":amount",      r.getAmount());
        insert.bindValue(":type",        r.getType());
        insert.bindValue(":categoryId",  r.getCategoryId());
        insert.bindValue(":userId",      userId);
        insert.bindValue(":date",        r.getNextDueDate());

        if (insert.exec()) {
            // advance next due date
            QSqlQuery update(db);
            update.prepare(R"(
                UPDATE recurring_transactions
                SET next_due_date = :next
                WHERE id = :id
            )");
            update.bindValue(":next",
                             nextDueDate(r.getNextDueDate(), r.getFrequency()));
            update.bindValue(":id", r.getId());
            update.exec();
            count++;
        }
    }

    return count;
}
