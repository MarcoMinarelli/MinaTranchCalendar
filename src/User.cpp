#include <sys/stat.h>
#include <fstream>
#include <algorithm>
#include <iostream>


#include "User.h"


User::User() : categories(), observers(){
	std::ifstream infile;
	infile.open("../user.dat", std::ios::binary);
	if(!infile){ //if the file is not present, it is created
		outfile.open("../user.dat", std::ios::binary);
		addActivityList(std::shared_ptr<ActivityList> ( new ActivityList("Eventi importanti", "Gli event importanti") ) );
		outfile.close();
	}else{
		int size;
		infile.seekg(0, infile.end);     
		    
		size = infile.tellg();              
		infile.seekg(0, infile.beg);
		
		categories.resize(size / sizeof(int) );
		
		infile.read((char *) categories.data(), size);
		
	}
	infile.close();
}

User::~User() { 
	outfile.close();
	for(auto obs : observers){
		delete obs;
	}
}

void User::addActivityList(std::shared_ptr<ActivityList> al){
	if(std::find(categories.begin(), categories.end(), al) == categories.end() ){
		categories.push_back(al);
	}
	outfile.open("../user.dat", std::ios::binary | std::ios::out);
	outfile.write((char*) &categories, categories.size() * sizeof(ActivityList));
	this->notify();
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
	this->notify();
}

std::vector< std::shared_ptr<ActivityList> > User::getActivityLists(){
	return categories;
}

void User::attach(Observer * o){ 
	//shared_ptr<Observer> my_ptr(o);
	observers.push_back( o );
}

void User::detach(Observer * o){
	//shared_ptr<Observer> my_ptr(o);
	observers.remove( o );
}

void User::notify() const {
	for(auto obs : observers) {
		obs->update();
	}
}
