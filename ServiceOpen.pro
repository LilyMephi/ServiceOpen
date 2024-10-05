   TEMPLATE = lib
   TARGET = ServiceOpen
   CONFIG += c++11
   CONFIG += shared
   QT += dbus
   QT += widgets
   QT +=core
   QT -=gui
   
   DEFINES += QUILIB_LIBRARY
   DEFINES += QUILIB_LIBRARY 

   SOURCES += ServiceOpen.cpp
   HEADERS += ServiceOpen.h
   HEADERS += quilib_global.h
