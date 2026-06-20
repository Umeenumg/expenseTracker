#include <QtWidgets>        // ← includes ALL Qt widgets at once
#include <QComboBox>// ← MUST be first, before ui_MainWindow.h
#include <QLineEdit>
#include <QTableWidget>
#include <QStackedWidget>
#include <QFrame>
#include <QMessageBox>
#include "core/Session.h"
#include "ui/LoginWindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QButtonGroup>
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QColor>
#include "ui/AddTransactionDialog.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"  // ← generated file comes AFTER widget includes

extern QSqlDatabase g_db;
extern DatabaseManager *g_dbManager;    // ← add this
// ─────────────────────────────────────────────
// CONSTRUCTOR
// ─────────────────────────────────────────────
MainWindow::MainWindow(int userId, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_userId(userId),
    m_transactionService(g_db),
    m_categoryService(g_db),
    m_userService(g_db),
    m_recurringService(g_db),
    m_settingsService(g_db)
{
    ui->setupUi(this);


    // user label
    ui->userLabel->setText("👤 " + Session::username);
    ui->topUserLabel->setText(Session::username);

    // ── SIDEBAR BUTTON GROUP ──────────────────
    QButtonGroup *group = new QButtonGroup(this);
    group->setExclusive(true);
    group->addButton(ui->dashboardBtn,    0);
    group->addButton(ui->transactionsBtn, 1);
    group->addButton(ui->categoriesBtn,   2);
    group->addButton(ui->analyticsBtn, 3);
    group->addButton(ui->profileBtn, 4);
    group->addButton(ui->recurringBtn, 5);

    connect(group, &QButtonGroup::idClicked, this, [=](int id) {
        ui->stackedWidget->setCurrentIndex(id);
        updateSidebarStyle(id);
        animatePage(ui->stackedWidget->currentWidget());

        if (id == 0) { ui->pageTitle->setText("Dashboard");    loadDashboard(); }
        if (id == 1) { ui->pageTitle->setText("Transactions"); loadTransactions(); }
        if (id == 2) { ui->pageTitle->setText("Categories");   loadCategories(); updateStats(); }
        if (id == 3) { ui->pageTitle->setText("Analytics");    loadAnalytics(); }
        if (id == 4) { ui->pageTitle->setText("Profile");  loadProfile(); }
        if (id == 5) {ui->pageTitle->setText("Recurring"); loadRecurring(); }

    });

    // ── RECENT TABLE (dashboard) ──────────────
    ui->recentTable->setColumnCount(5);
    ui->recentTable->setHorizontalHeaderLabels({"Date","Category","Type","Description","Amount"});
    ui->recentTable->horizontalHeader()->setStretchLastSection(true);
    ui->recentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->recentTable->verticalHeader()->setVisible(false);
    ui->recentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->recentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ── TRANSACTIONS TABLE ────────────────────
    ui->tableTransactions->setColumnCount(6);
    ui->tableTransactions->setHorizontalHeaderLabels({"Date","Category","Type","Description","Amount","ID"});
    ui->tableTransactions->setColumnHidden(5, true); // hidden ID column
    ui->tableTransactions->horizontalHeader()->setStretchLastSection(true);
    ui->tableTransactions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableTransactions->verticalHeader()->setVisible(false);
    ui->tableTransactions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableTransactions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableTransactions->setShowGrid(false);

    // ── CATEGORIES TABLE ──────────────────────
    ui->categoriesTable->setColumnCount(6);
    ui->categoriesTable->setHorizontalHeaderLabels( {"Name", "Type", "Used", "Spent", "Budget", "Status"});
    ui->categoriesTable->horizontalHeader()->setStretchLastSection(true);
    ui->categoriesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->categoriesTable->verticalHeader()->setVisible(false);
    ui->categoriesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->categoriesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->categoriesTable->setShowGrid(false);


    // ── RECURING  TABLE ──────────────────────
    ui->recurringTable->setColumnCount(7);
    ui->recurringTable->setHorizontalHeaderLabels(
        {"Title", "Type", "Amount", "Category",
         "Frequency", "Next Due", "Status"});
    ui->recurringTable->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);
    ui->recurringTable->verticalHeader()->setVisible(false);
    ui->recurringTable->setSelectionBehavior(
        QAbstractItemView::SelectRows);
    ui->recurringTable->setEditTriggers(
        QAbstractItemView::NoEditTriggers);
    ui->recurringTable->setShowGrid(false);

    // ── FILTER SIGNALS ────────────────────────
    connect(ui->searchInput, &QLineEdit::textChanged,
            this, &MainWindow::applyFilters);
    connect(ui->comboType, &QComboBox::currentTextChanged,
            this, &MainWindow::applyFilters);

    // ── INIT ─────────────────────────────────
    ui->dashboardBtn->click();

    // ── ANALYTICS CHARTS ─────────────────
    m_barChart  = new BarChartWidget(ui->barChartFrame);
    m_pieChart  = new PieChartWidget(ui->pieChartFrame);
    m_lineChart = new LineChartWidget(ui->lineChartFrame);

    // make them fill their parent frames
    auto fillParent = [](QWidget *w) {
        QVBoxLayout *l = new QVBoxLayout(w->parentWidget());
        l->setContentsMargins(0,0,0,0);
        l->addWidget(w);
    };
    fillParent(m_barChart);
    fillParent(m_pieChart);
    fillParent(m_lineChart);





    // ── PROCESS DUE RECURRING ────────────
    int processed = m_recurringService
                        .processDueRecurring(m_userId, g_db);
    if (processed > 0) {
        loadDashboard();
        loadTransactions();
        showToast(QString("%1 recurring transaction(s) processed.")
                      .arg(processed));
    }

    m_currencyCode = Session::currencyCode;
}

// ─────────────────────────────────────────────
// DESTRUCTOR
// ─────────────────────────────────────────────

MainWindow::~MainWindow()
{
    delete ui;
}

// ─────────────────────────────────────────────
// HELPERS
// ─────────────────────────────────────────────

void MainWindow::animatePage(QWidget *page)
{
    auto *effect = new QGraphicsOpacityEffect(page);
    page->setGraphicsEffect(effect);
    auto *anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(220);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::updateSidebarStyle(int activeId)
{
    QList<QPushButton*> btns = {
        ui->dashboardBtn,
        ui->transactionsBtn,
        ui->categoriesBtn,
        ui->analyticsBtn,
        ui->profileBtn,
        ui->recurringBtn
    };
    for (int i = 0; i < btns.size(); i++) {
        btns[i]->setProperty("active", i == activeId);
        btns[i]->style()->unpolish(btns[i]);
        btns[i]->style()->polish(btns[i]);
    }
}

void MainWindow::showToast(const QString &text)
{
    QLabel *toast = new QLabel(text, this);
    toast->setStyleSheet(
        "background:#1e1e2e;color:white;"
        "padding:8px 18px;border-radius:8px;");
    toast->adjustSize();
    toast->move(width() / 2 - toast->width() / 2, 60);
    toast->show();
    QTimer::singleShot(2200, toast, &QLabel::deleteLater);
}

// ─────────────────────────────────────────────
// DASHBOARD
// ─────────────────────────────────────────────

void MainWindow::loadDashboard()
{
    double income  = m_transactionService.getTotalIncome(m_userId);
    double expense = m_transactionService.getTotalExpense(m_userId);
    double balance = m_transactionService.getBalance(m_userId);
    int    count   = m_transactionService.getTransactionsCount(m_userId);

    // ── CARDS ─────────────────────────────
    ui->incomeValue->setText(
        formatAmount(m_transactionService.getTotalIncome(m_userId)));
    ui->expenseValue->setText(
        formatAmount(m_transactionService.getTotalExpense(m_userId)));
    ui->balanceValue->setText(
        formatAmount(m_transactionService.getBalance(m_userId)));

    // ── RECENT TABLE ──────────────────────
    auto list = m_transactionService.getRecentTransactions(m_userId, 5);
    ui->recentTable->setRowCount(0);

    for (int i = 0; i < list.size(); i++) {
        const Transaction &t = list[i];
        ui->recentTable->insertRow(i);

        // col 0 — date
        ui->recentTable->setItem(i, 0,
                                 new QTableWidgetItem(t.getDate()));

        // col 1 — category
        ui->recentTable->setItem(i, 1,
                                 new QTableWidgetItem(
                                     m_categoryService.getCategoryNameById(
                                         t.getCategoryId(), m_userId)));

        // col 2 — type badge (colored like Transactions page)
        // create centered badge that doesn't stretch full width
        QWidget *badgeContainer = new QWidget();
        QHBoxLayout *badgeLayout = new QHBoxLayout(badgeContainer);
        badgeLayout->setContentsMargins(4, 2, 4, 2);
        badgeLayout->setAlignment(Qt::AlignCenter);

        QLabel *badge = new QLabel(t.getType());
        badge->setAlignment(Qt::AlignCenter);
        badge->setFixedHeight(22);
        badge->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        badge->adjustSize();

        if (t.getType() == "income") {
            badge->setStyleSheet(
                "background:#064e3b;color:#4ade80;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        } else {
            badge->setStyleSheet(
                "background:#3f1d1d;color:#f87171;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        }

        badgeLayout->addWidget(badge);
        badgeContainer->setStyleSheet("background:transparent;");
        // OR for recentTable:
        ui->recentTable->setCellWidget(i, 2, badgeContainer);

        // col 3 — description
        ui->recentTable->setItem(i, 3,
                                 new QTableWidgetItem(t.getDescription()));

        // col 4 — amount (green/red colored)
        QString prefix = t.getType() == "income" ? "+" : "-";
        QTableWidgetItem *amt = new QTableWidgetItem( prefix + formatAmount(t.getAmount()));
        amt->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        amt->setForeground(t.getType() == "income"
                               ? QColor("#4ade80") : QColor("#f87171"));
        ui->recentTable->setItem(i, 4, amt);

        ui->recentTable->setRowHeight(i, 40);
    }
}

// ─────────────────────────────────────────────
// TRANSACTIONS
// ─────────────────────────────────────────────

void MainWindow::loadTransactions()
{
    loadTransactions(m_transactionService.getAllTransactions(m_userId));
}

void MainWindow::loadTransactions(const QList<Transaction> &list)
{
    ui->tableTransactions->setRowCount(0);

    double income = 0, expense = 0;

    for (int i = 0; i < list.size(); i++) {
        const Transaction &t = list[i];
        ui->tableTransactions->insertRow(i);

        if (t.getType() == "income")  income  += t.getAmount();
        if (t.getType() == "expense") expense += t.getAmount();

        // col 0 — date
        QTableWidgetItem *dateItem = new QTableWidgetItem(t.getDate());
        ui->tableTransactions->setItem(i, 0, dateItem);

        // col 1 — category
        ui->tableTransactions->setItem(i, 1,
                                       new QTableWidgetItem(
                                           m_categoryService.getCategoryNameById(t.getCategoryId(), m_userId)));

        // create centered badge that doesn't stretch full width
        QWidget *badgeContainer = new QWidget();
        QHBoxLayout *badgeLayout = new QHBoxLayout(badgeContainer);
        badgeLayout->setContentsMargins(4, 2, 4, 2);
        badgeLayout->setAlignment(Qt::AlignCenter);

        QLabel *badge = new QLabel(t.getType());
        badge->setAlignment(Qt::AlignCenter);
        badge->setFixedHeight(22);
        badge->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        badge->adjustSize();

        if (t.getType() == "income") {
            badge->setStyleSheet(
                "background:#064e3b;color:#4ade80;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        } else {
            badge->setStyleSheet(
                "background:#3f1d1d;color:#f87171;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        }

        badgeLayout->addWidget(badge);
        badgeContainer->setStyleSheet("background:transparent;");

        // use setCellWidget with container
        ui->tableTransactions->setCellWidget(i, 2, badgeContainer);

        // col 3 — description
        ui->tableTransactions->setItem(i, 3,
                                       new QTableWidgetItem(t.getDescription()));

        // col 4 — amount
        // col 4 — amount
        QTableWidgetItem *amt = new QTableWidgetItem((t.getType() == "income" ? "+" : "-") +formatAmount(t.getAmount()));
        amt->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        amt->setForeground(t.getType() == "income"
                               ? QColor("#4ade80") : QColor("#f87171"));
        ui->tableTransactions->setItem(i, 4, amt);

        // col 5 — hidden ID
        ui->tableTransactions->setItem(i, 5,
                                       new QTableWidgetItem(QString::number(t.getId())));

        ui->tableTransactions->setRowHeight(i, 40);
    }

    ui->lblIncome->setText(formatAmount(income));
    ui->lblExpense->setText(formatAmount(expense));
    ui->lblBalance->setText(formatAmount(income - expense));
    ui->lblCount->setText(QString::number(list.size()) + " transactions");
}

void MainWindow::applyFilters()
{
    auto list    = m_transactionService.getAllTransactions(m_userId);
    QString type = ui->comboType->currentText();
    QString search = ui->searchInput->text().trimmed();

    QList<Transaction> filtered;
    for (const Transaction &t : list) {
        if (type != "All" && t.getType() != type) continue;
        if (!search.isEmpty() &&
            !t.getDescription().contains(search, Qt::CaseInsensitive) &&
            !t.getTitle().contains(search, Qt::CaseInsensitive)) continue;
        filtered.append(t);
    }

    loadTransactions(filtered);
}

void MainWindow::on_btnReset_clicked()
{
    ui->comboType->setCurrentIndex(0);
    ui->searchInput->clear();
    loadTransactions();
}

void MainWindow::on_btnEdit_clicked()
{
    int row = ui->tableTransactions->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Edit", "Select a transaction first.");
        return;
    }

    int id = ui->tableTransactions->item(row, 5)->text().toInt();
    Transaction target = m_transactionService.getTransactionById(id, m_userId);
       m_categories = m_categoryService.getAllCategories(m_userId);
    AddTransactionDialog dlg(m_categories, target, this);
    if (dlg.exec() != QDialog::Accepted) return;

    Transaction updated = dlg.getTransaction();
    m_transactionService.updateTransaction(updated, m_userId);

    loadDashboard();
    loadTransactions();
    updateStats();
    showToast("Transaction updated.");
    checkBudgetAlerts();
}
void MainWindow::on_addBtn_clicked()
{
    m_categories = m_categoryService.getAllCategories(m_userId);

    AddTransactionDialog dlg(m_categories, this);
    if (dlg.exec() != QDialog::Accepted) return;

    Transaction t = dlg.getTransaction();
    m_transactionService.addTransaction(t, m_userId);

    loadDashboard();
    loadTransactions();
    loadCategories();
    updateStats();
    showToast("Transaction added.");

    checkBudgetAlerts();
}

void MainWindow::on_btnDelete_clicked()
{
    int row = ui->tableTransactions->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Delete", "Select a transaction first.");
        return;
    }

    auto reply = QMessageBox::question(this, "Delete",
                                       "Delete this transaction?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) return;

    int id = ui->tableTransactions->item(row, 5)->text().toInt();
    m_transactionService.deleteTransaction(id, m_userId);

    loadDashboard();
    loadTransactions();
    loadCategories();
    updateStats();
    showToast("Transaction deleted.");
    checkBudgetAlerts();
}

// ─────────────────────────────────────────────
// CATEGORIES
// ─────────────────────────────────────────────

void MainWindow::loadCategories()
{
    m_categories = m_categoryService.getAllCategories(m_userId);
    ui->categoriesTable->setRowCount(0);

    QMap<int, int>    counts = m_transactionService.getCategoryCounts(m_userId);
    QMap<int, double> totals = m_transactionService.getCategoryTotals(m_userId);

    for (int i = 0; i < m_categories.size(); i++) {
        const Category &c = m_categories[i];
        int    used   = counts.value(c.getId(), 0);
        double spent  = totals.value(c.getId(), 0.0);
        double budget = c.getBudget();

        ui->categoriesTable->insertRow(i);
        ui->categoriesTable->setItem(i, 0,
                                     new QTableWidgetItem(c.getName()));
        ui->categoriesTable->setItem(i, 1,
                                     new QTableWidgetItem(c.getType()));
        ui->categoriesTable->setItem(i, 2,
                                     new QTableWidgetItem(QString::number(used)));
        ui->categoriesTable->setItem(i, 3,
                                     new QTableWidgetItem(QString::number(spent, 'f', 2)));

        // budget column
        if (budget > 0) {
            ui->categoriesTable->setItem(i, 4,
                                         new QTableWidgetItem(QString::number(budget, 'f', 2)));
        } else {
            auto *noBudget = new QTableWidgetItem("No limit");
            noBudget->setForeground(QColor("#6b7280"));
            ui->categoriesTable->setItem(i, 4, noBudget);
        }

        // status with budget warning
        QString status;
        QColor  statusColor;

        if (used == 0) {
            status      = "Unused";
            statusColor = QColor("#6b7280");
        } else if (budget > 0 && spent >= budget) {
            status      = "⚠ Over Budget";
            statusColor = QColor("#f87171");
        } else if (budget > 0 && spent >= budget * 0.8) {
            status      = "⚡ Near Limit";
            statusColor = QColor("#fbbf24");
        } else {
            status      = "Active";
            statusColor = QColor("#4ade80");
        }

        auto *statusItem = new QTableWidgetItem(status);
        statusItem->setForeground(statusColor);
        ui->categoriesTable->setItem(i, 5, statusItem);

        ui->categoriesTable->setRowHeight(i, 44);
    }
}

void MainWindow::updateStats()
{
    QMap<int, int> counts = m_transactionService.getCategoryCounts(m_userId);

    int total    = m_categories.size();
    int unused   = 0;
    int mostUsed = 0;

    for (const Category &c : m_categories) {
        int n = counts.value(c.getId(), 0);
        if (n == 0) unused++;
        if (n > mostUsed) mostUsed = n;
    }

    ui->totalCardValue->setText(QString::number(total));
    ui->mostUsedCardValue->setText(QString::number(mostUsed));
    ui->unusedCardValue->setText(QString::number(unused));
}

void MainWindow::loadAnalytics()
{
    QString currentMonth = QDate::currentDate().toString("yyyy-MM");

    // ── BAR CHART ────────────────────────
    auto allT = m_transactionService.getAllTransactions(m_userId);

    double income = 0, expense = 0;
    QMap<QString, double> categoryTotals;
    QMap<int, double>     dailyExpenses;

    for (const Transaction &t : allT) {
        if (!t.getDate().startsWith(currentMonth)) continue;

        if (t.getType() == "income")  income  += t.getAmount();
        if (t.getType() == "expense") expense += t.getAmount();

        // category totals (expenses only)
        if (t.getType() == "expense") {
            QString catName = m_categoryService
                                  .getCategoryNameById(t.getCategoryId(), m_userId);
            categoryTotals[catName] += t.getAmount();
        }

        // daily (expenses only)
        if (t.getType() == "expense") {
            int day = QDate::fromString(t.getDate(), "yyyy-MM-dd").day();
            dailyExpenses[day] += t.getAmount();
        }
    }

    m_barChart->setData(income, expense);
    m_pieChart->setData(categoryTotals);
    m_lineChart->setData(dailyExpenses);
}

void MainWindow::on_addCategoryBtn_clicked()
{
    QString name = ui->categoryNameInput->text().trimmed();
    QString type = ui->categoryTypeCombo->currentText();

    if (name.isEmpty()) {
        showToast("Category name cannot be empty.");
        return;
    }

    if (m_categoryService.categoryExists(m_userId, name)) {
        showToast("Category already exists.");
        return;
    }

    m_categoryService.addCategory(m_userId, name, type);
    ui->categoryNameInput->clear();

    loadCategories();
    updateStats();
    showToast("Category \"" + name + "\" added.");
}

void MainWindow::on_deleteCategoryBtn_clicked()
{
    int row = ui->categoriesTable->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Delete", "Select a category first.");
        return;
    }

    int categoryId = m_categories[row].getId();

    if (m_categoryService.categoryHasTransactions(m_userId, categoryId)) {
        QMessageBox::warning(this, "Cannot Delete",
                             "This category has transactions. Delete them first.");
        return;
    }

    auto reply = QMessageBox::question(this, "Delete",
                                       "Delete this category?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) return;

    m_categoryService.deleteCategory(categoryId, m_userId);

    loadCategories();
    updateStats();
    showToast("Category deleted.");
}


void MainWindow::loadProfile()
{
    ui->profileUsernameEdit->setText(Session::username);
    ui->profileCurrentPassEdit->clear();
    ui->profileNewPassEdit->clear();
    ui->profileConfirmPassEdit->clear();
    ui->profileErrorLabel->setVisible(false);

    // ── POPULATE CURRENCY COMBO ───────────
    ui->currencyCombo->clear();
    auto currencies = CurrencyManager::allCurrencies();
    int  currentIdx = 0;

    for (int i = 0; i < currencies.size(); i++) {
        const Currency &c = currencies[i];
        ui->currencyCombo->addItem(
            c.symbol + "  " + c.code + " — " + c.name);
        if (c.code == m_currencyCode)
            currentIdx = i;
    }

    ui->currencyCombo->setCurrentIndex(currentIdx);
}
void MainWindow::on_profileBtn_clicked() {}

void MainWindow::on_profileSaveBtn_clicked()
{
    QString currentPass = ui->profileCurrentPassEdit->text();
    QString newPass     = ui->profileNewPassEdit->text();
    QString confirmPass = ui->profileConfirmPassEdit->text();

    // validation
    if (currentPass.isEmpty() || newPass.isEmpty() || confirmPass.isEmpty()) {
        ui->profileErrorLabel->setText("All password fields are required.");
        ui->profileErrorLabel->setVisible(true);
        return;
    }

    if (newPass != confirmPass) {
        ui->profileErrorLabel->setText("New passwords do not match.");
        ui->profileErrorLabel->setVisible(true);
        return;
    }

    QString error;
    bool ok = m_userService.changePassword(
        m_userId, currentPass, newPass, error);

    if (ok) {
        ui->profileErrorLabel->setVisible(false);
        ui->profileCurrentPassEdit->clear();
        ui->profileNewPassEdit->clear();
        ui->profileConfirmPassEdit->clear();
        showToast("Password changed successfully.");
    } else {
        ui->profileErrorLabel->setText(error);
        ui->profileErrorLabel->setVisible(true);
    }
}


void MainWindow::on_btnExport_clicked()
{
    QString path = QFileDialog::getSaveFileName(
        this,
        "Export Transactions",
        QDir::homePath() + "/transactions.csv",
        "CSV Files (*.csv)"
        );

    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);

    // header
    out << "Date,Title,Description,Category,Type,Amount\n";

    auto list = m_transactionService.getAllTransactions(m_userId);
    for (const Transaction &t : list) {
        QString catName = m_categoryService
                              .getCategoryNameById(t.getCategoryId(), m_userId);

        out << t.getDate()        << ","
            << t.getTitle()       << ","
            << t.getDescription() << ","
            << catName            << ","
            << t.getType()        << ","
            << QString::number(t.getAmount(), 'f', 2) << "\n";
    }

    file.close();

    // ask to open file
    auto reply = QMessageBox::question(this, "Export Done",
                                       "File saved successfully. Open it now?",
                                       QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));

    showToast("Exported " + QString::number(list.size()) + " transactions.");
}
// ─────────────────────────────────────────────
// BACKUP
// ─────────────────────────────────────────────

void MainWindow::on_backupBtn_clicked()
{
    QString defaultName = QString("ExpensesTracker_backup_%1.db")
    .arg(QDate::currentDate().toString("yyyy-MM-dd"));

    QString path = QFileDialog::getSaveFileName(
        this,
        "Export Database Backup",
        QDir::homePath() + "/" + defaultName,
        "SQLite Database (*.db)"
        );

    if (path.isEmpty()) return;

    QString error;
    if (m_dbManager->backupDatabase(path, error)) {
        showToast("Backup saved successfully.");
        QMessageBox::information(this, "Backup Complete",
                                 "Database backed up to:\n" + path);
    } else {
        QMessageBox::warning(this, "Backup Failed", error);
    }
}

// ─────────────────────────────────────────────
// RESTORE
// ─────────────────────────────────────────────

void MainWindow::on_restoreBtn_clicked()
{
    auto confirm = QMessageBox::warning(this,
                                        "Restore Database",
                                        "This will REPLACE your current database with the backup.\n"
                                        "All unsaved changes will be lost.\n\n"
                                        "Are you sure you want to continue?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (confirm != QMessageBox::Yes) return;

    QString path = QFileDialog::getOpenFileName(
        this,
        "Select Backup File",
        QDir::homePath(),
        "SQLite Database (*.db)"
        );

    if (path.isEmpty()) return;

    QString error;
    if (m_dbManager->restoreDatabase(path, error)) {

        // update global db reference
        g_db = m_dbManager->getDatabase();
        m_transactionService = TransactionService(g_db);
        m_categoryService    = CategoryService(g_db);
        m_userService        = UserService(g_db);

        // reload all data
        loadDashboard();
        loadTransactions();
        loadCategories();
        updateStats();

        showToast("Database restored successfully.");
        QMessageBox::information(this, "Restore Complete",
                                 "Database restored from backup.");
    } else {
        QMessageBox::warning(this, "Restore Failed", error);
    }
}

// ─────────────────────────────────────────────
//NOTES
// ─────────────────────────────────────────────

void MainWindow::on_tableTransactions_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column)

    if (row < 0) return;

    int id = ui->tableTransactions->item(row, 5)->text().toInt();
    Transaction t = m_transactionService.getTransactionById(id, m_userId);
    QString catName = m_categoryService
                          .getCategoryNameById(t.getCategoryId(), m_userId);

    TransactionNotesDialog dlg(t, catName, this);
    dlg.exec();
}

// ─────────────────────────────────────────────
//BUDGET
// ─────────────────────────────────────────────

void MainWindow::on_setBudgetBtn_clicked()
{
    int row = ui->categoriesTable->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Set Budget",
                                 "Please select a category first.");
        return;
    }

    const Category &cat = m_categories[row];

    // get current month spending for this category
    QMap<int, double> totals =
        m_transactionService.getCategoryTotals(m_userId);
    double spent = totals.value(cat.getId(), 0.0);

    BudgetDialog dlg(cat, spent, this);
    if (dlg.exec() != QDialog::Accepted) return;

    double newBudget = dlg.getBudget();
    m_categoryService.setBudget(cat.getId(), m_userId, newBudget);

    loadCategories();
    updateStats();

    if (newBudget > 0)
        showToast("Budget set: " + QString::number(newBudget, 'f', 2));
    else
        showToast("Budget limit removed.");
}

void MainWindow::checkBudgetAlerts()
{
    QString currentMonth = QDate::currentDate().toString("yyyy-MM");

    auto allT = m_transactionService.getAllTransactions(m_userId);
    QMap<int, double> monthlySpent;

    for (const Transaction &t : allT) {
        if (!t.getDate().startsWith(currentMonth)) continue;
        if (t.getType() == "expense")
            monthlySpent[t.getCategoryId()] += t.getAmount();
    }

    for (const Category &c : m_categories) {
        if (c.getBudget() <= 0) continue;

        double spent  = monthlySpent.value(c.getId(), 0.0);
        double budget = c.getBudget();

        if (spent >= budget) {
            showToast("⚠ Over budget: " + c.getName()
                                                     + " (" + QString::number(spent,'f',0)
                                                     + " / " + QString::number(budget,'f',0) + ")");
        } else if (spent >= budget * 0.8) {
            showToast("⚡ Near limit: " + c.getName()
                                                     + " (" + QString::number((spent/budget)*100,'f',0)
                                                     + "% used)");
        }
    }
}

///////////////////// Recurring page slots
void MainWindow::on_recurringBtn_clicked() {}

void MainWindow::loadRecurring()
{
    m_recurringList = m_recurringService.getAllRecurring(m_userId);
    ui->recurringTable->setRowCount(0);

    QString today = QDate::currentDate().toString("yyyy-MM-dd");

    for (int i = 0; i < m_recurringList.size(); i++) {
        const RecurringTransaction &r = m_recurringList[i];

        ui->recurringTable->insertRow(i);
        ui->recurringTable->setItem(i, 0,
                                    new QTableWidgetItem(r.getTitle()));

        // type badge
        QWidget *container = new QWidget();
        QHBoxLayout *lay = new QHBoxLayout(container);
        lay->setContentsMargins(4,2,4,2);
        lay->setAlignment(Qt::AlignCenter);
        QLabel *badge = new QLabel(r.getType());
        badge->setFixedHeight(22);
        badge->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        badge->adjustSize();
        if (r.getType() == "income")
            badge->setStyleSheet(
                "background:#064e3b;color:#4ade80;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        else
            badge->setStyleSheet(
                "background:#3f1d1d;color:#f87171;"
                "padding:2px 12px;border-radius:10px;"
                "font-size:11px;font-weight:600;");
        lay->addWidget(badge);
        container->setStyleSheet("background:transparent;");
        ui->recurringTable->setCellWidget(i, 1, container);

        // amount
        QString prefix = r.getType() == "income" ? "+" : "-";
        QTableWidgetItem *amt = new QTableWidgetItem(
            prefix + QString::number(r.getAmount(), 'f', 2));
        amt->setForeground(r.getType() == "income"
                               ? QColor("#4ade80") : QColor("#f87171"));
        ui->recurringTable->setItem(i, 2, amt);

        ui->recurringTable->setItem(i, 3,
                                    new QTableWidgetItem(
                                        m_categoryService.getCategoryNameById(
                                            r.getCategoryId(), m_userId)));

        ui->recurringTable->setItem(i, 4,
                                    new QTableWidgetItem(r.getFrequencyLabel()));

        // next due — highlight overdue
        QTableWidgetItem *dueItem =
            new QTableWidgetItem(r.getNextDueDate());
        if (r.isActive() && r.getNextDueDate() <= today)
            dueItem->setForeground(QColor("#f87171"));
        else
            dueItem->setForeground(QColor("#6b7280"));
        ui->recurringTable->setItem(i, 5, dueItem);

        // status
        QString statusText  = r.isActive() ? "Active" : "Paused";
        QColor  statusColor = r.isActive()
                                 ? QColor("#4ade80") : QColor("#4b5563");
        QTableWidgetItem *status = new QTableWidgetItem(statusText);
        status->setForeground(statusColor);
        ui->recurringTable->setItem(i, 6, status);

        ui->recurringTable->setRowHeight(i, 42);
    }
}

void MainWindow::on_addRecurringBtn_clicked()
{
    AddRecurringDialog dlg(m_categories, this);
    if (dlg.exec() != QDialog::Accepted) return;

    RecurringTransaction r = dlg.getRecurring();
    r.setUserId(m_userId);
    m_recurringService.addRecurring(r);

    loadRecurring();
    showToast("Recurring transaction added.");
}

void MainWindow::on_deleteRecurringBtn_clicked()
{
    int row = ui->recurringTable->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Delete",
                                 "Select a recurring transaction first.");
        return;
    }

    auto reply = QMessageBox::question(this, "Delete",
                                       "Delete this recurring transaction?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;

    m_recurringService.deleteRecurring(
        m_recurringList[row].getId(), m_userId);

    loadRecurring();
    showToast("Recurring transaction deleted.");
}

void MainWindow::on_toggleRecurringBtn_clicked()
{
    int row = ui->recurringTable->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Toggle",
                                 "Select a recurring transaction first.");
        return;
    }

    const RecurringTransaction &r = m_recurringList[row];
    bool newState = !r.isActive();

    m_recurringService.toggleActive(
        r.getId(), m_userId, newState);

    loadRecurring();
    showToast(newState ? "Resumed." : "Paused.");
}
    // ─────────────────────────────────────────────
    //  format helper
    // ─────────────────────────────────────────────

    QString MainWindow::formatAmount(double amount) const
    {
        return CurrencyManager::format(amount, m_currencyCode);
    }

    // ─────────────────────────────────────────────
    // save format currency
    // ─────────────────────────────────────────────

    void MainWindow::on_saveCurrencyBtn_clicked()
    {
        int idx = ui->currencyCombo->currentIndex();
        auto currencies = CurrencyManager::allCurrencies();

        if (idx < 0 || idx >= currencies.size()) return;

        const Currency &selected = currencies[idx];

        m_settingsService.setCurrency(
            m_userId, selected.code, selected.symbol);

        // update session + local cache
        Session::currencyCode   = selected.code;
        Session::currencySymbol = selected.symbol;
        m_currencyCode          = selected.code;

        // reload all monetary displays
        loadDashboard();
        loadTransactions();

        showToast("Currency changed to " + selected.code
                  + " (" + selected.symbol + ")");
    }

// ─────────────────────────────────────────────
// LOGOUT
// ─────────────────────────────────────────────

void MainWindow::on_logoutBtn_clicked()
{
    Session::clear();

    LoginWindow *login = new LoginWindow();
    login->show();

    this->close();
}

// ─────────────────────────────────────────────
// SIDEBAR SLOTS (connected via button group)
// ─────────────────────────────────────────────

void MainWindow::on_dashboardBtn_clicked()    {}
void MainWindow::on_transactionsBtn_clicked() {}
void MainWindow::on_categoriesBtn_clicked()   {}
