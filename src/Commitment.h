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

#include "Date.h"
#include "Time.h"
#include "User.h"

class Commitment {
public:
	Commitment(Date start, Date end, Time strartT, Time endT, bool repeat,
			std::string note, std::string url, std::list<User> users);
	Commitment(Date start, Date end, Time strartT, Time endT, bool repeat,
				std::string note, std::string url);
	const Date& getEndDate() const;
	const Time& getEndTime() const;
	const std::list<User>& getInvolvedUsers() const;
	const std::string& getNotes() const;
	bool isRepeated() const;
	const Date& getStartDate() const;
	const Time& getStartTime() const;
	const std::string& getUrl() const;

private:
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	bool repeated;
	std::string notes;
	std::string url;
	std::list<User> involvedUsers;
};


#endif /* SRC_COMMITMENT_H_ */
