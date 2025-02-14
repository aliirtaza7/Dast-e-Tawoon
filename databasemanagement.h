#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QSqlError>

class Databasemanagement
{
public:
    Databasemanagement();
    ~Databasemanagement();
    bool connectToDatabase();
private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGEMENT_H
extern QString username;
