#include "gtest/gtest.h"


#include "../src/ActivityList.h"
#include "../src/Commitment.h"
#include "../src/Date.h"
#include "../src/Time.h"

class ActivityListSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        Commitment c(Date(12, 01, 18), Date(14, 01, 18), Time(10, 00), Time(12,00), false, "This is a note", "This is a description", "www.loremipsum.com");
        al.addCommitment(c);
    }

    ActivityList al("Test", "ActivityTest");
    ActivityList anotherAl("Al", "Another al");
};


TEST_F(ActivityList, Constructor) {
    ASSERT_STREQ("Test", al.getName());
    ASSERT_STREQ("ActivityTest", al.getName());
}

TEST_F(ActivityList, GetCommitments) {
    ASSERT_EQ(1, al.getCommitments().size());
    
    Commitment c(Date(14, 10, 18), Date(14, 10, 18), Time(14, 00), Time(16,00), false, "This is a note, again", "This is another description", "www.boh.com");
        al.addCommitment(c);
    
    ASSERT_EQ(2, al.getCommitments().size());
}

TEST_F(ActivityList, GetCommitments) {
    ASSERT_TRUE(al == al);
    
    ASSERT_FALSE(al == anotherAl);
}

