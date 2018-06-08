/*
 * ActivityList.cpp
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#include "ActivityList.h"


ActivityList::ActivityList(std::string n, std::string desc):
	name(n), description(desc)
{
	std::multimap<Date, Commitment> commitments;
}

ActivityList::~ActivityList() {}

void ActivityList::addCommitment(Commitment toAdd){
	commitments.insert(std::make_pair (toAdd.getStartDate(), toAdd) );
}

const std::multimap<Date, Commitment>& ActivityList::getCommitments() const {
	return commitments;
}

const std::string& ActivityList::getDescription() const {
	return description;
}

const std::string& ActivityList::getName() const {
	return name;
}
