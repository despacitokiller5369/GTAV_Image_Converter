cmake_minimum_required(VERSION 3.10)

project(gtav_converter)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    main.c
)

add_executable(gtav_converter ${SOURCES})
