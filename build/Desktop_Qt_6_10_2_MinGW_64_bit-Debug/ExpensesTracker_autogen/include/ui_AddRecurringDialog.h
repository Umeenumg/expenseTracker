/********************************************************************************
** Form generated from reading UI file 'AddRecurringDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECURRINGDIALOG_H
#define UI_ADDRECURRINGDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddRecurringDialog
{
public:
    QVBoxLayout *mainLayout;
    QLabel *dialogTitle;
    QFrame *divider;
    QVBoxLayout *vboxLayout;
    QLabel *titleLbl;
    QLineEdit *titleEdit;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *amountLbl;
    QDoubleSpinBox *amountSpin;
    QVBoxLayout *vboxLayout2;
    QLabel *typeLbl;
    QComboBox *typeCombo;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout3;
    QLabel *catLbl;
    QComboBox *categoryCombo;
    QVBoxLayout *vboxLayout4;
    QLabel *freqLbl;
    QComboBox *frequencyCombo;
    QVBoxLayout *vboxLayout5;
    QLabel *startLbl;
    QDateEdit *startDateEdit;
    QVBoxLayout *vboxLayout6;
    QLabel *descLbl;
    QLineEdit *descEdit;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem1;
    QPushButton *cancelBtn;
    QPushButton *confirmBtn;

    void setupUi(QDialog *AddRecurringDialog)
    {
        if (AddRecurringDialog->objectName().isEmpty())
            AddRecurringDialog->setObjectName("AddRecurringDialog");
        AddRecurringDialog->setMinimumSize(QSize(420, 440));
        AddRecurringDialog->setMaximumSize(QSize(420, 440));
        mainLayout = new QVBoxLayout(AddRecurringDialog);
        mainLayout->setSpacing(14);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(24, 24, 24, 24);
        dialogTitle = new QLabel(AddRecurringDialog);
        dialogTitle->setObjectName("dialogTitle");

        mainLayout->addWidget(dialogTitle);

        divider = new QFrame(AddRecurringDialog);
        divider->setObjectName("divider");
        divider->setFrameShape(QFrame::HLine);

        mainLayout->addWidget(divider);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(5);
        vboxLayout->setObjectName("vboxLayout");
        titleLbl = new QLabel(AddRecurringDialog);
        titleLbl->setObjectName("titleLbl");

        vboxLayout->addWidget(titleLbl);

        titleEdit = new QLineEdit(AddRecurringDialog);
        titleEdit->setObjectName("titleEdit");

        vboxLayout->addWidget(titleEdit);


        mainLayout->addLayout(vboxLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(12);
        hboxLayout->setObjectName("hboxLayout");
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(5);
        vboxLayout1->setObjectName("vboxLayout1");
        amountLbl = new QLabel(AddRecurringDialog);
        amountLbl->setObjectName("amountLbl");

        vboxLayout1->addWidget(amountLbl);

        amountSpin = new QDoubleSpinBox(AddRecurringDialog);
        amountSpin->setObjectName("amountSpin");
        amountSpin->setMinimum(0.010000000000000);
        amountSpin->setMaximum(999999.989999999990687);
        amountSpin->setDecimals(2);

        vboxLayout1->addWidget(amountSpin);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(5);
        vboxLayout2->setObjectName("vboxLayout2");
        typeLbl = new QLabel(AddRecurringDialog);
        typeLbl->setObjectName("typeLbl");

        vboxLayout2->addWidget(typeLbl);

        typeCombo = new QComboBox(AddRecurringDialog);
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->setObjectName("typeCombo");

        vboxLayout2->addWidget(typeCombo);


        hboxLayout->addLayout(vboxLayout2);


        mainLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(12);
        hboxLayout1->setObjectName("hboxLayout1");
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(5);
        vboxLayout3->setObjectName("vboxLayout3");
        catLbl = new QLabel(AddRecurringDialog);
        catLbl->setObjectName("catLbl");

        vboxLayout3->addWidget(catLbl);

        categoryCombo = new QComboBox(AddRecurringDialog);
        categoryCombo->setObjectName("categoryCombo");

        vboxLayout3->addWidget(categoryCombo);


        hboxLayout1->addLayout(vboxLayout3);

        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(5);
        vboxLayout4->setObjectName("vboxLayout4");
        freqLbl = new QLabel(AddRecurringDialog);
        freqLbl->setObjectName("freqLbl");

        vboxLayout4->addWidget(freqLbl);

        frequencyCombo = new QComboBox(AddRecurringDialog);
        frequencyCombo->addItem(QString());
        frequencyCombo->addItem(QString());
        frequencyCombo->addItem(QString());
        frequencyCombo->addItem(QString());
        frequencyCombo->setObjectName("frequencyCombo");

        vboxLayout4->addWidget(frequencyCombo);


        hboxLayout1->addLayout(vboxLayout4);


        mainLayout->addLayout(hboxLayout1);

        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setSpacing(5);
        vboxLayout5->setObjectName("vboxLayout5");
        startLbl = new QLabel(AddRecurringDialog);
        startLbl->setObjectName("startLbl");

        vboxLayout5->addWidget(startLbl);

        startDateEdit = new QDateEdit(AddRecurringDialog);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setCalendarPopup(true);

        vboxLayout5->addWidget(startDateEdit);


        mainLayout->addLayout(vboxLayout5);

        vboxLayout6 = new QVBoxLayout();
        vboxLayout6->setSpacing(5);
        vboxLayout6->setObjectName("vboxLayout6");
        descLbl = new QLabel(AddRecurringDialog);
        descLbl->setObjectName("descLbl");

        vboxLayout6->addWidget(descLbl);

        descEdit = new QLineEdit(AddRecurringDialog);
        descEdit->setObjectName("descEdit");

        vboxLayout6->addWidget(descEdit);


        mainLayout->addLayout(vboxLayout6);

        spacerItem = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(spacerItem);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(10);
        hboxLayout2->setObjectName("hboxLayout2");
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout2->addItem(spacerItem1);

        cancelBtn = new QPushButton(AddRecurringDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setMinimumWidth(90);

        hboxLayout2->addWidget(cancelBtn);

        confirmBtn = new QPushButton(AddRecurringDialog);
        confirmBtn->setObjectName("confirmBtn");
        confirmBtn->setMinimumWidth(90);

        hboxLayout2->addWidget(confirmBtn);


        mainLayout->addLayout(hboxLayout2);


        retranslateUi(AddRecurringDialog);

        QMetaObject::connectSlotsByName(AddRecurringDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRecurringDialog)
    {
        AddRecurringDialog->setWindowTitle(QCoreApplication::translate("AddRecurringDialog", "Add Recurring Transaction", nullptr));
        dialogTitle->setText(QCoreApplication::translate("AddRecurringDialog", "Add Recurring Transaction", nullptr));
        titleLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Title", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("AddRecurringDialog", "e.g. Rent, Netflix, Salary...", nullptr));
        amountLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Amount", nullptr));
        typeLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Type", nullptr));
        typeCombo->setItemText(0, QCoreApplication::translate("AddRecurringDialog", "expense", nullptr));
        typeCombo->setItemText(1, QCoreApplication::translate("AddRecurringDialog", "income", nullptr));

        catLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Category", nullptr));
        freqLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Frequency", nullptr));
        frequencyCombo->setItemText(0, QCoreApplication::translate("AddRecurringDialog", "daily", nullptr));
        frequencyCombo->setItemText(1, QCoreApplication::translate("AddRecurringDialog", "weekly", nullptr));
        frequencyCombo->setItemText(2, QCoreApplication::translate("AddRecurringDialog", "monthly", nullptr));
        frequencyCombo->setItemText(3, QCoreApplication::translate("AddRecurringDialog", "yearly", nullptr));

        startLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Start Date", nullptr));
        startDateEdit->setDisplayFormat(QCoreApplication::translate("AddRecurringDialog", "yyyy-MM-dd", nullptr));
        descLbl->setText(QCoreApplication::translate("AddRecurringDialog", "Description", nullptr));
        descEdit->setPlaceholderText(QCoreApplication::translate("AddRecurringDialog", "Optional...", nullptr));
        cancelBtn->setText(QCoreApplication::translate("AddRecurringDialog", "Cancel", nullptr));
        confirmBtn->setText(QCoreApplication::translate("AddRecurringDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRecurringDialog: public Ui_AddRecurringDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECURRINGDIALOG_H
