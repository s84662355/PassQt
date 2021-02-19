#ifndef CHATBOXFORM_H
#define CHATBOXFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickItem>
#include <QQmlProperty>
#include <QMetaObject>
namespace Ui {
class ChatBoxForm;
}

class ChatBoxForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBoxForm(QWidget *parent = nullptr);
    ~ChatBoxForm();

private:
    Ui::ChatBoxForm *ui;
    QQuickWidget *imageQQuickWidget;
};

#endif // CHATBOXFORM_H
