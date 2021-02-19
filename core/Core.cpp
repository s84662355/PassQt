#include "core/Core.h"

Core *Core::instance = nullptr;
Core::Core() : QObject()
{
    workthread = new QThread;
    connect(workthread,&QThread::finished,workthread,&QObject::deleteLater);
    workthread->start ();
}

QString Core::getTmpCacheDir()
{
   return  QCoreApplication::applicationDirPath()+"/cccache";
}

QThread * Core::getWorkThread() const
{
    return workthread;
}

Core * Core::getInstance()
{
    if(instance == nullptr)
    {
        instance = new Core();
    }
    return instance;
}



Core::~Core()
{
    workthread->quit();
    workthread->wait();
    //  workthread->terminate ();
    //if(workthread) delete workthread;
    if(Core::instance)  delete Core::instance;
}
