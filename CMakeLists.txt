cmake_minimum_required(VERSION 3.3)
project(Calculator)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic-errors -Werror -ansi")

set(SOURCE_FILES
    main.c)

add_executable(Calculator ${SOURCE_FILES})