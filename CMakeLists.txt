cmake_minimum_required(VERSION 3.8)

project(gruniovita)

if(TEST)
    INCLUDE("Linux.cmake")
else()
    INCLUDE("Vita.cmake")
endif()