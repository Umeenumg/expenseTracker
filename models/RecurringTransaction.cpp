#include "models/RecurringTransaction.h"

RecurringTransaction::RecurringTransaction()
    : m_id(-1), m_amount(0), m_categoryId(-1),
    m_userId(-1), m_isActive(true)
{
}

RecurringTransaction::RecurringTransaction(
    int id, const QString &title, const QString &description,
    const QString &notes, double amount, const QString &type,
    int categoryId, int userId, const QString &frequency,
    const QString &nextDueDate, bool isActive)
    : m_id(id), m_title(title), m_description(description),
    m_notes(notes), m_amount(amount), m_type(type),
    m_categoryId(categoryId), m_userId(userId),
    m_frequency(frequency), m_nextDueDate(nextDueDate),
    m_isActive(isActive)
{
}

int     RecurringTransaction::getId()          const { return m_id; }
QString RecurringTransaction::getTitle()       const { return m_title; }
QString RecurringTransaction::getDescription() const { return m_description; }
QString RecurringTransaction::getNotes()       const { return m_notes; }
double  RecurringTransaction::getAmount()      const { return m_amount; }
QString RecurringTransaction::getType()        const { return m_type; }
int     RecurringTransaction::getCategoryId()  const { return m_categoryId; }
int     RecurringTransaction::getUserId()      const { return m_userId; }
QString RecurringTransaction::getFrequency()   const { return m_frequency; }
QString RecurringTransaction::getNextDueDate() const { return m_nextDueDate; }
bool    RecurringTransaction::isActive()       const { return m_isActive; }

void RecurringTransaction::setId(int v)                  { m_id = v; }
void RecurringTransaction::setTitle(const QString &v)    { m_title = v; }
void RecurringTransaction::setDescription(const QString &v) { m_description = v; }
void RecurringTransaction::setNotes(const QString &v)    { m_notes = v; }
void RecurringTransaction::setAmount(double v)           { m_amount = v; }
void RecurringTransaction::setType(const QString &v)     { m_type = v; }
void RecurringTransaction::setCategoryId(int v)          { m_categoryId = v; }
void RecurringTransaction::setUserId(int v)              { m_userId = v; }
void RecurringTransaction::setFrequency(const QString &v){ m_frequency = v; }
void RecurringTransaction::setNextDueDate(const QString &v){ m_nextDueDate = v; }
void RecurringTransaction::setIsActive(bool v)           { m_isActive = v; }

QString RecurringTransaction::getFrequencyLabel() const
{
    if (m_frequency == "daily")    return "Daily";
    if (m_frequency == "weekly")   return "Weekly";
    if (m_frequency == "monthly")  return "Monthly";
    if (m_frequency == "yearly")   return "Yearly";
    return m_frequency;
}
