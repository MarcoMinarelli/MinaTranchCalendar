#include <string>
#include <memory>

#include "gtest/gtest.h"

#include "../src/ActivityList.h"
#include "../src/Commitment.h"
#include "../src/Date.h"
#include "../src/Time.h"

class ActivityListSuite : public ::testing::Test {

protected:

    ActivityList* al;
    ActivityList* anotherAl;
    
    virtual void SetUp() {
    	al = new ActivityList("Test", "ActivityTest");
    	anotherAl = new ActivityList("Al", "Another al");
    	
    	
        Commitment c(Date(12, 01, 18), Date(14, 01, 18), Time(static_cast<unsigned>(10), static_cast<unsigned>(00), static_cast<unsigned>(00)), Time(static_cast<unsigned>(12),static_cast<unsigned>(00), static_cast<unsigned>(00)), false, std::string("This is a note"), 
       std::string("www.loremipsum.com"));
        al->addCommitment(c);
    }
    
    virtual void TearDown(){
    	delete al;
    	delete anotherAl;
    }

    
};


TEST_F(ActivityListSuite, Constructor) {
    ASSERT_STREQ("Test", al->getName().c_str());
    ASSERT_STREQ("ActivityTest", al->getDescription().c_str());
}

TEST_F(ActivityListSuite, GetCommitments) {
    ASSERT_EQ(1, al->getCommitments().size());
    
    
    Commitment c(Date(14, 10, 18), Date(14, 10, 18), Time(static_cast<unsigned>(14), static_cast<unsigned>(00), static_cast<unsigned>(00)), Time(static_cast<unsigned>(15),static_cast<unsigned>(00), static_cast<unsigned>(00)), false, std::string("This is a note, again"), std::string("www.boh.com"));
        al->addCommitment(c);
    
    ASSERT_EQ(2, al->getCommitments().size());
    
   
}

TEST_F(ActivityListSuite, RemoveCommitment){
	Commitment c(Date(14, 10, 18), Date(14, 10, 18), Time(static_cast<unsigned>(14), static_cast<unsigned>(00), static_cast<unsigned>(00)), Time(static_cast<unsigned>(15),static_cast<unsigned>(00), static_cast<unsigned>(00)), false, std::string("This is a note, again"), std::string("www.boh.com"));
	 al->removeCommitment(c);
    
    ASSERT_EQ(1, al->getCommitments().size());
    //Here, we test that the remaining commitment has the proper values
    Commitment c1 = al->getCommitments().find(Date(12, 01, 18))->second;
    ASSERT_STREQ("This is a note",c1.getNotes().c_str());
    ASSERT_STREQ("www.loremipsum.com", c1.getUrl().c_str());
}


TEST_F(ActivityListSuite, EqualityOperator) {
    ASSERT_TRUE(*al == *al);
    
    ASSERT_FALSE(*al == *anotherAl);
}

