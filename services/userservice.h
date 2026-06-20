#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QSqlDatabase>
#include <QString>
#include "models/User.h"

class UserService
{
public:
    explicit UserService(QSqlDatabase db);

    bool registerUser(const QString &username,
                      const QString &password,
                      QString &error);

    bool loginUser(const QString &username,
                   const QString &password,
                   User &outUser,
                   QString &error);
    bool changePassword(int userId,
                        const QString &currentPassword,
                        const QString &newPassword,
                        QString &error);

private:
    QSqlDatabase m_db;
};

#endif
