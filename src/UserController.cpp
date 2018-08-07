#include "UserController.h"

void UserController::addList(std::shared_ptr<ActivityList> al){
	user->addActivityList(al);
}

void UserController::removeList(std::shared_ptr<ActivityList> al){
	user->removeActivityList(al->getName());
}
