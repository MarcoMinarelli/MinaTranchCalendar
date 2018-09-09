#include <iostream>
#include <fstream>
#include <memory>

#include <QApplication>

#include "UserController.h"
#include "MainWindow.h"
#include "User.h"
#include "ActivityList.h"
#include "Commitment.h"
#include "Date.h"
#include "Time.h"

void createActivityList(std::shared_ptr<User> u);

int main(int argc, char **argv){
	QApplication app (argc, argv);
	std::shared_ptr<User> ptr(new User);
	std::shared_ptr<UserController> controllerPtr(new UserController(ptr) );
	MainWindow newWindow(ptr, controllerPtr);
    newWindow.show();
    
 	return app.exec();
}

