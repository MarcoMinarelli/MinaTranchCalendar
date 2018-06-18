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


//TODO implement
class User {
public:
	User();
	virtual ~User();
	void addCategory(Category aCategory);
	void removeCategory(std::string name);
	vector<Category> getCategories();
	
private:
	std::vector<ActivityList> categories;
	std::ofstream outfile;
};


#endif /* SRC_USER_H_ */
