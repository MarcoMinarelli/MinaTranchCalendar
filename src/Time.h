/*
 * Time.h
 *
 *  Created on: 06 giu 2018
 *      Author: Tranchino
 */

#ifndef SRC_TIME_H_
#define SRC_TIME_H_


class Time {
public:
	Time(int h, int m, int s);
	virtual ~Time();
	
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

//rimossa la definizione dei metodi

private:
	int hours;
	int minutes;
	int seconds;
};


#endif /* SRC_TIME_H_ */
