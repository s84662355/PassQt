#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QObject>
#include <QWidget>
#include <QQuickItem>
#include <QDebug>
#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueList>
#include <QJsonValueRef>
#include <QVariant>
#include "http/http.h"
#include <QThread>
#include <QCoreApplication>

class Core : public QObject
{
    //  Q_OBJECT
public:
    ~Core();
    static Core * getInstance();
    QThread *getWorkThread() const;
    QString  static getTmpCacheDir()  ;

private:
    explicit Core();

signals:

public slots:

private:
    static Core *instance;
    QThread *workthread;

};

#endif // LOGINFORM_H
