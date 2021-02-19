#ifndef ImageCache_H
#define ImageCache_H

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
#include <QAbstractListModel>
#include <QJsonValueRef>
#include <QVariant>
#include <QThread>
#include <QResource>
#include "qqfile.h"
#include <QCoreApplication>
#include "core/Core.h"
#include "networkcache.h"

class ImageCache : public QObject
{
    Q_OBJECT
    //注册属性，使之可以在QML中访问--具体语法百度Q_PROPERTY
    Q_PROPERTY(QString cacheDir READ getCacheDir WRITE setCacheDir NOTIFY CacheDirChanged)
    Q_PROPERTY(QString errorImage READ getErrorImage WRITE setErrorImage NOTIFY ErrorImageChanged)
    Q_PROPERTY(QString imageUrl READ getImageUrl WRITE setImageUrl NOTIFY ImageUrlChanged)
    Q_PROPERTY(QJSValue jsCallback   WRITE setJsCallback NOTIFY JsCallbackChanged)

public:
    explicit ImageCache( );
    ~ImageCache();
    enum STATE {
        loading,//标示加载中
        succeed,//标示加载成功
        failed//标示加载失败
    };
    enum STYLE {
        cover,//以长度小的一边为基准 显示中间位置
        contain,//完整显示图片 两边留空白
        percentage//以控件大小为基准，会失真
    };

    const int NETWORK = 1;//网络
    const int NETWORKLOCAL = 2;//网络本地
    const int LOCAL = 3;//本地

    Q_INVOKABLE void loadImage();//功能为发送信号

    void setCacheDir(const QString &name);
    QString getCacheDir() const;


    void setErrorImage(const QString &name);
    QString getErrorImage() const;

    QString  getImageUrl() const;
    void setImageUrl(const QString &name);

    QJSValue getJsCallback() const;
    void setJsCallback(QJSValue jsCallback);

public slots:
    void slotNetWorkFinish(bool,int,QString);

signals:
    void CacheDirChanged(const QString name);
    void ErrorImageChanged(const QString name);
    void ImageUrlChanged(const QString name);
    void JsCallbackChanged(QJSValue jsCallback);
    void runload(QString);


public slots:

private:
    QString cacheDir;//缓存目录
    QString errorImage;
    QString imageUrl ;
    QJSValue jsCallback;

    NetWorkCache *netWorkCache;
};

#endif
