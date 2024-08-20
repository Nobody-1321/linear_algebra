cmake_minimum_required(VERSION 3.25)

project(mi_proyecto VERSION 1.0 LANGUAGES CXX) 


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)
#add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(VECTOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vector)
set(MATRIX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/matrix)
set(MATH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/math)


set(MAIN_SOURCE_FILES 
    ${MATH_DIR}/mats.cpp    
    #${VECTOR_DIR}/src/vec2.inl
    #${VECTOR_DIR}/src/vec3.inl
)

add_library(lineal SHARED ${MAIN_SOURCE_FILES})

# Directorios de inclusión públicos
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vector/include)
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/matrix/include)
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/iterator/include)
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/math/include)
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/detail)







# Directorios de inclusión privados
#target_include_directories(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private)

#target_precompile_headers(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private/stlHeaders.hpp )

