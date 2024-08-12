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

    line::vec<10, float> v1(1.0f, 2.5f, 3.0f, 4.9f, 5.0f, 50.6f);
    cout << v1.data()->value() ;
    
    cout << std::endl;
    
 /*   for (int i = 0; i < 10; ++i) {
        cout << v1[i].value_or(1) << " ";
    }
 */
}   