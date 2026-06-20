/********************************************************************************
** Form generated from reading UI file 'AddTransactionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANSACTIONDIALOG_H
#define UI_ADDTRANSACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *dialogTitle;
    QFrame *divider;
    QVBoxLayout *titleLayout;
    QLabel *titleFieldLabel;
    QLineEdit *titleEdit;
    QHBoxLayout *amountTypeLayout;
    QVBoxLayout *amountLayout;
    QLabel *amountLabel;
    QDoubleSpinBox *amountSpin;
    QVBoxLayout *typeLayout;
    QLabel *typeLabel;
    QComboBox *typeCombo;
    QVBoxLayout *categoryLayout;
    QLabel *categoryLabel;
    QComboBox *categoryCombo;
    QVBoxLayout *dateLayout;
    QLabel *dateLabel;
    QDateEdit *dateEdit;
    QVBoxLayout *descLayout;
    QLabel *descFieldLabel;
    QLineEdit *descEdit;
    QVBoxLayout *notesLayout;
    QLabel *notesFieldLabel;
    QPlainTextEdit *notesEdit;
    QSpacerItem *spacerItem;
    QHBoxLayout *btnLayout;
    QSpacerItem *spacerItem1;
    QPushButton *cancelBtn;
    QPushButton *confirmBtn;

    void setupUi(QDialog *AddTransactionDialog)
    {
        if (AddTransactionDialog->objectName().isEmpty())
            AddTransactionDialog->setObjectName("AddTransactionDialog");
        AddTransactionDialog->resize(460, 580);
        AddTransactionDialog->setMinimumSize(QSize(460, 580));
        AddTransactionDialog->setMaximumSize(QSize(420, 480));
        AddTransactionDialog->setStyleSheet(QString::fromUtf8("/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   ADD TRANSACTION DIALOG\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QDialog {\n"
"    background-color: #13131a"
                        ";\n"
"}\n"
"\n"
"QDialog QLabel#dialogTitle {\n"
"    font-size: 18px;\n"
"    font-weight: 700;\n"
"    color: #a78bfa;\n"
"    padding-bottom: 2px;\n"
"}\n"
"\n"
"QDialog QFrame#divider {\n"
"    color: #1e1e2e;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QDialog QLabel {\n"
"    font-size: 11px;\n"
"    color: #6b7280;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.3px;\n"
"}\n"
"\n"
"QDialog QLineEdit {\n"
"    background-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QDialog QLineEdit:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"QDialog QDoubleSpinBox {\n"
"    background-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QDialog QDoubleSpinBox:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"QDialog QDouble"
                        "SpinBox::up-button,\n"
"QDialog QDoubleSpinBox::down-button {\n"
"    background-color: #1e1e2e;\n"
"    border: none;\n"
"    width: 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDialog QDoubleSpinBox::up-button:hover,\n"
"QDialog QDoubleSpinBox::down-button:hover {\n"
"    background-color: #2a2a3a;\n"
"}\n"
"\n"
"QDialog QComboBox {\n"
"    background-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QDialog QComboBox:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"QDialog QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QDialog QComboBox QAbstractItemView {\n"
"    background-color: #13131f;\n"
"    border: 1px solid #252535;\n"
"    color: #e2e2e8;\n"
"    selection-background-color: #1e1e3f;\n"
"    selection-color: #a78bfa;\n"
"    padding: 4px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QDialog QDateEdit {\n"
"    backgrou"
                        "nd-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"    min-height: 16px;\n"
"}\n"
"\n"
"QDialog QDateEdit:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"QDialog QDateEdit::drop-down {\n"
"    background-color: #1e1e2e;\n"
"    border: none;\n"
"    width: 24px;\n"
"    border-radius: 0 8px 8px 0;\n"
"}\n"
"\n"
"QDialog QPlainTextEdit {\n"
"    background-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QPlainTextEdit:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 BUTTONS \342\200\224 violet theme to match the whole app \342\224\200\342\224\200 */\n"
"QPushButton#confirmBtn {\n"
"    background-color: #7c3aed;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 11px 28px;\n"
"    color: white;\n"
"    font-size: 13px;\n"
""
                        "    font-weight: 700;\n"
"    min-height: 38px;\n"
"    min-width: 110px;\n"
"}\n"
"\n"
"QPushButton#confirmBtn:hover {\n"
"    background-color: #6d28d9;\n"
"}\n"
"\n"
"QPushButton#confirmBtn:pressed {\n"
"    background-color: #5b21b6;\n"
"}\n"
"\n"
"QPushButton#cancelBtn {\n"
"    background-color: #1a1a28;\n"
"    border: 1px solid #2e2e4e;\n"
"    border-radius: 8px;\n"
"    padding: 11px 28px;\n"
"    color: #9ca3af;\n"
"    font-size: 13px;\n"
"    font-weight: 500;\n"
"    min-height: 38px;\n"
"    min-width: 110px;\n"
"}\n"
"\n"
"QPushButton#cancelBtn:hover {\n"
"    background-color: #222235;\n"
"    color: #e2e2e8;\n"
"    border-color: #3e3e5e;\n"
"}"));
        mainLayout = new QVBoxLayout(AddTransactionDialog);
        mainLayout->setSpacing(14);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(24, 24, 24, 24);
        dialogTitle = new QLabel(AddTransactionDialog);
        dialogTitle->setObjectName("dialogTitle");

        mainLayout->addWidget(dialogTitle);

        divider = new QFrame(AddTransactionDialog);
        divider->setObjectName("divider");
        divider->setFrameShape(QFrame::Shape::HLine);
        divider->setFrameShadow(QFrame::Shadow::Sunken);

        mainLayout->addWidget(divider);

        titleLayout = new QVBoxLayout();
        titleLayout->setSpacing(5);
        titleLayout->setObjectName("titleLayout");
        titleFieldLabel = new QLabel(AddTransactionDialog);
        titleFieldLabel->setObjectName("titleFieldLabel");

        titleLayout->addWidget(titleFieldLabel);

        titleEdit = new QLineEdit(AddTransactionDialog);
        titleEdit->setObjectName("titleEdit");

        titleLayout->addWidget(titleEdit);


        mainLayout->addLayout(titleLayout);

        amountTypeLayout = new QHBoxLayout();
        amountTypeLayout->setSpacing(12);
        amountTypeLayout->setObjectName("amountTypeLayout");
        amountLayout = new QVBoxLayout();
        amountLayout->setSpacing(5);
        amountLayout->setObjectName("amountLayout");
        amountLabel = new QLabel(AddTransactionDialog);
        amountLabel->setObjectName("amountLabel");

        amountLayout->addWidget(amountLabel);

        amountSpin = new QDoubleSpinBox(AddTransactionDialog);
        amountSpin->setObjectName("amountSpin");
        amountSpin->setDecimals(2);
        amountSpin->setMinimum(0.010000000000000);
        amountSpin->setMaximum(999999.989999999990687);
        amountSpin->setSingleStep(10.000000000000000);

        amountLayout->addWidget(amountSpin);


        amountTypeLayout->addLayout(amountLayout);

        typeLayout = new QVBoxLayout();
        typeLayout->setSpacing(5);
        typeLayout->setObjectName("typeLayout");
        typeLabel = new QLabel(AddTransactionDialog);
        typeLabel->setObjectName("typeLabel");

        typeLayout->addWidget(typeLabel);

        typeCombo = new QComboBox(AddTransactionDialog);
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->setObjectName("typeCombo");

        typeLayout->addWidget(typeCombo);


        amountTypeLayout->addLayout(typeLayout);


        mainLayout->addLayout(amountTypeLayout);

        categoryLayout = new QVBoxLayout();
        categoryLayout->setSpacing(5);
        categoryLayout->setObjectName("categoryLayout");
        categoryLabel = new QLabel(AddTransactionDialog);
        categoryLabel->setObjectName("categoryLabel");

        categoryLayout->addWidget(categoryLabel);

        categoryCombo = new QComboBox(AddTransactionDialog);
        categoryCombo->setObjectName("categoryCombo");

        categoryLayout->addWidget(categoryCombo);


        mainLayout->addLayout(categoryLayout);

        dateLayout = new QVBoxLayout();
        dateLayout->setSpacing(5);
        dateLayout->setObjectName("dateLayout");
        dateLabel = new QLabel(AddTransactionDialog);
        dateLabel->setObjectName("dateLabel");

        dateLayout->addWidget(dateLabel);

        dateEdit = new QDateEdit(AddTransactionDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        dateLayout->addWidget(dateEdit);


        mainLayout->addLayout(dateLayout);

        descLayout = new QVBoxLayout();
        descLayout->setSpacing(5);
        descLayout->setObjectName("descLayout");
        descFieldLabel = new QLabel(AddTransactionDialog);
        descFieldLabel->setObjectName("descFieldLabel");

        descLayout->addWidget(descFieldLabel);

        descEdit = new QLineEdit(AddTransactionDialog);
        descEdit->setObjectName("descEdit");

        descLayout->addWidget(descEdit);


        mainLayout->addLayout(descLayout);

        notesLayout = new QVBoxLayout();
        notesLayout->setSpacing(5);
        notesLayout->setObjectName("notesLayout");
        notesFieldLabel = new QLabel(AddTransactionDialog);
        notesFieldLabel->setObjectName("notesFieldLabel");

        notesLayout->addWidget(notesFieldLabel);

        notesEdit = new QPlainTextEdit(AddTransactionDialog);
        notesEdit->setObjectName("notesEdit");

        notesLayout->addWidget(notesEdit);


        mainLayout->addLayout(notesLayout);

        spacerItem = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(spacerItem);

        btnLayout = new QHBoxLayout();
        btnLayout->setSpacing(10);
        btnLayout->setObjectName("btnLayout");
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btnLayout->addItem(spacerItem1);

        cancelBtn = new QPushButton(AddTransactionDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setMinimumSize(QSize(168, 62));

        btnLayout->addWidget(cancelBtn);

        confirmBtn = new QPushButton(AddTransactionDialog);
        confirmBtn->setObjectName("confirmBtn");
        confirmBtn->setMinimumSize(QSize(166, 60));

        btnLayout->addWidget(confirmBtn);


        mainLayout->addLayout(btnLayout);


        retranslateUi(AddTransactionDialog);

        QMetaObject::connectSlotsByName(AddTransactionDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTransactionDialog)
    {
        AddTransactionDialog->setWindowTitle(QCoreApplication::translate("AddTransactionDialog", "Add Transaction", nullptr));
        dialogTitle->setText(QCoreApplication::translate("AddTransactionDialog", "Add Transaction", nullptr));
        titleFieldLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Title", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("AddTransactionDialog", "e.g. Lunch, Rent, Salary...", nullptr));
        amountLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Amount", nullptr));
        typeLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Type", nullptr));
        typeCombo->setItemText(0, QCoreApplication::translate("AddTransactionDialog", "expense", nullptr));
        typeCombo->setItemText(1, QCoreApplication::translate("AddTransactionDialog", "income", nullptr));

        categoryLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Category", nullptr));
        dateLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Date", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("AddTransactionDialog", "yyyy-MM-dd", nullptr));
        descFieldLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Description", nullptr));
        descEdit->setPlaceholderText(QCoreApplication::translate("AddTransactionDialog", "Optional note...", nullptr));
        notesFieldLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Notes", nullptr));
        notesEdit->setPlaceholderText(QCoreApplication::translate("AddTransactionDialog", "Add detailed notes, links, references...", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddTransactionDialog", "Cancel", nullptr));
        confirmBtn->setText(QCoreApplication::translate("AddTransactionDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTransactionDialog: public Ui_AddTransactionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONDIALOG_H
