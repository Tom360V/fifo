cmake_minimum_required(VERSION 2.8)
project (fifo)

#Add include directories
include_directories("inc")

#Add sources
set(srcs src/fifo.c)

#Add Library
add_library(fifo SHARED ${srcs})
