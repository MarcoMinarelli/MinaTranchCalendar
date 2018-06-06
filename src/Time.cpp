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

Time::~Time() {}
