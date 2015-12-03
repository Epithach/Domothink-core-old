# Install script for directory: C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MySQL/ConnectorCPP")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppconn" TYPE FILE FILES
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/build_config.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/config.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/connection.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/datatype.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/driver.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/exception.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/metadata.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/parameter_metadata.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/prepared_statement.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/resultset.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/resultset_metadata.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/statement.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/sqlstring.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/warning.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/version_info.h"
    "C:/Users/Maxime/GIT/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/variant.h"
    )
endif()

