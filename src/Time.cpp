/*
 * Time.cpp
 *
 *  Created on: 06 giu 2018
 *      Author: Minarelli
 */

#include "Time.h"



Time::Time(int h, int m, int s) {
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

<<<<<<< HEAD
Time::~Time() {
}

int Time::getHours() const {
	return hours;
}

int Time::getMinutes() const {
	return minutes;
}

int Time::getSeconds() const {
	return seconds;
}
=======
Time::~Time() {}
>>>>>>> fa7914b284aad6b21d9e06d16d9785240d1c6c9b
