cmake_minimum_required(VERSION 2.8)
project (Test_fifo)

enable_testing()


#Search for check.h
find_path(INCLUDE_DIR_CHECK   NAMES check.h)

include_directories(
    ${INCLUDE_DIR_CHECK}
    ../inc)

#Add HEAD project
add_subdirectory(../ FUT)



#Set required libraries
find_library(LIBRARY_SUBUNIT NAMES subunit)

set(MyLIBS check m rt pthread)

if(LIBRARY_SUBUNIT)
  set(MyLIBS ${MyLIBS} ${LIBRARY_SUBUNIT})
  message ("*** SUBUNIT FOUND ***")
else(LIBRARY_SUBUNIT)
  message ("*** SUBUNIT NOT FOUND ***")
endif(LIBRARY_SUBUNIT)

#foreach(x ${MyLIBS})
#  message("*** MyLibs: " ${x})
#endforeach(x ${MyLIBS})

#create executable
add_executable(test_fifo test.c)
target_link_libraries(test_fifo fifo ${MyLIBS} )


add_test(TEST_fifo test_fifo)
