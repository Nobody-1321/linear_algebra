#include <iostream>
#include <vec.hpp>
#include <mat.hpp>
#include <vector>
#include <iterator_vec.hpp>
#include <memory>
#include <algorithm>
#include <math.hpp>
#include <array>

// clang-tidy -p build/ ./linearLib/vector/src/vec.inl -checks=cppcoreguidelines-* -header-filter='.*'

int main()
{

  using namespace line;
  using namespace std;



  return 0;
}




/*




 vec<3, double> a{2.0, 2.0, 3.0};
 vec<3, double> b{1.0, -2.0, 0.0};

 cout << "Vector a: ";
 for (auto i = a.cbegin(); i != a.cend(); ++i)
 {
   cout << *i << " ";
   }

 cout << endl << "Vector b: ";
 for (auto i = b.cbegin(); i != b.cend(); ++i)
 {
   cout << *i << " ";
 }

 vec<3, double> c = project(a, b);

 //dot product
 cout << "Dot product: " << dot_product(a, b) << endl;
 //magnitude
 cout << "Magnitude a: " << magnitude(a.cbegin(), a.cend()) << endl;
 cout << "Magnitude b: " << magnitude(b.cbegin(), b.cend()) << endl;


 for (auto i = c.cbegin(); i != c.cend(); ++i)
 {
   cout << *i << " ";
 }


 //print vector a
 cout << "Vector a: ";
 for (auto i = a.cbegin(); i != a.cend(); ++i)
 {
   cout << *i << " ";
 }

 //print vector b

 cout << endl << "Vector b: ";
 for (auto i = b.cbegin(); i != b.cend(); ++i)
 {
   cout << *i << " ";
 }




vec<3, double> a{3.0, 6.0, 1.0};
 vec<3, double> v1{1.0, 1.0, 2.0};
 vec<3, double> v2{-4.0, -8.0, 6.0};
 vec<3, double> b= v2 - v1;

 cout << "Vector a: " << a[0] << " " << a[1] << " " << a[2] << endl;
 cout << "Vector b: " << b[0] << " " << b[1] << " " << b[2] << endl;

 double dot = dot_product(a, b);
 double magv1 = magnitude(a.cbegin(), a.cend());
 double magv2 = magnitude(b.cbegin(), b.cend());
 double angle = angle_between(a, b);


 cout << "Dot product: " << dot << endl;
 cout << "Magnitude v1: " << magv1 << endl;
 cout << "Magnitude v2: " << magv2 << endl;
 cout << "Angle between v1 and v2: " << angle << endl;
 cout << "Angle between v1 and v2 in degrees: " << to_degrees(angle) << endl;
*/