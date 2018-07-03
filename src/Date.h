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
		explicit Date(int aDay, int aMonth, int aYear) throw (std::runtime_error);
		virtual ~Date();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		void setDay(int day) throw (std::runtime_error);
		void setMonth(int month) throw (std::runtime_error);
		void setYear(int year) throw (std::runtime_error);
		static Date today();
		bool operator < (const Date& right) const;

	private:
		short unsigned int day;
		short unsigned int month;
		short unsigned int year;
		int getMaxDays(int year);
		std::string getMonthString(short unsigned int month) const;
};

#endif /* SRC_DATE_H_ */
