#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();

private:
    Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
