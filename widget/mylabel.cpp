#include "mylabel.h"
#include <QPainter>
#include <QPen>
#include <QApplication>
#include <QLabel>
MyLabel::MyLabel(QWidget *parent) : QWidget(parent)
{

}



void MyLabel::paintEvent(QPaintEvent * event)
{

    QLabel www;
   www.setGeometry (0,0,100,50);
     www.setWordWrap(true);
   //  www.  adjustSize();
    www.setText ("dmfklgfdjgddpofgskdgkdfpogkdpsogkdspogkdpf");
    QFont ff;
    ff.setBold (true);
    www.setFont (ff);

    QPainter painter( this);

    painter.drawPixmap (0,0,  www.grab ());
}

