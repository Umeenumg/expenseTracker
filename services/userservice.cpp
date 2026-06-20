#include "services/UserService.h"
#include "core/Security.h"
#include "services/CategoryService.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

UserService::UserService(QSqlDatabase db)
    : m_db(db)
{
}

bool UserService::registerUser(const QString &username,
                               const QString &password,
                               QString &error)
{
    if (username.isEmpty() || password.isEmpty()) {
        error = "Empty fields";
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO users(username, password_hash)
        VALUES(:username, :password)
    )");

    query.bindValue(":username", username);
    query.bindValue(":password", Security::hashPassword(password));

    if (!query.exec()) {
        error = "Username already exists";
        return false;
    }

    // ── GET NEW USER ID ───────────────────
    int newUserId = query.lastInsertId().toInt();

    // ── ADD DEFAULT CATEGORIES ────────────
    CategoryService catService(m_db);
    catService.addDefaultCategories(newUserId);

    return true;
}

bool UserService::loginUser(const QString &username,
                            const QString &password,
                            User &outUser,
                            QString &error)
{
    QSqlQuery query(m_db);

    query.prepare(R"(
        SELECT id, username, password_hash
        FROM users
        WHERE username = :username
    )");

    query.bindValue(":username", username);

    if (!query.exec()) {
        error = "DB error";
        return false;
    }

    if (!query.next()) {
        error = "User not found";
        return false;
    }

    QString dbHash    = query.value(2).toString();
    QString inputHash = Security::hashPassword(password);

    if (dbHash != inputHash) {
        error = "Wrong password";
        return false;
    }

    outUser.setId(query.value(0).toInt());
    outUser.setUsername(query.value(1).toString());
    outUser.setPasswordHash(dbHash);

    return true;
}

bool UserService::changePassword(int userId,
                                 const QString &currentPassword,
                                 const QString &newPassword,
                                 QString &error)
{
    // verify current password
    QSqlQuery query(m_db);
    query.prepare("SELECT password_hash FROM users WHERE id = :id");
    query.bindValue(":id", userId);

    if (!query.exec() || !query.next()) {
        error = "User not found";
        return false;
    }

    QString dbHash = query.value(0).toString();
    if (Security::hashPassword(currentPassword) != dbHash) {
        error = "Current password is incorrect";
        return false;
    }

    if (newPassword.length() < 6) {
        error = "New password must be at least 6 characters";
        return false;
    }

    // update password
    QSqlQuery update(m_db);
    update.prepare(R"(
        UPDATE users
        SET password_hash = :hash
        WHERE id = :id
    )");
    update.bindValue(":hash", Security::hashPassword(newPassword));
    update.bindValue(":id", userId);

    if (!update.exec()) {
        error = "Failed to update password";
        return false;
    }

    return true;
}
