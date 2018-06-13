/*
 * Time.h
 *
 *  Created on: 06 June 2018
 *      Author: Minarelli
 *      Coauthor:Tranchino
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
	short unsigned int hours;
	short unsigned int minutes;
	short unsigned int seconds;
};


#endif /* SRC_TIME_H_ */
