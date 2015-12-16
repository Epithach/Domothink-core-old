# Set the minimum version of cmake
# 3.4 was the original version of cmake at the begining of DomoThink
CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

# TEST
# TODO : think if it is the right place do put this
# Set the MAJOR, MINOR, PATCH and TWEAK variable
set(MAJOR 0)
set(MINOR 1)
set(PATCH 0)
set(TWEAK 0)

# Name of the project
# Not mandatory
# domothink 		: the name of the project
# VERSION <version>	: the description of the version of the project (SEMVER notation)
# LANGUAGES <name>	: the name of the language of the project	
project(domothink
		VERSION ${MAJOR}.${MINOR}.${PATCH}.${TWEAK}
		LANGUAGES CXX
		)

# TEST
# Turn to ON to see the command line CMake produces
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Create a NAME variable which store the name of the executable
SET(NAME domothink)

# Create a SRC variable to store the name of the source file
set(SRC Server/exception.cpp
		Server/main.cpp
		Server/server.cpp
		Server/utils.cpp)

# add_compile_options add flags for compilation
# Add warning flags
add_compile_options(-W -Wall -Wextra -Werror)

# Add include directories to the INCLUDE_DIRECTORIES variable
# CMAKE_ROOT is the root directory from where the first cmake is called
include_directories(Server/include)

# add_executable take the name of the executable produce and the sources
add_executable(${NAME} ${SRC})

# This command passed flag for the linker
target_link_libraries(${NAME}	-lboost_filesystem
								-lboost_system
								-lboost_thread
								-lpthread)
							
