#-------------------------------------------------
#
# Project created by QtCreator 2020-03-09T07:43:09
#
#-------------------------------------------------

QT       += core gui serialbus serialport sql network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SUPERVISOR
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        connectdialog.cpp \
    correctpd.cpp \
    filtertabledlg.cpp \
    gridtableheadermodel.cpp \
    gridtableheaderview.cpp \
    mainwindow.cpp \
    Security_Custom.cpp \
    RegisterDlg.cpp \
    messagemanagement.cpp \
    materialmanagement.cpp \
    generalsetdlg.cpp \
    confrmpwddlg.cpp \
    changepwddlg.cpp \
    productcount.cpp \
    tableheaderitem.cpp \
    todayproduct.cpp

HEADERS  += connectdialog.h \
    connection.h \
    correctpd.h \
    filtertabledlg.h \
    gridtableheadermodel.h \
    gridtableheaderview.h \
    mainwindow.h \
    extravalues.h \
    Security_Custom.h \
    RegisterDlg.h \
    generalsetdlg.h \
    confrmpwddlg.h \
    changepwddlg.h \
    tableheaderitem.h

FORMS    += connectdialog.ui \
    correctpd.ui \
    filtertabledlg.ui \
    mainwindow.ui \
    RegisterDlg.ui \
    generalsetdlg.ui \
    confrmpwddlg.ui \
    changepwddlg.ui

RESOURCES += \
    resources.qrc

RC_FILE += SUPERVISOR.rc
