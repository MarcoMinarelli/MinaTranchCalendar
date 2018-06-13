/*
 * Observer.h
 *
 *  Created on: 13 June 2018
 *      Author: Minarelli
 *      Coauthor:Tranchino
 */
 

#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_



class Observer{
public:
	virtual void update() = 0;
	
protected:
	virtual ~Observer() { };

}
#endif /* SRC_OBSERVER_H_ */
