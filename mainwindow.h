#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pushbutton.h"
#include <QStackedLayout>
#include "homepage.h"
#include "employee.h"
#include <QDebug>
#include "database.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString user;
    QString *data;
    QString companyId;
    Database *database;
    employee *comp;
    HomePage *home;
    QStackedLayout *mainLayout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
     void getUser(QString user, QString pass);
     void getNewUser(const QString data[]);
};

#endif // MAINWINDOW_H
