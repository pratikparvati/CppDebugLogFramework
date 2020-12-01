#----------------------------------------------------------------
# @brief - Build project 'cpplist' and 'test' for demo
# @author - Pratik Parvati (pratikparvati@gmail.com)
#----------------------------------------------------------------

cmake_minimum_required(VERSION 3.10.2)
#----------------------------------------------------------
#
#                 PROJECT CPPLIST
#
#------------------------------------------------------------

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

############# end of project cpplist ################################

#---------------------------------------------------------------------
#
#                 TEST PROJECT
#
#---------------------------------------------------------------------
project(dtest)

file(GLOB SOURCELIST
    src/dbglog.cpp
    test/test.cpp)

#add debug flag
add_definitions(-Wall -DDBGFLAG)

#include directories
include_directories(include)

# add source list to the executable
add_executable(dtest ${SOURCELIST})

############## end of project dtest #######################################

#---------------------------------------------------------------------
#
#                 DEMO PROJECT
#
#---------------------------------------------------------------------
project(demo)

file(GLOB SOURCELIST
    src/dbglog.cpp
    test/demo.cpp)

#add debug flag
add_definitions(-Wall -DDBGFLAG)

#include directories
include_directories(include)

# add source list to the executable
add_executable(demo ${SOURCELIST})

############## end of project demo #######################################



#------------------------------------------------------------------------
#
#                  GENERATE SHARED LIBRARY (libdbglog.so)
#
#-----------------------------------------------------------------------
project(sharedLib)

# set build type
set(CMAKE_BUILD_TYPE Debug)

# add include directory
include_directories(include)

# add source file/files
file(GLOB SOURCES src/dbglog.cpp)

# add shared library for the target build
add_library(dbglog SHARED ${SOURCES})

# path for make install
install(TARGETS dbglog DESTINATION build/lib)

####################### end of project sharedLib ########################

#------------------------------------------------------------------------
#
#               GENERATE STATIC LIBRARY (libdbglogStatic.a)
#
#-----------------------------------------------------------------------

project(staticLib)

# set build type
set(CMAKE_BUILD_TYPE Debug)

# add include directory
include_directories(include)

# add source file
file(GLOB SOURCES src/dbglog.cpp)

# add static library for the target build
add_library(dbglogStatic STATIC ${SOURCES})

# path for make install
install(TARGETS dbglogStatic DESTINATION build/lib)

##################### end of project staticLib ########################
