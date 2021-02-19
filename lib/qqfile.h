#ifndef QQFILE_H
#define QQFILE_H
#include <QObject>
#include <QByteArray>
#include <QFile>
#include <QDebug>
#include <QDir>
class QQFile : public QObject
{
    Q_OBJECT
public:
    explicit QQFile();

public slots:
   QString WriteFile(QString  ,QString ,QByteArray );

signals:
    void finished(const QString);
};

#endif // QQFILE_H
