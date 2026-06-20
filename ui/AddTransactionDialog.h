

#ifndef ADDTRANSACTIONDIALOG_H
#define ADDTRANSACTIONDIALOG_H

#include <QtWidgets>                      // ← ADD THIS

#include <QDialog>
#include <QList>
#include "models/Transaction.h"
#include "models/Category.h"

namespace Ui {
class AddTransactionDialog;
}

class AddTransactionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTransactionDialog(const QList<Category> &categories,
                                  QWidget *parent = nullptr);

    explicit AddTransactionDialog(const QList<Category> &categories,
                                  const Transaction &transaction,
                                  QWidget *parent = nullptr);

    ~AddTransactionDialog();

    Transaction getTransaction() const;

private slots:
    void on_confirmBtn_clicked();
    void on_cancelBtn_clicked();

private:
    Ui::AddTransactionDialog *ui;

    QList<Category> m_categories;
    bool            m_editMode = false;
    int             m_editId   = -1;

    void setup(const QList<Category> &categories);
    void populateCategories();
    bool validate(QString &error);
};

#endif
