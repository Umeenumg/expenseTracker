#include "services/UserSettingsService.h"
#include <QSqlError>
#include <QDebug>

UserSettingsService::UserSettingsService(QSqlDatabase db)
    : m_db(db)
{
}

void UserSettingsService::initSettings(int userId)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        INSERT OR IGNORE INTO user_settings
        (user_id, currency_code, currency_symbol)
        VALUES(:userId, 'USD', '$')
    )");
    query.bindValue(":userId", userId);
    query.exec();
}

QString UserSettingsService::getCurrencyCode(int userId)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT currency_code FROM user_settings
        WHERE user_id = :userId
    )");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toString();

    return "USD";
}

QString UserSettingsService::getCurrencySymbol(int userId)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT currency_symbol FROM user_settings
        WHERE user_id = :userId
    )");
    query.bindValue(":userId", userId);

    if (query.exec() && query.next())
        return query.value(0).toString();

    return "$";
}

bool UserSettingsService::setCurrency(int userId,
                                      const QString &code,
                                      const QString &symbol)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
        INSERT INTO user_settings
            (user_id, currency_code, currency_symbol)
        VALUES(:userId, :code, :symbol)
        ON CONFLICT(user_id) DO UPDATE
        SET currency_code   = :code,
            currency_symbol = :symbol
    )");
    query.bindValue(":userId", userId);
    query.bindValue(":code",   code);
    query.bindValue(":symbol", symbol);

    if (!query.exec()) {
        qDebug() << "setCurrency error:"
                 << query.lastError().text();
        return false;
    }
    return true;
}
