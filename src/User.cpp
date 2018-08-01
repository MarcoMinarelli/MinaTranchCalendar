/*
 * User.cpp
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#include <sys/stat.h>
#include <fstream>
#include <algorithm>

#include "User.h"


User::User() {
	std::ifstream infile;
	infile.open("user.dat", std::ios::binary);
	if(!infile){ //if the file is not present, it is created
		outfile.open("user.dat", std::ios::binary);
		addActivityList(std::shared_ptr<ActivityList> (new ActivityList("Eventi importanti", "Gli event importanti") ) );
		outfile.close();
	}else{
		infile.seekg(0, std::ios::end);
		int fileSize = infile.tellg();
		infile.seekg(0, std::ios::beg);
		infile.read(reinterpret_cast<char*>(categories.data()), fileSize);
		infile.close();
	}
}

User::~User() { }

void User::addActivityList(std::shared_ptr<ActivityList> al){
	if(std::find(categories.begin(), categories.end(), al) == categories.end() ){
		categories.push_back(al);
	}
	outfile.open("user.dat", std::ios::binary | std::ios::out);
	outfile.write( (char *) &categories[0], sizeof(ActivityList) * categories.size() );
	outfile.close();
}

void User::removeActivityList(std::string aName){
	int pos = 0;
	for(auto it : categories){
		pos ++;
		if (it->getName() == aName){
			break;
		}
	}
	categories.erase(categories.begin() + pos);
}

std::vector< std::shared_ptr<ActivityList> > User::getActivityLists(){
	return categories;
}

