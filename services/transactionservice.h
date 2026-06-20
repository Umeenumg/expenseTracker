
#ifndef TRANSACTIONSERVICE_H
#define TRANSACTIONSERVICE_H

#include <QSqlDatabase>
#include <QString>
#include <QList>
#include <QDate>
#include <QMap>
#include "models/transaction.h"

class TransactionService
{
public:
    explicit TransactionService(QSqlDatabase database);

    // CRUD
    bool validateTransaction(const Transaction &t, QString &error);

    bool addTransaction(const Transaction &transaction, int userId);

    QList<Transaction> getAllTransactions(int userId);

    QList<Transaction> getTransactionsByType(int userId, const QString &type);

    bool deleteTransaction(int id, int userId);

    bool updateTransaction(const Transaction &transaction, int userId);

    int getTransactionsCount(int userId);

    int countTransactionsByType(int userId, const QString &type);

    QList<Transaction> searchTransactions(int userId, const QString &text);

    Transaction getTransactionById(int id, int userId);

    QList<Transaction> getTransactionsByCategory(int userId, int categoryId);

    QList<Transaction> getTransactionsByDateRange(int userId, const QDate &start, const QDate &end);

    QList<Transaction> getRecentTransactions(int userId, int limit);

    double getTotalIncome(int userId);

    double getTotalExpense(int userId);

    double getBalance(int userId);

    QMap<int, int> getCategoryCounts(int userId);

    QMap<int, double> getCategoryTotals(int userId);

private:
    QSqlDatabase m_database;
};

#endif // TRANSACTIONSERVICE_H
