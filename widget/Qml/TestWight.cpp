#include "TestWight.h"
#include <QStyle>
#include <QStyleOption>
#include <QDebug>
#include <QFont>
TestWight:: TestWight(QQuickPaintedItem *parent  ) :QQuickPaintedItem(parent)
{

}

void TestWight::paint(QPainter *painter)
{


   painter->drawText (0,10,"dfgjmdfiogjifd");
     // 绘制文本

   qDebug()<<"ccccccccccc";
     qDebug()<<"bbbbbbbbbbbbbbn";
}


TestWight::~TestWight()
{

}
