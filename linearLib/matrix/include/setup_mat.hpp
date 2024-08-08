#pragma once 
#include <concepts>
#include <type_traits>
#include "../../detail/types_d.hpp"

template<typename T>
concept IsNumberM = std::is_arithmetic_v<T>;

namespace line{
    using namespace detail;
    template<length_t C, length_t R, IsNumberM T> 
    struct mat;
    
}