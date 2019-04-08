#include "homepage.h"
#include <QPixmap>
#include <QFont>
#include <QDebug>
HomePage::HomePage(QWidget *parent) : QWidget(parent)
{

    mainLayout = new QVBoxLayout();
    middle = new QGridLayout();
    loginSignup = new QStackedWidget();
    currentForm = createHome();
    signupForm  = createSignup();
    //signupForm->setMinimumSize(200, 200);
    QFont font;
    font.setPointSize(30);
    font.setBold(true);

    logo = new QLabel();
    footer = new QLabel();

    footer->setText("all right reserved ");
    footer->setMaximumHeight(60);
    logo->setText(" MAROON \nSOLUTIONS\n");
    logo->setWordWrap(true);
    logo->setFont(font);
    loginSignup->addWidget(currentForm);
    loginSignup->addWidget(signupForm);
    loginSignup->setCurrentIndex(0);
    middle->addWidget(logo, 0, 0, Qt::AlignCenter);
    middle->addWidget(loginSignup, 0, 1, Qt::AlignCenter);
    mainLayout->addLayout(middle, Qt::AlignCenter);
    mainLayout->addWidget(footer, Qt::AlignCenter);
    setLayout(mainLayout);
}

QWidget *HomePage::createHome(){
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *home = new QWidget;
    username = new QLineEdit();
    username->setPlaceholderText("username");
    password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText("password");
    login = new pushButton("login");
    pushButton *signup = new pushButton("signup");
    connect(login,  &pushButton::clicked, this, &HomePage::getLoginDetails);
    connect(signup, &pushButton::clicked, this, &HomePage::changeStacked);
    layout->addWidget(username);
    layout->addWidget(password);
    layout->addWidget(login);
    layout->addWidget(signup);
    error = new QLabel();
    layout->addWidget(error);
    home->setLayout(layout);
    home->setStyleSheet("QLineEdit{"
                        "height:27px;"
                        "}");
    return home;
}

QWidget *HomePage::createSignup(){
    QGridLayout *layout = new QGridLayout;
    QWidget *sign = new QWidget;
    QString placeHolder[7] = {"first name", "last name",
                            "user id", "email", "phone",
                            "password", "company_id"};
    QLineEdit **list[7] = {&firstName, &lastName,
                        &userId, &email,
                        &phone, &passwordOfSign, &companyId};
    for(int i=0; i<7; i++){
        *(list[i]) = new QLineEdit();
        (*(list[i]))->setPlaceholderText(placeHolder[i]);
    }
    pushButton *cancel = new pushButton("cancel");
    pushButton *create = new pushButton("create");
    connect(create, &QPushButton::clicked, this, &HomePage::getSignupDetails);
    connect(cancel, &QPushButton::clicked, this, &HomePage::setHome);
    layout->addWidget(*list[0], 0, 0);
    layout->addWidget(*list[1], 0, 1);
    layout->addWidget(*list[2], 1, 0, 1, 2);
    layout->addWidget(*list[3], 2, 0, 1, 2);
    layout->addWidget(*list[4], 3, 0, 1, 2);
    layout->addWidget(*list[5], 4, 0, 1, 2);
    layout->addWidget(*list[6], 5, 0, 1, 2);
    layout->addWidget(create, 6, 0);
    layout->addWidget(cancel, 6, 1);
    sign->setLayout(layout);
    sign->setStyleSheet("QLineEdit{"
                        "height:24px;"
                        "}");
    return sign;
}

void HomePage::changeStacked(){
    loginSignup->setCurrentIndex(1);
}

void HomePage::setHome(){
    loginSignup->setCurrentIndex(0);
}

void HomePage::getLoginDetails(){
    QString user = username->text();
    QString pass = password->text();
    if(user != "" && pass != "")
        emit sendUser(user, pass);
    else if(user == "")
        qDebug()<<"username must be filled";
    else {
        qDebug()<<"password must be entered";
    }
}

void HomePage::clearUserLogin(){
    username->setText("");
    password->setText("");
}

void HomePage::setError(QString errorMsg){
    error->setText(errorMsg);
    error->setWordWrap(true);
    QTimer::singleShot(5000, this ,SLOT(clearError()));
}

void HomePage::clearError(){
    error->setText("");
}

void HomePage::getSignupDetails(){
    const QString f = firstName->text();
    const QString l = lastName->text();
    const QString u = userId->text();
    const QString e = email->text();
    const QString p = phone->text();
    const QString ps = passwordOfSign->text();
    const QString ci = companyId->text();
    const QString data[] = {f, l, u, e, p, ps, ci};
    loginSignup->setCurrentIndex(0);
    emit sendNewUser(data);
}
