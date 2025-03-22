#pragma once
#include <concepts>
#include <type_traits>
#include "concepts_det.hpp"
#include "types_det.hpp"

namespace line
{

    namespace structs
    {

        template <types::length_t L, detail::concepts::is_numeric T>
        struct SVec;

        // Dynamic vector
        template <concepts::is_numeric T>
        struct DVec;

        template <types::length_t R, types::length_t C, detail::concepts::is_numeric T>
        struct SMat;

        // Dynamic matrix
        // template<concepts::detail::is_numeric T>
        // struct DMat;


    }
}
