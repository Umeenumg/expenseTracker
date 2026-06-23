cmake_minimum_required(VERSION 3.16)
project(ExpensesTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)
qt_standard_project_setup()

qt_add_executable(ExpensesTracker

    # ── MAIN ──────────────────────────────
    main.cpp


    # ── RESSOURCES ──────────────────────────────

    resources/resources.qrc

    # ── MAIN WINDOW ───────────────────────
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui

    # ── DATABASE ──────────────────────────
    database/DatabaseManager.h
    database/DatabaseManager.cpp

    # ── MODELS ────────────────────────────
    models/User.h
    models/User.cpp
    models/Transaction.h
    models/Transaction.cpp
    models/Category.h
    models/Category.cpp

    # ── SERVICES ──────────────────────────
    services/UserService.h
    services/UserService.cpp
    services/TransactionService.h
    services/TransactionService.cpp
    services/CategoryService.h
    services/CategoryService.cpp

    # ── CORE ──────────────────────────────
    core/Session.h
    core/Session.cpp
    core/Security.h

    # ── UI WINDOWS ────────────────────────
    ui/LoginWindow.h
    ui/LoginWindow.cpp
    ui/LoginWindow.ui
    ui/RegisterWindow.h
    ui/RegisterWindow.cpp
    ui/RegisterWindow.ui
    ui/AddTransactionDialog.h
    ui/AddTransactionDialog.cpp
    ui/AddTransactionDialog.ui
    ui/BarChartWidget.h ui/BarChartWidget.cpp
    ui/PieChartWidget.h ui/PieChartWidget.cpp
    ui/LineChartWidget.h ui/LineChartWidget.cpp
    ui/BarChartWidget.h
    ui/BarChartWidget.cpp
    ui/PieChartWidget.h
    ui/PieChartWidget.cpp
    ui/LineChartWidget.h
    ui/LineChartWidget.cpp
    ui/TransactionNotesDialog.h ui/TransactionNotesDialog.cpp
    ui/BudgetDialog.h ui/BudgetDialog.cpp
    models/RecurringTransaction.h models/RecurringTransaction.cpp
    services/recurringtransactionservice.h services/recurringtransactionservice.cpp
    ui/AddRecurringDialog.ui
    ui/AddRecurringDialog.h ui/AddRecurringDialog.cpp
    core/currency.h core/currency.cpp
    services/UserSettingsService.h services/UserSettingsService.cpp


)


# ── INCLUDE PATHS ─────────────────────────
target_include_directories(ExpensesTracker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ExpensesTracker PRIVATE
    Qt6::Widgets
    Qt6::Sql
)
