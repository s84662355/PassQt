#include "windowtopwidget.h"
#include "ui_windowtopwidget.h"
#include <QQuickItem>
WindowTopWidget::WindowTopWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowTopWidget)
{
    ui->setupUi(this);
    setMouseTracking(true);
    /// ui->quickWidget->setMaximumHeight (this->height ()*0.95);
   ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse);

  //
   //ui->label->setMouseTracking (false);

    QQuickItem  *qQuickItem = ui->quickWidget->rootObject ();

    connect (qQuickItem,SIGNAL(close()),this,SLOT(getClose()));
    connect (qQuickItem,SIGNAL(small()),this,SLOT(getSmall()));

}

void WindowTopWidget::setLabel(QString text)
{
      ui->label->setText (text);
}

QString WindowTopWidget::getLabel()
{
     return  ui->label->text ();
}

void WindowTopWidget::getClose()
{
    qDebug()<<" connect (qQuickItem,SIGNAL(close()),this,SLOT(getClose()))";
    emit sendClose();
}


void WindowTopWidget::getSmall()
{
    qDebug()<<"connect (qQuickItem,SIGNAL(small()),this,SLOT(getSmall()))";
    emit sendSmall();
}

WindowTopWidget::~WindowTopWidget()
{
    delete ui;
}
