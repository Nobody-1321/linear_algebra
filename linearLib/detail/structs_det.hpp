#pragma once 
#include <concepts>
#include <type_traits>
#include  "concepts_det.hpp"
#include "types_det.hpp"

namespace line{

    namespace structs{

        namespace detail{

            template<types::detail::length_t L, concepts::detail::is_numeric T> 
            struct vec;
       
            template<types::detail::length_t R, types::detail::length_t C, line::concepts::detail::is_numeric T> 
            struct mat;
        }
     
    }
}



