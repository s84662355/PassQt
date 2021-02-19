#ifndef TestWight_H
#define TestWight_H


#include <QQuickPaintedItem>
#include <QtCore>
#include <QtGui>


class TestWight : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit TestWight(QQuickPaintedItem *parent = nullptr);
    ~TestWight();

protected:

    void paint(QPainter * painter);

};

#endif // MYQTWIGHT_H
