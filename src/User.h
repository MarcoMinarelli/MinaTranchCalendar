/*
 * User.h
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#ifndef SRC_USER_H_
#define SRC_USER_H_

#include <vector>

#include "ActivityList.h"

class User {
public:
	User();
	virtual ~User();
	void addActivityList(ActivityList al);
	void removeActivityList(std::string name);
	std::vector<ActivityList> getActivityLists();
	
private:
	std::vector<ActivityList> categories;
	std::ofstream outfile;
};


#endif /* SRC_USER_H_ */
