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
#include <fstream>

#include "Date.h"
#include "Time.h"

class User;

class Commitment {
public:


	explicit Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u, std::string places, std::list< std::shared_ptr<User> > users) throw (std::runtime_error);
	explicit Commitment(Date start, Date end, Time strartT, Time endT, bool repeat,
				std::string note, std::string u, std::string places) throw (std::runtime_error);
	~Commitment() { };
	const Date& getEndDate() const;
	const Time& getEndTime() const;
	const std::list< std::shared_ptr<User> >& getInvolvedUsers() const;
	const std::string& getNotes() const;
	bool isRepeated() const;
	const Date& getStartDate() const;
	const Time& getStartTime() const;
	const std::string& getUrl() const;
	const std::string& getPlace() const;
	bool operator == (const Commitment& right) const;
	void save(std::ofstream& outfile);
	static Commitment load(std::ifstream& infile);
	
private:
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	bool repeated;
	std::string notes;
	std::string url;
	std::string place;
	std::list< std::shared_ptr<User> > involvedUsers;
};


#endif /* SRC_COMMITMENT_H_ */
