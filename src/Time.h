/*
 * Time.h
 *
 *  Created on: 06 June 2018
 *      Author: Minarelli
 *      Coauthor:Tranchino
 */

#include <stdexcept>

#ifndef SRC_TIME_H_
#define SRC_TIME_H_


class Time {
public:
	explicit Time(short unsigned int h, short unsigned int m, short unsigned int s) throw(std::runtime_error);
	virtual ~Time();
	
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	std::string toString();
	bool operator == (const Time& right) const;


private:
	short unsigned int hours;
	short unsigned int minutes;
	short unsigned int seconds;
};


#endif /* SRC_TIME_H_ */
