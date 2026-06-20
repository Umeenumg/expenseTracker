#ifndef USERSETTINGSSERVICE_H
#define USERSETTINGSSERVICE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class UserSettingsService
{
public:
    explicit UserSettingsService(QSqlDatabase db);

    // currency
    QString getCurrencyCode(int userId);
    QString getCurrencySymbol(int userId);
    bool    setCurrency(int userId,
                     const QString &code,
                     const QString &symbol);

    // ensure row exists
    void initSettings(int userId);

private:
    QSqlDatabase m_db;
};

#endif
