#include <iostream>
//#include <setup_vec.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat2x2.hpp>
#include <types_mat.hpp>
#include <iomanip> 

int main()
{

    line::mat<2, 2, float> m2(8.0f, 8.0f, 1.0f, 4.0f);
    line::mat<2, 2, float> m1{5.0f, 8.0f, 1.0f, 4.0f};
    line::mat<2, 2, float> m3 = (5.0523841f * m1);

    bool verdad = m1 == m2;

    std::cout << sizeof(m1) << std::endl;
    std::cout << verdad << std::endl;

    
    std::cout << m3[0][0] << " " << m3[0][1] << std::endl; 
    std::cout << m3[1][0] << " " << m3[1][1] << std::endl; 

    return 0;
}