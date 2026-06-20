#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    QString getUsername() const;
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

signals:
    void accountCreated(); // optional: notify LoginWindow

private slots:
    void on_registerButton_clicked();
    void on_backButton_clicked();

private:
    Ui::RegisterWindow *ui;

    bool validateInputs(QString &error);
};

#endif
