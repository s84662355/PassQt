#ifndef MAINFORM_H
#define MAINFORM_H


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
#include <QtWidgets/QHBoxLayout>
#include <mainleftform.h>
#include "mainhuihuaform.h"
#include "mainwicketform.h"
namespace Ui {
class MainForm;
}

class MainForm : public MyQtWight
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

protected:


private:
    void initMainLeftForm();
    void initMainHuiHuaForm();
    void initMainWicketForm();

private:
    Ui::MainForm *ui;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_1;
    MainLeftForm *mainLeftForm;
    MainHuiHuaForm *mainHuiHuaForm;
    MainWicketForm *mainWicketForm;
};

#endif // MAINFORM_H
