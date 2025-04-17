import os
import subprocess
import argparse

# Definir los grupos de tests disponibles
TEST_GROUPS = {
    "svec": "ENABLE_SVEC_TESTS",
    "dvec": "ENABLE_DVEC_TESTS",
    "smat": "ENABLE_SMAT_TESTS",
}

def configure_cmake(selected_tests):
    """Configura CMake con los grupos de tests seleccionados."""
    cmake_cmd = ["cmake", "-B", "build", "-S", ".", "-DBUILD_TESTS=ON"]

    for test in TEST_GROUPS:
        flag = "ON" if test in selected_tests else "OFF"
        cmake_cmd.append(f"-D{TEST_GROUPS[test]}={flag}")

    print("Configuring CMake with:", " ".join(cmake_cmd))
    subprocess.run(cmake_cmd, check=True)

def build_tests():
    """Compila los tests seleccionados."""
    subprocess.run(["cmake", "--build", "build"], check=True)

def run_tests(filter_pattern=""):
    """Ejecuta los tests con `ctest` y opcionalmente un filtro."""
    ctest_cmd = ["ctest", "--test-dir", "build", "--output-on-failure"]

    if filter_pattern:
        ctest_cmd.extend(["-R", filter_pattern])

    print("Running tests with:", " ".join(ctest_cmd))
    subprocess.run(ctest_cmd, check=True)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run selected test groups.")
    parser.add_argument("--tests", nargs="+", choices=TEST_GROUPS.keys(), help="Select test groups to run")
    parser.add_argument("--filter", type=str, help="Regex pattern to filter tests")

    args = parser.parse_args()

    selected_tests = args.tests if args.tests else TEST_GROUPS.keys()
    
    configure_cmake(selected_tests)
    build_tests()
    run_tests(args.filter)
