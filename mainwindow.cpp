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
    database = new Database("/home/maahi/wagemanage/develop.db");
    QWidget *main = new QWidget();
    this->setCentralWidget(main);
    home = new HomePage();
    comp = new employee();
    //QWidget *employee = new QWidget();
    //QLabel *emp = new QLabel("employee", comp);
    connect(home, &HomePage::sendUser, this, &MainWindow::getUser);
    connect(home, &HomePage::sendNewUser, this, &MainWindow::getNewUser);
    mainLayout = new QStackedLayout();
    mainLayout->addWidget(home);
    mainLayout->addWidget(comp);
    mainLayout->setCurrentIndex(0);
    main->setLayout(mainLayout);
}

void MainWindow::getUser(QString user, QString pass){
    const QString userData[] = {user, pass};
    if(database->validateUser(userData)){
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
}
MainWindow::~MainWindow()
{

}
