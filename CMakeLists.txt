cmake_minimum_required(VERSION 2.8)
project (fifo)

enable_testing()

#Add related projects
add_subdirectory(test)


#Add include directories
include_directories("inc")


#Add sources
set(srcs src/fifo.c)


#Add Library
add_library(FIFO SHARED ${srcs})
add_test(TEST test/fifo_test)
