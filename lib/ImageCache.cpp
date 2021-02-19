#include "ImageCache.h"


ImageCache::ImageCache( )
    : QObject( )
{

  //  cacheDir = QCoreApplication::applicationDirPath()+"/mfdiovmfdi";
  cacheDir =  Core::  getTmpCacheDir();
    netWorkCache = new NetWorkCache();
    netWorkCache->setCacheDir (cacheDir);
    QThread  *m_objThread=  Core::getInstance ()->getWorkThread();
   // this->moveToThread (m_objThread);
    netWorkCache->moveToThread(m_objThread);
    connect(this ,&ImageCache::runload, netWorkCache, &NetWorkCache::runload);
    connect(m_objThread, &QThread::finished, netWorkCache, &NetWorkCache::deleteLater);
    connect(netWorkCache,&NetWorkCache::finish ,this,&ImageCache::slotNetWorkFinish);

}

void ImageCache::setCacheDir(const QString &name )
{
    this->cacheDir = name;
}

QString ImageCache::getCacheDir() const
{
    return this->cacheDir;
}

void ImageCache::setErrorImage(const QString &name )
{
    this->errorImage = name;
}

QString ImageCache::getErrorImage() const
{
    return  this->errorImage;
}

void ImageCache::setImageUrl(const QString &name)
{
    this->imageUrl = name;
}

QString ImageCache::getImageUrl() const
{
    return this->imageUrl;
}

QJSValue  ImageCache::getJsCallback() const
{
    return this->jsCallback;
}

void  ImageCache::setJsCallback(QJSValue jsCallback)
{
    this->jsCallback= jsCallback;
}

void ImageCache::slotNetWorkFinish(bool isC,int type,QString filepath)
{
    QJSValueList paramList;
    if( type == NetWorkCache::LOCAL )
    {
        paramList.append(jsCallback.engine()->toScriptValue(ImageCache::NETWORKLOCAL ));//网络本地
    }else{
        paramList.append(jsCallback.engine()->toScriptValue(ImageCache::NETWORK ));//网络
    }

    qDebug()<<"1111111网络加载1gjl50n-k 506n-,56n,i51";

    paramList.append(jsCallback.engine()->toScriptValue(isC));
    paramList.append(jsCallback.engine()->toScriptValue(filepath));
    paramList.append(jsCallback.engine()->toScriptValue(this->errorImage));
    jsCallback.call(paramList).toBool();
}

void ImageCache::loadImage()
{

    //判断是否为网络路

    if( this->imageUrl.contains("http://") || this->imageUrl.contains("https://")  )
    {

        qDebug()<<"-11111111111111111-"+ this->imageUrl ;
        emit runload(this->imageUrl);
        return ;
    }
    QJSValueList paramList;
    paramList.append(jsCallback.engine()->toScriptValue( ImageCache::LOCAL ));// 本地
    paramList.append(jsCallback.engine()->toScriptValue(true));
    paramList.append(jsCallback.engine()->toScriptValue(this->imageUrl));
    paramList.append(jsCallback.engine()->toScriptValue(errorImage));
    jsCallback.call(paramList).toBool();
  qDebug()<<"-11554545445545411111-"+ this->imageUrl ;
}


ImageCache::~ImageCache( )
{
    if(  netWorkCache ){
          netWorkCache->deleteLater();
    }

     qDebug()<<"bbbbbergtrgrtgrtgtrbbb";
//   delete netWorkCache;
}

