cmake_minimum_required(VERSION 2.8)
project (Test_fifo)

#Search for check.h
find_path(CHECK_INCLUDE_DIR NAMES check.h)
include_directories(${CHECK_INCLUDE_DIR})
include_directories(../inc)


#Set required libraries
find_library(LIBRARY_SUBUNIT NAMES subunit)

set(MyLIBS check m rt pthread subunit)

#if(LIBRARY_SUBUNIT)
#  set(MyLIBS ${MyLIBS} ${LIBRARY_SUBUNIT})
#  message ("*** SUBUNIT FOUND ***")
#endif(LIBRARY_SUBUNIT)

#foreach(x ${MyLIBS})
#  message("*** MyLibs: " ${x})
#endforeach(x ${MyLIBS})

#create executable
add_executable(test_fifo test.c)
target_link_libraries(test_fifo FIFO ${MyLIBS} )
