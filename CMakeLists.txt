cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # not necessary, but encouraged
project(generator)

#
# set vars
#
SET(LIB_NAME "generator")

#
# wrangle files
#
include_directories("include/")

file(GLOB LIB_SOURCES "src/*.cc")

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})


#
# install the lib and include files for use
#
install(TARGETS ${LIB_NAME} DESTINATION lib)

install(DIRECTORY include/ DESTINATION include/
        FILES_MATCHING PATTERN "*.hh")
        



