#include "transaction.h"

Transaction::Transaction()
    : id(-1), amount(0), categoryId(-1), userId(-1)
{
}

Transaction::Transaction(int id,
                         const QString &title,
                         const QString &description,
                         const QString &notes,
                         double amount,
                         const QString &type,
                         int categoryId,
                         int userId,
                         const QString &date)
    : id(id), title(title), description(description),
    notes(notes), amount(amount), type(type),
    categoryId(categoryId), userId(userId), date(date)
{
}

int     Transaction::getId()          const { return id; }
QString Transaction::getTitle()       const { return title; }
QString Transaction::getDescription() const { return description; }
QString Transaction::getNotes()       const { return notes; }
double  Transaction::getAmount()      const { return amount; }
QString Transaction::getType()        const { return type; }
int     Transaction::getCategoryId()  const { return categoryId; }
int     Transaction::getUserId()      const { return userId; }
QString Transaction::getDate()        const { return date; }

void Transaction::setId(int v)                  { id = v; }
void Transaction::setTitle(const QString &v)    { title = v; }
void Transaction::setDescription(const QString &v) { description = v; }
void Transaction::setNotes(const QString &v)    { notes = v; }
void Transaction::setAmount(double v)           { amount = v; }
void Transaction::setType(const QString &v)     { type = v; }
void Transaction::setCategoryId(int v)          { categoryId = v; }
void Transaction::setUserId(int v)              { userId = v; }
void Transaction::setDate(const QString &v)     { date = v; }
