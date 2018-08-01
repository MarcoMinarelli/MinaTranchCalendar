
#include <memory>

#include <QApplication>

#include "MainWindow.h"
#include "User.h"

int main(int argc, char **argv){
	std::shared_ptr<User> ptr(new User);
	QApplication app (argc, argv);
	MainWindow *newWindow = new MainWindow(ptr);
    newWindow->show();
 	return app.exec();
 	return 0;
}

