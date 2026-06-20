#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// ← ALL Qt widget includes BEFORE the Ui namespace forward declaration
#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStackedWidget>
#include <QHeaderView>
#include <QButtonGroup>
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include <QFrame>
#include <QColor>

#include "services/RecurringTransactionService.h"

#include "ui/AddRecurringDialog.h"
#include "services/TransactionService.h"
#include "services/CategoryService.h"
#include "models/Transaction.h"
#include "models/Category.h"
#include "models/RecurringTransaction.h"

#include "ui/BarChartWidget.h"
#include "ui/PieChartWidget.h"
#include "ui/LineChartWidget.h"
#include "services/UserService.h"

#include "database/DatabaseManager.h"
#include <QFileDialog>
#include "ui/BudgetDialog.h"
#include "ui/TransactionNotesDialog.h"

#include "services/UserSettingsService.h"
#include "core/Currency.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dashboardBtn_clicked();
    void on_transactionsBtn_clicked();
    void on_categoriesBtn_clicked();

    void on_addBtn_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnReset_clicked();

    void on_profileBtn_clicked();
    void on_profileSaveBtn_clicked();

    void on_btnExport_clicked();

    void on_addCategoryBtn_clicked();
    void on_deleteCategoryBtn_clicked();

    void on_logoutBtn_clicked();

    void applyFilters();

    void on_backupBtn_clicked();
    void on_restoreBtn_clicked();

    void on_tableTransactions_cellDoubleClicked(int row, int column);

    void on_setBudgetBtn_clicked();

    void on_recurringBtn_clicked();
    void on_addRecurringBtn_clicked();
    void on_deleteRecurringBtn_clicked();
    void on_toggleRecurringBtn_clicked();


    void on_saveCurrencyBtn_clicked();


private:
    Ui::MainWindow *ui;
   DatabaseManager *m_dbManager = nullptr;
    int m_userId;


    BarChartWidget  *m_barChart  = nullptr;
    PieChartWidget  *m_pieChart  = nullptr;
    LineChartWidget *m_lineChart = nullptr;

    TransactionService m_transactionService;
    CategoryService    m_categoryService;

    RecurringTransactionService m_recurringService;
    QList<RecurringTransaction>  m_recurringList;

    QList<Category> m_categories;

    UserSettingsService m_settingsService;
    QString             m_currencyCode;

    void loadDashboard();
    void loadTransactions();
    void loadTransactions(const QList<Transaction> &list);
    void loadCategories();
    void updateStats();

    void loadAnalytics();

    UserService m_userService;
    void loadProfile();

    void animatePage(QWidget *page);
    void updateSidebarStyle(int activeId);
    void showToast(const QString &text);
    void checkBudgetAlerts();

    void loadRecurring();

    QString formatAmount(double amount) const;


};

#endif
