###########
# Project #
###########

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
# TODO : at the end delete the line
# Turn to ON to see the command line CMake produces
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Create a NAME variable which store the name of the executable
SET(NAME domothink)

################
# Dependencies #
################

# Check for the presence of the Boost libraries
set(BOOST_ROOT deps/boost_1_59_0)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib32-msvc-14.0)
find_package(Boost 1.59.0 REQUIRED
             filesystem system thread unit_test_framework)

# Check for the presence of the PostgreSQL libraries
find_package(PostgreSQL 9.4.0 REQUIRED)

###########
# Sources #
###########

set(SRC_PATH src)

set(SERVER_PATH ${SRC_PATH})

set(SERVER_SRC  src/exception.cpp
                src/main.cpp
                src/server.cpp
                src/utils.cpp)

set(API_PATH ${SRC_PATH}/api)

set(DB_PATH ${API_PATH}/db)

if (PostgreSQL_FOUND)
    set(DB_PATH ${API_PATH}/PostgreSQL)
    set(DB_SRC ${DB_PATH}/src/postgre.cpp)
endif (PostgreSQL_FOUND)

set(SRC ${SERVER_SRC} ${DB_SRC})

#####################
# Compilation rules #
#####################

# add_compile_options add flags for compilation
if (UNIX)
    add_compile_options(-W -Wall -Wextra -Werror)   # Warning for g++ / clang++
    add_compile_options(--std=c++14)                # Specify C++ version
elseif (WIN32)
    add_compile_options(/Wall)  # Warning for cl
    add_compile_options(/EHsc)  # Enable exception handling
endif (UNIX)

# Disable auto linking for the boost libraries.
# Without this definition, compiler (at least cl.exe) cannot link the Boost
# libraries.
add_definitions(-D BOOST_ALL_NO_LIB)

# Add include directories to the INCLUDE_DIRECTORIES variable
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(${SERVER_PATH}/include)
include_directories(${DB_PATH}/include)

###############
# Build rules #
###############

# add_executable take the name of the executable produce and the sources
add_executable(${NAME} ${SRC})

# passed flag for the linker
if (UNIX)
    target_link_libraries(${NAME}	-lboost_filesystem
                                    -lboost_system
                                    -lboost_thread
                                    -lpthread)
elseif (WIN32)
    target_link_libraries(${NAME}
                                    ${Boost_LIBRARIES}
                                    ${PostgreSQL_LIBRARIES}
                                    )
                                    #test/mysql/mysql-connector-c++-1.1.6/libmysqlcppconn/mysqlcppconn
endif (UNIX)
