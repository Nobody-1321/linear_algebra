#pragma once 
#include <concepts>
#include <type_traits>

template<typename T>
//concept IsNumberV = std::is_arithmetic_v<T>;
concept IsNumberV = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;


namespace line{
    
    typedef std::size_t length_t;
    
    template<length_t L, IsNumberV T> 
    struct vec;
    
}



