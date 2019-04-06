#include "database.h"

Database::Database(const QString path){
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);
   if (!m_db.open()){
      qDebug() << "Error: connection with database fail";
   }
   else{
      qDebug() << "Database: connection ok";
   }
}

bool Database::addNewUser(const QString user, const QString pass){
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT username ,password FROM users WHERE username=:usern AND"
                  " password=:passn");
    //qDebug()<<user<<pass;
    query.bindValue(":usern", user);
    query.bindValue(":passn", pass);
    if(query.exec()){
       success = true;
    }
    else{
        qDebug() << "addPerson error:  "
                 << query.lastError();
    }
    if(query.next()){
        qDebug() <<"got it";
        qDebug()<<query.value(1);
    }
    else{
        qDebug()<<"no"<< query.lastError();
    }
    return success;
}
