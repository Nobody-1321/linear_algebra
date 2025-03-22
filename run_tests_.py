import os
import subprocess
import sys

# Directorio del proyecto y del directorio de construcción
project_dir = os.path.abspath(os.path.dirname(__file__))
build_dir = os.path.join(project_dir, "build")

# CMake configurado para compilar los tests
cmake_command = [
    "cmake",
    "-S", project_dir,  # Directorio fuente (donde está CMakeLists.txt)
    "-B", build_dir,    # Directorio de construcción
    "-DCMAKE_BUILD_TYPE=Release",  # Puedes cambiar entre Debug/Release
    "-DBUILD_TESTS=ON", # Asegúrate de construir los tests
]

# Función para ejecutar CMake y compilar
def run_cmake():
    print("Ejecutando CMake para configurar el proyecto...")
    subprocess.check_call(cmake_command)
    print("CMake configurado con éxito.")

# Función para ejecutar los tests con un filtro específico (si se proporciona)
def run_tests(test_filter=None):
    ctest_command = ["ctest", "--build-dir", build_dir]

    if test_filter:
        ctest_command += ["-D", f"TEST_FILTER={test_filter}"]

    print(f"Ejecutando los tests con el filtro: {test_filter if test_filter else 'todos'}...")
    subprocess.check_call(ctest_command)

# Función para ejecutar el script completo
def main(test_filter=None):
    # Primero, configurar CMake
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)
    
    # Ejecutar CMake solo si no fue previamente configurado o si es necesario
    if not os.path.exists(os.path.join(build_dir, "CMakeCache.txt")):
        run_cmake()
    
    # Luego, compilar el proyecto (esto puede tomar un poco de tiempo)
    print("Compilando el proyecto...")
    subprocess.check_call(["cmake", "--build", build_dir])

    # Ejecutar los tests
    run_tests(test_filter)

if __name__ == "__main__":
    # Permitir que el usuario pase un filtro como argumento (si lo necesita)
    test_filter = None
    if len(sys.argv) > 1:
        test_filter = sys.argv[1]
    
    # Ejecutar todo
    main(test_filter)
