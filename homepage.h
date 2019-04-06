#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "pushbutton.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QGridLayout>
#include <QVBoxLayout>

class HomePage : public QWidget
{
    Q_OBJECT
    QLabel *logo;
    QLabel *footer;

    QStackedWidget *loginSignup;
    QWidget *currentForm;    
    QLineEdit *username;
    QLineEdit *password;

    QWidget *signupForm;
    QLineEdit *email;
    QLineEdit *usernameSign;
    QLineEdit *passwordSign;
    QLineEdit *confpasswordSign;

    QGridLayout *homePage;
public:
    pushButton *login;
    explicit HomePage(QWidget *parent = nullptr);
    QWidget *createSignup();
    QWidget *createHome();
    void changeStacked();
    void setHome();
    void changeParent();
    void getDetails();
signals:
    void sendUserDetails(QString user, QString pass);

public slots:
};

#endif // HOMEPAGE_H
