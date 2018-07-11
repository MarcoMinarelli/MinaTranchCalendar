/*
 * Time.cpp
 *
 *  Created on: 06 giu 2018
 *      Author: Minarelli
 *      Co-author:Tranchino
 */

#include "Time.h"


/**
	Costructor
	@param h: the hour of the day [0, 23]
	@param m: the minute of the hour [1, 60]
	@þaram s: the seconds in the minutes [1, 60]
*/
Time::Time(short unsigned int h, short unsigned int m, short unsigned int s) throw(std::runtime_error){
	if(h < 0 || h > 24){
		throw std::runtime_error("Error in number of hours");
	}
	if( m < 0 || m > 60){
		throw std::runtime_error("Error in number of minutes");
	}
	if( s < 0 || s > 6){
		throw std::runtime_error("Error in number of seconds");
	}
	hours = h;
	minutes = m;
	seconds = s;
}


bool Time::operator == (const Time& right) const{
	return this->hours == right.hours && this->minutes == right.minutes && this->seconds == right.seconds;

}

Time::~Time() { }

/**
	The followng methods are easy getters
*/
int Time::getHours() const {
	return hours;
}

int Time::getMinutes() const {
	return minutes;
}

int Time::getSeconds() const {
	return seconds;
}
