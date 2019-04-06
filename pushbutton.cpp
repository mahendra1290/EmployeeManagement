#include "pushbutton.h"

pushButton::pushButton(const QString &text, QWidget *parent)
{
    btn = new QPushButton(parent);
    this->setText(text);
    this->setStyleSheet(style);
}
QString pushButton::style = "pushButton{"
                                     "background-color:green;"
                                     "color:white;"
                                     "border:none;"
                                     "height:27px;"
                                     "}"
                                 "pushButton:hover{"
                                 "background-color:white;"
                                 "border:1px solid black;"
                                 "color:black;"
                                 "border-color:black"
                                 "}";
void pushButton::updateStyle(){
    btn->setStyleSheet(style);
}
