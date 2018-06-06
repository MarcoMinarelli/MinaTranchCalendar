/*
 * Date.cpp
 *
 *  Created on: 06 giu 2018
 *      Author: Minarelli
 */

#include "Date.h"
#include <chrono>
#include <ctime>
#include <iostream>
/**
 * Class constructor
 * @param aDay: The day in the month [1, 31]
 * @param aMonth: the month in the year [1, 12 ]
 * @param aYear: the year
 */
Date::Date(int aDay, int aMonth, int aYear) : day(aDay), month(aMonth), year(aYear){}

Date::~Date() {
}

/**
 * Method that allows to know the day
 */
int Date::getDay() const{
	return this->day;
};

/**
 * Method that allows to know the month
 */
int Date::getMonth() const{
	return this->month;
};

/**
 * Method that allows to know the year
 */
int Date::getYear() const{
	return this->year;
};

/**
 * Static method that allows to get the today's date
 */
Date Date::today(){
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm = *std::localtime(&now_c);;
	return Date(now_tm.tm_mday ,now_tm.tm_mon + 1, now_tm.tm_year + 1900);
}

bool Date::operator < (const Date& right) const{
	if ( this->year > right.year)
	    return false;
	else if (this->year == right.year) {
	    if (this->month > right.month)
	        return false;
	    else if (this->month == right.month) {
	        if (this->day >= right.day)
	            return false;
	    }
	}
	return true;
}
