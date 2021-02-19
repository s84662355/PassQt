#ifndef WINDOWTOPWIDGET_H
#define WINDOWTOPWIDGET_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class WindowTopWidget;
}

class WindowTopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WindowTopWidget(QWidget *parent = nullptr);
    ~WindowTopWidget();
    void setLabel(QString);
    QString  getLabel();

signals:
    void sendClose();
    void sendSmall();

public slots:
    void getClose();
    void getSmall();

private:
    Ui::WindowTopWidget *ui;
};

#endif // WINDOWTOPWIDGET_H
