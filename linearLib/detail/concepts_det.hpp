#pragma once
#include <concepts>
#include <type_traits>

namespace line
{
    namespace concepts
    {
        namespace detail{

            template <typename T>
            concept is_numeric = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;
        
            template <typename T, typename... Args>
            concept same_numeric_type = (is_numeric<Args> && ...) && (std::is_same_v<T, Args> && ...);
        }
    }
}