#ifndef MAINWICKETFORM_H
#define MAINWICKETFORM_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class MainWicketForm;
}

class MainWicketForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainWicketForm(QWidget *parent = nullptr);
    ~MainWicketForm();

signals:
    void sendClose();
    void sendSmall();

public slots:

    void getClose();
    void getSmall();

private:
    Ui::MainWicketForm *ui;
};

#endif // MAINWICKETFORM_H
