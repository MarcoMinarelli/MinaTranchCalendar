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
Time::Time(short unsigned int h, short unsigned int m, short unsigned int s) {
	if(h > 0 && h < 24){
		hours = h;
	}
	if( m > 0 && m < 61){
		minutes = m;
	}
	if( s > 0 && s < 61){
			seconds = s;
	}
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
Time::~Time() {}
