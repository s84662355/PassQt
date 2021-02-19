#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    MyQtWight(parent),
    ui(new Ui::MainForm)
{
    //     ui->setupUi(this);
    this->setMinimumSize (700,500);

    horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    // horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    initMainLeftForm();
    initMainHuiHuaForm();
    initMainWicketForm();

}

void  MainForm::initMainWicketForm()
{
    mainWicketForm = new MainWicketForm(this);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(mainWicketForm->sizePolicy().hasHeightForWidth());
    mainWicketForm->setSizePolicy(sizePolicy);

    QObject::connect(mainWicketForm, &MainWicketForm::sendClose,[=](){
        qDebug()<<"mainWicketForm close()";
        this->close ();
    });

    QObject::connect(mainWicketForm, &MainWicketForm::sendSmall,[=](){
        qDebug()<<"mainWicketForm small()";
        this->showMinimized ();
    });

    horizontalLayout ->addWidget(mainWicketForm );
}

void MainForm:: initMainHuiHuaForm()
{
    mainHuiHuaForm = new MainHuiHuaForm(this);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(mainHuiHuaForm->sizePolicy().hasHeightForWidth());
    mainHuiHuaForm->setSizePolicy(sizePolicy);
    mainHuiHuaForm->setMinimumSize(QSize(250, 0));
    mainHuiHuaForm->setMaximumSize(QSize(250, 16777215));
    horizontalLayout ->addWidget(mainHuiHuaForm, 0, Qt::AlignLeft);
}

void MainForm::initMainLeftForm()
{
    mainLeftForm = new MainLeftForm(this );
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(mainLeftForm->sizePolicy().hasHeightForWidth());
    mainLeftForm->setSizePolicy(sizePolicy);
    mainLeftForm->setMinimumSize(QSize(60, 0));
    mainLeftForm->setMaximumSize(QSize(60, 16777215));
    mainLeftForm->setBaseSize (QSize(60, 16777215));
    // mainLeftForm->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
    horizontalLayout ->addWidget(mainLeftForm );
}


MainForm::~MainForm()
{
    delete ui;
    mainLeftForm->deleteLater ();
    mainHuiHuaForm->deleteLater ();
    horizontalLayout->deleteLater ();
}
