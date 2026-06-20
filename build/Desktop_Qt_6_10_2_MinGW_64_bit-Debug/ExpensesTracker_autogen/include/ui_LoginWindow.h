/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *errorLabel;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(669, 320);
        LoginWindow->setMinimumSize(QSize(420, 320));
        LoginWindow->setStyleSheet(QString::fromUtf8("* {\n"
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
"QLabel#errorLabel {\n"
"    font-size: 12px;\n"
"    color: #f87171;\n"
"    background-color: #2a0f0f;\n"
"    border: 1px solid rgba(248,113,113,0.25);\n"
"    border-radius: 6px;\n"
"    padding: 7px 10px;\n"
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
"QPushButton#loginButton {\n"
"    background-color: #4f46e5;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding:"
                        " 11px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    min-height: 20px;\n"
"}\n"
"QPushButton#loginButton:hover { background-color: #4338ca; }\n"
"QPushButton#loginButton:pressed { background-color: #3730a3; }\n"
"QPushButton#registerButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #7c3aed;\n"
"    font-size: 12px;\n"
"    padding: 4px;\n"
"}\n"
"QPushButton#registerButton:hover { color: #a78bfa; }"));
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(LoginWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(LoginWindow);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        usernameEdit = new QLineEdit(LoginWindow);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(LoginWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordEdit);

        errorLabel = new QLabel(LoginWindow);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setVisible(false);
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(errorLabel);

        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");

        verticalLayout->addWidget(loginButton);

        registerButton = new QPushButton(LoginWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setFlat(true);

        verticalLayout->addWidget(registerButton);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "Expense Tracker", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginWindow", "Sign in to your account", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        errorLabel->setText(QString());
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "Don't have an account? Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
