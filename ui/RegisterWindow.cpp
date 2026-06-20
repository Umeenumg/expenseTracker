#include "RegisterWindow.h"
#include "ui_RegisterWindow.h"

#include "services/UserService.h"

#include <QMessageBox>

extern QSqlDatabase g_db;

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}
QString RegisterWindow::getUsername() const
{
    return ui->usernameEdit->text().trimmed();
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

// ────────────────────────────────────────
// VALIDATION
// ────────────────────────────────────────

bool RegisterWindow::validateInputs(QString &error)
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirm  = ui->confirmPasswordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        error = "All fields are required.";
        return false;
    }

    if (username.length() < 3) {
        error = "Username must be at least 3 characters.";
        return false;
    }

    if (password.length() < 6) {
        error = "Password must be at least 6 characters.";
        return false;
    }

    if (password != confirm) {
        error = "Passwords do not match.";
        return false;
    }

    return true;
}

// ────────────────────────────────────────
// REGISTER BUTTON
// ────────────────────────────────────────

void RegisterWindow::on_registerButton_clicked()
{
    QString validationError;

    if (!validateInputs(validationError)) {
        QMessageBox::warning(this, "Invalid Input", validationError);
        return;
    }

    UserService service(g_db);
    QString error;

    bool success = service.registerUser(
        ui->usernameEdit->text().trimmed(),
        ui->passwordEdit->text(),
        error
        );

    if (success) {
        QMessageBox::information(this, "Success", "Account created! You can now log in.");
        emit accountCreated(); // notify LoginWindow if connected
        this->close();
    } else {
        QMessageBox::warning(this, "Registration Failed", error);
    }
}

// ────────────────────────────────────────
// BACK BUTTON
// ────────────────────────────────────────

void RegisterWindow::on_backButton_clicked()
{
    this->close();
}
