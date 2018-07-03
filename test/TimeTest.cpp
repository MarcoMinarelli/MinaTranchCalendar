#include "gtest/gtest.h"

#include "../src/Time.h"

TEST(Time, Constructor) {
   Time t(15, 42, 00);
   ASSERT_EQ(15, t.getHours());
   ASSERT_EQ(42, t.getMinutes());
   ASSERT_EQ(00, t.getSeconds());
}


TEST(Time, ExceptionThrows){
	try{
		Time t(-1, 42, 00);
		FAIL() << "Expected std::runtime_error"; 
	}catch(std::runtime_error const & err){
		EXPECT_EQ(err.what(),std::string("Error in number of hours"));
	}
}
