#ifndef SECURITY_H
#define SECURITY_H

#include <QString>
#include <QCryptographicHash>

class Security
{
public:
    // Hash password using SHA-256
    static QString hashPassword(const QString &password)
    {
        return QString(
            QCryptographicHash::hash(
                password.toUtf8(),
                QCryptographicHash::Sha256
                ).toHex()
            );
    }

    // Optional helper (useful later)
    static bool verifyPassword(const QString &password, const QString &hash)
    {
        return hashPassword(password) == hash;
    }
};

#endif
