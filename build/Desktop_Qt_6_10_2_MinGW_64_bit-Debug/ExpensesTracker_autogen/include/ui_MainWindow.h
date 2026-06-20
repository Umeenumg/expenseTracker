/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
    QFrame *sidebar;
    QVBoxLayout *sidebarLayout;
    QLabel *appTitle;
    QLabel *userLabel;
    QPushButton *dashboardBtn;
    QPushButton *transactionsBtn;
    QPushButton *categoriesBtn;
    QPushButton *analyticsBtn;
    QPushButton *profileBtn;
    QPushButton *recurringBtn;
    QSpacerItem *spacerItem;
    QPushButton *logoutBtn;
    QVBoxLayout *contentLayout;
    QFrame *topBar;
    QHBoxLayout *topBarLayout;
    QLabel *pageTitle;
    QSpacerItem *spacerItem1;
    QLabel *topUserLabel;
    QStackedWidget *stackedWidget;
    QWidget *pageDashboard;
    QVBoxLayout *dashLayout;
    QHBoxLayout *statsLayout;
    QFrame *balanceCard;
    QVBoxLayout *vboxLayout;
    QLabel *balanceTitle;
    QLabel *balanceValue;
    QFrame *incomeCard;
    QVBoxLayout *vboxLayout1;
    QLabel *incomeTitle;
    QLabel *incomeValue;
    QFrame *expenseCard;
    QVBoxLayout *vboxLayout2;
    QLabel *expenseTitle;
    QLabel *expenseValue;
    QFrame *countCard;
    QVBoxLayout *vboxLayout3;
    QLabel *countTitle;
    QLabel *countValue;
    QLabel *recentLabel;
    QTableWidget *recentTable;
    QWidget *pageTransactions;
    QVBoxLayout *transLayout;
    QHBoxLayout *filterLayout;
    QLineEdit *searchInput;
    QComboBox *comboType;
    QPushButton *btnReset;
    QPushButton *addBtn;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QPushButton *btnExport;
    QTableWidget *tableTransactions;
    QFrame *frameSummary;
    QHBoxLayout *summaryLayout;
    QLabel *lblIncomeTitle;
    QLabel *lblIncome;
    QSpacerItem *spacerItem2;
    QLabel *lblExpenseTitle;
    QLabel *lblExpense;
    QSpacerItem *spacerItem3;
    QLabel *lblBalanceTitle;
    QLabel *lblBalance;
    QSpacerItem *spacerItem4;
    QLabel *lblCount;
    QWidget *pageCategories;
    QVBoxLayout *catLayout;
    QHBoxLayout *catStatsLayout;
    QFrame *totalCatCard;
    QVBoxLayout *vboxLayout4;
    QLabel *totalCatTitle;
    QLabel *totalCardValue;
    QFrame *mostUsedCard;
    QVBoxLayout *vboxLayout5;
    QLabel *mostUsedTitle;
    QLabel *mostUsedCardValue;
    QFrame *unusedCard;
    QVBoxLayout *vboxLayout6;
    QLabel *unusedTitle;
    QLabel *unusedCardValue;
    QHBoxLayout *catInputLayout;
    QLineEdit *categoryNameInput;
    QComboBox *categoryTypeCombo;
    QPushButton *setBudgetBtn;
    QPushButton *addCategoryBtn;
    QPushButton *deleteCategoryBtn;
    QTableWidget *categoriesTable;
    QWidget *pageAnalytics;
    QVBoxLayout *analyticsLayout;
    QLabel *analyticsMonthLabel;
    QHBoxLayout *chartsTopRow;
    QFrame *barChartFrame;
    QFrame *pieChartFrame;
    QFrame *lineChartFrame;
    QWidget *pageProfile;
    QVBoxLayout *profileLayout;
    QLabel *profileTitle;
    QFrame *profileCard;
    QVBoxLayout *profileCardLayout;
    QLabel *profileUsernameLabel;
    QLineEdit *profileUsernameEdit;
    QLabel *profileCurrentPassLabel;
    QLineEdit *profileCurrentPassEdit;
    QLabel *profileNewPassLabel;
    QLineEdit *profileNewPassEdit;
    QLabel *profileConfirmPassLabel;
    QLineEdit *profileConfirmPassEdit;
    QLabel *profileErrorLabel;
    QHBoxLayout *hboxLayout;
    QPushButton *profileSaveBtn;
    QSpacerItem *spacerItem5;
    QFrame *profileDivider;
    QLabel *backupSectionLabel;
    QHBoxLayout *backupBtnLayout;
    QPushButton *backupBtn;
    QPushButton *restoreBtn;
    QFrame *currencyDivider;
    QLabel *currencySectionLabel;
    QHBoxLayout *currencyRowLayout;
    QComboBox *currencyCombo;
    QPushButton *saveCurrencyBtn;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;
    QSpacerItem *spacerItem8;
    QWidget *pageRecurring;
    QVBoxLayout *recurringLayout;
    QHBoxLayout *recurringToolbar;
    QLabel *recurringTitle;
    QSpacerItem *spacerItem9;
    QPushButton *addRecurringBtn;
    QPushButton *deleteRecurringBtn;
    QPushButton *toggleRecurringBtn;
    QTableWidget *recurringTable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 650);
        MainWindow->setMinimumSize(QSize(1000, 650));
        MainWindow->setStyleSheet(QString::fromUtf8("/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   BASE\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QMainWindow, QDialog, QWidget {\n"
"    background-color: #0a"
                        "0a0f;\n"
"    color: #e2e2e8;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   SIDEBAR\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QFrame#sidebar {\n"
"    background-color: #0d0d14;\n"
"    border-right: 1px solid #1a1a28;\n"
"    min-width: 210px;\n"
"    max-width: 210px;\n"
"}\n"
"\n"
"QLabel#appTitle {\n"
"    font-size: 16px;\n"
"    font-weight: 700;\n"
"    color: #ffffff;\n"
"    padding: 20px 16px 4px 16px;\n"
"    letter-spacing: -0.3px;\n"
"}\n"
"\n"
"QLabel#userLabel {\n"
"    font-size: 12px;\n"
"    color: #9ca3af;\n"
"    padding: 4px 16px 16px 16px;\n"
"    border-bottom: 1px solid #1a1a28;\n"
"}\n"
"\n"
"/* \342\224\200\342\224\200 NAV BUTTONS \342\224\200\342\224\200 */\n"
"QFrame#sidebar QPushButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid transparent;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    text-align: left;\n"
"    color: #6b7280;\n"
"    font-size: 13px;\n"
"    margin: 1px 8px;\n"
"}\n"
"\n"
"QFrame#sidebar QPushButton:hover {\n"
"    background-color: #13131f;\n"
"    color: #c4b5fd;\n"
"    border-color: trans"
                        "parent;\n"
"}\n"
"\n"
"QFrame#sidebar QPushButton:checked {\n"
"    background-color: rgba(124, 58, 237, 0.15);\n"
"    color: #a78bfa;\n"
"    font-weight: 600;\n"
"    border: 1px solid rgba(167, 139, 250, 0.2);\n"
"}\n"
"\n"
"QFrame#sidebar QPushButton#logoutBtn {\n"
"    color: #4b5563;\n"
"    margin-top: 4px;\n"
"}\n"
"\n"
"QFrame#sidebar QPushButton#logoutBtn:hover {\n"
"    background-color: #1f0f0f;\n"
"    color: #f87171;\n"
"    border-color: rgba(248, 113, 113, 0.15);\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   TOP BAR\n"
"\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QFrame#topBar {\n"
"    background-color: #0d0d14;\n"
"    border-bottom: 1px solid #1a1a28;\n"
"    min-height: 52px;\n"
"    max-height: 52px;\n"
"    padding: 0 20px;\n"
"}\n"
"\n"
"QLabel#pageTitle {\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #f1f0f8;\n"
"}\n"
"\n"
"QLabel#topUserLabel {\n"
"    font-size: 12px;\n"
"    color: #4b5563;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   STAT CARDS\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"\n"
"QFrame#balanceCard,\n"
"QFrame#incomeCard,\n"
"QFrame#expenseCard,\n"
"QFrame#countCard,\n"
"QFrame#totalCatCard,\n"
"QFrame#mostUsedCard,\n"
"QFrame#unusedCard {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 1"
                        "0px;\n"
"    padding: 18px 16px;\n"
"    min-height: 90px;\n"
"}\n"
"\n"
"QFrame#balanceCard  { border-top: 2px solid #7c3aed; }\n"
"QFrame#incomeCard   { border-top: 2px solid #059669; }\n"
"QFrame#expenseCard  { border-top: 2px solid #dc2626; }\n"
"QFrame#countCard    { border-top: 2px solid #2563eb; }\n"
"QFrame#totalCatCard { border-top: 2px solid #2563eb; }\n"
"QFrame#mostUsedCard { border-top: 2px solid #7c3aed; }\n"
"QFrame#unusedCard   { border-top: 2px solid #d97706; }\n"
"\n"
"QFrame#balanceCard  QLabel:first-child,\n"
"QFrame#incomeCard   QLabel:first-child,\n"
"QFrame#expenseCard  QLabel:first-child,\n"
"QFrame#countCard    QLabel:first-child,\n"
"QFrame#totalCatCard QLabel:first-child,\n"
"QFrame#mostUsedCard QLabel:first-child,\n"
"QFrame#unusedCard   QLabel:first-child {\n"
"    font-size: 12px;\n"
"    color: #6b7280;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.5px;\n"
"}\n"
"\n"
"QFrame#balanceCard  QLabel:last-child { color: #a78bfa; font-size: 26px; font-weight: 700; }\n"
"QFrame#inc"
                        "omeCard   QLabel:last-child { color: #4ade80; font-size: 26px; font-weight: 700; }\n"
"QFrame#expenseCard  QLabel:last-child { color: #f87171; font-size: 26px; font-weight: 700; }\n"
"QFrame#countCard    QLabel:last-child { color: #60a5fa; font-size: 26px; font-weight: 700; }\n"
"QFrame#totalCatCard QLabel:last-child { color: #60a5fa; font-size: 26px; font-weight: 700; }\n"
"QFrame#mostUsedCard QLabel:last-child { color: #a78bfa; font-size: 26px; font-weight: 700; }\n"
"QFrame#unusedCard   QLabel:last-child { color: #fbbf24; font-size: 26px; font-weight: 700; }\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342"
                        "\225\220\342\225\220\n"
"   SUMMARY BAR\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QFrame#frameSummary {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 10px 16px;\n"
"}\n"
"\n"
"QLabel#lblIncome  { color: #4ade80; font-weight: 700; font-size: 13px; }\n"
"QLabel#lblExpense { color: #f87171; font-weight: 700; font-size: 13px; }\n"
"QLabel#lblBalance { color: #a78bfa; font-weight: 700; font-size: 13px; }\n"
"QLabel#lblCount   { color: #4b5563; font-size: 12px; }\n"
"QLabel#lblIncomeTitle,\n"
"QLabel#lblExpenseTitle,\n"
""
                        "QLabel#lblBalanceTitle { color: #374151; font-size: 12px; }\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   TABLES\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        " */\n"
"QTableWidget {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 10px;\n"
"    gridline-color: transparent;\n"
"    selection-background-color: #1a1a30;\n"
"    selection-color: #e2e2e8;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px 12px;\n"
"    border-bottom: 1px solid #111120;\n"
"    color: #6b7280;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #1a1a30;\n"
"    color: #e2e2e8;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #0f0f1a;\n"
"    color: #9ca3af;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #080810;\n"
"    color: #374151;\n"
"    font-size: 10px;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.6px;\n"
"    padding: 8px 12px;\n"
"    border: none;\n"
"    border-bottom: 1px solid #1a1a28;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QHeaderView::section:first { border-top-left-radius: 10px; }\n"
"QHeaderView::section:last  { border-top-righ"
                        "t-radius: 10px; }\n"
"\n"
"QScrollBar:vertical {\n"
"    background: #0d0d14;\n"
"    width: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #1e1e30;\n"
"    border-radius: 3px;\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical { height: 0; }\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   INPUTS\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QLineEdit {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 7px;\n"
"    padding: 7px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 12px;\n"
"    selection-background-color: #4f46e5;\n"
"}\n"
"\n"
"QLineEdit:focus { border-color: #7c3aed; }\n"
"QLineEdit:hover { border-color: #252535; }\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   COMBOBOX\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QComboBox {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 7px;\n"
"    padding: 7px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 12px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QComboBox:hover { border-color: #252535; }\n"
"QComboBox:focus { border-color: #7c3aed; }\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 24px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image"
                        ": none;\n"
"    width: 0; height: 0;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #4b5563;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #13131f;\n"
"    border: 1px solid #252535;\n"
"    border-radius: 7px;\n"
"    color: #e2e2e8;\n"
"    selection-background-color: #1e1e3f;\n"
"    selection-color: #a78bfa;\n"
"    padding: 4px;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   CONTENT AREA BUTTONS\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342"
                        "\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QWidget#pageTransactions QPushButton,\n"
"QWidget#pageCategories QPushButton {\n"
"    background-color: #13131f;\n"
"    border: 1px solid #1e1e30;\n"
"    border-radius: 7px;\n"
"    padding: 6px 14px;\n"
"    color: #6b7280;\n"
"    font-size: 12px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QWidget#pageTransactions QPushButton:hover,\n"
"QWidget#pageCategories QPushButton:hover {\n"
"    background-color: #1a1a2e;\n"
"    color: #c4b5fd;\n"
"    border-color: #2e2e4e;\n"
"}\n"
"\n"
"QPushButton#addBtn {\n"
"    background-color: #4f46e5 !important;\n"
"    border-color: #4f46e5 !important;\n"
""
                        "    color: white !important;\n"
"    font-weight: 600 !important;\n"
"}\n"
"\n"
"QPushButton#addBtn:hover {\n"
"    background-color: #4338ca !important;\n"
"    border-color: #4338ca !important;\n"
"}\n"
"\n"
"QPushButton#btnDelete,\n"
"QPushButton#deleteCategoryBtn {\n"
"    background-color: #2a0f0f !important;\n"
"    border-color: rgba(248,113,113,0.3) !important;\n"
"    color: #f87171 !important;\n"
"}\n"
"\n"
"QPushButton#btnDelete:hover,\n"
"QPushButton#deleteCategoryBtn:hover {\n"
"    background-color: #3f1d1d !important;\n"
"    border-color: #f87171 !important;\n"
"}\n"
"\n"
"QPushButton#addCategoryBtn {\n"
"    background-color: #052e1c !important;\n"
"    border-color: rgba(74,222,128,0.3) !important;\n"
"    color: #4ade80 !important;\n"
"}\n"
"\n"
"QPushButton#addCategoryBtn:hover {\n"
"    background-color: #064e3b !important;\n"
"    border-color: #4ade80 !important;\n"
"}\n"
"\n"
"QPushButton#btnExport {\n"
"    background-color: #0c1a2e !important;\n"
"    border-color: rgba(96,165,250,0.3"
                        ") !important;\n"
"    color: #60a5fa !important;\n"
"}\n"
"\n"
"QPushButton#btnExport:hover {\n"
"    background-color: #1e3a5f !important;\n"
"    border-color: #60a5fa !important;\n"
"}\n"
"\n"
"QPushButton#btnEdit {\n"
"    background-color: #13131f !important;\n"
"    border-color: rgba(167,139,250,0.2) !important;\n"
"    color: #a78bfa !important;\n"
"}\n"
"\n"
"QPushButton#btnEdit:hover {\n"
"    background-color: #1e1e3f !important;\n"
"    border-color: #a78bfa !important;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   LABELS\n"
"\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QLabel#recentLabel,\n"
"QLabel#analyticsMonthLabel {\n"
"    font-size: 10px;\n"
"    font-weight: 500;\n"
"    color: #374151;\n"
"    letter-spacing: 0.7px;\n"
"    padding: 6px 0 4px 0;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225"
                        "\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   ANALYTICS FRAMES\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QFrame#barChartFrame,\n"
"QFrame#pieChartFrame,\n"
"QFrame#lineChartFrame {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   PROFILE PAGE\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QLabel#profileTitle {\n"
"    font-size: 18px;\n"
"    font-weight: 700;\n"
"    color: #f1f0f8;\n"
"    padding-bottom: 8px;\n"
"}\n"
"\n"
"QFrame#profileCard {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 12px;\n"
"    padding: 24px;\n"
"    max-"
                        "width: 500px;\n"
"}\n"
"\n"
"QFrame#profileCard QLabel {\n"
"    font-size: 11px;\n"
"    color: #4b5563;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.4px;\n"
"}\n"
"\n"
"QLabel#profileErrorLabel {\n"
"    color: #f87171;\n"
"    background-color: #2a0f0f;\n"
"    border: 1px solid rgba(248,113,113,0.2);\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QPushButton#profileSaveBtn {\n"
"    background-color: #4f46e5;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 10px 24px;\n"
"    color: white;\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QPushButton#profileSaveBtn:hover {\n"
"    background-color: #4338ca;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   BACKUP BUTTONS\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QPushButton#backupBtn {\n"
"    background-color: #052e1c !important;\n"
"    border: 1px solid rgba(74,222,128,0.3) !important;\n"
"    color: #4ade80 !important;\n"
"    border-radius: 8px;\n"
"    padding: 9px 18px;\n"
"    font-size: 12px;\n"
"    font-weight: 500;\n"
"    min-width: 120px;\n"
"}\n"
"\n"
"QPushButton#backupBtn:hover {\n"
"    backg"
                        "round-color: #064e3b !important;\n"
"    border-color: #4ade80 !important;\n"
"}\n"
"\n"
"QPushButton#restoreBtn {\n"
"    background-color: #0c1a2e !important;\n"
"    border: 1px solid rgba(96,165,250,0.3) !important;\n"
"    color: #60a5fa !important;\n"
"    border-radius: 8px;\n"
"    padding: 9px 18px;\n"
"    font-size: 12px;\n"
"    font-weight: 500;\n"
"    min-width: 120px;\n"
"}\n"
"\n"
"QPushButton#restoreBtn:hover {\n"
"    background-color: #1e3a5f !important;\n"
"    border-color: #60a5fa !important;\n"
"}\n"
"\n"
"QLabel#backupSectionLabel {\n"
"    font-size: 11px;\n"
"    color: #4b5563;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.4px;\n"
"    padding-top: 4px;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   MESSAGE BOX\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QMessageBox {\n"
"    background-color: #0d0d14;\n"
"    color: #e2e2e8;\n"
"}\n"
"\n"
"QMessageBox QPushButton {\n"
"    background-color: #13131f;\n"
"    border: 1px solid #1e1e30;\n"
"    border-radius: 7px;\n"
"    padding: 7px 20px;\n"
"    color: #e2e2e8;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #4f46e5;"
                        "\n"
"    border-color: #4f46e5;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   DIALOGS (Login / Register / AddTransaction)\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225"
                        "\220\342\225\220 */\n"
"QDialog {\n"
"    background-color: #0d0d14;\n"
"    border: 1px solid #1a1a28;\n"
"}\n"
"\n"
"QDialog QLabel#titleLabel,\n"
"QDialog QLabel#dialogTitle {\n"
"    font-size: 20px;\n"
"    font-weight: 700;\n"
"    color: #a78bfa;\n"
"    padding-bottom: 4px;\n"
"}\n"
"\n"
"QDialog QLabel#subtitleLabel {\n"
"    font-size: 13px;\n"
"    color: #4b5563;\n"
"    padding-bottom: 8px;\n"
"}\n"
"\n"
"QDialog QLabel#errorLabel {\n"
"    color: #f87171;\n"
"    background-color: #2a0f0f;\n"
"    border: 1px solid rgba(248,113,113,0.2);\n"
"    border-radius: 6px;\n"
"    padding: 7px 10px;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QDialog QLabel {\n"
"    font-size: 11px;\n"
"    color: #4b5563;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.3px;\n"
"}\n"
"\n"
"QDialog QLineEdit {\n"
"    background-color: #080810;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 10px 14px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QLineEdit:focus "
                        "{ border-color: #7c3aed; }\n"
"\n"
"QDialog QDoubleSpinBox {\n"
"    background-color: #080810;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QDoubleSpinBox:focus { border-color: #7c3aed; }\n"
"\n"
"QDialog QDoubleSpinBox::up-button,\n"
"QDialog QDoubleSpinBox::down-button {\n"
"    background-color: #13131f;\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QDialog QDoubleSpinBox::up-button:hover,\n"
"QDialog QDoubleSpinBox::down-button:hover {\n"
"    background-color: #1e1e30;\n"
"}\n"
"\n"
"QDialog QComboBox {\n"
"    background-color: #080810;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QComboBox:focus { border-color: #7c3aed; }\n"
"\n"
"QDialog QDateEdit {\n"
"    background-color: #080810;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    paddin"
                        "g: 9px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QDateEdit:focus { border-color: #7c3aed; }\n"
"\n"
"QDialog QDateEdit::drop-down {\n"
"    background-color: #13131f;\n"
"    border: none;\n"
"    width: 24px;\n"
"    border-radius: 0 8px 8px 0;\n"
"}\n"
"\n"
"QDialog QPushButton#loginButton,\n"
"QDialog QPushButton#confirmBtn,\n"
"QDialog QPushButton#registerButton {\n"
"    background-color: #4f46e5;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 11px;\n"
"    color: white;\n"
"    font-size: 13px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QDialog QPushButton#loginButton:hover,\n"
"QDialog QPushButton#confirmBtn:hover,\n"
"QDialog QPushButton#registerButton:hover {\n"
"    background-color: #4338ca;\n"
"}\n"
"\n"
"QDialog QPushButton#cancelBtn,\n"
"QDialog QPushButton#backButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #4b5563;\n"
"    font-size: 12px;\n"
""
                        "}\n"
"\n"
"QDialog QPushButton#cancelBtn:hover,\n"
"QDialog QPushButton#backButton:hover {\n"
"    background-color: #13131f;\n"
"    color: #9ca3af;\n"
"    border-color: #252535;\n"
"}\n"
"\n"
"QDialog QPushButton#registerButton[flat=\"true\"] {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: #7c3aed;\n"
"    font-size: 12px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QDialog QPushButton#registerButton[flat=\"true\"]:hover {\n"
"    color: #a78bfa;\n"
"}\n"
"\n"
"QDialog QFrame#divider {\n"
"    color: #1a1a28;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220"
                        "\n"
"   NOTES FIELD IN DIALOG\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QDialog QPlainTextEdit {\n"
"    background-color: #080810;\n"
"    border: 1px solid #1a1a28;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    color: #e2e2e8;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QDialog QPlainTextEdit:focus {\n"
"    border-color: #7c3aed;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225"
                        "\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   BUDGET BUTTON\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QPushButton#setBudgetBtn {\n"
"    background-color: #1a0f2e !important;\n"
"    border: 1px solid rgba(167,139,250,0.3) !important;\n"
"    color: #a78bfa !important;\n"
"    border-radius: 7px;\n"
"    padding: 6px 14px;\n"
"    font-size: 12px;\n"
"    font-weight: 500;\n"
"}"
                        "\n"
"\n"
"QPushButton#setBudgetBtn:hover {\n"
"    background-color: #1e1e3f !important;\n"
"    border-color: #a78bfa !important;\n"
"}\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   RECURRING PAGE\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342"
                        "\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QLabel#recurringTitle {\n"
"    font-size: 15px;\n"
"    font-weight: 600;\n"
"    color: #f1f0f8;\n"
"}\n"
"\n"
"QPushButton#addRecurringBtn {\n"
"    background-color: #4f46e5 !important;\n"
"    border-color: #4f46e5 !important;\n"
"    color: white !important;\n"
"    font-weight: 600 !important;\n"
"    border-radius: 7px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"QPushButton#addRecurringBtn:hover {\n"
"    background-color: #4338ca !important;\n"
"}\n"
"\n"
"QPushButton#deleteRecurringBtn {\n"
"    background-color: #2a0f0f !important;\n"
"    border: 1px solid rgba(248,113,113,0.3) !important;\n"
"    color: #f87171 !important;\n"
"    border-radius: 7px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"QPushButton#toggleRecurringBtn {\n"
"    background-color: #13131f !important;\n"
"    border: 1px solid rgba(251,191,36,0.3) !important;\n"
"    color: #fbbf24 !important;\n"
"    border-radius: 7px;\n"
"    padding: 6px 14"
                        "px;\n"
"}\n"
"\n"
"QPushButton#toggleRecurringBtn:hover {\n"
"    background-color: #1f1a0f !important;\n"
"    border-color: #fbbf24 !important;\n"
"}\n"
"\n"
"/* \342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\n"
"   CURRENCY SECTION\n"
"\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342"
                        "\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220 */\n"
"QLabel#currencySectionLabel {\n"
"    font-size: 11px;\n"
"    color: #4b5563;\n"
"    font-weight: 500;\n"
"    letter-spacing: 0.4px;\n"
"    padding-top: 4px;\n"
"}\n"
"\n"
"QPushButton#saveCurrencyBtn {\n"
"    background-color: #4f46e5;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 9px 18px;\n"
"    color: white;\n"
"    font-size: 12px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QPushButton#saveCurrencyBtn:hover {\n"
"    background-color: #4338ca;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        mainLayout = new QHBoxLayout(centralWidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QFrame(centralWidget);
        sidebar->setObjectName("sidebar");
        sidebarLayout = new QVBoxLayout(sidebar);
        sidebarLayout->setSpacing(8);
        sidebarLayout->setObjectName("sidebarLayout");
        appTitle = new QLabel(sidebar);
        appTitle->setObjectName("appTitle");
        appTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        sidebarLayout->addWidget(appTitle);

        userLabel = new QLabel(sidebar);
        userLabel->setObjectName("userLabel");
        userLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        sidebarLayout->addWidget(userLabel);

        dashboardBtn = new QPushButton(sidebar);
        dashboardBtn->setObjectName("dashboardBtn");
        dashboardBtn->setCheckable(true);

        sidebarLayout->addWidget(dashboardBtn);

        transactionsBtn = new QPushButton(sidebar);
        transactionsBtn->setObjectName("transactionsBtn");
        transactionsBtn->setCheckable(true);

        sidebarLayout->addWidget(transactionsBtn);

        categoriesBtn = new QPushButton(sidebar);
        categoriesBtn->setObjectName("categoriesBtn");
        categoriesBtn->setCheckable(true);

        sidebarLayout->addWidget(categoriesBtn);

        analyticsBtn = new QPushButton(sidebar);
        analyticsBtn->setObjectName("analyticsBtn");
        analyticsBtn->setCheckable(true);

        sidebarLayout->addWidget(analyticsBtn);

        profileBtn = new QPushButton(sidebar);
        profileBtn->setObjectName("profileBtn");
        profileBtn->setCheckable(true);

        sidebarLayout->addWidget(profileBtn);

        recurringBtn = new QPushButton(sidebar);
        recurringBtn->setObjectName("recurringBtn");
        recurringBtn->setCheckable(true);

        sidebarLayout->addWidget(recurringBtn);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(spacerItem);

        logoutBtn = new QPushButton(sidebar);
        logoutBtn->setObjectName("logoutBtn");

        sidebarLayout->addWidget(logoutBtn);


        mainLayout->addWidget(sidebar);

        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        topBar = new QFrame(centralWidget);
        topBar->setObjectName("topBar");
        topBarLayout = new QHBoxLayout(topBar);
        topBarLayout->setObjectName("topBarLayout");
        pageTitle = new QLabel(topBar);
        pageTitle->setObjectName("pageTitle");

        topBarLayout->addWidget(pageTitle);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topBarLayout->addItem(spacerItem1);

        topUserLabel = new QLabel(topBar);
        topUserLabel->setObjectName("topUserLabel");

        topBarLayout->addWidget(topUserLabel);


        contentLayout->addWidget(topBar);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        pageDashboard = new QWidget();
        pageDashboard->setObjectName("pageDashboard");
        dashLayout = new QVBoxLayout(pageDashboard);
        dashLayout->setObjectName("dashLayout");
        statsLayout = new QHBoxLayout();
        statsLayout->setSpacing(15);
        statsLayout->setObjectName("statsLayout");
        balanceCard = new QFrame(pageDashboard);
        balanceCard->setObjectName("balanceCard");
        vboxLayout = new QVBoxLayout(balanceCard);
        vboxLayout->setObjectName("vboxLayout");
        balanceTitle = new QLabel(balanceCard);
        balanceTitle->setObjectName("balanceTitle");
        balanceTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout->addWidget(balanceTitle);

        balanceValue = new QLabel(balanceCard);
        balanceValue->setObjectName("balanceValue");
        balanceValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout->addWidget(balanceValue);


        statsLayout->addWidget(balanceCard);

        incomeCard = new QFrame(pageDashboard);
        incomeCard->setObjectName("incomeCard");
        vboxLayout1 = new QVBoxLayout(incomeCard);
        vboxLayout1->setObjectName("vboxLayout1");
        incomeTitle = new QLabel(incomeCard);
        incomeTitle->setObjectName("incomeTitle");
        incomeTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout1->addWidget(incomeTitle);

        incomeValue = new QLabel(incomeCard);
        incomeValue->setObjectName("incomeValue");
        incomeValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout1->addWidget(incomeValue);


        statsLayout->addWidget(incomeCard);

        expenseCard = new QFrame(pageDashboard);
        expenseCard->setObjectName("expenseCard");
        vboxLayout2 = new QVBoxLayout(expenseCard);
        vboxLayout2->setObjectName("vboxLayout2");
        expenseTitle = new QLabel(expenseCard);
        expenseTitle->setObjectName("expenseTitle");
        expenseTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout2->addWidget(expenseTitle);

        expenseValue = new QLabel(expenseCard);
        expenseValue->setObjectName("expenseValue");
        expenseValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout2->addWidget(expenseValue);


        statsLayout->addWidget(expenseCard);

        countCard = new QFrame(pageDashboard);
        countCard->setObjectName("countCard");
        vboxLayout3 = new QVBoxLayout(countCard);
        vboxLayout3->setObjectName("vboxLayout3");
        countTitle = new QLabel(countCard);
        countTitle->setObjectName("countTitle");
        countTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout3->addWidget(countTitle);

        countValue = new QLabel(countCard);
        countValue->setObjectName("countValue");
        countValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout3->addWidget(countValue);


        statsLayout->addWidget(countCard);


        dashLayout->addLayout(statsLayout);

        recentLabel = new QLabel(pageDashboard);
        recentLabel->setObjectName("recentLabel");

        dashLayout->addWidget(recentLabel);

        recentTable = new QTableWidget(pageDashboard);
        recentTable->setObjectName("recentTable");

        dashLayout->addWidget(recentTable);

        stackedWidget->addWidget(pageDashboard);
        pageTransactions = new QWidget();
        pageTransactions->setObjectName("pageTransactions");
        transLayout = new QVBoxLayout(pageTransactions);
        transLayout->setObjectName("transLayout");
        filterLayout = new QHBoxLayout();
        filterLayout->setSpacing(8);
        filterLayout->setObjectName("filterLayout");
        searchInput = new QLineEdit(pageTransactions);
        searchInput->setObjectName("searchInput");

        filterLayout->addWidget(searchInput);

        comboType = new QComboBox(pageTransactions);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        filterLayout->addWidget(comboType);

        btnReset = new QPushButton(pageTransactions);
        btnReset->setObjectName("btnReset");

        filterLayout->addWidget(btnReset);

        addBtn = new QPushButton(pageTransactions);
        addBtn->setObjectName("addBtn");

        filterLayout->addWidget(addBtn);

        btnEdit = new QPushButton(pageTransactions);
        btnEdit->setObjectName("btnEdit");

        filterLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(pageTransactions);
        btnDelete->setObjectName("btnDelete");

        filterLayout->addWidget(btnDelete);

        btnExport = new QPushButton(pageTransactions);
        btnExport->setObjectName("btnExport");

        filterLayout->addWidget(btnExport);


        transLayout->addLayout(filterLayout);

        tableTransactions = new QTableWidget(pageTransactions);
        tableTransactions->setObjectName("tableTransactions");

        transLayout->addWidget(tableTransactions);

        frameSummary = new QFrame(pageTransactions);
        frameSummary->setObjectName("frameSummary");
        summaryLayout = new QHBoxLayout(frameSummary);
        summaryLayout->setObjectName("summaryLayout");
        lblIncomeTitle = new QLabel(frameSummary);
        lblIncomeTitle->setObjectName("lblIncomeTitle");

        summaryLayout->addWidget(lblIncomeTitle);

        lblIncome = new QLabel(frameSummary);
        lblIncome->setObjectName("lblIncome");

        summaryLayout->addWidget(lblIncome);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        summaryLayout->addItem(spacerItem2);

        lblExpenseTitle = new QLabel(frameSummary);
        lblExpenseTitle->setObjectName("lblExpenseTitle");

        summaryLayout->addWidget(lblExpenseTitle);

        lblExpense = new QLabel(frameSummary);
        lblExpense->setObjectName("lblExpense");

        summaryLayout->addWidget(lblExpense);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        summaryLayout->addItem(spacerItem3);

        lblBalanceTitle = new QLabel(frameSummary);
        lblBalanceTitle->setObjectName("lblBalanceTitle");

        summaryLayout->addWidget(lblBalanceTitle);

        lblBalance = new QLabel(frameSummary);
        lblBalance->setObjectName("lblBalance");

        summaryLayout->addWidget(lblBalance);

        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        summaryLayout->addItem(spacerItem4);

        lblCount = new QLabel(frameSummary);
        lblCount->setObjectName("lblCount");

        summaryLayout->addWidget(lblCount);


        transLayout->addWidget(frameSummary);

        stackedWidget->addWidget(pageTransactions);
        pageCategories = new QWidget();
        pageCategories->setObjectName("pageCategories");
        catLayout = new QVBoxLayout(pageCategories);
        catLayout->setObjectName("catLayout");
        catStatsLayout = new QHBoxLayout();
        catStatsLayout->setSpacing(15);
        catStatsLayout->setObjectName("catStatsLayout");
        totalCatCard = new QFrame(pageCategories);
        totalCatCard->setObjectName("totalCatCard");
        vboxLayout4 = new QVBoxLayout(totalCatCard);
        vboxLayout4->setObjectName("vboxLayout4");
        totalCatTitle = new QLabel(totalCatCard);
        totalCatTitle->setObjectName("totalCatTitle");
        totalCatTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout4->addWidget(totalCatTitle);

        totalCardValue = new QLabel(totalCatCard);
        totalCardValue->setObjectName("totalCardValue");
        totalCardValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout4->addWidget(totalCardValue);


        catStatsLayout->addWidget(totalCatCard);

        mostUsedCard = new QFrame(pageCategories);
        mostUsedCard->setObjectName("mostUsedCard");
        vboxLayout5 = new QVBoxLayout(mostUsedCard);
        vboxLayout5->setObjectName("vboxLayout5");
        mostUsedTitle = new QLabel(mostUsedCard);
        mostUsedTitle->setObjectName("mostUsedTitle");
        mostUsedTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout5->addWidget(mostUsedTitle);

        mostUsedCardValue = new QLabel(mostUsedCard);
        mostUsedCardValue->setObjectName("mostUsedCardValue");
        mostUsedCardValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout5->addWidget(mostUsedCardValue);


        catStatsLayout->addWidget(mostUsedCard);

        unusedCard = new QFrame(pageCategories);
        unusedCard->setObjectName("unusedCard");
        vboxLayout6 = new QVBoxLayout(unusedCard);
        vboxLayout6->setObjectName("vboxLayout6");
        unusedTitle = new QLabel(unusedCard);
        unusedTitle->setObjectName("unusedTitle");
        unusedTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout6->addWidget(unusedTitle);

        unusedCardValue = new QLabel(unusedCard);
        unusedCardValue->setObjectName("unusedCardValue");
        unusedCardValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout6->addWidget(unusedCardValue);


        catStatsLayout->addWidget(unusedCard);


        catLayout->addLayout(catStatsLayout);

        catInputLayout = new QHBoxLayout();
        catInputLayout->setSpacing(8);
        catInputLayout->setObjectName("catInputLayout");
        categoryNameInput = new QLineEdit(pageCategories);
        categoryNameInput->setObjectName("categoryNameInput");

        catInputLayout->addWidget(categoryNameInput);

        categoryTypeCombo = new QComboBox(pageCategories);
        categoryTypeCombo->addItem(QString());
        categoryTypeCombo->addItem(QString());
        categoryTypeCombo->setObjectName("categoryTypeCombo");

        catInputLayout->addWidget(categoryTypeCombo);

        setBudgetBtn = new QPushButton(pageCategories);
        setBudgetBtn->setObjectName("setBudgetBtn");

        catInputLayout->addWidget(setBudgetBtn);

        addCategoryBtn = new QPushButton(pageCategories);
        addCategoryBtn->setObjectName("addCategoryBtn");

        catInputLayout->addWidget(addCategoryBtn);

        deleteCategoryBtn = new QPushButton(pageCategories);
        deleteCategoryBtn->setObjectName("deleteCategoryBtn");

        catInputLayout->addWidget(deleteCategoryBtn);


        catLayout->addLayout(catInputLayout);

        categoriesTable = new QTableWidget(pageCategories);
        categoriesTable->setObjectName("categoriesTable");

        catLayout->addWidget(categoriesTable);

        stackedWidget->addWidget(pageCategories);
        pageAnalytics = new QWidget();
        pageAnalytics->setObjectName("pageAnalytics");
        analyticsLayout = new QVBoxLayout(pageAnalytics);
        analyticsLayout->setSpacing(16);
        analyticsLayout->setObjectName("analyticsLayout");
        analyticsMonthLabel = new QLabel(pageAnalytics);
        analyticsMonthLabel->setObjectName("analyticsMonthLabel");

        analyticsLayout->addWidget(analyticsMonthLabel);

        chartsTopRow = new QHBoxLayout();
        chartsTopRow->setSpacing(16);
        chartsTopRow->setObjectName("chartsTopRow");
        barChartFrame = new QFrame(pageAnalytics);
        barChartFrame->setObjectName("barChartFrame");

        chartsTopRow->addWidget(barChartFrame);

        pieChartFrame = new QFrame(pageAnalytics);
        pieChartFrame->setObjectName("pieChartFrame");

        chartsTopRow->addWidget(pieChartFrame);


        analyticsLayout->addLayout(chartsTopRow);

        lineChartFrame = new QFrame(pageAnalytics);
        lineChartFrame->setObjectName("lineChartFrame");

        analyticsLayout->addWidget(lineChartFrame);

        stackedWidget->addWidget(pageAnalytics);
        pageProfile = new QWidget();
        pageProfile->setObjectName("pageProfile");
        profileLayout = new QVBoxLayout(pageProfile);
        profileLayout->setSpacing(16);
        profileLayout->setObjectName("profileLayout");
        profileLayout->setContentsMargins(40, 30, 40, -1);
        profileTitle = new QLabel(pageProfile);
        profileTitle->setObjectName("profileTitle");

        profileLayout->addWidget(profileTitle);

        profileCard = new QFrame(pageProfile);
        profileCard->setObjectName("profileCard");
        profileCardLayout = new QVBoxLayout(profileCard);
        profileCardLayout->setSpacing(14);
        profileCardLayout->setObjectName("profileCardLayout");
        profileUsernameLabel = new QLabel(profileCard);
        profileUsernameLabel->setObjectName("profileUsernameLabel");

        profileCardLayout->addWidget(profileUsernameLabel);

        profileUsernameEdit = new QLineEdit(profileCard);
        profileUsernameEdit->setObjectName("profileUsernameEdit");

        profileCardLayout->addWidget(profileUsernameEdit);

        profileCurrentPassLabel = new QLabel(profileCard);
        profileCurrentPassLabel->setObjectName("profileCurrentPassLabel");

        profileCardLayout->addWidget(profileCurrentPassLabel);

        profileCurrentPassEdit = new QLineEdit(profileCard);
        profileCurrentPassEdit->setObjectName("profileCurrentPassEdit");
        profileCurrentPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        profileCardLayout->addWidget(profileCurrentPassEdit);

        profileNewPassLabel = new QLabel(profileCard);
        profileNewPassLabel->setObjectName("profileNewPassLabel");

        profileCardLayout->addWidget(profileNewPassLabel);

        profileNewPassEdit = new QLineEdit(profileCard);
        profileNewPassEdit->setObjectName("profileNewPassEdit");
        profileNewPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        profileCardLayout->addWidget(profileNewPassEdit);

        profileConfirmPassLabel = new QLabel(profileCard);
        profileConfirmPassLabel->setObjectName("profileConfirmPassLabel");

        profileCardLayout->addWidget(profileConfirmPassLabel);

        profileConfirmPassEdit = new QLineEdit(profileCard);
        profileConfirmPassEdit->setObjectName("profileConfirmPassEdit");
        profileConfirmPassEdit->setEchoMode(QLineEdit::EchoMode::Password);

        profileCardLayout->addWidget(profileConfirmPassEdit);

        profileErrorLabel = new QLabel(profileCard);
        profileErrorLabel->setObjectName("profileErrorLabel");
        profileErrorLabel->setVisible(false);

        profileCardLayout->addWidget(profileErrorLabel);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        profileSaveBtn = new QPushButton(profileCard);
        profileSaveBtn->setObjectName("profileSaveBtn");

        hboxLayout->addWidget(profileSaveBtn);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(spacerItem5);


        profileCardLayout->addLayout(hboxLayout);

        profileDivider = new QFrame(profileCard);
        profileDivider->setObjectName("profileDivider");
        profileDivider->setFrameShape(QFrame::Shape::HLine);
        profileDivider->setFrameShadow(QFrame::Shadow::Sunken);

        profileCardLayout->addWidget(profileDivider);

        backupSectionLabel = new QLabel(profileCard);
        backupSectionLabel->setObjectName("backupSectionLabel");

        profileCardLayout->addWidget(backupSectionLabel);

        backupBtnLayout = new QHBoxLayout();
        backupBtnLayout->setSpacing(10);
        backupBtnLayout->setObjectName("backupBtnLayout");
        backupBtn = new QPushButton(profileCard);
        backupBtn->setObjectName("backupBtn");

        backupBtnLayout->addWidget(backupBtn);

        restoreBtn = new QPushButton(profileCard);
        restoreBtn->setObjectName("restoreBtn");

        backupBtnLayout->addWidget(restoreBtn);

        currencyDivider = new QFrame(profileCard);
        currencyDivider->setObjectName("currencyDivider");
        currencyDivider->setFrameShape(QFrame::Shape::HLine);
        currencyDivider->setFrameShadow(QFrame::Shadow::Sunken);

        backupBtnLayout->addWidget(currencyDivider);

        currencySectionLabel = new QLabel(profileCard);
        currencySectionLabel->setObjectName("currencySectionLabel");

        backupBtnLayout->addWidget(currencySectionLabel);

        currencyRowLayout = new QHBoxLayout();
        currencyRowLayout->setSpacing(10);
        currencyRowLayout->setObjectName("currencyRowLayout");
        currencyCombo = new QComboBox(profileCard);
        currencyCombo->setObjectName("currencyCombo");

        currencyRowLayout->addWidget(currencyCombo);

        saveCurrencyBtn = new QPushButton(profileCard);
        saveCurrencyBtn->setObjectName("saveCurrencyBtn");

        currencyRowLayout->addWidget(saveCurrencyBtn);

        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        currencyRowLayout->addItem(spacerItem6);


        backupBtnLayout->addLayout(currencyRowLayout);

        spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        backupBtnLayout->addItem(spacerItem7);


        profileCardLayout->addLayout(backupBtnLayout);


        profileLayout->addWidget(profileCard);

        spacerItem8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        profileLayout->addItem(spacerItem8);

        stackedWidget->addWidget(pageProfile);
        pageRecurring = new QWidget();
        pageRecurring->setObjectName("pageRecurring");
        recurringLayout = new QVBoxLayout(pageRecurring);
        recurringLayout->setSpacing(12);
        recurringLayout->setObjectName("recurringLayout");
        recurringToolbar = new QHBoxLayout();
        recurringToolbar->setSpacing(8);
        recurringToolbar->setObjectName("recurringToolbar");
        recurringTitle = new QLabel(pageRecurring);
        recurringTitle->setObjectName("recurringTitle");

        recurringToolbar->addWidget(recurringTitle);

        spacerItem9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        recurringToolbar->addItem(spacerItem9);

        addRecurringBtn = new QPushButton(pageRecurring);
        addRecurringBtn->setObjectName("addRecurringBtn");

        recurringToolbar->addWidget(addRecurringBtn);

        deleteRecurringBtn = new QPushButton(pageRecurring);
        deleteRecurringBtn->setObjectName("deleteRecurringBtn");

        recurringToolbar->addWidget(deleteRecurringBtn);

        toggleRecurringBtn = new QPushButton(pageRecurring);
        toggleRecurringBtn->setObjectName("toggleRecurringBtn");

        recurringToolbar->addWidget(toggleRecurringBtn);


        recurringLayout->addLayout(recurringToolbar);

        recurringTable = new QTableWidget(pageRecurring);
        recurringTable->setObjectName("recurringTable");

        recurringLayout->addWidget(recurringTable);

        stackedWidget->addWidget(pageRecurring);

        contentLayout->addWidget(stackedWidget);


        mainLayout->addLayout(contentLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Expense Tracker", nullptr));
        appTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\222\260 ExpenseTracker", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        dashboardBtn->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        transactionsBtn->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        categoriesBtn->setText(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        analyticsBtn->setText(QCoreApplication::translate("MainWindow", "Analytics", nullptr));
        profileBtn->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        recurringBtn->setText(QCoreApplication::translate("MainWindow", "Recurring", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        pageTitle->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        topUserLabel->setText(QString());
        balanceTitle->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        balanceValue->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        incomeTitle->setText(QCoreApplication::translate("MainWindow", "Income", nullptr));
        incomeValue->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        expenseTitle->setText(QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        expenseValue->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        countTitle->setText(QCoreApplication::translate("MainWindow", "Transactions", nullptr));
        countValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        recentLabel->setText(QCoreApplication::translate("MainWindow", "Recent Transactions", nullptr));
        searchInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search transactions...", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("MainWindow", "income", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("MainWindow", "expense", nullptr));

        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+ Add", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btnExport->setText(QCoreApplication::translate("MainWindow", "Export CSV", nullptr));
        lblIncomeTitle->setText(QCoreApplication::translate("MainWindow", "Income:", nullptr));
        lblIncome->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        lblExpenseTitle->setText(QCoreApplication::translate("MainWindow", "Expense:", nullptr));
        lblExpense->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        lblBalanceTitle->setText(QCoreApplication::translate("MainWindow", "Balance:", nullptr));
        lblBalance->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        lblCount->setText(QCoreApplication::translate("MainWindow", "0 transactions", nullptr));
        totalCatTitle->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        totalCardValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        mostUsedTitle->setText(QCoreApplication::translate("MainWindow", "Most Used", nullptr));
        mostUsedCardValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        unusedTitle->setText(QCoreApplication::translate("MainWindow", "Unused", nullptr));
        unusedCardValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        categoryNameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Category name...", nullptr));
        categoryTypeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "expense", nullptr));
        categoryTypeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "income", nullptr));

        setBudgetBtn->setText(QCoreApplication::translate("MainWindow", "Set Budget", nullptr));
        addCategoryBtn->setText(QCoreApplication::translate("MainWindow", "+ Add Category", nullptr));
        deleteCategoryBtn->setText(QCoreApplication::translate("MainWindow", "Delete Selected", nullptr));
        analyticsMonthLabel->setText(QCoreApplication::translate("MainWindow", "Analytics \342\200\224 Current Month", nullptr));
        profileTitle->setText(QCoreApplication::translate("MainWindow", "Profile Settings", nullptr));
        profileUsernameLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        profileCurrentPassLabel->setText(QCoreApplication::translate("MainWindow", "Current Password", nullptr));
        profileCurrentPassEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter current password...", nullptr));
        profileNewPassLabel->setText(QCoreApplication::translate("MainWindow", "New Password", nullptr));
        profileNewPassEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter new password...", nullptr));
        profileConfirmPassLabel->setText(QCoreApplication::translate("MainWindow", "Confirm New Password", nullptr));
        profileConfirmPassEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Confirm new password...", nullptr));
        profileErrorLabel->setText(QString());
        profileSaveBtn->setText(QCoreApplication::translate("MainWindow", "Save Changes", nullptr));
        backupSectionLabel->setText(QCoreApplication::translate("MainWindow", "Database Backup", nullptr));
        backupBtn->setText(QCoreApplication::translate("MainWindow", "Export Backup", nullptr));
        restoreBtn->setText(QCoreApplication::translate("MainWindow", "Restore Backup", nullptr));
        currencySectionLabel->setText(QCoreApplication::translate("MainWindow", "Display Currency", nullptr));
        saveCurrencyBtn->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        recurringTitle->setText(QCoreApplication::translate("MainWindow", "Recurring Transactions", nullptr));
        addRecurringBtn->setText(QCoreApplication::translate("MainWindow", "+ Add Recurring", nullptr));
        deleteRecurringBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        toggleRecurringBtn->setText(QCoreApplication::translate("MainWindow", "Pause / Resume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
