#include "gtest/gtest.h"

#include "../src/Time.h"

TEST(Time, Constructor) {
   Time t(15, 42, 00);
   ASSERT_EQ(15, t.getHours());
   ASSERT_EQ(42, t.getMinutes());
   ASSERT_EQ(00, t.getSeconds());
}


TEST(Time, ExceptionThrows){
		EXPECT_THROW(Time t(-1, 42, 00), std::runtime_error );
		EXPECT_THROW(Time t(100, 42, 00), std::runtime_error );
		EXPECT_THROW(Time t(1, -1, 00), std::runtime_error );
		EXPECT_THROW(Time t(1, 100, 00), std::runtime_error );
		EXPECT_THROW(Time t(1, 42, -1), std::runtime_error );
		EXPECT_THROW(Time t(1, 42, 100), std::runtime_error );
}

TEST(Time, fromString){
	std::string s = "10:03:05";
	Time t = Time::fromString(s);
	ASSERT_EQ(10, t.getHours());
   	ASSERT_EQ(03, t.getMinutes());
   	ASSERT_EQ(05, t.getSeconds());
}
