#ifndef NETWORKCACHE_H
#define NETWORKCACHE_H

#include <QObject>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>
#include <QDir>
#include <QFile>
#include <QtDebug>
#include <QColor>
#include "qqfile.h"
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueList>
#include <QJsonValueRef>
#include <QVariant>
#include <QThread>
#include <QResource>
#include "qqfile.h"
#include <QCoreApplication>
#include "core/Core.h"


class NetWorkCache : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkCache();
    ~NetWorkCache();

    void setCacheDir(QString cacheDir);
    QString getCacheDir() const;

    const static int LOCAL = 0;
    const static int NETWORK = 1;

signals:
    void finish(bool,int,QString);


public slots:
    void runload(QString);
     void slotReplyPixmapLoad(QNetworkReply* reply);


private:
    QNetworkAccessManager *mManager;
    QString cacheDir;//缓存目录
    QQFile *qfile;

};

#endif // NETWORKCACHE_H
