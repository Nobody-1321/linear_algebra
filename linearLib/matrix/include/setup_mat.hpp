#pragma once 
#include <concepts>
#include <type_traits>

template<typename T>
concept IsNumberM = std::is_arithmetic_v<T>;

namespace line{
    
    typedef int length_t;
    
    template<length_t C, length_t R, IsNumberM T> 
    struct mat;
    
}