project(simple)

set(SRC simple_library.cpp)
add_library(${PROJECT_NAME} SHARED ${SRC})

install(TARGETS ${PROJECT_NAME}
    COMPONENT python
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
