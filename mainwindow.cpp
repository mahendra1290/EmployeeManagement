#include "mainwindow.h"
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *main = new QWidget();
    this->setCentralWidget(main);
    home = new HomePage();
    comp = new employee();
    //QWidget *employee = new QWidget();
    //QLabel *emp = new QLabel("employee", comp);
    connect(home, &HomePage::sendUserDetails, this, &MainWindow::getUser);
    mainLayout = new QStackedLayout();
    mainLayout->addWidget(home);
    mainLayout->addWidget(comp);
    mainLayout->setCurrentIndex(0);
    main->setLayout(mainLayout);
}

void MainWindow::getUser(QString user, QString pass){
     mainLayout->setCurrentIndex(1);
     qDebug()<<user;
     qDebug()<<pass;
}
MainWindow::~MainWindow()
{

}
