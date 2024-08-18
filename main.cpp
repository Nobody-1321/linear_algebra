#include <iostream>
#include <vec.hpp>
//#include <mat.hpp>
#include <vector>
#include <iterator_vec.hpp>
#include <memory>
#include <array>

//clang-tidy -p build/ ./linearLib/vector/src/vec.inl -checks=cppcoreguidelines-* -header-filter='.*'



int main() {

    using namespace line;
    using namespace std;;

  //  mat<5,2,int> A{1,2,3,4,5,6,7,8,9,10};
  //  int scalar = 2;
  //  mat<5,2,int> result = A * scalar;

    mat<5,2,double> A1{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    double scalar1 = 2;
    mat<5,2,double> result1 = A1 * scalar1;





    return 0;
}   