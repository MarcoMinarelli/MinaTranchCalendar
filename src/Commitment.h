/*
 * Commitment.h
 *
 *  Created on: 08 June 2018
 *      Author: Minarelli
 *		Coauthor:Tranchino
 */

#ifndef SRC_COMMITMENT_H_
#define SRC_COMMITMENT_H_

#include <iostream>
#include <list>
#include <memory>

#include "Date.h"
#include "Time.h"

class User;

class Commitment {
public:


	explicit Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u, std::list< std::shared_ptr<User> > users);
	explicit Commitment(Date start, Date end, Time strartT, Time endT, bool repeat,
				std::string note, std::string u);
	const Date& getEndDate() const;
	const Time& getEndTime() const;
	const std::list< std::shared_ptr<User> >& getInvolvedUsers() const;
	const std::string& getNotes() const;
	bool isRepeated() const;
	const Date& getStartDate() const;
	const Time& getStartTime() const;
	const std::string& getUrl() const;
	bool operator == (const Commitment& right) const;

private:
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	bool repeated;
	std::string notes;
	std::string url;
	std::list< std::shared_ptr<User> > involvedUsers;
};


#endif /* SRC_COMMITMENT_H_ */
