#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include "MainWindow.h"
#include "RegisterWindow.h"
#include "services/UserService.h"
#include "core/Session.h"
#include "models/User.h"
#include "MainWindow.h"
#include "services/UserSettingsService.h"
#include "core/Currency.h"

#include <QMessageBox>

extern QSqlDatabase g_db;

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Allow pressing Enter to login
    ui->loginButton->setDefault(true);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// ────────────────────────────────────────
// HELPERS
// ────────────────────────────────────────

void LoginWindow::showError(const QString &message)
{
    ui->errorLabel->setText(message);
    ui->errorLabel->setVisible(true);
}

void LoginWindow::clearError()
{
    ui->errorLabel->setText("");
    ui->errorLabel->setVisible(false);
}

// ────────────────────────────────────────
// LOGIN BUTTON
// ────────────────────────────────────────
void LoginWindow::on_loginButton_clicked()
{
    clearError();
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        showError("Please fill in all fields.");
        return;
    }

    UserService service(g_db);
    User user;
    QString error;

    if (service.loginUser(username, password, user, error))
    {
        Session::userId   = user.getId();
        Session::username = user.getUsername();

        // ── LOAD CURRENCY ─────────────────
        UserSettingsService settings(g_db);
        settings.initSettings(user.getId());
        Session::currencyCode   = settings.getCurrencyCode(user.getId());
        Session::currencySymbol = settings.getCurrencySymbol(user.getId());

        MainWindow *w = new MainWindow(user.getId());
        w->show();
        this->close();
    }
    else
    {
        showError(error);
    }
}

// ────────────────────────────────────────
// REGISTER BUTTON → opens RegisterWindow
// ────────────────────────────────────────

void LoginWindow::on_registerButton_clicked()
{
    clearError();

    RegisterWindow *reg = new RegisterWindow(this);

    // When account is created → pre-fill username back in LoginWindow
    connect(reg, &RegisterWindow::accountCreated, this, [=]() {
        ui->usernameEdit->setText(reg->getUsername());
        ui->passwordEdit->setFocus();
        showError(""); // clear any old error
        clearError();
    });

    reg->exec(); // modal — blocks until RegisterWindow closes
    // After exec() returns, user is back on LoginWindow automatically
}

