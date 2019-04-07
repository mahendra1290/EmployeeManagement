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
                  "email, phone, password, company_id) VALUES (:fname, :lname, "
                  ":userid, :email, :phone,:pass, :compid)");
    query.bindValue(":fname", data[0]);
    query.bindValue(":lname", data[1]);
    query.bindValue(":userid",data[2]);
    query.bindValue(":email", data[3]);
    query.bindValue(":phone", data[4]);
    query.bindValue(":pass",  data[5]);
    query.bindValue(":compid",  data[6]);
    if(query.exec()){
       success = true;
    }
    else{
        qDebug() << "add user error:  "
                 << query.lastError();
    }
    return success;
}

bool Database::addCompanyDetails(const QString *data){
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO companies (company_name, registration, address, "
                  "city, state, country, post, email, phone, fax, company_id) VALUES (:cname, :regis, "
                  ":address, :city, :state,:country, :post, :email, :phone, "
                  ":fax ,:c_id)");
    query.bindValue(":cname", data[0]);
    query.bindValue(":regis", data[1]);
    query.bindValue(":address",data[2]);
    query.bindValue(":city", data[3]);
    query.bindValue(":state", data[4]);
    query.bindValue(":country",  data[5]);
    query.bindValue(":post",  data[6]);
    query.bindValue(":email",  data[7]);
    query.bindValue(":phone",  data[8]);
    query.bindValue(":fax",  data[9]);
    query.bindValue(":c_id",  data[10]);
    if(query.exec()){
       success = true;
    }
    else{
        qDebug() << "add user error:  "
                 << query.lastError();
    }
    return success;
}

bool Database::validateUser(const QString *data, QString &username, QString &companyId){
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT user_id, password, company_id "
                  "FROM users WHERE user_id=:userid");
    query.bindValue(":userid", data[0]);
    if(query.exec()){
        success = true;
    }
    if(query.first()){
        success = true;
        username = query.value(0).toString();
        companyId = query.value(2).toString();
        qDebug()<<username<<" "<<companyId;
        qDebug()<<query.value(2);
    }
    else{
        qDebug()<<query.first();
        qDebug()<<"cant login"
                <<query.lastError();
        success = false;
    }

    return success;
}

bool Database::getCompanyDetails(QString compid, QString *data){
    bool success = false;
    QSqlQuery query;
    qDebug()<<"comp id is"<<compid;
    query.prepare("SELECT company_name, registration, address, "
                  "city, state, country, post, email, phone, fax FROM companies WHERE company_id = :compid");
    query.bindValue(":compid", compid);
    if(query.exec()){
        success = true;
    }
    if(query.first()){
        success = true;
        for(int i=0; i<10; i++){
            data[i] = query.value(i).toString();
        }
        qDebug()<<query.value(0);
    }
    else{
        qDebug()<<query.first();
        qDebug()<<"cant login"
                <<query.lastError();
        success = false;
    }

    return success;
}
