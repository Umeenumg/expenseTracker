#include "TransactionNotesDialog.h"

TransactionNotesDialog::TransactionNotesDialog(const Transaction &t,
                                               const QString &categoryName,
                                               QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Transaction Details");
    setMinimumSize(420, 340);
    setMaximumSize(480, 420);

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(12);
    mainLayout->setContentsMargins(24, 24, 24, 24);

    // ── TITLE ─────────────────────────────
    auto *titleLabel = new QLabel(t.getTitle(), this);
    titleLabel->setStyleSheet(
        "font-size:18px;font-weight:700;color:#f1f0f8;");
    mainLayout->addWidget(titleLabel);

    // ── DIVIDER ───────────────────────────
    auto *divider = new QFrame(this);
    divider->setFrameShape(QFrame::HLine);
    divider->setStyleSheet("color:#1a1a28;");
    mainLayout->addWidget(divider);

    // ── META ROW ──────────────────────────
    auto *metaLayout = new QHBoxLayout();
    metaLayout->setSpacing(16);

    auto addMeta = [&](const QString &label, const QString &value,
                       const QString &color) {
        auto *col = new QVBoxLayout();
        auto *lbl = new QLabel(label);
        lbl->setStyleSheet("font-size:10px;color:#374151;font-weight:500;");
        auto *val = new QLabel(value);
        val->setStyleSheet(
            QString("font-size:14px;font-weight:700;color:%1;").arg(color));
        col->addWidget(lbl);
        col->addWidget(val);
        metaLayout->addLayout(col);
    };

    QString amtColor = t.getType() == "income" ? "#4ade80" : "#f87171";
    QString prefix   = t.getType() == "income" ? "+" : "-";

    addMeta("Amount",   prefix + QString::number(t.getAmount(),'f',2), amtColor);
    addMeta("Type",     t.getType(),     t.getType()=="income"?"#4ade80":"#f87171");
    addMeta("Category", categoryName,    "#a78bfa");
    addMeta("Date",     t.getDate(),     "#6b7280");

    mainLayout->addLayout(metaLayout);

    // ── DESCRIPTION ───────────────────────
    if (!t.getDescription().isEmpty()) {
        auto *descLabel = new QLabel("Description", this);
        descLabel->setStyleSheet(
            "font-size:10px;color:#374151;font-weight:500;letter-spacing:0.4px;");
        mainLayout->addWidget(descLabel);

        auto *descVal = new QLabel(t.getDescription(), this);
        descVal->setStyleSheet("font-size:13px;color:#9ca3af;");
        descVal->setWordWrap(true);
        mainLayout->addWidget(descVal);
    }

    // ── NOTES ─────────────────────────────
    auto *notesLabel = new QLabel("Notes", this);
    notesLabel->setStyleSheet(
        "font-size:10px;color:#374151;font-weight:500;letter-spacing:0.4px;");
    mainLayout->addWidget(notesLabel);

    auto *notesEdit = new QTextEdit(this);
    notesEdit->setReadOnly(true);
    notesEdit->setMaximumHeight(100);
    notesEdit->setStyleSheet(
        "background:#080810;border:1px solid #1a1a28;"
        "border-radius:8px;padding:8px;color:#9ca3af;font-size:12px;");

    if (t.getNotes().isEmpty())
        notesEdit->setPlaceholderText("No notes for this transaction.");
    else
        notesEdit->setPlainText(t.getNotes());

    mainLayout->addWidget(notesEdit);

    // ── CLOSE BUTTON ──────────────────────
    auto *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    auto *closeBtn = new QPushButton("Close", this);
    closeBtn->setFixedWidth(90);
    closeBtn->setStyleSheet(
        "background:#13131f;border:1px solid #1a1a28;"
        "border-radius:8px;padding:9px;color:#6b7280;font-size:12px;");
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    btnLayout->addWidget(closeBtn);
    mainLayout->addLayout(btnLayout);
}
