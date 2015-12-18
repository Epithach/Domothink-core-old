# Install script for directory: /home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/libmysqlcppconn.so.7.1.1.6"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/libmysqlcppconn.so.7"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/libmysqlcppconn.so"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/libmysqlcppconn-static.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/mysql_connection.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/mysql_driver.h"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/mysql_error.h"
    )
endif()
