# Install script for directory: /home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/README"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/INSTALL"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/COPYING"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/Licenses_for_Third-Party_Components.txt"
    "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/ANNOUNCEMENT"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE OPTIONAL FILES "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/BUILDINFO")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/cppconn/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/driver/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/examples/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/test/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/test/framework/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/test/CJUnitTestsPort/cmake_install.cmake")
  include("/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/test/unit/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/home/astyr/Documents/EIP---HTTPS_SRV/test/mysql/mysql-connector-c++-1.1.6/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
