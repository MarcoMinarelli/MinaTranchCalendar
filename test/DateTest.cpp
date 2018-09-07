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
		EXPECT_THROW(Date d(-1, 02, 2018), std::runtime_error ) ;
		EXPECT_THROW(Date d(123, 02, 2018), std::runtime_error ) ;
		EXPECT_THROW(Date d(11, -2, 2018), std::runtime_error ) ;
		EXPECT_THROW(Date d(11, 13, 2018), std::runtime_error ) ;
		EXPECT_THROW(Date d(11, 02, -1), std::runtime_error ) ;
		Date d(29, 02, 2016);
		EXPECT_THROW( d.setYear(2018), std::runtime_error );
		
}

