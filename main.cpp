#include <iostream>
#include <vec2.hpp>  
#include <vec3.hpp>   
#include <vec4.hpp>
#include <vec.hpp>
#include <vector>
#include <iterator_vec.hpp>
#include <memory>

//clang-tidy -p build/ ./linearLib/vector/src/vec.inl -checks=cppcoreguidelines-* -header-filter='.*'

int main() {

    using namespace std;

    line::vec<10, int> vec1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    line::vec<15, int> vec2(1);

    vec2 = std::move(vec1);
    


    std::cout << std::endl;

}   