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
	infile.open("user.dat", std::ios::binary | std::ios::in);
	if(!infile){ //if the file is not present, it is created
		outfile.open("user.dat", std::ios::binary | std::ios::out);
		outfile.close();
	}else{
		/*int fileLenght;
		struct stat results;
		if (stat("user.dat", &results) == 0){
			fileLenght = results.st_size;
		}
		infile.read(&categories, fileLenght);*/
		//infile >> categories;
	}
}

User::~User() { }

void User::addActivityList(ActivityList al){
	if(std::find(categories.begin(), categories.end(), al) == categories.end() ){
		categories.push_back(al);
	}
}

void User::removeActivityList(std::string aName){
	int pos = 0;
	for(auto it : categories){
		pos ++;
		if (it.getName() == aName){
			break;
		}
	}
	categories.erase(categories.begin() + pos);
}

std::vector<ActivityList> User::getActivityLists(){
	return categories;
}

