cmake_minimum_required(VERSION 2.8)
project( Minarelli_Tranchino_Calendar )
#find_package( OpenCV REQUIRED )

#aggiungo flag per l'utilizzo dei thread

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 ")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

#aggiungo i file eseguibili
add_executable( Minarelli_Tranchino_Calendar 
		src/main.cpp
		src/Date.h
		src/Date.cpp
		src/Time.h
		src/Time.cpp
		)
#target_link_libraries( light_inv ${OpenCV_LIBS} )