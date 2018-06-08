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
<<<<<<< HEAD
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
=======

	int getHours() const {
		return hours;
	}

	int getMinutes() const {
		return minutes;
	}

	int getSeconds() const {
		return seconds;
	}
>>>>>>> fa7914b284aad6b21d9e06d16d9785240d1c6c9b

private:
	int hours;
	int minutes;
	int seconds;
};


#endif /* SRC_TIME_H_ */
