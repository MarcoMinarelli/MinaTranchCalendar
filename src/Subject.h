/*
 * Subject.h
 *
 *  Created on: 13 June 2018
 *      Author: Minarelli
 *      Coauthor:Tranchino
 */
 
#include "Observer.H"
#include <list>
#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_



class Subject{
public:
	virtual void attach(Observer * o) = 0;
	virtual void detach(Observer * o) = 0;
	virtual void notify() const  = 0;
	
protected:
	virtual ~Subject() { };

}
#endif /* SRC_SUBJECT_H_ */
