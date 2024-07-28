#include <iostream>
#include <setup.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <types.hpp>
#include <iomanip> 

int main()
{
    line::vec2_f v1(1.0f, 2.0f);
    line::vec2_f v2(3.0f, 4.0f);
    int a = 5;
    line::vec2_f v3 = static_cast<float>(a) / v1;

    std::cout << "v1: " << v1.x << " " << v1.y << std::endl;
    std::cout << "v2: " << v2.x << " " << v2.y << std::endl;
    std::cout << "v3: " << v3.x << " " << v3.y << std::endl;

    line::vec3_f v4(1.0f, 2.0f, 3.0f);
    line::vec3_f v5(4.0f, 5.0f, 6.0f);
    line::vec3_f v6 = v4 * v5;

    std::cout << "v4: " << v4.x << " " << v4.y << " " << v4.z << std::endl;
    std::cout << "v5: " << v5.x << " " << v5.y << " " << v5.z << std::endl;
    std::cout << "v6: " << v6.x << " " << v6.y << " " << v6.z << std::endl;

    line::vec4_f v7(1.0f, 2.0f, 3.0f, 4.0f);
    line::vec4_f v8(5.0f, 6.0f, 7.0f, 8.0f);
    line::vec4_f v9 = v7 / 0.0f;

    std::cout << "v7: " << v7.x << " " << v7.y << " " << v7.z << " " << v7.w << std::endl;
    std::cout << "v8: " << v8.x << " " << v8.y << " " << v8.z << " " << v8.w << std::endl;
    std::cout << "v9: " << v9.x << " " << v9.y << " " << v9.z << " " << v9.w << std::endl;

    


    return 0;
}