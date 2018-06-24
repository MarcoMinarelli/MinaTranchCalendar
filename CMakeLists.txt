cmake_minimum_required(VERSION 3.5)
project( Minarelli_Tranchino_Calendar )

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 ")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})


add_subdirectory(test)


set(SOURCE_FILES src/Date.h
		 src/Date.cpp
		 src/Time.h
		 src/Time.cpp
		 src/ActivityList.h
		 src/ActivityList.cpp
		 src/User.h
		 src/User.cpp
		 src/Commitment.h
		 src/Commitment.cpp
		 src/Observer.h
		 src/Subject.h
		 )

add_executable( Minarelli_Tranchino_Calendar src/main.cpp )

add_library(core ${SOURCE_FILES})		
		
target_link_libraries(Minarelli_Tranchino_Calendar core)	
		











