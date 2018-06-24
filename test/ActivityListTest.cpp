#include "gtest/gtest.h"

#include "../src/ActivityList.h"


TEST(ActivityList, Constructor) {
	ActivityList al("Test", "ActivityTest");
    	ASSERT_STREQ("Test", al.getName());
    	ASSERT_STREQ("ActivityTest", al.getName());
}

