#include <sys/stat.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "User.h"


User::User(){
	load();
}

User::~User() { 
	outfile.close();
	for(auto obs : observers){
		delete obs;
	}
}


void User::load(){
	std::ifstream infile;
	infile.open("user.dat", std::ios::in | std::ios::binary);
	if(!infile.is_open()){ //if the file is not present, it is created
		addActivityList(std::shared_ptr<ActivityList> ( new ActivityList("Important Tasks", "Important Tasks") ) );
	}else{
		int size;
		infile.read( reinterpret_cast<char *> (&size), sizeof(int)); //Read the number of ActivityList
		std::string name, desc;
		int commNumber, strSize;
		for(int i = 0; i < size; i++){
		
			//read ActivityList's name and desc
			//name reading
			infile.read( reinterpret_cast<char *>( &strSize), sizeof(int)); // read string size
			char * buf = new char[strSize+1];
			infile.read( buf, strSize);
			buf[strSize] = '\0';
			name.assign(buf);
			
			//desc reading
			infile.read( reinterpret_cast<char *>( &strSize), sizeof(int)); // read string size
			buf = new char[strSize+1];
			infile.read( buf, strSize);
			buf[strSize] = '\0';
			desc.assign(buf);
			delete buf;
			
			std::shared_ptr<ActivityList> toAdd = std::make_shared<ActivityList> ( ActivityList(name, desc)); //the pointer to ActivityList is created 
			infile.read( reinterpret_cast<char *> (&commNumber), sizeof(int)); //the number of commitments is read
			for(int j =0; j < commNumber; j++){ //all the commitments are read
				toAdd->addCommitment( Commitment::load(infile) );
			} 
			categories.push_back(toAdd);
		}	
	}
	infile.close();
}

void User::save(){
	outfile.open("user.dat", std::ios::binary | std::ios::out);
	if(outfile.is_open()){
		int size = categories.size() ;
		outfile.write( reinterpret_cast<char*>( &( size) ), sizeof(int) ); //saves the number of activityList
		//write the lists
		for(auto it : categories){
		
			// writes activityList's name and description
			int strSize = it->getName().size();
			outfile.write( reinterpret_cast<char*>( &( strSize) ), sizeof(int) );
			outfile.write( it->getName().c_str(), strSize );
			strSize = it->getDescription().size();
			outfile.write( reinterpret_cast<char*>( &( strSize) ), sizeof(int) );
			outfile.write( it->getDescription().c_str(),strSize);
			
			
			int comSize = it->getCommitments().size();
			outfile.write( reinterpret_cast<char*>( &(comSize) ), sizeof(int) ); //saves the numb. of commitments
			for(auto comIt : it->getCommitments()){
				comIt.second.save(outfile); //save all commitments of the ActivityList
			}
		}
		outfile.close();
		this->notify();
	}else{
		std::cerr<<"Unable to write on file" << std::endl;
	}
}
void User::addActivityList(std::shared_ptr<ActivityList> al){
	if(std::find(categories.begin(), categories.end(), al) == categories.end() ){
		categories.push_back(al);
	}
	save();
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
