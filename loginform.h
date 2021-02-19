#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include "widget/myqtwight.h"
#include <QQuickItem>
#include <QDebug>
#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueList>
#include <QJsonValueRef>
#include <QVariant>

namespace Ui {
class LoginForm;
}

class LoginForm : public MyQtWight
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    //信号可以在QML中访问
    void isLoginFunc(QVariant code , QVariant msg = "");

public slots:
    //public槽函数可以在QML中访问
    void getClose();
    void getLogin(QString username,QString password);




private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
