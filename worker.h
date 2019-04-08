#pragma once
#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "pushbutton.h"

class Worker : public QWidget
{
    Q_OBJECT

    QLabel *img;
    QLineEdit *name;
    QLineEdit *companyId;
    QLineEdit *salary;
    QLineEdit *email;
    QLineEdit *phone;
    QLineEdit *address;
    pushButton *delet;
    pushButton *edit;

public:
    explicit Worker(QWidget *parent = nullptr);
    void setData(QString *data);

signals:

public slots:
};
