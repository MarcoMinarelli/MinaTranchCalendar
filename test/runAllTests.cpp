#include "gtest/gtest.h"

/*#include "../src/Date.h"
#include "../src/Time.h"

TEST(Time, Constructor) {
   Time t(15, 42, 00);
    ASSERT_EQ(15, t.getHours());
    ASSERT_EQ(42, t.getMinutes());
    ASSERT_EQ(00, t.getSeconds());
}


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
*/
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
