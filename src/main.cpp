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
	//createActivityList(ptr);
	std::shared_ptr<UserController> controllerPtr(new UserController(ptr) );
	MainWindow newWindow(ptr, controllerPtr);
    newWindow.show();
    
 	return app.exec();
}

void createActivityList(std::shared_ptr<User> u){
	ActivityList al("University", "University Stuff");
	Commitment c(Date(01, 02, 2018), Date (01, 02, 2018), Time((unsigned int) 14,(unsigned int) 00, (unsigned int) 00), Time((unsigned int) 16,(unsigned int)  00, (unsigned int) 00), false, std::string("Very Important Meeting"), std::string("www.unifi.it"), std::string("UniFi")) ; 
	Commitment c1(Date(01, 02, 2018), Date (01, 02, 2018), Time((unsigned int) 18,(unsigned int) 00, (unsigned int) 00), Time((unsigned int) 18,(unsigned int)  30, (unsigned int) 00), false, std::string("Project"), std::string("www.unifi.it"), std::string("UniFi") ) ;
	Commitment c2(Date(03, 04, 2018), Date (06, 05, 2018), Time((unsigned int) 11,(unsigned int) 45, (unsigned int) 00), Time((unsigned int) 12,(unsigned int)  00, (unsigned int) 00), false, std::string("Project Meeting"), std::string("www.unifi.it"), std::string("UniFi") ) ;  
	al.addCommitment(c);
	al.addCommitment(c1);
	al.addCommitment(c2);
	u->addActivityList( std::make_shared<ActivityList>(al) );	
	ActivityList al1("Test", "Example");
	Commitment c3(Date(14, 05, 2018), Date (14, 05, 2018), Time((unsigned int) 14,(unsigned int) 00, (unsigned int) 00), Time((unsigned int) 16,(unsigned int)  00, (unsigned int) 00), false, std::string("Lorem ipsum"), std::string(), std::string() ) ; 
	Commitment c4(Date(01, 02, 2018), Date (01, 02, 2018), Time((unsigned int) 18,(unsigned int) 00, (unsigned int) 00), Time((unsigned int) 18,(unsigned int)  30, (unsigned int) 00), false, std::string("Dolor sit amet"), std::string(), std::string() ) ;
	al1.addCommitment(c3);
	al1.addCommitment(c4);
	u->addActivityList( std::make_shared<ActivityList>(al1) );	
}

