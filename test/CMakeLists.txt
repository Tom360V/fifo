cmake_minimum_required(VERSION 2.8)
project (fifo_TEST)

#Search for check.h
find_path(CHECK_INCLUDE_DIR NAMES check.h)
include_directories(${CHECK_INCLUDE_DIR})
include_directories(../inc)


#Set required libraries
find_library(LIBRARY_SUBUNIT NAMES subunit)

set(MyLIBS check m rt pthread)

if(LIBRARY_SUBUNIT)
  set(MyLIBS ${MyLIBS} ${LIBRARY_SUBUNIT})
endif(LIBRARY_SUBUNIT)

#foreach(x ${MyLIBS})
#  message("*** MyLibs: " ${x})
#endforeach(x ${MyLIBS})

#enter test sources here
set(testsrcs test.c)
  
#create executable
add_executable(fifo_test ${testsrcs})
target_link_libraries(fifo_test FIFO ${MyLIBS} )
