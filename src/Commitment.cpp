/*
 * Commitment.cpp
 *
 *  Created on: 08 June 2018
 *      Author:Minarelli
 *      Coauthor:Tranchino
 */

#include "Commitment.h"

/**
	Costructor 
	@param start: the day (d / m / y) in which the commitment start
	@param end: the day (d/ m/ y) in which the commitment ends
	@param startT: the time (h / m / s) in which the commitment start
	@param endT: the time (h / m / s) in which the commitment end
	@param repeat: specifies if the commitment will be repeated
	@param note: the note that will be attached to the commitment
	@param u: the url of the commitment
	@param users: list of the users that will be involved in th commitment
*/
Commitment::Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u, std::string places, std::list< std::shared_ptr<User> > users)throw (std::runtime_error) : startDate(start), endDate(end), startTime(startT), endTime(endT), repeated(repeat), notes(note), url(u), place(places), involvedUsers(users){
				if(end < start){
					throw std::runtime_error("Error: end date is less than start date");
				}
				if(endT < startT && start == end){
					throw std::runtime_error("Error: end time is less than start time");
				}
			};

/**
	Costructor where the list of the users that will be involved in th commitment is initially empty
	@param start: the day (d / m / y) in which the commitment start
	@param end: the day (d/ m/ y) in which the commitment ends
	@param startT: the time (h / m / s) in which the commitment start
	@param endT: the time (h / m / s) in which the commitment end
	@param repeat: specifies if the commitment will be repeated
	@param note: the note that will be attached to the commitment
	@param u: the url of the commitment
*/
Commitment::Commitment(Date start, Date end, Time startT, Time endT, bool repeat,
			std::string note, std::string u, std::string places) throw (std::runtime_error) : startDate(start), endDate(end), startTime(startT), endTime(endT), repeated(repeat), notes(note), url(u), place(places), involvedUsers(){
				if(end < start){
					throw std::runtime_error("Error: end date is less than start date");
				}
				if(endT < startT && start == end){
					throw std::runtime_error("Error: end time is less than start time");
				}
			};



bool Commitment::operator == (const Commitment& right) const{
	return this->startDate == right.startDate &&
		 this->endDate == right.endDate &&
		 this->startTime == right.startTime &&
		 this->endTime == right.endTime &&
		 this->notes == right.notes &&
		 this->url == right.url;
}

void Commitment::save(std::ofstream& outfile){
	outfile.write( reinterpret_cast<char*>( &( startDate) ), sizeof(Date) );
	outfile.write( reinterpret_cast<char*>( &( endDate) ), sizeof(Date) );
	outfile.write( reinterpret_cast<char*>( &( startTime) ), sizeof(Time) );
	outfile.write( reinterpret_cast<char*>( &( endTime) ), sizeof(Time) );
	outfile.write( reinterpret_cast<char*>( &( repeated) ), sizeof(bool) );
	
	int size = notes.size();
	outfile.write ( reinterpret_cast<char*> ( &(size) ), sizeof(int)  );
	outfile.write( notes.c_str() , notes.size() );
	size = url.size();
	outfile.write ( reinterpret_cast<char*> ( &(size) ), sizeof(int)  );
	outfile.write( url.c_str(), url.size() );
	size = place.size();
	outfile.write ( reinterpret_cast<char*> ( &(size) ), sizeof(int)  );
	outfile.write( place.c_str(), place.size() );
	outfile.flush();
}


Commitment Commitment::load(std::ifstream& infile){
	Date start(1, 1, 2001), end (1 , 1, 2001);
	Time startT(12, 12, 12), endT(12, 12, 12);
	bool rep;
	std::string note, url, places;
	int size;
	
	
	infile.read( reinterpret_cast<char *>( &start), sizeof(Date));
	infile.read( reinterpret_cast<char *>( &end), sizeof(Date));
	infile.read( reinterpret_cast<char *>( &startT), sizeof(Time));
	infile.read( reinterpret_cast<char *>( &endT), sizeof(Time));
	infile.read( reinterpret_cast<char *>( &rep), sizeof(bool));
	
	infile.read( reinterpret_cast<char *>( &size), sizeof(int)); // read string size
	char * buf = new char[size+1];
	infile.read( buf, size);
	buf[size] = '\0';
	note.assign(buf);
	delete[] buf;
	infile.read( reinterpret_cast<char *>( &size), sizeof(int)); // read string size
	buf = new char[size+1];
	infile.read( buf, size);
	buf[size] = '\0';
	url.assign(buf);
	infile.read( reinterpret_cast<char *>( &size), sizeof(int)); // read string size
	buf = new char[size+1];
	infile.read( buf, size);
	buf[size] = '\0';
	places.assign(buf);
	delete[] buf;
	
	
	return Commitment(start, end, startT, endT, rep, note, url, places);
}
 /**
 	The following methods are getters
 */
const Date& Commitment::getEndDate() const {
	return endDate;
}

const Time& Commitment::getEndTime() const {
	return endTime;
}

const std::list< std::shared_ptr<User> >& Commitment::getInvolvedUsers() const {
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

const std::string& Commitment::getPlace() const {
	return place;
}
