#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T15:03:30
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseDialog
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


SOURCES += \
        main.cpp \
        BaseDialog.cpp \
    teachExample/QT_07/TCPNetChartDialog/TcpServerDialog/TcpServerDialog.cpp \
    teachExample/QT_07/TCPNetChartDialog/TcpClientDialog/TcpClientDialog.cpp \
    teachExample/QT_07/UdpBroadCastDialog/receiveDialog/receiveDialog.cpp \
    teachExample/QT_07/UdpBroadCastDialog/sendDialog/sendDialog.cpp \
    DialogTest/DigiClockWidget/DigiClockWidget.cpp \
    DialogTest/DrawerToolBoxDialog/DrawerToolBoxDialog.cpp \
    DialogTest/InputDialog/InputDialog.cpp \
    DialogTest/ProgressBarDialog/ProgressBarDialog.cpp \
    DialogTest/ShapeWidget/ShapeWidget.cpp \
    DialogTest/StdMsgDialog/StdMsgDialog.cpp \
    teachExample/QT_06/ThreadDialog/ThreadDialog.cpp \
    teachExample/QT_06/ThreadDialog/WorkerThread.cpp \
    teachExample/QT_06/SemaphoreDialog/SemaphoreDialog.cpp \
    teachExample/QT_06/SemaphoreDialog/Semaphore.cpp \
    teachExample/QT_08/HttpClientMainWindow/HttpClientMainWindow.cpp \
    teachExample/QT_08/HttpClientMainWindow/LoginDialog.cpp \
    teachExample/QT_08/HttpClientMainWindow/DownloadFileThread.cpp \
    teachExample/QT_08/HttpClientMainWindow/showDownloadProgressDialog.cpp


HEADERS += \
        BaseDialog.h \
    teachExample/QT_07/TCPNetChartDialog/TcpServerDialog/TcpServerDialog.h \
    teachExample/QT_07/TCPNetChartDialog/TcpClientDialog/TcpClientDialog.h \
    teachExample/QT_07/UdpBroadCastDialog/receiveDialog/receiveDialog.h \
    teachExample/QT_07/UdpBroadCastDialog/sendDialog/sendDialog.h \
    DialogTest/DigiClockWidget/DigiClockWidget.h \
    DialogTest/DrawerToolBoxDialog/DrawerToolBoxDialog.h \
    DialogTest/InputDialog/InputDialog.h \
    DialogTest/ProgressBarDialog/ProgressBarDialog.h \
    DialogTest/ShapeWidget/ShapeWidget.h \
    DialogTest/StdMsgDialog/StdMsgDialog.h \
    teachExample/QT_06/ThreadDialog/ThreadDialog.h \
    teachExample/QT_06/ThreadDialog/WorkerThread.h \
    teachExample/QT_06/SemaphoreDialog/SemaphoreDialog.h \
    teachExample/QT_06/SemaphoreDialog/Semaphore.h \
    teachExample/QT_08/HttpClientMainWindow/HttpClientMainWindow.h \
    teachExample/QT_08/HttpClientMainWindow/LoginDialog.h \
    teachExample/QT_08/HttpClientMainWindow/DownloadFileThread.h \
    teachExample/QT_08/HttpClientMainWindow/showDownloadProgressDialog.h



FORMS += \
    BaseDialog.ui \
    teachExample/QT_07/TCPNetChartDialog/TcpServerDialog/TcpServerDialog.ui \
    teachExample/QT_07/TCPNetChartDialog/TcpClientDialog/TcpClientDialog.ui \
    teachExample/QT_07/UdpBroadCastDialog/receiveDialog/receiveDialog.ui \
    teachExample/QT_07/UdpBroadCastDialog/sendDialog/sendDialog.ui \
    DialogTest/DrawerToolBoxDialog/DrawerToolBoxDialog.ui \
    DialogTest/InputDialog/InputDialog.ui \
    DialogTest/ProgressBarDialog/ProgressBarDialog.ui \
    DialogTest/StdMsgDialog/StdMsgDialog.ui \
    teachExample/QT_06/ThreadDialog/ThreadDialog.ui \
    teachExample/QT_06/SemaphoreDialog/SemaphoreDialog.ui \
    teachExample/QT_08/HttpClientMainWindow/HttpClientMainWindow.ui \
    teachExample/QT_08/HttpClientMainWindow/LoginDialog.ui \
    teachExample/QT_08/HttpClientMainWindow/showDownloadProgressDialog.ui


