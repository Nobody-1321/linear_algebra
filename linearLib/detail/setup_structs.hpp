#pragma once 
#include <concepts>
#include <type_traits>
#include "types_d.hpp"

namespace line{
    using namespace detail;

    template<length_t L, IsNumber T> 
    struct vec;
       
    template<length_t R, length_t C, IsNumber T> 
    struct mat;
}



