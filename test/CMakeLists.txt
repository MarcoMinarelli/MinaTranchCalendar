#Test project
cmake_minimum_required(VERSION 3.5)


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES 
		../src/Date.h
		../src/Date.cpp
		../src/Time.h
		../src/Time.cpp
		../src/ActivityList.h
		../src/ActivityList.cpp
		../src/User.h
		../src/User.cpp
		../src/Commitment.h
		../src/Commitment.cpp )
		
add_library(core ${SOURCE_FILES} )

set(TEST_SOURCE_FILES runAllTests.cpp DateTest.cpp TimeTest.cpp  ActivityListFixture.cpp) 
add_executable(MinaTranchCalendarTests ${TEST_SOURCE_FILES})
target_link_libraries(MinaTranchCalendarTests gtest gtest_main core)

