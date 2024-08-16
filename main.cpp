#include <iostream>
#include <vec2.hpp>  
#include <vec3.hpp>   
#include <vec4.hpp>
#include <vec.hpp>
#include <mat2x2.hpp>
#include <vector>
#include <iterator_vec.hpp>
#include <memory>
#include <array>

//clang-tidy -p build/ ./linearLib/vector/src/vec.inl -checks=cppcoreguidelines-* -header-filter='.*'

int main() {

    using namespace line;
    using namespace std;
//    line::mat<2,2,int> m2(1,2,3,4);
    line::vec<2,int> v1(1,2);
    line::vec<2,int> v2(3,4);
    line::mat<2,2,int> m1(v1,v2);
    
//    std::array<int, 2> ff{1,1};

    cout << m1[0][0] << " " << m1[0][1] << endl;
    cout << m1[1][0] << " " << m1[1][1] << endl;

    std::cout << std::endl;
}   