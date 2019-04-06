#include "homepage.h"
#include <QPixmap>

HomePage::HomePage(QWidget *parent) : QWidget(parent)
{
    homePage = new QGridLayout();
    loginSignup = new QStackedWidget();
    currentForm = createHome();
    signupForm  = createSignup();
    signupForm->setMinimumSize(200, 200);
    logo = new QLabel("MAROON SOLUTIONS");
    logo->setText("MAROON SOLUTIONS");
    loginSignup->addWidget(currentForm);
    loginSignup->addWidget(signupForm);
    loginSignup->setCurrentIndex(0);
    homePage->addWidget(logo, 0, 0, Qt::AlignCenter);
    homePage->addWidget(loginSignup , 0, 1, Qt::AlignCenter);
    setLayout(homePage);
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
    connect(login,  &pushButton::clicked, this, &HomePage::getDetails);
    connect(signup, &pushButton::clicked, this, &HomePage::changeStacked);
    layout->addWidget(username);
    layout->addWidget(password);
    layout->addWidget(login);
    layout->addWidget(signup);
    home->setLayout(layout);
    home->setStyleSheet("QLineEdit{"
                        "height:27px;"
                        "}");
    return home;
}

QWidget *HomePage::createSignup(){
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *sign = new QWidget;
    email = new QLineEdit();
    email->setPlaceholderText("email");
    usernameSign = new QLineEdit();
    usernameSign->setPlaceholderText("username");
    passwordSign = new QLineEdit();
    passwordSign->setPlaceholderText("password");
    confpasswordSign = new QLineEdit();
    confpasswordSign->setPlaceholderText("confirm password");
    pushButton *cancel = new pushButton("cancel");
    pushButton *create = new pushButton("create");
    connect(cancel, &QPushButton::clicked, this, &HomePage::setHome);
    layout->addWidget(email);
    layout->addWidget(usernameSign);
    layout->addWidget(passwordSign);
    layout->addWidget(confpasswordSign);
    layout->addWidget(cancel);
    layout->addWidget(create);
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
void HomePage::getDetails(){
    QString user = username->text();
    QString pass = password->text();
    emit sendUserDetails(user, pass);
}

