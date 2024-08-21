# Encuentra los paquetes necesarios
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

include(GoogleTest)

# Ejecutable de tests
add_executable(tests 
    main_test.cpp
    vec_test.cpp
    fixture_vec.cpp
    mat_test.cpp
    fixture_mat.cpp
)

# Aplicar optimización específica para tests
#target_compile_options(tests PRIVATE -O1)

# No aplicar las opciones de compilación globales (como -Wall, -Wextra, etc.) en tests
target_compile_options(tests PRIVATE -Wno-error)  # Desactivar warnings como errores si se necesitan

target_link_libraries(tests 
    GTest::GTest 
    GTest::Main
    lineal
)

# Añadir pruebas a CTest
gtest_discover_tests(tests)

add_test(NAME tests COMMAND ./tests)

# Ejecutable de benchmarks
add_executable(benchmarks 
    main_bench.cpp
)

# Aplicar optimización específica para benchmarks
target_compile_options(benchmarks PRIVATE -O3)

target_link_libraries(benchmarks 
    benchmark::benchmark
    lineal
)
