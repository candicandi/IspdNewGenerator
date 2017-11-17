#-------------------------------------------------
#
# Project created by QtCreator 2017-10-02T09:05:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IspdGenerator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    common.cpp \
    handletime.cpp \
    qalgorithm.cpp

HEADERS  += mainwindow.h \
    common.h \
    handletime.h \
    qalgorithm.h

FORMS    += mainwindow.ui

win32 {

    INCLUDEPATH = ../../../include_cpp
    LIBS += ../../../lib/libxl.lib

    QMAKE_POST_LINK +=$$quote(cmd /c copy /y ..\..\..\bin\libxl.dll .)

} else:macx {

    INCLUDEPATH = ../../include_cpp
    LIBS += -framework LibXL

    QMAKE_LFLAGS += -F../../
    QMAKE_POST_LINK +=$$quote(mkdir $${TARGET}.app/Contents/Frameworks;cp -R ../../LibXL.framework $${TARGET}.app/Contents/Frameworks/)

} else {

    INCLUDEPATH = ../../include_cpp
    LIBS += ../../lib/libxl.so

    QMAKE_LFLAGS_DEBUG = "-Wl,-rpath,../../lib"
    QMAKE_LFLAGS_RELEASE = "-Wl,-rpath,../../lib"
}

RC_FILE = app.rc

