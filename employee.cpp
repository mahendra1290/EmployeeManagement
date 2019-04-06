#include "employee.h"
#include <QDebug>
employee::employee(QWidget *parent) : QWidget(parent)
{
    user = new QString();
    mainLayout = new QVBoxLayout();
    mainPage = new QTabWidget(this);
    companyProfile = createCompanyPage();
    employeeProfile = createEmployeePage();
    this->setLayout(mainLayout);
    mainPage->addTab(companyProfile, "company");
    mainPage->addTab(employeeProfile, "employee");
    mainLayout->addWidget(mainPage);
    mainPage->setCurrentIndex(0);
}

QWidget *employee::createCompanyPage(){
    layout = new QVBoxLayout();
    QWidget *company = new QWidget();
    QLabel *hlo = new QLabel(*user);
    QLineEdit *name = new QLineEdit();
    layout->addWidget(hlo);
    layout->addWidget(name);
    company->setLayout(layout);
    return company;
}

QWidget *employee::createEmployeePage(){
    layout = new QVBoxLayout();
    QWidget *company = new QWidget();
    QLabel *hlo = new QLabel("employee page");
    QLineEdit *name = new QLineEdit();
    layout->addWidget(hlo);
    layout->addWidget(name);
    company->setLayout(layout);
    return company;
}


