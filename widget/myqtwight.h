#ifndef MYQTWIGHT_H
#define MYQTWIGHT_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QBitmap>

namespace Ui {
class MyQtWight;
}

class MyQtWight : public QWidget
{
    Q_OBJECT

public:
    explicit MyQtWight(QWidget *parent = nullptr);
    ~MyQtWight();
    void setChangeSize(bool isChange);
    bool getChangeSize();
protected:
    void mousePressEvent (QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);

private:


private:
    //辅助函数
    int calcPosition(const QPoint& pt);
    void setCursorType(int value);
private:
    bool					m_bLeftMouseButtonPressed;
    int						m_lastPosition;
    QPoint					m_ptLast;
    Qt::CursorShape			m_currentCursor;


private:
    bool isChange;

};

#endif // MYQTWIGHT_H
