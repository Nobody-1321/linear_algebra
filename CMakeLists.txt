cmake_minimum_required(VERSION 3.25)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/linearLib)


option(BUILD_TESTS "Build the tests" )

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

set(MAIN_SOURCES
    main.cpp
)

add_executable(HelloWorld ${MAIN_SOURCES})

target_link_libraries(HelloWorld  lineal)