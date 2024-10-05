#include "ServiceOpen.h"

ServiceOpen::ServiceOpen(string &service){
	//Создаем сервис для октрытия файла
	this->service = QString::fromStdString(service);
	QDBusConnection dbusConnection = QDBusConnection::sessionBus();
        if (dbusConnection.registerService(this->service)){
            qInfo() << "Service registered successfully.";
        } else {
            qDebug() << QDBusConnection::sessionBus().lastError().message();
            qFatal("Failed to register service.");
        }

	// Регистрация интерфейса  корневым путем "/"
        if (dbusConnection.registerObject("/", this, QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals)) {
            qDebug() << "Object registered successfully";
        } else {
            qDebug() << QDBusConnection::sessionBus().lastError().message();
            qFatal("Failed to register object.");
	}

	//connect(this, &ServiceOpen::fileOpened,this, &ServiceOpen::OpenFileService);
}

//Деструткор
ServiceOpen::~ServiceOpen(){
	 // Очистка сервиса
        QDBusConnection::sessionBus().unregisterService(service);
        qInfo() << "Service unregistered.";
}
//чтобы не создавать свой metatype (Для упрощения) 
void ServiceOpen::OpenFile(const string &path){
        QString qpath = QString::fromStdString(path);
        OpenFileService(qpath);
}
//Функцция где мы вызываем интерфейс "com.system.sharing" чтобы открыть файл 
void ServiceOpen::OpenFileService(const QString &path){
	//Ищем имя интерфейса
	QString interfaceName;
        // Попытка получить информацию о доступных интерфейсах
        QDBusInterface ifaceIntrospect(service, "/", QString(), QDBusConnection::sessionBus());
        QDBusReply<QString> reply = ifaceIntrospect.call("Introspect");
        if (reply.isValid()) {
           interfaceName =  reply.value();
        } else {
           qDebug() << reply.error().message();
	   qFatal("Failed to find out interface name.");
        }
	//Подключаемся к интерфейсу чтобы открыть файл
	auto iface = new QDBusInterface("com.system.sharing", "/","com.system.sharing" , QDBusConnection::sessionBus(),this);
	QDBusPendingCall pcall  = iface->asyncCall("OpenFile", path);
	//Асинхронный вызов (без него падает)
	auto watcher = new QDBusPendingCallWatcher(pcall, this);
	QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this,
                     [&](QDBusPendingCallWatcher *w) {
        	     	QDBusPendingReply<void> reply(*w);
			if(reply.isError()){
				qCritical() << "Error reading the file: " << reply.error().message();
			}else{
				qInfo() << "The file reading was successful";
			}
        });
        string path_s = path.toStdString();
	//emit fileOpened(path_s);
	
}

