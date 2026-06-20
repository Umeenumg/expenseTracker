\# 💰 ExpenseTracker



A multi-user personal finance management desktop application built with \*\*Qt 6\*\* and \*\*C++\*\*, using \*\*SQLite\*\* for local data storage.



\## ✨ Features



\- 🔐 \*\*Multi-user support\*\* with secure SHA-256 password hashing

\- 💸 \*\*Transaction management\*\* — add, edit, delete income/expense entries with notes

\- 🏷️ \*\*Budget categories\*\* with configurable spending limits

\- 🔁 \*\*Recurring transactions\*\* (e.g. rent, subscriptions)

\- 🌍 \*\*Multi-currency support\*\* (15 currencies)

\- 📊 \*\*Custom analytics charts\*\* — bar, pie, and line charts built with `QPainter`

\- 📤 \*\*CSV export\*\* of transaction history

\- 💾 \*\*Database backup \& restore\*\*

\- ⚙️ \*\*Profile \& settings page\*\*



\## 🏗️ Architecture



The project follows a clean \*\*3-layer architecture\*\*:



```

Models   → Plain data structures (User, Transaction, Category, RecurringTransaction)

Services → Business logic (UserService, TransactionService, CategoryService, ...)

UI       → Qt Widgets (MainWindow, dialogs, custom chart widgets)

```



Other key components:

\- `DatabaseManager` — handles all SQLite operations via Qt SQL, including schema migrations

\- `Session` — static class holding the current logged-in user's runtime state

\- `Security` — SHA-256 password hashing utility



\## 🛠️ Tech Stack



| Component | Technology |

|---|---|

| Language | C++ |

| Framework | Qt 6 (Widgets, SQL) |

| Database | SQLite |

| Build system | CMake + Ninja |

| Compiler | MinGW 64-bit |

| Charts | Custom `QPainter`-based widgets |



\## 🚀 Getting Started



\### Prerequisites

\- Qt 6.10+ (with MinGW 64-bit kit)

\- CMake 3.16+

\- Qt Creator (recommended) or any CMake-compatible IDE



\### Build



```bash

git clone https://github.com/Umeenumg/expenseTracker.git

cd expenseTracker

mkdir build \&\& cd build

cmake ..

cmake --build .

```



Or simply open `CMakeLists.txt` in \*\*Qt Creator\*\* and run.



\### Run

Launch the compiled `ExpensesTracker.exe` (or equivalent on your OS). On first run, register a new user account to get started.



\## 📁 Project Structure



```

ExpensesTracker/

├── core/           # Session, currency, security utilities

├── database/       # DatabaseManager (SQLite layer)

├── models/         # Data models (User, Transaction, Category, RecurringTransaction)

├── services/       # Business logic layer

├── ui/             # Dialogs and custom chart widgets

├── resources/       # Stylesheets (QSS)

├── mainwindow.\*    # Main application window

└── main.cpp        # Entry point

```



\## 📌 Notes



\- UI styling (QSS) is embedded directly in `.ui` files rather than loaded externally.

\- Database schema changes are handled via additive migrations in `DatabaseManager::createTables()` to preserve existing user data.



\## 👤 Author



Imane — University academic project (Qt 6 / C++ desktop application)



\## 📄 License



This project is for educational purposes.

