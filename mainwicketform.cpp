#include "mainwicketform.h"
#include "ui_mainwicketform.h"

MainWicketForm::MainWicketForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWicketForm)
{
    ui->setupUi(this);
    setMouseTracking(true);
    // ui->windowTopWidget->
    //  ui->windowTopWidget

    connect(ui->windowTopWidget,SIGNAL(sendClose( )),this, SLOT(getClose()));
    connect(ui->windowTopWidget,SIGNAL(sendSmall( )),this, SLOT(getSmall()));
}


void MainWicketForm::getClose()
{
    qDebug()<<" connect(ui->windowTopWidget,SIGNAL(sendClose( )),this, SLOT(getClose())) ";
    emit sendClose();
}

void MainWicketForm::getSmall()
{
    qDebug()<<" connect(ui->windowTopWidget,SIGNAL(sendSmall( )),this, SLOT(getSmall()))";
    emit sendSmall();
}

MainWicketForm::~MainWicketForm()
{
    delete ui;
}
