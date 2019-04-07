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

bool Database::addNewUser(const QString data[]){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, last_name, user_id, "
                  "email, phone, password) VALUES (:fname, :lname, "
                  ":userid, :email, :phone,:pass)");
    query.bindValue(":fname", data[0]);
    query.bindValue(":lname", data[1]);
    query.bindValue(":userid",data[2]);
    query.bindValue(":email", data[3]);
    query.bindValue(":phone", data[4]);
    query.bindValue(":pass",  data[5]);
    if(query.exec()){
       success = true;
    }
    else{
        qDebug() << "add user error:  "
                 << query.lastError();
    }
    return success;
}

bool Database::validateUser(const QString *data){
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT user_id, password FROM users WHERE user_id=:userid");
    query.bindValue(":userid", data[0]);
    if(query.exec()){
        success = true;
    }
    if(query.first()){
        success = true;
        qDebug()<<query.value(1);
    }
    else{
        qDebug()<<query.first();
        qDebug()<<"cant login"
                <<query.lastError();
        success = false;
    }

    return success;
}
