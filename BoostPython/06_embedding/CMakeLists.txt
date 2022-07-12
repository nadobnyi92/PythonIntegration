project(embedded_python)

set(SRC main.cpp)

include_directories(${Boost_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${Python3_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

