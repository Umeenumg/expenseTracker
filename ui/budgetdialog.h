#ifndef BUDGETDIALOG_H
#define BUDGETDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QFrame>
#include "models/Category.h"

class BudgetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BudgetDialog(const Category &category,
                          double currentSpent,
                          QWidget *parent = nullptr);

    double getBudget() const;

private:
    QDoubleSpinBox *m_budgetSpin = nullptr;
};

#endif
