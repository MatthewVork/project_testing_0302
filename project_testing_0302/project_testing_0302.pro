QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loginwidget.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    registerwidget.cpp \
    scorereport.cpp \
    testingroom.cpp

HEADERS += \
    loginwidget.h \
    mainmenu.h \
    mainwindow.h \
    registerwidget.h \
    scorereport.h \
    testingroom.h

FORMS += \
    loginwidget.ui \
    mainmenu.ui \
    mainwindow.ui \
    registerwidget.ui \
    scorereport.ui \
    testingroom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
