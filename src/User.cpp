#include <sys/stat.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "User.h"


User::User(){
	std::ifstream infile;
	infile.open("user.dat", std::ios::in | std::ios::binary);
	if(!infile.is_open()){ //if the file is not present, it is created
		addActivityList(std::shared_ptr<ActivityList> ( new ActivityList("Important Tasks", "Important Tasks") ) );
	}else{
		ActivityList appo("", "");
		infile.read( reinterpret_cast<char *>( &appo), sizeof(appo));
		while( !infile.eof() ){
			categories.push_back( std::make_shared<ActivityList> (appo) ); //add to the vector
			infile.read( reinterpret_cast<char *> (&appo), sizeof(appo));  //read single activityList 
		}
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
	outfile.open("user.dat", std::ios::binary | std::ios::out);
	if(outfile.is_open()){
		//write the lists
		ActivityList appo("", "");
		for(auto it : categories){
			appo = *it; 
			outfile.write( reinterpret_cast<char*>( &appo), sizeof(ActivityList) );
		}
		outfile.close();
		this->notify();
	}else{
		std::cerr<<"Unable to write on file" << std::endl;
	}
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
	observers.push_back( o );
}

void User::detach(Observer * o){
	observers.remove( o );
}

void User::notify() const {
	for(auto obs : observers) {
		obs->update();
	}
}
