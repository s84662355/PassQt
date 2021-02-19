#include "mainhuihuaform.h"
#include "ui_mainhuihuaform.h"

MainHuiHuaForm::MainHuiHuaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainHuiHuaForm)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

MainHuiHuaForm::~MainHuiHuaForm()
{
    delete ui;
}
