#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>

class Transaction
{
private:
    int id;
    QString title;
    QString description;
    QString notes;
    double amount;
    QString type;
    int categoryId;
    int userId;
    QString date;

public:
    Transaction();
    Transaction(int id,
                const QString &title,
                const QString &description,
                const QString &notes,
                double amount,
                const QString &type,
                int categoryId,
                int userId,
                const QString &date);

    // Getters
    int getId() const;
    QString getTitle() const;
    QString getDescription() const;
    QString getNotes()       const;
    double getAmount() const;
    QString getType() const;
    int getCategoryId() const;
    int getUserId() const;
    QString getDate() const;

    // Setters
    void setId(int id);
    void setTitle(const QString& title);
    void setDescription(const QString& description);
    void setNotes(const QString &notes);
    void setAmount(double amount);
    void setType(const QString& type);
    void setCategoryId(int categoryId);
    void setUserId(int userId);
    void setDate(const QString& date);
};

#endif
