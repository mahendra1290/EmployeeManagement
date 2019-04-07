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
    mainPage->addTab(companyProfile, "company profile");
    mainPage->addTab(employeeProfile, "employee");
    mainLayout->addWidget(mainPage);
    mainPage->setCurrentIndex(0);
}

QWidget *employee::createCompanyPage(){
    QGridLayout *mainLayout = new QGridLayout();
    QWidget *company = new QWidget();
    QLineEdit **input[] = {
        &compName, &regis, &address,
        &city, &state, &country, &postal,
        &email, &phone, &fax};
    for(int i=0; i<10; i++){
        *input[i] = new QLineEdit();
    }
    QString labelName[10] = {
        "company name", "regis no.", "address","city",
        "state", "country", "postal code", "email",
        "phone" , "fax"
    };
    QLabel *labels[10];
    for(int i=0; i<10; i++){
        labels[i] = new QLabel();
        labels[i]->setText(labelName[i]);
    }
    mainLayout->addWidget(labels[0], 0 , 0);
    mainLayout->addWidget(*input[0], 0, 1);
    mainLayout->addWidget(labels[1], 0 , 2);
    mainLayout->addWidget(*input[1], 0, 3);

    mainLayout->addWidget(labels[2], 1 , 0);
    mainLayout->addWidget(*input[2], 1, 1, 1, 3);

    mainLayout->addWidget(labels[3], 2 , 0);
    mainLayout->addWidget(*input[3], 2, 1);
    mainLayout->addWidget(labels[4], 2 , 2);
    mainLayout->addWidget(*input[4], 2, 3);

    mainLayout->addWidget(labels[5], 3 , 0);
    mainLayout->addWidget(*input[5], 3, 1);
    mainLayout->addWidget(labels[6], 3 , 2);
    mainLayout->addWidget(*input[6], 3, 3);

    mainLayout->addWidget(labels[7], 4 , 0);
    mainLayout->addWidget(*input[7], 4, 1, 1, 3);

    mainLayout->addWidget(labels[8], 5 , 0);
    mainLayout->addWidget(*input[8], 5, 1);
    mainLayout->addWidget(labels[9], 5 , 2);
    mainLayout->addWidget(*input[9], 5, 3);

    company->setLayout(mainLayout);

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

void employee::setUser(QString user){
    this->setWindowTitle(user);
}


