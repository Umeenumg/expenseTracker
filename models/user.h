#ifndef USER_H
#define USER_H

#include <QString>

class User
{
private:
    int id;
    QString username;
    QString passwordHash;

public:
    User();
    User(int id, const QString& username, const QString& passwordHash);

    int getId() const;
    QString getUsername() const;
    QString getPasswordHash() const;

    void setId(int id);
    void setUsername(const QString& username);
    void setPasswordHash(const QString& hash);
};

#endif
