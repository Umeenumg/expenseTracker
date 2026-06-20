#include "Category.h"

Category::Category()
    : id(-1), userId(-1), budget(0.0)
{
}

Category::Category(int id, const QString &name,
                   const QString &type, int userId,
                   double budget)
    : id(id), name(name), type(type),
    userId(userId), budget(budget)
{
}

int     Category::getId()     const { return id; }
QString Category::getName()   const { return name; }
QString Category::getType()   const { return type; }
int     Category::getUserId() const { return userId; }
double  Category::getBudget() const { return budget; }

void Category::setId(int v)              { id = v; }
void Category::setName(const QString &v) { name = v; }
void Category::setType(const QString &v) { type = v; }
void Category::setUserId(int v)          { userId = v; }
void Category::setBudget(double v)       { budget = v; }
