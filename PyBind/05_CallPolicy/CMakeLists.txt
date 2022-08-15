project(CallPolicy)

find_package(pybind11 REQUIRED)

include_directories(${Python3_INCLUDE_DIRS})

set(SRC CallPolicy.cpp)
pybind11_add_module(${PROJECT_NAME} ${SRC})

install(TARGETS ${PROJECT_NAME}
    COMPONENT python
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

