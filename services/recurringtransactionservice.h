#ifndef RECURRINGTRANSACTIONSERVICE_H
#define RECURRINGTRANSACTIONSERVICE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QDate>
#include "models/RecurringTransaction.h"
#include "models/Transaction.h"

class RecurringTransactionService
{
public:
    explicit RecurringTransactionService(QSqlDatabase db);

    bool addRecurring(const RecurringTransaction &r);
    bool updateRecurring(const RecurringTransaction &r);
    bool deleteRecurring(int id, int userId);
    bool toggleActive(int id, int userId, bool active);

    QList<RecurringTransaction> getAllRecurring(int userId);
    QList<RecurringTransaction> getDueRecurring(int userId);

    // ── AUTO PROCESS ─────────────────────
    // call on app startup — creates transactions for overdue items
    int processDueRecurring(int userId, QSqlDatabase db);

private:
    QSqlDatabase m_db;

    QString nextDueDate(const QString &currentDate,
                        const QString &frequency);
};

#endif
