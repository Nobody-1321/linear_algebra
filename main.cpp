#include <iostream>
#include <vec2.hpp>      // Asegúrate de que estos encabezados existan y sean correctos
#include <vec3.hpp>
#include <vec4.hpp>
#include <types_mat.hpp>
#include <iomanip>
#include <iterator_vec.hpp> 
#include <algorithm>

using namespace line;

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

    check_iterator_traits<iterator<int>>();

    std::cout << "Iterator traits check passed!" << std::endl;
    return 0;
}