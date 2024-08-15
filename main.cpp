#include <iostream>
#include <vec2.hpp>  
#include <vec3.hpp>   
#include <vec4.hpp>
#include <vec.hpp>
#include <mat2x2.hpp>
#include <vector>
#include <iterator_vec.hpp>
#include <memory>

//clang-tidy -p build/ ./linearLib/vector/src/vec.inl -checks=cppcoreguidelines-* -header-filter='.*'

int main() {

    using namespace line;
    using namespace std;

    line::vec<6, float> vec2_1(1.2f, 2.0f, 3.0f, 4.0f, 5.0f);
    line::vec<6, float> vec2_2(0.0f);

    std::cout << "vec2_1: ";
    for (size_t i = 0; i < vec2_1.size(); i++)
    {
        std::cout << vec2_1.at(i).value_or(11111) << " ";
    }
    
    std::cout << std::endl;
}   