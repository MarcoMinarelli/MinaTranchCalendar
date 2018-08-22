/*
 * UserController.h
 *
 *  Created on: 7 ago 2018
 *      Author: marco
 */

#ifndef SRC_USERCONTROLLER_H_
#define SRC_USERCONTROLLER_H_

#include<memory>

#include "ActivityList.h"
#include "User.h"
class UserController{
public:
	UserController(std::shared_ptr<User> u) : user(u) { };
	~UserController() { }

	void addList(std::shared_ptr<ActivityList> al);
	void removeList(std::string al);
	void onClose();

private:
	std::shared_ptr<User> user;
};
#endif
