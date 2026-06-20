#ifndef TRANSACTIONNOTESDIALOG_H
#define TRANSACTIONNOTESDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFrame>
#include "models/Transaction.h"

class TransactionNotesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionNotesDialog(const Transaction &t,
                                    const QString &categoryName,
                                    QWidget *parent = nullptr);
};

#endif
