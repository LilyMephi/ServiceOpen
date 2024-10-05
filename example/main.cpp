#include "ServiceOpen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QCoreApplication>

using namespace std;

int main(int argc, char *argv[]){
	QCoreApplication app(argc, argv);
	string service_name = "com.example.open";

	ServiceOpen service(service_name);

	// Убедитесь, что имя файла передается как аргумент
        if (argc < 2) {
             cout << "Usage:" << argv[0] << " <file_path>" << endl;;
            return -1;
        }
	string path = argv[1];

	service.OpenFile(path);

	return app.exec();
}
