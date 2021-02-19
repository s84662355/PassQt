#include "qqfile.h"

QQFile::QQFile()  : QObject( )
{

}

QString QQFile:: WriteFile(QString dirpath,QString filename,QByteArray dataByte)
{
    QDir dir;
    dir.mkpath(dirpath);
    QString filepath = dirpath+"/"+filename;
    qDebug()<<"网络加载fmniofjniojniohg"+filepath;
    QFile file(filepath);
    if(!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    if (file.open(QIODevice::Append)){
        file.write(dataByte);
    }
    qDebug()<<"网络加载mmmmmmmmmmmmmmmm";
    file.close();
    emit finished(filepath);
    return filepath;

}
