#include <iostream>
#include <vec2.hpp>      // Asegúrate de que estos encabezados existan y sean correctos
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat2x2.hpp>
#include <mat3x3.hpp>
#include <mat4x4.hpp>
#include <types_mat.hpp>
#include <iomanip> 

int main()
{
    using namespace line;
    using namespace std;
    mat3_d m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3_d m2(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3_d m3 = m1 * m2;

    cout << m3[0][0] << " " << m3[0][1] << " " << m3[0][2] << endl;
    cout << m3[1][0] << " " << m3[1][1] << " " << m3[1][2] << endl;
    cout << m3[2][0] << " " << m3[2][1] << " " << m3[2][2] << endl;


    return 0;
}
