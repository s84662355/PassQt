#include "chatwidget.h"
#include "ui_chatwidget.h"

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);

   QHBoxLayout * _layout = ui->hboxLayout;

   _layout->setDirection(QBoxLayout::RightToLeft);

   // 设置 QHBoxLayout 边距为 0
   _layout->setMargin(0);
   // 设置所有控件之间的间距为 0
   _layout->setSpacing(0);

   QPushButton *aaaa = new QPushButton("button1");

   QWidget *dddd = new QWidget();
   dddd->setMinimumSize (100,100);
     dddd->setMaximumSize (100,100);
      dddd->setStyleSheet ("background-color:red");

   // 添加控件的同时直接在参数中将控件 new 出来，这样代码可以更简洁
     _layout->addWidget(dddd, 1);
     // 添加间距
   //  _layout->addSpacing(50);
  //   _layout->addWidget( new QPushButton("button2"), 2);
   //  _layout->addWidget(  new QPushButton("button3"), 3);

     // 在布局中添加一个弹簧，让控件不会跟随窗口变大而变大
 //    _layout->addStretch(1);             // 占整个窗口的 1/n


        QWidget *vvvvv = new QWidget();
        vvvvv->setMinimumSize (100,100);
     //  vvvvv->setMaximumSize (100,100);
        vvvvv->setStyleSheet ("background-color:blue");
     // 在控件 0 后面插入一个控件，这个控件被插入后就是在位置 1
     _layout->insertWidget(1, vvvvv);


}

ChatWidget::~ChatWidget()
{
    delete ui;
}
