#include "gtest/gtest.h"

#include "../src/Date.h"

TEST(Date, Constructor) {
    Date d(15, 02, 2018);
    ASSERT_EQ(15, d.getDay());
    ASSERT_EQ(02, d.getMonth());
    ASSERT_EQ(2018, d.getYear());
}


TEST(Date, minorityOperator) {
    Date d1(15, 02, 2018) ;
    Date d2(16, 05, 2018) ;
    ASSERT_TRUE(d1 < d2);
    Date d3(14, 01, 2016) ;
    ASSERT_FALSE(d1< d3);
}


TEST(Date, fromString) {
    std::string s = "12:12:2012";
    Date d = Date::fromString(s);
    ASSERT_EQ(12, d.getDay());
    ASSERT_EQ(12, d.getMonth());
    ASSERT_EQ(2012, d.getYear());
}


TEST(Date, ExceptionThrows){
	try{
		Date d(123, 02, 2018);
		FAIL() << "Expected std::runtime_error";
	}catch(std::runtime_error const & err){
		EXPECT_EQ(err.what(),std::string("Error in number of days"));
	}
	
	try{
		Date d(1, -1, 2018);
		FAIL() << "Expected std::runtime_error";
	}catch(std::runtime_error const & err){
		EXPECT_EQ(err.what(),std::string("Error in month number"));
	}
	
	try{
		Date d(1, 29, 2016);
		d.setYear(2018);
		FAIL() << "Expected std::runtime_error";
	}catch(std::runtime_error const & err){
		EXPECT_EQ(err.what(),std::string("Error in month number"));
	}
}

