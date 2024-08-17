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


    vec<6, double> v{1.4, 2.7, 3.888, 4.2, 5.45, 6.922};



/*
    //mat<4, 4, double> m1{1.0};
    //mat<4, 4, double> m{1.0};
    //mat<2, 3, double> m{1.4, 2.7, 3.888, 4.2, 5.45};
    mat<2, 3, double> m{{1.4, 3.888}, {4.2, 5.45, 6.922}};

    for (int i = 0; i < m.size_row(); i++)
    {
        for (int j = 0; j < m.size_col(); j++)
        {
            cout << m[i][j].value_or(123456.005) << " ";
        }
        cout << endl;
    }


    m[0][0]=1;  m[0][1]=2;  m[0][2]=3; m[0][3]=4; 
    m[1][0]=5;  m[1][1]=6;  m[1][2]=7; m[1][3]=8;
    m[2][0]=9;  m[2][1]=10;  m[2][2]=11; m[2][3]=12; 
    m[3][0]=13;  m[3][1]=14;  m[3][2]=15; m[3][3]=16; 

    m1[0][0]=1;  m1[0][1]=2;  m1[0][2]=3; m1[0][3]=4; 
    m1[1][0]=5;  m1[1][1]=6;  m1[1][2]=7; m1[1][3]=8;
    m1[2][0]=9;  m1[2][1]=10;  m1[2][2]=11; m1[2][3]=12; 
    m1[3][0]=13;  m1[3][1]=14;  m1[3][2]=15; m1[3][3]=16;

    auto m2 = m * m1;

    cout << m2[0][0].value() << " " << m2[0][1].value() << " " << m2[0][2].value() << " " << m2[0][3].value() << endl;
    cout << m2[1][0].value() << " " << m2[1][1].value() << " " << m2[1][2].value() << " " << m2[1][3].value() << endl;
    cout << m2[2][0].value() << " " << m2[2][1].value() << " " << m2[2][2].value() << " " << m2[2][3].value() << endl;
    cout << m2[3][0].value() << " " << m2[3][1].value() << " " << m2[3][2].value() << " " << m2[3][3].value() << endl;
*/
}   