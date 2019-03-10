#-------------------------------------------------
#
# Project created by QtCreator 2019-02-15T14:57:49
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MI_Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cook.cpp \
    warehousekeeper.cpp \
    wform2.cpp \
    admin.cpp \
    aform1.cpp \
    aform2.cpp \
    aform3.cpp \
    aform4.cpp \
    network.cpp \
    filterinvoice.cpp

HEADERS += \
        mainwindow.h \
    cook.h \
    warehousekeeper.h \
    wform2.h \
    admin.h \
    aform1.h \
    aform2.h \
    aform3.h \
    aform4.h \
    network.h \
    filterinvoice.h

FORMS += \
        mainwindow.ui \
    cook.ui \
    warehousekeeper.ui \
    wform2.ui \
    admin.ui \
    aform1.ui \
    aform2.ui \
    aform3.ui \
    aform4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
