#include "BudgetDialog.h"

BudgetDialog::BudgetDialog(const Category &category,
                           double currentSpent,
                           QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Set Budget");
    setMinimumWidth(360);
    setMaximumWidth(400);

    auto *layout = new QVBoxLayout(this);
    layout->setSpacing(14);
    layout->setContentsMargins(24, 24, 24, 24);

    // title
    auto *title = new QLabel(
        "Budget for \"" + category.getName() + "\"", this);
    title->setStyleSheet(
        "font-size:16px;font-weight:700;color:#f1f0f8;");
    layout->addWidget(title);

    // divider
    auto *div = new QFrame(this);
    div->setFrameShape(QFrame::HLine);
    div->setStyleSheet("color:#1a1a28;");
    layout->addWidget(div);

    // current spent
    auto *spentLabel = new QLabel(
        QString("Current spending this month: %1")
            .arg(QString::number(currentSpent, 'f', 2)), this);
    spentLabel->setStyleSheet("font-size:12px;color:#f87171;");
    layout->addWidget(spentLabel);

    // budget field
    auto *budgetLabel = new QLabel("Monthly Budget Limit", this);
    budgetLabel->setStyleSheet(
        "font-size:11px;color:#4b5563;font-weight:500;");
    layout->addWidget(budgetLabel);

    m_budgetSpin = new QDoubleSpinBox(this);
    m_budgetSpin->setRange(0, 999999.99);
    m_budgetSpin->setDecimals(2);
    m_budgetSpin->setSingleStep(100);
    m_budgetSpin->setValue(category.getBudget());
    m_budgetSpin->setSpecialValueText("No limit");
    layout->addWidget(m_budgetSpin);

    auto *hint = new QLabel(
        "Set to 0 to remove the budget limit.", this);
    hint->setStyleSheet("font-size:11px;color:#374151;");
    layout->addWidget(hint);

    layout->addStretch();

    // buttons
    auto *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();

    auto *cancelBtn = new QPushButton("Cancel", this);
    cancelBtn->setFixedWidth(90);
    cancelBtn->setStyleSheet(
        "background:transparent;border:1px solid #1a1a28;"
        "border-radius:8px;padding:9px;color:#4b5563;font-size:12px;");
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    auto *saveBtn = new QPushButton("Save", this);
    saveBtn->setFixedWidth(90);
    saveBtn->setStyleSheet(
        "background:#4f46e5;border:none;border-radius:8px;"
        "padding:9px;color:white;font-size:12px;font-weight:600;");
    connect(saveBtn, &QPushButton::clicked, this, &QDialog::accept);

    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(saveBtn);
    layout->addLayout(btnLayout);
}

double BudgetDialog::getBudget() const
{
    return m_budgetSpin->value();
}
