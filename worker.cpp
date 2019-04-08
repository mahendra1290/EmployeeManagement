#include "worker.h"
#include <QPixmap>
Worker::Worker(QWidget *parent) : QWidget(parent)
{
    QPixmap *prof  = new QPixmap("/home/maahi/wagemanage/prof.png");
    *prof = prof->scaled(180, 180, Qt::KeepAspectRatio);
    QGridLayout *layout = new QGridLayout();
    img = new QLabel();
    img->setPixmap(*prof);
    delet = new pushButton("delete");
    edit = new pushButton("edit");
    QLineEdit **list[6] = {&name, &companyId,
                        &salary, &email,
                        &phone, &address};
    QString labelName[] = {"name", "id", "salary",
                         "email", "phone", "address"};
    QLabel *labels [] = {nullptr ,nullptr, nullptr, nullptr, nullptr, nullptr};
    for(int i=0; i<6; i++){
        labels[i] = new QLabel();
        labels[i]->setText(labelName[i]);
    }
    for(int i=0; i<6; i++){
        *list[i] = new QLineEdit();
    }

    layout->addWidget(img, 0, 0, 6, 1);

    layout->addWidget(labels[0], 0, 1);
    layout->addWidget(*list[0], 0, 2, 1, 3);

    layout->addWidget(labels[1], 1, 1);
    layout->addWidget(*list[1], 1, 2);
    layout->addWidget(labels[2], 1, 3);
    layout->addWidget(*list[2], 1, 4);

    layout->addWidget(labels[3], 2, 1);
    layout->addWidget(*list[3], 2, 2, 1, 3);

    layout->addWidget(labels[4], 3, 1);
    layout->addWidget(*list[4], 3, 2, 1, 3);

    layout->addWidget(labels[5], 4, 1);
    layout->addWidget(*list[5], 4, 2, 1, 3);

    layout->addWidget(edit, 5, 1, 1, 2);
    layout->addWidget(delet, 5, 3, 1, 2);
    this->setLayout(layout);
}

void Worker::setData(QString *data){
    QLineEdit **list[6] = {&name, &companyId,
                        &salary, &email,
                        &phone, &address};
    for(int i=0; i<6; i++){
        (*list[i])->setText(data[i]);
    }
}
