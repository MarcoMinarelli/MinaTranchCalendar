/*
 * User.cpp
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#include <sys/stat.h>
#include <fstream>

#include "User.h"


User::User() {
	std::ifstream infile;
	infile.open("user.dat", ios::binary | ios::in);
	if(!infile){ //if the file is not present, it is created
		outfile.open("user.dat", ios::binary | ios::out);
		outfile.close();
	}else{
		int fileLenght;
		struct stat results;
		if (stat("user.dat", &results) == 0){
			fileLenght = results.st_size;
		}
		infile.read(&categories, fileLenght);
	}
}

User::~User() { }

void User::addCategory(Category aCategory){
	auto it = find (categories.begin(), categories.end(), aCategory);
	if(it = categories.end){
		categories.push_back(aCategory);
	}
}

void User::removeCategory(std::string name){
	int pos = 0;
	for(auto it : categories){
		pos ++;
		if (it.getName == name){
			break;
		}
	}
	categories.erase(pos);
}

vector<Category> User::getCategories(){
	return categories;
}

