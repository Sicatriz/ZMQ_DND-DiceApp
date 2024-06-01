TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
DEFINES += ZMQ_STATIC
# DEFINES += NZMQT_LIB

LIBS += -L$$PWD/../lib -lzmq -lnzmqt -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.cpp \
    communicationmanager.cpp \
    diceroller.cpp \
    heartbeat.cpp \
    mainapplication.cpp

HEADERS += \
    communicationmanager.h \
    diceroller.h \
    heartbeat.h \
    mainapplication.h
