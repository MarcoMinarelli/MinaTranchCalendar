/*
 * Date.cpp
 *
 *  Created on: 06 June 2018
 *      Author:Minarelli
 *      Coauthor:Tranchino
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
Date::Date(int aDay, int aMonth, int aYear) throw (std::runtime_error){
	if(aDay < 0)
		throw std::runtime_error("Days < 0");
	if(aMonth < 0 || aMonth > 12)
		throw std::runtime_error("Error in month number");
	this->month = aMonth;
	this->year = aYear;
	if (aDay > getMaxDays(this->year))
		 throw std::runtime_error("Error in number of days");
	this->day = aDay;

}

Date::~Date() {
}
/**
 * Get method
 */
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

int Date::getMaxDays(int year) {
    short unsigned int maxDay = 31;
    switch(month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
            maxDay = 30;
            break;
        case 2:{
            //TODO vedere se utile e possibile mettere insieme alcune condizioni
            //https://en.wikipedia.org/wiki/Leap_year#Algorithm
            if(this->year % 4 != 0 ){
                maxDay = 28;
                break;
            }else if(this->year % 100 !=0){
                maxDay = 29;
                break;
            }else if (this->year % 400 != 0){
                maxDay = 28;
                break;
            }else{
                maxDay = 29;
                break;
            }
        }
        //FIXME si puo' rimuovere per me il caso di defaul essendo inizializzato in precedenza
        default:
            maxDay = 31;
    }
    return maxDay;
}

std::string Date::getMonthString(short unsigned int month) const {
    std::string monthText;
    switch (month) {
        case 1:
            monthText = "January";
            break;
        case 2:
            monthText = "February";
            break;
        case 3:
            monthText = "March";
            break;
        case 4:
            monthText = "April";
            break;
        case 5:
            monthText = "May";
            break;
        case 6:
            monthText = "June";
            break;
        case 7:
            monthText = "July";
            break;
        case 8:
            monthText = "August";
            break;
        case 9:
            monthText = "September";
            break;
        case 10:
            monthText = "October";
            break;
        case 11:
            monthText = "November";
            break;
        case 12:
            monthText = "December";
            break;
        default:
            monthText = "isNotMonth";
    }
    return monthText;
}
/**
 * Set method
 */
void Date::setDay(int day) throw (std::runtime_error){
    int maxDay = getMaxDays(this->year);
    if (day <= 0 || day>maxDay)
        throw std::runtime_error("Error in day");
    Date::day = day;
}

void Date::setMonth(int month) throw (std::runtime_error){
    Date::month = month;
    int maxDay = getMaxDays(this->year);
    if (day>maxDay)
        day = maxDay;
}

void Date::setYear(int year) throw (std::runtime_error){
    if(day > getMaxDays(year))
    	throw std::runtime_error("Error in day after year modify");
    Date::year = year;
}

/**
 * Static method that allows to get the today's date
 */

Date Date::today(){
	//FIXME
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm = *std::localtime(&now_c);;
	return Date(now_tm.tm_mday ,now_tm.tm_mon + 1, now_tm.tm_year + 1900);
}

std::string Date::toString(){
	return std::string(day) + " " + month + " " + year;
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


bool Date::operator == (const Date& right) const{
	return this->year == right.year && this->month == right.month && this->day == right.day;
}
