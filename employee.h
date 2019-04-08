#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QWidget>
#include <QTabWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "worker.h"
#include "pushbutton.h"

class employee : public QWidget
{
    Q_OBJECT
    Worker *emp;
    Worker *emp_1;

    QTabWidget *mainPage;
    QVBoxLayout *layout;
    QVBoxLayout *mainLayout;
    QString *user;
    QWidget *companyProfile;

    QString *company;

    QLineEdit *compName = nullptr;
    QLineEdit *regis  = nullptr;
    QLineEdit *address= nullptr;
    QLineEdit *city   = nullptr;
    QLineEdit *state  = nullptr;
    QLineEdit *country= nullptr;
    QLineEdit *postal = nullptr;
    QLineEdit *email  = nullptr;
    QLineEdit *phone  = nullptr;
    QLineEdit *fax    = nullptr;

    pushButton *edit = nullptr;
    pushButton *save = nullptr;
    pushButton *cancel = nullptr;

    QLineEdit **input[10] = {
        &compName, &regis, &address,
        &city, &state, &country, &postal,
        &email, &phone, &fax};

    QWidget *employeeProfile;

public:    
    explicit employee(QWidget *parent = nullptr);
    QWidget *createCompanyPage();
    QWidget *createEmployeePage();
    void setUser(QString user);
    void enableCompanyEdit(bool on);
    void setCompanyDetails(QString data[]);
signals:

public slots:
    void editCompanyDetails();
    void saveCompanyDetails();
    void cancelCompanyEdit();
};

#endif // EMPLOYEE_H
