project(inheritance_object)

set(SRC InheritanceObject.cpp)

include_directories(${Boost_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS})

add_library(${PROJECT_NAME} MODULE ${SRC})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

