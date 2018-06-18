/*
 * ActivityList.h
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#ifndef SRC_ACTIVITYLIST_H_
#define SRC_ACTIVITYLIST_H_

#include<iostream>
#include<map>

#include "Commitment.h"
#include "Date.h"

class ActivityList {
public:
	ActivityList(std::string n, std::string desc);
	virtual ~ActivityList();

	void addCommitment(Commitment toAdd);
	const std::multimap<Date, Commitment>& getCommitments() const;
	const std::string& getDescription() const;
	const std::string& getName() const;
	bool operator == (const Activity& right) const;


private:
	std::string name;
	std::string description;
	std::multimap<Date, Commitment> commitments;
};


#endif /* SRC_ACTIVITYLIST_H_ */
