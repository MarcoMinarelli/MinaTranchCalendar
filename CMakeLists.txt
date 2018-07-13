cmake_minimum_required(VERSION 3.5)
project( Minarelli_Tranchino_Calendar )

set(CMAKE_CXX_STANDARD 11)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

#add test directory
add_subdirectory(test)



add_executable( Minarelli_Tranchino_Calendar src/main.cpp 
		#backend files
		src/Date.h
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
		
		#GUI files
		src/MainWindow.h
		src/MainWindow.cpp )

		
# Use the Widgets module from Qt 5.
target_link_libraries(Minarelli_Tranchino_Calendar Qt5::Widgets)
