#ifndef MAINLEFTFORM_H
#define MAINLEFTFORM_H

#include <QWidget>

namespace Ui {
class MainLeftForm;
}

class MainLeftForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainLeftForm(QWidget *parent = nullptr);
    ~MainLeftForm();

protected:
    bool event(QEvent * event);
    void mousePressEvent (QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:

private:
    Ui::MainLeftForm *ui;
};

#endif // MAINLEFTFORM_H
