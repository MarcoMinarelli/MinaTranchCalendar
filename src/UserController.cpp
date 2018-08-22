#include<iostream>

#include "UserController.h"

void UserController::addList(std::shared_ptr<ActivityList> al){
	user->addActivityList(al);
}

void UserController::removeList(std::string alName){
	user->removeActivityList(alName);
}

void UserController::onClose(){
	user->save();
}
