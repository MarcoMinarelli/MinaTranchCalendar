
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
	std::shared_ptr<User> ptr(new User);
	createActivityList(ptr);
	std::shared_ptr<UserController> controllerPtr(new UserController(ptr) );
	QApplication app (argc, argv);
	MainWindow *newWindow = new MainWindow(ptr, controllerPtr);
    newWindow->show();
 	return app.exec();
 	return 0;
}

void createActivityList(std::shared_ptr<User> u){
	ActivityList al("University", "University Stuff");
	Commitment c(Date(01, 02, 2018), Date (01, 02, 2018), Time((unsigned int) 14,(unsigned int) 00, (unsigned int) 00), Time((unsigned int) 16,(unsigned int)  00, (unsigned int) 00), false, std::string("Very Important Meeting"), std::string("www.unifi.it") ) ; 
	al.addCommitment(c);
	u->addActivityList( std::make_shared<ActivityList>(al) );	
}

