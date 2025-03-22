# Encuentra los paquetes necesarios
find_package(GTest REQUIRED)

include(GoogleTest)

# Filtrar pruebas por nombre (si se necesita)
option(TEST_FILTER "Specify test filter (default: run all tests)" "")

# Agrupar todos los archivos de pruebas
file(GLOB TEST_SOURCES "*.cpp")

# Ejecutable de tests
add_executable(tests ${TEST_SOURCES})

# Configura el estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Desactivar warnings como errores
target_compile_options(tests PRIVATE -Wno-error)

# Enlazar con GoogleTest y tu propia biblioteca
target_link_libraries(tests 
    GTest::GTest 
    GTest::Main
    line
)

# Si hay un filtro, se configura para que los tests se ejecuten con el filtro
if(TEST_FILTER)
    message(STATUS "Running tests with filter: ${TEST_FILTER}")
    set(TEST_COMMAND "${CMAKE_BINARY_DIR}/tests --gtest_filter=${TEST_FILTER}")
    add_test(NAME filtered_tests COMMAND ${TEST_COMMAND})
else()
    # Si no hay filtro, ejecuta todos los tests
    add_test(NAME tests COMMAND ./tests)
endif()

# Registrar todos los tests para CTest
gtest_discover_tests(tests)
