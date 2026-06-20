#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager();

    bool openDatabase();
    QSqlDatabase getDatabase() const;

    // ── BACKUP / RESTORE ─────────────────
    bool backupDatabase(const QString &destPath, QString &error);
    bool restoreDatabase(const QString &sourcePath, QString &error);
    QString getDatabasePath() const;


private:
    void createTables();
    QSqlDatabase m_database;
};

#endif
