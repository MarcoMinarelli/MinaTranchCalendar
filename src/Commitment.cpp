/*
 * Commitment.cpp
 *
 *  Created on: 08 giu 2018
 *      Author: marco
 */

#include "Commitment.h"


Commitment::Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u, std::list<User> users) :
			startDate(start), endDate(end), startTime(startT),
			endTime(endT), repeated(repeat), notes(note),
			url(u), involvedUsers(users){};

Commitment::Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u) :
			startDate(start), endDate(end), startTime(startT),
			endTime(endT), repeated(repeat), notes(note),
			url(u){
	std::list<User> involvedUsers;
};


Commitment::~Commitment() { }

const Date& Commitment::getEndDate() const {
	return endDate;
}

const Time& Commitment::getEndTime() const {
	return endTime;
}

const std::list<User>& Commitment::getInvolvedUsers() const {
	return involvedUsers;
}

const std::string& Commitment::getNotes() const {
	return notes;
}

bool Commitment::isRepeated() const {
	return repeated;
}

const Date& Commitment::getStartDate() const {
	return startDate;
}

const Time& Commitment::getStartTime() const {
	return startTime;
}

const std::string& Commitment::getUrl() const {
	return url;
}
