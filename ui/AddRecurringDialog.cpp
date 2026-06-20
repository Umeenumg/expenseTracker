#include "AddRecurringDialog.h"
#include "ui_AddRecurringDialog.h"

#include <QMessageBox>

AddRecurringDialog::AddRecurringDialog(
    const QList<Category> &categories, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddRecurringDialog),
    m_categories(categories)
{
    ui->setupUi(this);

    for (const Category &c : m_categories)
        ui->categoryCombo->addItem(c.getName());

    ui->startDateEdit->setDate(QDate::currentDate());
    ui->frequencyCombo->setCurrentText("monthly");
}

AddRecurringDialog::~AddRecurringDialog()
{
    delete ui;
}

void AddRecurringDialog::on_confirmBtn_clicked()
{
    if (ui->titleEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty.");
        return;
    }
    if (ui->amountSpin->value() <= 0) {
        QMessageBox::warning(this, "Error", "Amount must be greater than 0.");
        return;
    }
    accept();
}

void AddRecurringDialog::on_cancelBtn_clicked()
{
    reject();
}

RecurringTransaction AddRecurringDialog::getRecurring() const
{
    RecurringTransaction r;
    r.setTitle(ui->titleEdit->text().trimmed());
    r.setDescription(ui->descEdit->text().trimmed());
    r.setAmount(ui->amountSpin->value());
    r.setType(ui->typeCombo->currentText());
    r.setFrequency(ui->frequencyCombo->currentText());
    r.setNextDueDate(
        ui->startDateEdit->date().toString("yyyy-MM-dd"));
    r.setIsActive(true);

    int idx = ui->categoryCombo->currentIndex();
    if (idx >= 0 && idx < m_categories.size())
        r.setCategoryId(m_categories[idx].getId());

    return r;
}
