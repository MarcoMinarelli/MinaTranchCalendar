/*
 * User.h
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#ifndef SRC_USER_H_
#define SRC_USER_H_

#include <vector>
#include <fstream>
#include <memory>

#include "ActivityList.h"

class User {
public:
	User();
	virtual ~User();
	void addActivityList(std::shared_ptr<ActivityList> al);
	void removeActivityList(std::string name);
	std::vector< std::shared_ptr<ActivityList> > getActivityLists();
	
private:
	std::vector< std::shared_ptr<ActivityList> > categories;
	std::ofstream outfile;
};


#endif /* SRC_USER_H_ */
