cmake_minimum_required(VERSION 3.25)

project(HelloWorld)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC) # Para Visual Studio
    add_compile_options(/W4 /WX)
else() # Para GCC y Clang
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

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