cmake_minimum_required(VERSION 3.10)
project(MyLinearAlgebraLib)

# Encuentra Google Benchmark
find_package(benchmark REQUIRED)
if (benchmark_FOUND)
    message(STATUS "Paquete 'benchmark' encontrado correctamente.")
else()
    message(FATAL_ERROR "Paquete 'benchmark' no encontrado.")
endif()


find_package(line REQUIRED)
if (line_FOUND)
    message(STATUS "Paquete 'line' encontrado correctamente.")
else()
    message(FATAL_ERROR "Paquete 'line' no encontrado.")
endif()

# Configura el estándar de C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(line_benchmarks
    #vec.cpp
    mat.cpp
)

target_link_libraries(line_benchmarks
    PRIVATE
    line::line
    benchmark::benchmark
)

# Opcional: activa optimizaciones para los benchmarks
if(CMAKE_BUILD_TYPE MATCHES "Release")
    target_compile_options(line_benchmarks PRIVATE -O3)
endif()
