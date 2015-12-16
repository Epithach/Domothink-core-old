# Install script for directory: /home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppconn" TYPE FILE FILES
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/build_config.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/config.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/connection.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/datatype.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/driver.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/exception.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/metadata.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/parameter_metadata.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/prepared_statement.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/resultset.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/resultset_metadata.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/statement.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/sqlstring.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/warning.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/version_info.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/variant.h"
    )
endif()

