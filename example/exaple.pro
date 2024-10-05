QT += core dbus
QT -= gui
QT += widgets
CONFIG += c++11

TARGET = ServerOpen
TEMPLATE = app
SOURCES += main.cpp

LIBS += -L/home/lilycherly/Work/serviceOpen -lServiceOpen 
INCLUDEPATH += /home/lilycherly/Work/serviceOpen
