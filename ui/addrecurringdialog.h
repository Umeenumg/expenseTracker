#ifndef ADDRECURRINGDIALOG_H
#define ADDRECURRINGDIALOG_H

#include <QtWidgets>
#include <QList>
#include "models/RecurringTransaction.h"
#include "models/Category.h"

namespace Ui { class AddRecurringDialog; }

class AddRecurringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecurringDialog(const QList<Category> &categories,
                                QWidget *parent = nullptr);
    ~AddRecurringDialog();

    RecurringTransaction getRecurring() const;

private slots:
    void on_confirmBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::AddRecurringDialog *ui;
    QList<Category> m_categories;
};

#endif
