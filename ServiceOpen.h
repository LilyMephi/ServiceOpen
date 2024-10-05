#ifndef SERVICE_OPEN_H
#define SERVICE_OPEN_H

#include "quilib_global.h"

#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusError>
#include <QDBusInterface>
#include <QDBusMetaType>
#include <QDebug>
#include <QFile>
#include <QtWidgets> 
#include <QVector>
#include <QDBusReply>
#include <QObject>
#include <QDBusPendingCall>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

Q_DECLARE_METATYPE(string)

class QUILIBSHARED_EXPORT ServiceOpen : public QObject {
	Q_OBJECT
	public:
	      explicit ServiceOpen(string &service);
	      ~ServiceOpen();
	      void OpenFile(const string &path);
	private slots:
	      void OpenFileService(const QString &path);
	private:
	      QString service;
	      QString object;
};

#endif 
