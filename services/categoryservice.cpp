#include "categoryservice.h"

// constructor
CategoryService::CategoryService(QSqlDatabase database)
    : m_database(database)
{
}

// ---------------- ADD ----------------

bool CategoryService::addCategory(int userId, const QString &name, const QString &type)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        INSERT INTO categories(name, type, user_id)
        VALUES(:name, :type, :userId)
    )");

    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":userId", userId);

    return query.exec();
}

// ---------------- GET ALL ----------------

QList<Category> CategoryService::getAllCategories(int userId)
{
    QList<Category> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, name, type, user_id, budget
        FROM categories
        WHERE user_id = :userId
        ORDER BY name
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            list.append(Category(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toInt(),
                query.value(4).toDouble()
                ));
        }
    }

    return list;
}

// ---------------- DELETE ----------------

bool CategoryService::deleteCategory(int id, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        DELETE FROM categories
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    return query.exec();
}

// ---------------- UPDATE ----------------

bool CategoryService::updateCategory(int id, int userId, const QString &newName)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        UPDATE categories
        SET name = :name
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":name", newName);
    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    return query.exec();
}

// ---------------- EXISTS ----------------

bool CategoryService::categoryExists(int userId, const QString &name)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT COUNT(*)
        FROM categories
        WHERE user_id = :userId AND name = :name
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":name", name);

    if (query.exec() && query.next())
        return query.value(0).toInt() > 0;

    return false;
}

// ---------------- HAS TRANSACTIONS ----------------

bool CategoryService::categoryHasTransactions(int userId, int categoryId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT COUNT(*)
        FROM transactions
        WHERE user_id = :userId AND category_id = :categoryId
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":categoryId", categoryId);

    if (query.exec() && query.next())
        return query.value(0).toInt() > 0;

    return false;
}

// ---------------- COUNT ----------------

int CategoryService::getCategoryCount(int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT COUNT(*)
        FROM categories
        WHERE user_id = :userId
    )");

    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toInt();

    return 0;
}

// ---------------- DEFAULT CATEGORIES ----------------

bool CategoryService::addDefaultCategories(int userId)
{
    addCategory(userId, "Salary", "income");
    addCategory(userId, "Freelance", "income");

    addCategory(userId, "Food", "expense");
    addCategory(userId, "Transport", "expense");
    addCategory(userId, "Bills", "expense");

    return true;
}

// ---------------- SEARCH ----------------

QList<Category> CategoryService::searchCategories(int userId, const QString &text)
{
    QList<Category> list;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, name, type, user_id, budget
        FROM categories
        WHERE user_id = :userId
        AND name LIKE :text
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":text", "%" + text + "%");

    if (query.exec()) {
        while (query.next()) {
            list.append(Category(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toString(),
                query.value(3).toInt(),
                query.value(4).toDouble()
                ));
        }
    }

    return list;
}

// ---------------- GET BY ID ----------------

bool CategoryService::getCategoryById(int id, int userId, Category &category)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, name, type, user_id
        FROM categories
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    if (query.exec() && query.next()) {
        category = Category(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toInt()
            );
        return true;
    }

    return false;
}

// ---------------- HELPERS ----------------

QString CategoryService::getCategoryNameById(int id, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT name
        FROM categories
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id", id);
    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toString();

    return "";
}

int CategoryService::getCategoryIdByName(int userId, const QString &name)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id
        FROM categories
        WHERE user_id = :userId AND name = :name
    )");

    query.bindValue(":userId", userId);
    query.bindValue(":name", name);

    if (query.exec() && query.next())
        return query.value(0).toInt();

    return -1;
}
// ── SET BUDGET ────────────────────────────────────────

bool CategoryService::setBudget(int categoryId,
                                int userId,
                                double budget)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        UPDATE categories
        SET budget = :budget
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":budget", budget);
    query.bindValue(":id",     categoryId);
    query.bindValue(":userId", userId);

    return query.exec();
}

// ── GET BUDGET ────────────────────────────────────────

double CategoryService::getBudget(int categoryId, int userId)
{
    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT budget FROM categories
        WHERE id = :id AND user_id = :userId
    )");

    query.bindValue(":id",     categoryId);
    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toDouble();

    return 0.0;
}

// ── GET ALL BUDGETS ───────────────────────────────────

QMap<int, double> CategoryService::getAllBudgets(int userId)
{
    QMap<int, double> map;

    QSqlQuery query(m_database);

    query.prepare(R"(
        SELECT id, budget FROM categories
        WHERE user_id = :userId AND budget > 0
    )");

    query.bindValue(":userId", userId);

    if (query.exec()) {
        while (query.next()) {
            map[query.value(0).toInt()] = query.value(1).toDouble();
        }
    }

    return map;
}
