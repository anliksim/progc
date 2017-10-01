cmake_minimum_required(VERSION 3.8)
project(s03_arrays)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c src/marks.h src/marks.c)

add_executable(s03_arrays ${SOURCE_FILES})
