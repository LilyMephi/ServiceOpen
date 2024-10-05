QT += core dbus
QT -= gui
QT += widgets
CONFIG += c++11

TARGET = ServerOpen
TEMPLATE = app
SOURCES += main.cpp

LIBS += -L/path/to/lib/ServiceOpen -lServiceOpen 
INCLUDEPATH += /path/to/lib/ServiceOpen
