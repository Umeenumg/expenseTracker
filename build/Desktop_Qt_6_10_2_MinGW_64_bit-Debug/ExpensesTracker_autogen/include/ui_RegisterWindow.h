/********************************************************************************
** Form generated from reading UI file 'RegisterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit;
    QPushButton *registerButton;
    QPushButton *backButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(420, 340);
        RegisterWindow->setMinimumSize(QSize(420, 340));
        RegisterWindow->setStyleSheet(QString::fromUtf8("* {\n"
"    background-color: #0f0f14;\n"
"    color: #e2e2e8;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"QDialog {\n"
"    background-color: #13131a;\n"
"}\n"
"QLabel#titleLabel {\n"
"    font-size: 22px;\n"
"    font-weight: 700;\n"
"    color: #a78bfa;\n"
"}\n"
"QLabel#subtitleLabel {\n"
"    font-size: 12px;\n"
"    color: #4b5563;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #0f0f14;\n"
"    border: 1px solid #1e1e2e;\n"
"    border-radius: 8px;\n"
"    padding: 10px 14px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"    min-height: 18px;\n"
"}\n"
"QLineEdit:focus { border-color: #7c3aed; }\n"
"QLineEdit:hover { border-color: #2e2e4e; }\n"
"QPushButton#registerButton {\n"
"    background-color: #4f46e5;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 11px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    min-height: 20px;\n"
"}\n"
"QPushButton#registerButton:hover { background-color: #4338ca; }\n"
"QPushButton#registerButton:press"
                        "ed { background-color: #3730a3; }\n"
"QPushButton#backButton {\n"
"    background-color: #1a1a28;\n"
"    border: 1px solid #2e2e4e;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #6b7280;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton#backButton:hover {\n"
"    background-color: #222235;\n"
"    color: #9ca3af;\n"
"    border-color: #3e3e5e;\n"
"}"));
        verticalLayout = new QVBoxLayout(RegisterWindow);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(RegisterWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        usernameEdit = new QLineEdit(RegisterWindow);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(RegisterWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordEdit);

        confirmPasswordEdit = new QLineEdit(RegisterWindow);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        confirmPasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(confirmPasswordEdit);

        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        backButton = new QPushButton(RegisterWindow);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Create Account", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegisterWindow", "Create New Account", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Username", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        confirmPasswordEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Confirm Password", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        backButton->setText(QCoreApplication::translate("RegisterWindow", "Back to Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
