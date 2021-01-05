
QT += sql
QT       += core gui sql network printsupport charts multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += serialport
CONFIG += c++11


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
    arduino.cpp \
    arduino_yassine.cpp \
    client_marriage.cpp \
    connection.cpp \
    decorator.cpp \
    employes.cpp \
    hall.cpp \
    invite.cpp \
    main.cpp \
    mainwindow.cpp \
    musiciens.cpp \
    prod_client.cpp \
    produit.cpp \
    smtp.cpp \
    deletehall.cpp \
    deletedecorator.cpp \
    statistics.cpp \
    traiteur.cpp

HEADERS += \
    ../../arduinoAZ/arduinoAZ.ino \
    arduino.h \
    arduino_yassine.h \
    client_marriage.h \
    connection.h \
    decorator.h \
    employes.h \
    hall.h \
    invite.h \
    mainwindow.h \
    musiciens.h \
    prod_client.h \
    produit.h \
    smtp.h \
    deletehall.h \
    deletedecorator.h \
    statistics.h \
    traiteur.h

FORMS += \
    mainwindow.ui \
    deletehall.ui \
    deletedecorator.ui \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
