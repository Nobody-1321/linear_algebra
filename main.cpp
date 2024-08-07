#include <iostream>
#include <vector>
#include <vec2.hpp>  
#include <vec3.hpp>   
#include <vec4.hpp>
#include <vec.hpp>
#include <iterator_vec.hpp>

template<typename Iter>
void check_iterator_traits() {
    using namespace std;

    using traits = iterator_traits<Iter>;

    static_assert(is_same<typename traits::iterator_category, random_access_iterator_tag>::value, "Iterator category mismatch");
    static_assert(is_same<typename traits::value_type, typename Iter::value_type>::value, "Value type mismatch");
    static_assert(is_same<typename traits::difference_type, typename Iter::difference_type>::value, "Difference type mismatch");
    static_assert(is_same<typename traits::pointer, typename Iter::pointer>::value, "Pointer type mismatch");
    static_assert(is_same<typename traits::reference, typename Iter::reference>::value, "Reference type mismatch");
}

int main() {
    using namespace line;
    using namespace std;

    line::vec<10, int> v1{1, 2, 3, 4, 5};
    line::iterator<optional<int>> it = v1.begin();

    cout << it->has_value() << endl << endl;

    for (auto e : v1) {
        cout << e.value_or(9) << " ";
    }
//    cout << v1[0].value() << " " << v1[1].value() << " " << v1[2].value() << " " << v1[3].value() << " " << v1[4].value() << endl;



//    cout << v1[0] << " " << v1[1] << " " << v1[2] << " " << v1[3] << endl;
//    cout << v1.at(0) << " " << v1.at(4) << " " << v1.at(2) << " " << v1.at(3) << endl;
    
  
  /*  using namespace std;
    line::vec<10, int> v1;
    line::vec<10, int> v2 = v1;

    for (int i = 0; i < 15; ++i) {
        if (v2[i].has_value()) {
            cout << v2[i].value() << " ";
        } else {
            cout << "N/A ";
        }
    }
    vector <vec<10, int>> v = {v1, v2};

    v.si
    line::iterator<std::optional<int>> it = v1.begin();
    for (int i = 1; i <= 10; ++i) {
        *it = i;
        ++it;
    }

    line::vec<15, int> v2(v1);


    for (int i = 0; i < 15; ++i) {
         if (v2[i].has_value()) {
            cout << v2[i].value() << " ";
        } else {
            cout << "N/A ";
        }
    }
*/

//  line::vec<2, int8_t> v2(1.0f, 2.0f);
//  std::cout << sizeof(v2) << std::endl;

//  line::vec<2, int> v3(1.0f, 2.0f);
//  std::cout << sizeof(v3) << std::endl;


//    line::iterator<char> it2 = v2.begin();
//
//    std::cout << *it2 << std::endl;
//    std::cout << *(it2 + 1) << std::endl;


/*    using namespace line;
    using namespace std;

    check_iterator_traits<line::iterator<int>>();
    std::cout << "Iterator traits check passed!" << std::endl;

   vec<2, int> v1(1, 2);
    auto it = v1.begin();

    std::cout << *it<< std::endl;
    std::cout << *(it + 1) << std::endl;

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------" << std::endl;
    for(const auto& e : v1){
        std::cout << e << std::endl;
    }

    std::vector<vec<2,int>> v = {{1,2},{3,4},{5,6}};
    
    line::iterator<vec<2,int>> it2{v.data()};

    line::vec<2,int> v2 = *it2;
    std::cout << v2[0] << " " << v2[1] << std::endl;
    cout << "----------------" << endl;

    line::vec<2,int> v3 = *it2 + *(it2 + 1);
    cout << v3[0] << " " << v3[1] << endl;
    cout << "----------------" << endl;
*/
    return 0;
}