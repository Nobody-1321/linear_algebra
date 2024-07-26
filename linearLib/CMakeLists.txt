cmake_minimum_required(VERSION 3.25)

project(mi_proyecto)  


set(CMAKE_CXX_STANDARD 20)

set(VECTOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vector)
set(MATRIX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/matrix)
set(MATH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/math)


set(MAIN_SOURCE_FILES 
    ${VECTOR_DIR}/src/vec2.inl
    ${VECTOR_DIR}/src/vec3.cpp
#    ${VECTOR_DIR}/vec3.cpp
#    ${VECTOR_DIR}/vec4.cpp
#    ${MATRIX_DIR}/mat2.cpp
#    ${MATRIX_DIR}/mat3.cpp
#    ${MATRIX_DIR}/mat4.cpp
#    ${GEOMETRY_DIR}/geometry.cpp
)

add_library(lineal SHARED ${MAIN_SOURCE_FILES})

# Directorios de inclusión públicos
target_include_directories(lineal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vector/include)

# Directorios de inclusión privados
#target_include_directories(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private)

#target_precompile_headers(utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private/stlHeaders.hpp )

