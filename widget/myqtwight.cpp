#include "myqtwight.h"
#include <QStyle>
#include <QStyleOption>
namespace
{
const int g_padding = 4;

int helperCalcPosition(int pos, int range)
{
    return (pos < g_padding) ? 0 : ((pos > (range - g_padding)) ? 2 : 1);
}
}


MyQtWight::MyQtWight(QWidget *parent) :
    QWidget(parent),
    m_bLeftMouseButtonPressed(false)
  , m_lastPosition(11)
  , m_currentCursor(Qt::ArrowCursor)
{

    setMouseTracking(true);
    setCursor(m_currentCursor);
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(Qt::FramelessWindowHint|m_flags);
    isChange = true;
    /// this->setMinimumSize(QSize(280, 360));
}

void MyQtWight::setChangeSize(bool isChange)
{
    this->isChange = isChange;
}

bool MyQtWight::getChangeSize()
{
    return isChange;
}


void MyQtWight::paintEvent(QPaintEvent*)
{
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),8,8);
    setMask(bmp);

}


int MyQtWight::calcPosition(const QPoint& pt)
{
    int row = helperCalcPosition(pt.y(), rect().height());
    int col = helperCalcPosition(pt.x(), rect().width());
    return row * 10 + col;
}

void MyQtWight::mousePressEvent(QMouseEvent* event)
{
     if(event->button()==Qt::RightButton){
         return ;
     }

    m_bLeftMouseButtonPressed = true;
    m_ptLast = event->globalPos();
    m_lastPosition = calcPosition(event->pos());
    event->ignore();
}

void MyQtWight::mouseReleaseEvent(QMouseEvent* event)
{
    if(m_bLeftMouseButtonPressed) m_bLeftMouseButtonPressed = false;
    event->ignore();
}

void MyQtWight::mouseMoveEvent(QMouseEvent* event)
{
    if(event->button()==Qt::RightButton){
        return ;
    }

    setCursorType(calcPosition(event->pos()));
    if(m_bLeftMouseButtonPressed)
    {

        QPoint ptNew = event->globalPos();
        ptNew -= m_ptLast;
        if(11 == m_lastPosition) //拖动
        {
            ptNew += pos();
            move(ptNew);
        }
        else if(isChange)//调整大小
        {
            QRect rectWindow = geometry();
            switch(m_lastPosition)
            {
            case 00:
                rectWindow.setTopLeft(rectWindow.topLeft() + ptNew);
                break;
            case 02:
                rectWindow.setTopRight(rectWindow.topRight() + ptNew);
                break;
            case 20:
                rectWindow.setBottomLeft(rectWindow.bottomLeft() + ptNew);
                break;
            case 22:
                rectWindow.setBottomRight(rectWindow.bottomRight() + ptNew);
                break;
            case 10:
                rectWindow.setLeft(rectWindow.left() + ptNew.x());
                break;
            case 12:
                rectWindow.setRight(rectWindow.right() + ptNew.x());
                break;
            case 01:
                rectWindow.setTop(rectWindow.top() + ptNew.y());
                break;
            case 21:
                rectWindow.setBottom(rectWindow.bottom() + ptNew.y());
                break;
                //case 11:
            default:
                Q_ASSERT(0);
            }
            setGeometry(rectWindow);
            //qDebug() << rectWindow.topLeft() << ", " << rectWindow.bottomRight();
        }
        m_ptLast  = event->globalPos();
    }
    event->ignore();
}

void MyQtWight::setCursorType(int value)
{
    Qt::CursorShape cursor;

    switch(value)
    {
    case 00:
    case 22:
        cursor = Qt::SizeFDiagCursor;
        break;
    case 02:
    case 20:
        cursor = Qt::SizeBDiagCursor;
        break;
    case 10:
    case 12:
        cursor = Qt::SizeHorCursor;
        break;
    case 01:
    case 21:
        cursor = Qt::SizeVerCursor;
        break;
    case 11:
        cursor = Qt::ArrowCursor;
        break;
    default:
        Q_ASSERT(0);
        break;
    }
    if(cursor != m_currentCursor)
    {
        m_currentCursor = cursor;
        setCursor(m_currentCursor);
    }
}

MyQtWight::~MyQtWight()
{

}
