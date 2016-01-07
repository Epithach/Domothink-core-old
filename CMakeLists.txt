###########
# Project #
###########

# Set the minimum version of cmake
# 3.4 was the original version of cmake at the begining of DomoThink
CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

# Set the MAJOR, MINOR, PATCH and TWEAK variable
set(MAJOR 0)
set(MINOR 1)
set(PATCH 0)
set(TWEAK 0)

# Name of the project
# Not mandatory
# DomoThink 				: the name of the project
# VERSION <version>	: the description of the version of the project (SEMVER notation)
# LANGUAGES <name>	: the name of the language of the project
project(DomoThink
		VERSION ${MAJOR}.${MINOR}.${PATCH}.${TWEAK}
		LANGUAGES CXX
		)

# Create a NAME variable which store the name of the executable
set(NAME domothink)

# TODO : delete
# The name of the API library
set(API_NAME domothink_api)

# Specify the architectur of the destination platform
# Since we use the Raspberry Pi 2 we need to build in 32bits because it is in ARMv7
# TODO : check for an arch package or create it !
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(HOST_IS_64BIT TRUE)
  set(HOST_IS_32BIT FALSE)
else ()
  set(HOST_IS_64BIT FALSE)
  set(HOST_IS_32BIT TRUE)
endif (CMAKE_SIZEOF_VOID_P EQUAL 8)

set(TARGET_ARCH "ARMv7")
if (${TARGET_ARCH} STREQUAL "ARMv7")
  set(TARGET_IS_64BIT FALSE)
  set(TARGET_IS_32BIT TRUE)
endif ()

if (UNIX AND HOST_IS_64BIT AND TARGET_IS_32BIT)
  set(TARGET_CPU_ARCH 32)
endif ()

################
# Dependencies #
################

# Check for the presence of the Boost libraries
if (WIN32)
  set(BOOST_ROOT deps/boost_1_59_0)
  set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib32-msvc-14.0)
endif()
find_package(Boost 1.59.0 REQUIRED
             filesystem system thread unit_test_framework)

# Replace the lib64 with lib32 when cross compiling for 32bits
if (UNIX AND TARGET_IS_32BIT)
  foreach(lib IN LISTS Boost_LIBRARIES)
	  string(REGEX REPLACE "lib64" "lib32" lib32_path ${lib})
		list(APPEND TMP_Boost_LIBRARIES ${lib32_path})
  endforeach(lib)
	set(Boost_LIBRARIES ${TMP_Boost_LIBRARIES})
endif ()

if(NOT EXISTS DB)
  set(DB MySQL)
endif()

# Check for the presence of the PostgreSQL libraries
if ("${DB}" STREQUAL PostgreSQL)
	find_package(PostgreSQL 9.4.5 REQUIRED)
    if (WIN32)
	set(PostgreSQL_LIBRARIES "/Program Files (x86)/PostgreSQL/9.4/lib/libpq.lib")
    endif (WIN32)
endif()

# TODO: finish package MySQL
#find_package(MySQL REQUIRED
#             cxx_connector 1.1.6)
if ("${DB}" STREQUAL MySQL)
    if (UNIX)
	if (TARGET_IS_32BIT)
	  set(MySQL_LIBRARIES /usr/lib32/libmysqlcppconn.so)
	else ()
	  set(MySQL_LIBRARIES mysqlcppconn)
	endif (TARGET_IS_32BIT)
    elseif (WIN32)
	set(MySQL_LIBRARIES "/Program Files (x86)/MySQL/MySQL Connector C++ 1.1.6/lib/opt/mysqlcppconn.lib")
    endif(UNIX)
    set(MySQL_FOUND TRUE)
endif ()

if (MySQL_FOUND)
  set(DB_LIBRARIES ${MySQL_LIBRARIES})
elseif (PostgreSQL_FOUND)
  set(DB_LIBRARIES ${PostgreSQL_LIBRARIES})
endif (MySQL_FOUND)

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
set(DB_SRC ${DB_PATH}/DataBaseException.cpp)

if (PostgreSQL_FOUND)
    set(SQL_PATH ${DB_PATH}/PostgreSQL)
    set(SQL_SRC ${SQL_PATH}/postgre.cpp)
endif (PostgreSQL_FOUND)

if (MySQL_FOUND)
    set(SQL_PATH ${DB_PATH}/MySQL)
    set(SQL_SRC ${SQL_PATH}/mysql.cpp
				${SQL_PATH}/MySQLException.cpp
				${SQL_PATH}/mainMySQL.cpp) ## Main de test à delete
endif (MySQL_FOUND)

set(SRC ${SERVER_SRC} ${DB_SRC} ${SQL_SRC})

#####################
# Compilation rules #
#####################

# Choose the compiler : default 'g++' or you can pass your custom compiler through the CXX definition
if (NOT ${CXX})
  set(CMAKE_CXX_COMPILER g++)
else (CXX)
  set(CMAKE_CXX_COMPILER ${CXX})
endif()

# add_compile_options add flags for compilation
if (UNIX)
    add_compile_options(-W -Wall -Wextra -Werror)   # Warning for g++ / clang++
    add_compile_options(--std=c++14)                # Specify C++ version
		if (HOST_IS_64BIT AND TARGET_IS_32BIT)
        add_compile_options(-m32)                   # Specify the CPU architectur destination
		endif (HOST_IS_64BIT AND TARGET_IS_32BIT)
elseif (WIN32)
#    add_compile_options(/Wall)  # Warning for cl
    add_compile_options(/EHsc)  # Enable exception handling
    add_compile_options(/D_WIN32_WINNT=0x501)

# Disable auto linking for the boost libraries.
# Without this definition, compiler (at least cl.exe) cannot link the Boost
# libraries.
  add_definitions(-D BOOST_ALL_NO_LIB)

endif (UNIX)

# Add include directories to the INCLUDE_DIRECTORIES variable
include_directories(${Boost_INCLUDE_DIRS})

if (PostgreSQL_FOUND)
    include_directories(${PostgreSQL_INCLUDE_DIRS})
endif (PostgreSQL_FOUND)

if (MySQL_FOUND)
    if (WIN32)
        include_directories("/Program Files (x86)/MySQL/MySQL Connector C++ 1.1.6/include")
    endif(WIN32)
endif (MySQL_FOUND)

include_directories(${SERVER_PATH})
include_directories(${DB_PATH})
include_directories(${SQL_PATH})

###############
# Build rules #
###############

# TODO : delete if change web api design
# Create the API shared library
#add_library(${API_NAME} SHARED ${DB_SRC})

# TODO : delete if change web api design
# Link the api shared library and passed flag for the linker
#target_link_libraries(${API_NAME}   ${DB_LIBRARIES})

# add_executable take the name of the executable produce and the sources
add_executable(${NAME} ${SRC})

# Link the executable and passed flag for the linker
target_link_libraries(${NAME}  ${Boost_LIBRARIES}
                               ${DB_LIBRARIES}
			       -m32
				)
