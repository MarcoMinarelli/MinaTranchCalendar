#ifndef SRC_USER_H_
#define SRC_USER_H_

#include <vector>
#include <list>
#include <fstream>
#include <memory>

#include "ActivityList.h"
#include "Subject.h"
#include "Observer.h"

class User : public Subject{
public:
	User();
	virtual ~User();
	void addActivityList(std::shared_ptr<ActivityList> al);
	void removeActivityList(std::string name);
	std::vector< std::shared_ptr<ActivityList> > getActivityLists();
	virtual void attach(Observer * o) override;
	virtual void detach(Observer * o) override;
	virtual void notify() const override;
	
private:
	std::list < Observer* > observers;
	std::vector< std::shared_ptr<ActivityList> > categories;
	std::ofstream outfile;
};


#endif /* SRC_USER_H_ */
