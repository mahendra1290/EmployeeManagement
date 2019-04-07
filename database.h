#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "homepage.h"

class Database
{
    QSqlDatabase m_db;
public:
    Database(const QString path);
    bool addNewUser(const QString data[]);
    bool validateUser(const QString data[]);
};

#endif // DATABASE_H
