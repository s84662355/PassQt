#ifndef MAINHUIHUAFORM_H
#define MAINHUIHUAFORM_H

#include <QWidget>

namespace Ui {
class MainHuiHuaForm;
}

class MainHuiHuaForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainHuiHuaForm(QWidget *parent = nullptr);
    ~MainHuiHuaForm();

private:
    Ui::MainHuiHuaForm *ui;
};

#endif // MAINHUIHUAFORM_H
