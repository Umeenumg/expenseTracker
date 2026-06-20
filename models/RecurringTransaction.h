#ifndef RECURRINGTRANSACTION_H
#define RECURRINGTRANSACTION_H

#include <QString>
#include <QDate>

class RecurringTransaction
{
public:
    RecurringTransaction();
    RecurringTransaction(int id,
                         const QString &title,
                         const QString &description,
                         const QString &notes,
                         double amount,
                         const QString &type,
                         int categoryId,
                         int userId,
                         const QString &frequency,
                         const QString &nextDueDate,
                         bool isActive);

    int     getId()          const;
    QString getTitle()       const;
    QString getDescription() const;
    QString getNotes()       const;
    double  getAmount()      const;
    QString getType()        const;
    int     getCategoryId()  const;
    int     getUserId()      const;
    QString getFrequency()   const;
    QString getNextDueDate() const;
    bool    isActive()       const;

    void setId(int v);
    void setTitle(const QString &v);
    void setDescription(const QString &v);
    void setNotes(const QString &v);
    void setAmount(double v);
    void setType(const QString &v);
    void setCategoryId(int v);
    void setUserId(int v);
    void setFrequency(const QString &v);
    void setNextDueDate(const QString &v);
    void setIsActive(bool v);

    // helper
    QString getFrequencyLabel() const;

private:
    int     m_id;
    QString m_title;
    QString m_description;
    QString m_notes;
    double  m_amount;
    QString m_type;
    int     m_categoryId;
    int     m_userId;
    QString m_frequency;
    QString m_nextDueDate;
    bool    m_isActive;
};

#endif
