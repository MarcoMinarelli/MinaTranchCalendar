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
#include<list>
#include<memory>


#include "Commitment.h"
#include "Date.h"
#include "Observer.h"
#include "Subject.h"

class ActivityList : public Subject {
public:
	ActivityList(std::string n, std::string desc);
	virtual ~ActivityList();

	void addCommitment(Commitment toAdd);
	void removeCommitment(Commitment toDelete);
	const std::multimap<Date, Commitment>& getCommitments() const;
	const std::string& getDescription() const;
	const std::string& getName() const;
	bool operator == (const ActivityList& right) const;
	
	virtual void attach(Observer * o) override;
	virtual void detach(Observer * o) override;
	virtual void notify() const  override;

private:
	std::list < Observer* > observers;
	std::string name;
	std::string description;
	std::multimap<Date, Commitment> commitments;
};


#endif /* SRC_ACTIVITYLIST_H_ */
