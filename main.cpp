#include <iostream>
#include <setup.hpp>
#include <vec2.hpp>
#include <types.hpp>
#include <iomanip> 

int main()
{
    line::vec<2, double> vec2(1.06200, 2.005690);
    
    std::cout << std::fixed << std::setprecision(16);

    line::vec2_d vec4 = 2.2558855233222240 / vec2;
    line::vec2_f vec5 = 2.2558855233222240f / vec2;
    line::vec2_d vec6 = 2.2558855233222240 / vec2;
    line::vec2_d vec7 = 2.2558855233222240f * vec2;

    std::cout << vec4.x << " " << vec4.y << std::endl;
    std::cout << vec5.x << " " << vec5.y << std::endl;
    std::cout << vec6.x << " " << vec6.y << std::endl;
    std::cout << vec7.x << " " << vec7.y << std::endl;

    
    return 0;
}