#include "gtest/gtest.h"

#include "../src/Time.h"

TEST(Time, Constructor) {
   Time t(15, 42, 00);
    ASSERT_EQ(15, t.getHours());
    ASSERT_EQ(42, t.getMinutes());
    ASSERT_EQ(00, t.getSeconds());
}


//TODO implement test for minority operator
/*TEST(Time, minorityOperator) {
    Date d1(15, 02, 2018) ;
    Date d2(16, 05, 2018) ;
    ASSERT_TRUE(d1 < d2);
    Date d3(14, 01, 2016) ;
    ASSERT_FALSE(d1< d3);
}*/
