cmake_minimum_required(VERSION 3.8)
project(s02_days)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/days.c src/main.c)

add_executable(s02_days ${SOURCE_FILES})
