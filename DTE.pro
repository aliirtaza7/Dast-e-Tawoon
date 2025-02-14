QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databasemanagement.cpp \
    main.cpp \
    mainwindow.cpp \
    needyperson.cpp \
    ngo.cpp \
    ngo_log_in.cpp \
    ngo_sign_in.cpp \
    np_log_in.cpp \
    np_sign_in.cpp \
    server.cpp

HEADERS += \
    databasemanagement.h \
    mainwindow.h \
    needyperson.h \
    ngo.h \
    ngo_log_in.h \
    ngo_sign_in.h \
    np_log_in.h \
    np_sign_in.h \
    server.h

FORMS += \
    mainwindow.ui \
    needyperson.ui \
    ngo.ui \
    ngo_log_in.ui \
    ngo_sign_in.ui \
    np_log_in.ui \
    np_sign_in.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sqldiff.exe \
    sqlite3_analyzer.exe \
    sqlite3_rsync.exe

RESOURCES += \
    images.qrc
