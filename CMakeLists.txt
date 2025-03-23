cmake_minimum_required(VERSION 3.25)

project(line VERSION 1.0 LANGUAGES CXX)

# Configura el estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build the tests" )
option(ENABLE_SVEC_TESTS "Enable static vector tests" OFF)
option(ENABLE_DVEC_TESTS "Enable dynamic vector tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Crear una biblioteca de interfaz (INTERFACE library)
add_library(line INTERFACE)

# Especificar los directorios de inclusión (headers)
target_include_directories(line INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

# Incluir GNUInstallDirs para rutas de instalación estándar
include(GNUInstallDirs)

# Instalar los headers
install(
    DIRECTORY src/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/line
)

# Exportar el target para que otros proyectos lo usen
install(TARGETS line
    EXPORT lineTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Instalar el archivo de exportación de targets
install(EXPORT lineTargets
    FILE lineTargets.cmake
    NAMESPACE line::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/line
)

# Configurar el archivo de configuración del paquete
configure_file(
    cmake/lineConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/lineConfig.cmake
    @ONLY
)

# Instalar el archivo de configuración del paquete
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/lineConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/line
)