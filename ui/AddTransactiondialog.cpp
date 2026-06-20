#include <QtWidgets>                      // ← MUST be first

#include "AddTransactionDialog.h"
#include "ui_AddTransactionDialog.h"

#include <QMessageBox>
#include <QDate>


#include "AddTransactionDialog.h"
#include "ui_AddTransactionDialog.h"


// ─────────────────────────────────────────────
// ADD MODE
// ─────────────────────────────────────────────

AddTransactionDialog::AddTransactionDialog(const QList<Category> &categories,
                                           QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddTransactionDialog),
    m_editMode(false)
{
    setup(categories);
    setWindowTitle("Add Transaction");
    ui->dialogTitle->setText("Add Transaction");
    ui->confirmBtn->setText("Add");
    ui->notesEdit->clear();
    // default date = today
    ui->dateEdit->setDate(QDate::currentDate());
}

// ─────────────────────────────────────────────
// EDIT MODE
// ─────────────────────────────────────────────

AddTransactionDialog::AddTransactionDialog(const QList<Category> &categories,
                                           const Transaction &transaction,
                                           QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddTransactionDialog),
    m_editMode(true),
    m_editId(transaction.getId())
{
    setup(categories);
    setWindowTitle("Edit Transaction");
    ui->dialogTitle->setText("Edit Transaction");
    ui->confirmBtn->setText("Save");
    ui->notesEdit->setPlainText(transaction.getNotes());
    // pre-fill fields
    ui->titleEdit->setText(transaction.getTitle());
    ui->amountSpin->setValue(transaction.getAmount());
    ui->descEdit->setText(transaction.getDescription());
    ui->dateEdit->setDate(
        QDate::fromString(transaction.getDate(), "yyyy-MM-dd"));

    // set type
    int typeIdx = ui->typeCombo->findText(transaction.getType());
    if (typeIdx >= 0) ui->typeCombo->setCurrentIndex(typeIdx);

    // set category
    for (int i = 0; i < m_categories.size(); i++) {
        if (m_categories[i].getId() == transaction.getCategoryId()) {
            ui->categoryCombo->setCurrentIndex(i);
            break;
        }
    }
}

// ─────────────────────────────────────────────
// DESTRUCTOR
// ─────────────────────────────────────────────

AddTransactionDialog::~AddTransactionDialog()
{
    delete ui;
}

// ─────────────────────────────────────────────
// SETUP
// ─────────────────────────────────────────────

void AddTransactionDialog::setup(const QList<Category> &categories)
{
    ui->setupUi(this);
    m_categories = categories;
    populateCategories();
}

void AddTransactionDialog::populateCategories()
{
    ui->categoryCombo->clear();
    for (const Category &c : m_categories) {
        ui->categoryCombo->addItem(c.getName());
    }
}

// ─────────────────────────────────────────────
// VALIDATION
// ─────────────────────────────────────────────

bool AddTransactionDialog::validate(QString &error)
{
    if (ui->titleEdit->text().trimmed().isEmpty()) {
        error = "Title cannot be empty.";
        return false;
    }
    if (ui->amountSpin->value() <= 0) {
        error = "Amount must be greater than 0.";
        return false;
    }
    if (ui->categoryCombo->count() == 0) {
        error = "Please add a category first.";
        return false;
    }
    return true;
}

// ─────────────────────────────────────────────
// CONFIRM
// ─────────────────────────────────────────────

void AddTransactionDialog::on_confirmBtn_clicked()
{
    QString error;
    if (!validate(error)) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }
    accept();
}

void AddTransactionDialog::on_cancelBtn_clicked()
{
    reject();
}

// ─────────────────────────────────────────────
// GET TRANSACTION
// ─────────────────────────────────────────────

Transaction AddTransactionDialog::getTransaction() const
{
    Transaction t;

    t.setId(m_editId); // -1 for new, real id for edit
    t.setTitle(ui->titleEdit->text().trimmed());
    t.setAmount(ui->amountSpin->value());
    t.setType(ui->typeCombo->currentText());
    t.setDescription(ui->descEdit->text().trimmed());
    t.setNotes(ui->notesEdit->toPlainText().trimmed());
    t.setDate(ui->dateEdit->date().toString("yyyy-MM-dd"));

    // category id from selected index
    int idx = ui->categoryCombo->currentIndex();
    if (idx >= 0 && idx < m_categories.size()) {
        t.setCategoryId(m_categories[idx].getId());
    }

    return t;
}
