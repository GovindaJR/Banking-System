QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bankaccount.cpp \
    checkingaccount.cpp \
    checkingmenu.cpp \
    customer.cpp \
    customermenu.cpp \
    database.cpp \
    interface.cpp \
    iterators.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    registerform.cpp \
    savingsaccount.cpp \
    savingsmenu.cpp \
    user.cpp

HEADERS += \
    bankaccount.h \
    checkingaccount.h \
    checkingmenu.h \
    customer.h \
    customermenu.h \
    database.h \
    interface.h \
    loginform.h \
    mainwindow.h \
    registerform.h \
    savingsaccount.h \
    savingsmenu.h \
    user.h

FORMS += \
    checkingmenu.ui \
    customermenu.ui \
    loginform.ui \
    mainwindow.ui \
    registerform.ui \
    savingsmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
