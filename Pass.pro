QT       += core gui \
  qml  quick \

QT       += quickwidgets
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/Core.cpp \
    http/cachedhttp.cpp \
    http/http.cpp \
    http/httpreply.cpp \
    http/localcache.cpp \
    http/networkhttpreply.cpp \
    http/throttledhttp.cpp \
    lib/ImageCache.cpp \
    lib/networkcache.cpp \
    lib/qqfile.cpp \
    loginform.cpp \
    main.cpp \
    mainform.cpp \
    mainhuihuaform.cpp \
    mainleftform.cpp \
    mainwicketform.cpp \
    widget.cpp \
    widget/Qml/TestWight.cpp \
    widget/chatboxform.cpp \
    widget/chatwidget.cpp \
    widget/mylabel.cpp \
    widget/myqtwight.cpp \
    widget/windowtopwidget.cpp

HEADERS += \
    core/Core.h \
    http/cachedhttp.h \
    http/http.h \
    http/httpreply.h \
    http/httprequest.h \
    http/localcache.h \
    http/networkhttpreply.h \
    http/throttledhttp.h \
    lib/ImageCache.h \
    lib/networkcache.h \
    lib/qqfile.h \
    loginform.h \
    mainform.h \
    mainhuihuaform.h \
    mainleftform.h \
    mainwicketform.h \
    widget.h \
    widget/Qml/TestWight.h \
    widget/chatboxform.h \
    widget/chatwidget.h \
    widget/mylabel.h \
    widget/myqtwight.h \
    widget/windowtopwidget.h

FORMS += \
    loginform.ui \
    mainform.ui \
    mainhuihuaform.ui \
    mainleftform.ui \
    mainwicketform.ui \
    widget.ui \
    widget/chatboxform.ui \
    widget/chatwidget.ui \
    widget/windowtopwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc


