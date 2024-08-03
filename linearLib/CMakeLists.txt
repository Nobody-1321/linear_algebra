cmake_minimum_required(VERSION 3.25)

project(mi_proyecto VERSION 1.0 LANGUAGES CXX) 


set(CMAKE_CXX_STANDARD 20)

set(VECTOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vector)
set(MATRIX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/matrix)
set(MATH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/math)


set(MAIN_SOURCE_FILES 
    ${MATH_DIR}/math.cpp    
    #${VECTOR_DIR}/src/vec2.inl
    #${VECTOR_DIR}/src/vec3.inl
)

add_library(lineal SHARED ${MAIN_SOURCE_FILES})

# Directorios de inclusión públicos
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vector/include)
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/matrix/include)







# Directorios de inclusión privados
#target_include_directories(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private)

#target_precompile_headers(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private/stlHeaders.hpp )

