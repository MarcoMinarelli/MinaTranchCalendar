#include <algorithm>

#include "ActivityList.h"


/**
	Costructor
	@param n: the name of the list
	@param desc: a list description
*/
ActivityList::ActivityList(std::string n, std::string desc):
	name(n), description(desc), observers()
{
	std::multimap<Date, Commitment> commitments;
}

ActivityList::~ActivityList() {
	for(auto obs : observers){
		delete obs;
	}
}

/**
	Method that allows to add a commitment to the list
	@param toAdd: the commitment that will be added
*/
void ActivityList::addCommitment(Commitment toAdd){
	
	if(std::none_of(commitments.begin(), commitments.end(),
                   [&toAdd](const std::pair<Date, Commitment>& c)
                   { return c.second == toAdd; }))
    {
		commitments.insert(std::make_pair (toAdd.getStartDate(), toAdd) );
		this->notify();
	}
}

/**
	Method that allows to remove a commitment to the list. If the Commitment is not present, then nothing is done
	@param toAdd: the commitment that will be removed
*/
void ActivityList::removeCommitment(Commitment toDelete){
	bool found = false;
	for(auto it = commitments.equal_range(toDelete.getStartDate()).first; it != commitments.equal_range(toDelete.getStartDate()).second && !found; it++){
		if(it->second == toDelete){
			commitments.erase(it);
			found = true;
			break;
		}
	}
	this->notify();
}

void ActivityList::attach(Observer * o){
	observers.push_back( o );
}

void ActivityList::detach(Observer * o){
	observers.remove( o );
}

void ActivityList::notify() const{  
	//std::cout << name << " obs " << observers.size() << std::endl;
	for(auto obs : observers){
		obs->update();
	}
}


bool ActivityList::operator == (const ActivityList& right) const{
	return (description == right.description) && (name == right.name);
}

/**
	The following methods are getters
*/
const std::multimap<Date, Commitment>& ActivityList::getCommitments() const {
	return commitments;
}

const std::string& ActivityList::getDescription() const {
	return description;
}

const std::string& ActivityList::getName() const {
	return name;
}
