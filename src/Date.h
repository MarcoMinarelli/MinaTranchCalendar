/*
 * Date.h
 *
*  Created on: 06 June 2018
 *      Author:Minarelli
 *      Coauthor:Tranchino
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <ostream>

class Date {
	public:
		Date(int aDay, int aMonth, int aYear);
		virtual ~Date();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);
		static Date today();
		bool operator < (const Date& right) const;

	private:
		short unsigned int day;
		short unsigned int month;
		short unsigned int year;
		int getMaxDays();
		std::string getMonthString(short unsigned int month) const;
};

#endif /* SRC_DATE_H_ */
