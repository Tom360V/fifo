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
  include_directories(${CHECK_INCLUDE_DIRS})

  set(testsrcs test/test.c)
  add_executable(fifo_test ${testsrcs})

  target_link_libraries(fifo_test FIFO
	libcheck.a
	libm.so
	librt.so
	libpthread.so
	libsubunit.so)

  add_test(FiFo fifo_test)
#endif()
