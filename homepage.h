#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "pushbutton.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QTimer>
class HomePage : public QWidget
{
    Q_OBJECT
    QLabel *logo;
    QLabel *footer;
    QLabel *error;

    QStackedWidget *loginSignup;
    QWidget *currentForm;    
    QLineEdit *username;
    QLineEdit *password;

    QWidget *signupForm;

    QLineEdit *firstName = nullptr;
    QLineEdit *lastName = nullptr;
    QLineEdit *userId = nullptr;
    QLineEdit *email = nullptr;
    QLineEdit *phone= nullptr;
    QLineEdit *passwordOfSign=nullptr;

    QGridLayout *homePage;
public:
    pushButton *login;
    explicit HomePage(QWidget *parent = nullptr);
    QWidget *createSignup();
    QWidget *createHome();
    void changeStacked();
    void setHome();
    void changeParent();
    void clearUserLogin();
    void setError(QString errorMsg);
    void getLoginDetails();
    void getSignupDetails();
signals:
    void sendUser(QString user, QString pass);
    void sendNewUser(const QString data[]);

public slots:
    void clearError();
};

#endif // HOMEPAGE_H
