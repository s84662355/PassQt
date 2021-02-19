#include "networkcache.h"

NetWorkCache::NetWorkCache():QObject()
{
    this->mManager = new QNetworkAccessManager(this);
    qfile = new QQFile();

    connect(this->mManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotReplyPixmapLoad(QNetworkReply*)));
}

void NetWorkCache::setCacheDir(QString cacheDir)
{
    this->cacheDir = cacheDir;
}

void NetWorkCache::slotReplyPixmapLoad(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {

        QByteArray bytes =  reply->readAll();
        QString md5;
        QByteArray bb = QCryptographicHash::hash ( reply->url ().toString ().toUtf8(), QCryptographicHash::Md5 );
        md5.append(bb.toHex());
        QString filepath = this->cacheDir+QDir::separator() + md5;
        qDebug()<<"网络加载55555444 "+ cacheDir;

        qfile-> WriteFile(this->cacheDir,md5,bytes);
        emit finish (true,NetWorkCache::NETWORK,filepath);

    }else{
        emit finish (false,NetWorkCache::NETWORK,"");
    }

}

void NetWorkCache::runload(QString url)
{
    //网络图片
    //判断有没有缓存
    qDebug()<<"网络加载11 11";
    QString md5 = "";
    QByteArray bb = QCryptographicHash::hash (url.toUtf8(), QCryptographicHash::Md5 );
    md5.append(bb.toHex());
    QString filepath = this->cacheDir+QDir::separator() + md5;
    QFile file(filepath);
    if(!file.exists())
    {
        //不存在 走网络
        qDebug()<<"网络加载nnnnnnnnnnn";
        this->mManager->get(QNetworkRequest(url));
        return;
    }

    if(file.exists())
    {
        file.close();
        emit finish (true,NetWorkCache::LOCAL,filepath);
    }

}

QString NetWorkCache::getCacheDir() const
{
    return cacheDir;
}


NetWorkCache::~NetWorkCache()
{
    qDebug()<<"bbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    delete mManager;
    delete qfile;

}
