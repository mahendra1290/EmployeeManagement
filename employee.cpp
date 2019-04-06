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
    QGridLayout *mainLayout = new QGridLayout();
    QWidget *company = new QWidget();
    QLabel *compName = new QLabel("company name");
    QLineEdit *comp_name = new QLineEdit();
    QLabel *gstIn = new QLabel("GSTIN");
    QLineEdit *gst_in = new QLineEdit();
    QLabel *regis = new QLabel("regitration no.");
    QLineEdit *regiS = new QLineEdit();
    QLabel *state = new QLabel("state");
    QLineEdit *State = new QLineEdit();
    mainLayout->addWidget(compName, 0, 0);
    mainLayout->addWidget(comp_name, 0, 1);
    mainLayout->addWidget(gstIn, 0, 2);
    mainLayout->addWidget(gst_in, 0, 3);
    mainLayout->addWidget(regis, 1, 0);
    mainLayout->addWidget(regiS, 1, 1);
    mainLayout->addWidget(state, 1, 2);
    mainLayout->addWidget(State, 1, 3);
    company->setLayout(mainLayout);
    //QLabel *compName = new QLabel("company name");
    //QLineEdit *comp_name = new QLineEdit();
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


