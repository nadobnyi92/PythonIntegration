cmake_minimum_required(VERSION 3.5)

project(BoostAsioExamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(Boost REQUIRED python)

add_subdirectory(CPython)

add_subdirectory(libpython/libpython_simple)
add_subdirectory(libpython/libpython_embedding)

add_subdirectory(BoostPython/01_HelloWorld)
add_subdirectory(BoostPython/02_SimpleClass)
add_subdirectory(BoostPython/03_ComplexNumber)
add_subdirectory(BoostPython/04_ClassInheritance)
add_subdirectory(BoostPython/05_CallPolicy)
add_subdirectory(BoostPython/06_overloading)
add_subdirectory(BoostPython/06_embedding)

add_subdirectory(PyBind/01_HelloWorld)
add_subdirectory(PyBind/02_SimpleClass)
add_subdirectory(PyBind/03_ComplexNumber)
add_subdirectory(PyBind/04_ClassInheritance)
add_subdirectory(PyBind/05_CallPolicy)
add_subdirectory(PyBind/06_overloading)
add_subdirectory(PyBind/07_exception)
add_subdirectory(PyBind/08_embedding)

file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json SYMBOLIC)

