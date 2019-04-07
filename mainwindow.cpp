#include "mainwindow.h"
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    data = new QString[10];
    database = new Database("/home/maahi/wagemanage/develop.db");
    QWidget *main = new QWidget();
    this->setCentralWidget(main);
    home = new HomePage();
    user = "";
    companyId = "";
    //QWidget *employee = new QWidget();
    //QLabel *emp = new QLabel("employee", comp);
    connect(home, &HomePage::sendUser, this, &MainWindow::getUser);
    connect(home, &HomePage::sendNewUser, this, &MainWindow::getNewUser);
    mainLayout = new QStackedLayout();
    mainLayout->addWidget(home);
    //mainLayout->addWidget(comp);
    mainLayout->setCurrentIndex(0);
    main->setLayout(mainLayout);
}

void MainWindow::getUser(QString user, QString pass){
    const QString userData[] = {user, pass};
    if(database->validateUser(userData, user, companyId)){
        database->getCompanyDetails(companyId, data);
        for(int i=0; i<10; i++){
            qDebug()<<data[i];
        }
        comp = new employee();
        //QString data[] = {""};
        comp->setCompanyDetails(data);
        mainLayout->addWidget(comp);
        mainLayout->setCurrentIndex(1);
        this->setWindowTitle(user);
    }
    else{
        home->clearUserLogin();
        home->setError("username or \npassword incorrect");
    }
}

void MainWindow::getNewUser(const QString data[]){
    database->addNewUser(data);
   // QString compdata[] = {"dfs", "fdsf", "fds", "df", "fds", "fdf",
        //                 "dsg", "dgsa", "grgr", "fegr", "vin"};
    //database->addCompanyDetails(compdata);
}
MainWindow::~MainWindow()
{

}
