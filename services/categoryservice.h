#ifndef CATEGORYSERVICE_H
#define CATEGORYSERVICE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QList>
#include <QMap>
#include "models/Category.h"

class CategoryService
{
public:
    explicit CategoryService(QSqlDatabase database);

    bool            addCategory(int userId, const QString &name,
                     const QString &type);
    QList<Category> getAllCategories(int userId);
    bool            deleteCategory(int id, int userId);
    bool            updateCategory(int id, int userId,
                        const QString &newName);
    bool            categoryExists(int userId, const QString &name);
    bool            categoryHasTransactions(int userId, int categoryId);
    int             getCategoryCount(int userId);
    bool            addDefaultCategories(int userId);
    QList<Category> searchCategories(int userId, const QString &text);
    bool            getCategoryById(int id, int userId, Category &category);
    QString         getCategoryNameById(int id, int userId);
    int             getCategoryIdByName(int userId, const QString &name);

    // ── BUDGET ───────────────────────────
    bool   setBudget(int categoryId, int userId, double budget);
    double getBudget(int categoryId, int userId);
    QMap<int, double> getAllBudgets(int userId);

private:
    QSqlDatabase m_database;
};

#endif
