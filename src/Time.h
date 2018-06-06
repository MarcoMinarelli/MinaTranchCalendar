/*
 * Time.h
 *
 *  Created on: 06 giu 2018
 *      Author: Minarelli
 */

#ifndef SRC_TIME_H_
#define SRC_TIME_H_


class Time {
public:
	Time(int h, int m, int s);
	virtual ~Time();

	int getHours() const {
		return hours;
	}

	int getMinutes() const {
		return minutes;
	}

	int getSeconds() const {
		return seconds;
	}

private:
	int hours;
	int minutes;
	int seconds;
};


#endif /* SRC_TIME_H_ */
