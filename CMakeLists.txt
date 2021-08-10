cmake_minimum_required(VERSION 3.19)
project(INIReadWrite)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp IniFile.cpp IniFile.h)
add_executable(INIReadWrite ${SOURCE_FILES} IniFile.cpp IniFile.h)

add_library(core ${SOURCE_FILES})
target_link_libraries(INIReadWrite core)