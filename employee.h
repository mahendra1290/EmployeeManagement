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
    QWidget *employeeProfile;
public:    
    explicit employee(QWidget *parent = nullptr);
    QWidget *createCompanyPage();
    QWidget *createEmployeePage();
signals:

public slots:

};

#endif // EMPLOYEE_H
