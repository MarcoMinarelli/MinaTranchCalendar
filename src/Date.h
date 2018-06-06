/*
 * Date.h
 *
*  Created on: 06 giu 2018
 *      Author: Minarelli
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_


class Date {
	public:
		Date(int aDay, int aMonth, int aYear);
		virtual ~Date();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		static Date today();
		bool operator < (const Date& right) const;

	private:
		int day;
		int month;
		int year;
};

#endif /* SRC_DATE_H_ */
