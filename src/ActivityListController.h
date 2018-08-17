#ifndef SRC_ACTIVITYLISTCONTROLLER_H_
#define SRC_ACTIVITYLISTCONTROLLER_H_

#include<memory>

#include "ActivityList.h"
#include "Commitment.h"

class ActivityListController{

public:
	ActivityListController(std::shared_ptr<ActivityList> al) : activityList(al) { };
	~ActivityListController() { };
	
	void add(Commitment c);
	void remove(Commitment c);
	void setActivityList(std::shared_ptr<ActivityList> a);

private:
	std::shared_ptr<ActivityList> activityList;
};
#endif
