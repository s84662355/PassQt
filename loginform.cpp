#include "loginform.h"
#include "ui_loginform.h"
#include "http/http.h"
LoginForm::LoginForm(QWidget *parent) :
    MyQtWight(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    this->setMaximumSize (280,400);
    this->setMinimumSize (280,400);
    QObject *qmlObj=  ui->quickWidget->rootObject ();
    connect(qmlObj, SIGNAL(sendClose()),this,SLOT(getClose()));
    connect(qmlObj,SIGNAL(sendLogin(QString,QString )),this,SLOT(getLogin(QString,QString)));
    connect(this,SIGNAL(isLoginFunc( QVariant  , QVariant )),qmlObj,SLOT(isLoginFunc(QVariant,QVariant )));

/*
    HttpReply *reply1 =  Http::instance().get(QUrl("https://www.dy2018.com/d/file/html/gndy/dyzz/2021-02-05/91c62ff48db75077056abe624cad1cb6.jpg"));
    connect(reply1,&HttpReply::finished, this,  []( const HttpReply &reply1) {
        if (reply1.isSuccessful()) {
             qDebug() << "Feel the bytes!" << reply1.body();
        } else {
          qDebug() << "Something's wrong here" << reply1.statusCode() << reply1.reasonPhrase();
        }
    });
*/
}

//public槽函数可以在QML中访问
void LoginForm::getClose()
{
    qDebug()<<"getClose";
    this->close ();
}

void LoginForm::getLogin(QString username,QString password)
{
    qDebug()<<username+"  ----  "+password;
    emit isLoginFunc( 23432,"fdgdfgf");
}


LoginForm::~LoginForm()
{
    delete ui;
}
