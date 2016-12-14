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

# if test
#if (TEST)
  set(testsrcs test/test.c)
  add_executable(fifo_test ${testsrcs})
  target_link_libraries(fifo_test FIFO)
#endif()


#target_sources(fifo_test)
