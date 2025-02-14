#include "databasemanagement.h"
#include <QDebug>

Databasemanagement::Databasemanagement()
{
}
Databasemanagement::~Databasemanagement()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool Databasemanagement::connectToDatabase()
{
db = QSqlDatabase::addDatabase("QSQLITE"); // For SQLite
    db.setDatabaseName("C:/Users/hp/Desktop/DTE/needyperson.db"); // Path to your SQLite database
    if (!db.open()) {
        qDebug() << "Error: Could not connect to database" << db.lastError().text();
        return false;
    }
    return true;
}

