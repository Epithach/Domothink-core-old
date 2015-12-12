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
set(CMAKE_VERBOSE_MAKEFILE ON)

# Create a NAME variable which store the name of the executable
SET(NAME domothink)

# Create a SRC variable to store the name of the source file
set(SRC Server/exception.cpp
		Server/main.cpp
		Server/server.cpp
		Server/utils.cpp)

set(BOOST_ROOT deps/boost_1_59_0)
set(BOOST_LIBRARYDIR deps/boost_1_59_0/lib32-msvc-14.0)
find_package(Boost
             1.59.0
             REQUIRED
             filesystem-vc140-mt-gd-1_59 system-vc140-mt-gd-1_59 thread-vc140-mt-gd-1_59)

add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINTIONS})

# add_compile_options add flags for compilation
if (UNIX)
    add_compile_options(-W -Wall -Wextra -Werror)   # Warning for g++ / clang++
elseif (WIN32)
    add_compile_options(/Wall)  # Warning for cl
    add_compile_options(/EHsc)  # Enable exception handling
endif (UNIX)

# Add include directories to the INCLUDE_DIRECTORIES variable
include_directories(Server/include)
include_directories(deps/boost_1_59_0)
if (WIN32)
    include_directories(deps/boost_1_59_0/lib32-msvc-14.0)
endif (WIN32)

# add_executable take the name of the executable produce and the sources
add_executable(${NAME} ${SRC})

# passed flag for the linker
if (UNIX)
    target_link_libraries(${NAME}	-lboost_filesystem
                                    -lboost_system
                                    -lboost_thread
                                    -lpthread)
elseif (WIN32)
    target_link_libraries(${NAME}   test/mysql/mysql-connector-c++-1.1.6/libmysqlcppconn/mysqlcppconn
                                    ${Boost_LIBRARIES})
endif (UNIX)
