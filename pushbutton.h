#pragma once
#include <QPushButton>

class pushButton : public QPushButton
{
    Q_OBJECT
    QPushButton *btn;
    static QString style;
public:
    explicit pushButton(const QString &text, QWidget *parent = nullptr);
    void updateStyle();
    static void setStyle(const QString &newStyle){
        style = newStyle;
    }
};

