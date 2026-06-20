#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

class Category
{
public:
    Category();
    Category(int id, const QString &name,
             const QString &type, int userId,
             double budget = 0.0);

    int     getId()     const;
    QString getName()   const;
    QString getType()   const;
    int     getUserId() const;
    double  getBudget() const;

    void setId(int id);
    void setName(const QString &name);
    void setType(const QString &type);
    void setUserId(int userId);
    void setBudget(double budget);

private:
    int     id;
    QString name;
    QString type;
    int     userId;
    double  budget;
};

#endif
