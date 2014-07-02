cmake_minimum_required(VERSION 2.8)
project(miller)

set( SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src )
#set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
#set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
#set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

file(GLOB CPP_SOURCES "${SOURCES}/*.cpp")
file(GLOB H_SOURCES "${SOURCES}/*.h")
file(GLOB HPP_SOURCES "${SOURCES}/*.hpp")

add_library(miller STATIC ${CPP_SOURCES})

install(FILES ${H_SOURCES} ${HPP_SOURCES}
        DESTINATION ${CMAKE_BINARY_DIR})
        
#building of tests is optional
IF (BUILD_TESTING)
    add_subdirectory (tests)
    enable_testing ()

    add_test (NAME MyTest COMMAND Test)
    set_tests_properties (MyTest
                          PROPERTIES PASS_REGULAR_EXPRESSION "Passed")
ENDIF(BUILD_TESTING)

