#include "widget.h"

#include <QApplication>
#include "loginform.h"
#include "mainform.h"
#include "http/http.h"
#include "lib/ImageCache.h"
#include "mainleftform.h"
#include "mainhuihuaform.h"
#include "widget/Qml/TestWight.h"
#include "widget/windowtopwidget.h"
#include "widget/chatwidget.h"
#include "widget/chatboxform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    //  w.show();

    qmlRegisterType<ImageCache>("MyImageCache",1,0,"ImageCache");

    qmlRegisterType<TestWight>("TestWight",1,0,"TestWight");

    ChatBoxForm ddd ;
    ddd.show();

   // WindowTopWidget vvvv ;
  //  vvvv.show ();


  //  LoginForm lll;
   // lll.show ();

   //  MainForm ggg;
   // ggg.show();

    return a.exec();
}
