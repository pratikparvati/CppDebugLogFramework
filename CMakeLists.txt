#----------------------------------------------------------------
# @brief - Build project 'cpplist' and 'test' for demo
# @author - Pratik Parvati (pratikparvati@gmail.com)
#----------------------------------------------------------------

cmake_minimum_required(VERSION 3.10.2)
project(cpplist)

# list the source file for the project
file(GLOB SOURCELIST 
    src/dbglog.cpp
    test/cpplist/src/*.cpp)

# add debug flag 
add_definitions(-Wall -DDBGFLAG)

# include directories
include_directories(include)
include_directories(test/cpplist/include)

# add source list to the executables
add_executable(cpplist ${SOURCELIST})
