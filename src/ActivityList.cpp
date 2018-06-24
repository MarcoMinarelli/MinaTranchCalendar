/*
 * ActivityList.cpp
 *
 *  Created on: 08 giu 2018
 *      Author: Minarelli
 */

#include "ActivityList.h"

/**
	Costructor
	@param n: the name of the list
	@param desc: a list description
*/
ActivityList::ActivityList(std::string n, std::string desc):
	name(n), description(desc)
{
	std::multimap<Date, Commitment> commitments;
}

ActivityList::~ActivityList() {}

/**
	Method that allows to add a commitment to the list
	@param toAdd: the commitment that will be added
*/
void ActivityList::addCommitment(Commitment toAdd){
	commitments.insert(std::make_pair (toAdd.getStartDate(), toAdd) );
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
