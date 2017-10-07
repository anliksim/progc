cmake_minimum_required(VERSION 3.8)
project(s05_list)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c src/list.h src/list.c src/person.h src/person.c)

add_executable(s05_list ${SOURCE_FILES})
