#include "mainleftform.h"
#include "ui_mainleftform.h"

MainLeftForm::MainLeftForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainLeftForm)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_TransparentForMouseEvents,true);
   setMouseTracking(true);

}

bool MainLeftForm::event(QEvent * event)
{
    return false;
}


void MainLeftForm::mousePressEvent(QMouseEvent* event)
{
 event->ignore();
}

void MainLeftForm::mouseReleaseEvent(QMouseEvent* event)
{
 event->ignore();
}

void MainLeftForm::mouseMoveEvent(QMouseEvent* event)
{
 event->ignore();
}

MainLeftForm::~MainLeftForm()
{
    delete ui;
}
