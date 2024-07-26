#include <gtest/gtest.h>


// Función principal de ejecución de las pruebas
int main(int argc, char** argv) {
    
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
