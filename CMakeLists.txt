cmake_minimum_required(VERSION 2.8)
project (fifo)

#Add related projects

#Add include directories
include_directories("inc")

#Add sources
set(srcs src/fifo.c)


#Add Library
add_library(FIFO SHARED ${srcs})

#######################################

#if (TEST)
  enable_testing()

  #Search for check.h
  FIND_PATH(CHECK_INCLUDE_DIR NAMES check.h)
  FIND_LIBRARY(LIBRARY_CHECK   NAMES check)
  FIND_LIBRARY(LIBRARY_SUBUNIT NAMES subunit)

  message("*** LIB SUBUNIT :" ${LIBRARY_SUBUNIT})
  message("*** LIB CHECK   :" ${LIBRARY_CHECK})
  message("*** Check path:" ${CHECK_INCLUDE_DIR})
  include_directories(${CHECK_INCLUDE_DIR})

  #enter test sources here
  set(testsrcs test/test.c)
  
  #create executable
  add_executable(fifo_test ${testsrcs})
  target_link_libraries(fifo_test FIFO
	${LIBRARY_CHECK}
	${LIBRARY_SUBUNIT}
	libm.so
	librt.so
	libpthread.so)

  add_test(FiFo fifo_test)
#endif()
