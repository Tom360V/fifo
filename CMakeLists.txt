cmake_minimum_required(VERSION 3.7)

project (fifo)

#Add related projects


#Add include directories
include_directories("inc")


#Add sources
set(srcs src/fifo.c)

if (TEST)
  list(APPEND srcs test/test.c)
endif()


add_library(FIFO SHARED ${srcs})
