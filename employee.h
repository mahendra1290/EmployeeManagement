#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QWidget>
#include <QTabWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
class employee : public QWidget
{
    Q_OBJECT
    QTabWidget *mainPage;
    QVBoxLayout *layout;
    QVBoxLayout *mainLayout;
    QString *user;
    QWidget *companyProfile;

    QLineEdit *compName;
    QLineEdit *regis;
    QLineEdit *address;
    QLineEdit *city;
    QLineEdit *state;
    QLineEdit *country;
    QLineEdit *postal;
    QLineEdit *email;
    QLineEdit *phone;
    QLineEdit *fax;

    QWidget *employeeProfile;

public:    
    explicit employee(QWidget *parent = nullptr);
    QWidget *createCompanyPage();
    QWidget *createEmployeePage();
    void setUser(QString user);
signals:

public slots:

};

#endif // EMPLOYEE_H
