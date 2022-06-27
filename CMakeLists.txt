cmake_minimum_required(VERSION 3.5)

project(BoostAsioExamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED python)
find_package(Python3 COMPONENTS Development REQUIRED)

add_subdirectory(BoostPython/HelloWorld)
add_subdirectory(BoostPython/SimpleClass)

file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json SYMBOLIC)

