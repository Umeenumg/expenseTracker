#include "database/DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QStandardPaths>

DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::openDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("expenses.db");

    if (!m_database.open()) {
        qDebug() << "Database failed:" << m_database.lastError().text();
        return false;
    }

    qDebug() << "Database opened successfully";
    createTables();
    return true;
}

QSqlDatabase DatabaseManager::getDatabase() const
{
    return m_database;
}

void DatabaseManager::createTables()
{
    QSqlQuery query(m_database);

    // ── USERS ────────────────────────────────────────────
    query.exec(R"(
        CREATE TABLE IF NOT EXISTS users (
            id              INTEGER PRIMARY KEY AUTOINCREMENT,
            username        TEXT UNIQUE NOT NULL,
            password_hash   TEXT NOT NULL
        )
    )");

    // ── CATEGORIES (per user) ────────────────────────────
    query.exec(R"(
    CREATE TABLE IF NOT EXISTS categories (
        id      INTEGER PRIMARY KEY AUTOINCREMENT,
        name    TEXT NOT NULL,
        type    TEXT NOT NULL,
        user_id INTEGER NOT NULL,
        budget  REAL DEFAULT 0,
        FOREIGN KEY(user_id) REFERENCES users(id)
    )
    )");

    // ── MIGRATION: add budget column if missing ──
    query.exec(R"(
    ALTER TABLE categories ADD COLUMN budget REAL DEFAULT 0
    )");

    // ── TRANSACTIONS (per user) ──────────────────────────
    query.exec(R"(
    CREATE TABLE IF NOT EXISTS transactions (
        id          INTEGER PRIMARY KEY AUTOINCREMENT,
        title       TEXT NOT NULL,
        description TEXT,
        notes       TEXT,
        amount      REAL NOT NULL,
        type        TEXT NOT NULL,
        category_id INTEGER,
        user_id     INTEGER NOT NULL,
        date        TEXT,
        FOREIGN KEY(user_id)     REFERENCES users(id),
        FOREIGN KEY(category_id) REFERENCES categories(id)
    )
    )");
    qDebug() << "Tables ready (users + categories + transactions)";

    // ── RECURRING TRANSACTIONS ────────────────────────────
    query.exec(R"(
    CREATE TABLE IF NOT EXISTS recurring_transactions (
        id             INTEGER PRIMARY KEY AUTOINCREMENT,
        title          TEXT NOT NULL,
        description    TEXT,
        notes          TEXT,
        amount         REAL NOT NULL,
        type           TEXT NOT NULL,
        category_id    INTEGER,
        user_id        INTEGER NOT NULL,
        frequency      TEXT NOT NULL,
        next_due_date  TEXT NOT NULL,
        is_active      INTEGER DEFAULT 1,
        FOREIGN KEY(user_id)     REFERENCES users(id),
        FOREIGN KEY(category_id) REFERENCES categories(id)
    )
)");
    // ── USER SETTINGS (currency preference) ──────────────
    query.exec(R"(
    CREATE TABLE IF NOT EXISTS user_settings (
        user_id          INTEGER PRIMARY KEY,
        currency_code    TEXT DEFAULT 'USD',
        currency_symbol  TEXT DEFAULT '$',
        FOREIGN KEY(user_id) REFERENCES users(id)
    )
)");

    // ── MIGRATION: add currency to transactions ───────────
    query.exec(R"(
    ALTER TABLE transactions ADD COLUMN currency TEXT DEFAULT 'USD'
)");
    // silently fails if column already exists — fine
}

// ─────────────────────────────────────────────
// GET DATABASE PATH
// ─────────────────────────────────────────────

QString DatabaseManager::getDatabasePath() const
{
    return m_database.databaseName();
}

// ─────────────────────────────────────────────
// BACKUP
// ─────────────────────────────────────────────

bool DatabaseManager::backupDatabase(const QString &destPath, QString &error)
{
    QString dbPath = m_database.databaseName();

    if (dbPath.isEmpty()) {
        error = "Database path is empty.";
        return false;
    }

    if (!QFile::exists(dbPath)) {
        error = "Database file not found at: " + dbPath;
        return false;
    }

    // remove existing file at destination
    if (QFile::exists(destPath)) {
        if (!QFile::remove(destPath)) {
            error = "Could not overwrite existing backup file.";
            return false;
        }
    }

    if (!QFile::copy(dbPath, destPath)) {
        error = "Failed to copy database to: " + destPath;
        return false;
    }

    qDebug() << "Backup created at:" << destPath;
    return true;
}

// ─────────────────────────────────────────────
// RESTORE
// ─────────────────────────────────────────────

bool DatabaseManager::restoreDatabase(const QString &sourcePath, QString &error)
{
    if (!QFile::exists(sourcePath)) {
        error = "Backup file not found.";
        return false;
    }

    QString dbPath = m_database.databaseName();

    // close all connections before replacing the file
    m_database.close();
    QSqlDatabase::removeDatabase(m_database.connectionName());

    // replace database file
    if (QFile::exists(dbPath)) {
        if (!QFile::remove(dbPath)) {
            error = "Could not remove current database file.";
            return false;
        }
    }

    if (!QFile::copy(sourcePath, dbPath)) {
        error = "Failed to restore database from backup.";
        return false;
    }

    // reopen database
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(dbPath);

    if (!m_database.open()) {
        error = "Database restored but failed to reopen: "
                + m_database.lastError().text();
        return false;
    }

    qDebug() << "Database restored from:" << sourcePath;
    return true;
}
