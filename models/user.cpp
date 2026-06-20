#include "user.h"

User::User()
    : id(-1)
{
}

User::User(int id, const QString& username, const QString& passwordHash)
{
    this->id = id;
    this->username = username;
    this->passwordHash = passwordHash;
}

int User::getId() const { return id; }
QString User::getUsername() const { return username; }
QString User::getPasswordHash() const { return passwordHash; }

void User::setId(int id) { this->id = id; }
void User::setUsername(const QString& username) { this->username = username; }
void User::setPasswordHash(const QString& hash) { this->passwordHash = hash; }
