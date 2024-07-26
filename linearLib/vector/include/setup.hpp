#pragma once 
#include <concepts>
#include <type_traits>

template<typename T>
concept IsNumber = std::is_arithmetic_v<T>;

namespace line{
    
    typedef int length_t;
    
    template<length_t L, IsNumber T> 
    struct vec;
    
}



