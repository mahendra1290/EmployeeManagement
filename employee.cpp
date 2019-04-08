#include "employee.h"
#include <QDebug>
#include <QScrollArea>
employee::employee(QWidget *parent) : QWidget(parent)
{
    QWidget *top = new QWidget();
    QHBoxLayout *topLayout = new QHBoxLayout();
    QLabel *u = new QLabel("username");
    QLabel *add = new QLabel("add worker");
    QLabel *find = new QLabel("find worker");
    QLabel *remove = new QLabel("remove worker");
    topLayout->addWidget(u);
    topLayout->addWidget(add);
    topLayout->addWidget(find);
    topLayout->addWidget(remove);
    top->setLayout(topLayout);
    user = new QString();
    mainLayout = new QVBoxLayout();
    mainPage = new QTabWidget(this);
    companyProfile = createCompanyPage();
    employeeProfile = createEmployeePage();
    this->setLayout(mainLayout);
    mainPage->addTab(companyProfile, "company profile");
    mainPage->addTab(employeeProfile, "employee");
    mainLayout->addWidget(top);
    mainLayout->addWidget(mainPage);
    mainPage->setCurrentIndex(0);
    //area->setWidget(mainPage);
    enableCompanyEdit(false);
}

QWidget *employee::createCompanyPage(){

    //QScrollArea *area = new QScrollArea();
    company = new QString[10];
    QGridLayout *mainLayout = new QGridLayout();
    QHBoxLayout *btnlayout = new QHBoxLayout();
    QWidget *company = new QWidget();
    edit = new pushButton("update");
    edit->setMaximumWidth(100);
    save = new pushButton("save");
    save->setMaximumWidth(100);
    cancel = new pushButton("cancel");
    cancel->setMaximumWidth(100);
    connect(edit, &QPushButton::clicked, this, &employee::editCompanyDetails);
    connect(save, &QPushButton::clicked, this, &employee::saveCompanyDetails);
    connect(cancel, &QPushButton::clicked, this, &employee::cancelCompanyEdit);
    btnlayout->addWidget(edit, Qt::AlignLeft);
    btnlayout->addWidget(save, Qt::AlignLeft);
    btnlayout->addWidget(cancel, Qt::AlignLeft);

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

    mainLayout->addLayout(btnlayout, 6, 0, 1, 2, Qt::AlignLeft);
    company->setLayout(mainLayout);
    //area->setWidget(company);
    return company;
}

QWidget *employee::createEmployeePage(){
    emp = new Worker();
    emp_1 = new Worker();
    Worker *emp_2 = new Worker();
    layout = new QVBoxLayout();
    QWidget *company = new QWidget();
    layout->addWidget(emp);
    layout->addWidget(emp_1);
    layout->addWidget(emp_2);
    company->setLayout(layout);
    return company;
}

void employee::setUser(QString user){
    this->setWindowTitle(user);
}


void employee::enableCompanyEdit(bool on){
    for(int i=0; i<10; i++){
        (*input[i])->setReadOnly(!on);
    }
    edit->setVisible(!on);
    save->setVisible(on);
    cancel->setVisible(on);
}

void employee::editCompanyDetails(){
    enableCompanyEdit(true);
    for(int i=0; i<10; i++){
        company[i] = (*input[i])->text();
    }
}

void employee::saveCompanyDetails(){
    enableCompanyEdit(false);
}

void employee::cancelCompanyEdit(){
    for(int i=0; i<10; i++){
        (*input[i])->setText(company[i]);
        company[i] = "";
    }
    enableCompanyEdit(false);
}

void employee::setCompanyDetails(QString *data){
    enableCompanyEdit(true);
    for(int i=0; i<10; i++){
        (*input[i])->setText(data[i]);
    }
    enableCompanyEdit(false);
}

