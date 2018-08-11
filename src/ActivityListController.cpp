#include "ActivityListController.h"

void ActivityListController::add(Commitment c){
	activityList->addCommitment(c);
}

void ActivityListController::remove(Commitment c){
	activityList->removeCommitment(c);
}
