#some libraries are build as external projects
include(ExternalProject)

#gmock/gtest library
ExternalProject_Add(
    gmock_project
    PREFIX ${CMAKE_BINARY_DIR}
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    INSTALL_COMMAND ""
)

#compile project itself
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${miller_SOURCE_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/src/gmock_project/include/)
include_directories(${CMAKE_BINARY_DIR}/src/gmock_project/gtest/include/)

link_directories(${CMAKE_BINARY_DIR}/src/gmock_project-build)

set(TEST_EXECUTABLE Test)
file(GLOB CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(${TEST_EXECUTABLE} ${CPP_SOURCES})

add_dependencies(${TEST_EXECUTABLE} gmock_project)
target_link_libraries(${TEST_EXECUTABLE} 
            miller
            gmock
            pthread)
