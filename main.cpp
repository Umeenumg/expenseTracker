#include <QApplication>
#include <QFile>
#include "database/DatabaseManager.h"
#include "ui/LoginWindow.h"

QSqlDatabase g_db;
DatabaseManager *g_dbManager = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        a.setStyleSheet(QString::fromUtf8(styleFile.readAll()));
        styleFile.close();
    }

    DatabaseManager dbManager;
    g_dbManager = &dbManager;

    if (!dbManager.openDatabase()) {
        return -1;
    }

    g_db = dbManager.getDatabase();

    LoginWindow login;
    login.show();

    return a.exec();
}
