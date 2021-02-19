#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>

class MyLabel : public QWidget
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
  //  void mousePressEvent (QMouseEvent* event);
//    void mouseReleaseEvent(QMouseEvent* event);
   // void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);



signals:

};

#endif // MYLABEL_H
