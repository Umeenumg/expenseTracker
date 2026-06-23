#include "ui/LoginWindow.h"
#include "database/DatabaseManager.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

QSqlDatabase g_db;
DatabaseManager *g_dbManager = nullptr;

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QFile styleFile(":/style.qss");
    qDebug() << "File exists:" << styleFile.exists();

 /*   if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        qDebug() << "Stylesheet length:" << styleSheet.length();
        app.setStyleSheet(styleSheet);
        styleFile.close();
    } else {
        qDebug() << "FAILED to open style.qss!";
    }
*/
    DatabaseManager dbManager;
    g_dbManager = &dbManager;
    if (!dbManager.openDatabase()) {
        return -1;
    }
    g_db = dbManager.getDatabase();

    LoginWindow login;
    login.show();
    return app.exec();
}
