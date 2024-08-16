#pragma once
#include <concepts>
#include <type_traits>

namespace line
{
    namespace detail
    {

        template <typename T>
        concept IsNumeric = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;
        
        template <typename T, typename... Args>
        concept AreSameAndNumbers = (IsNumeric<Args> && ...) && (std::is_same_v<T, Args> && ...);

        typedef std::size_t length_t;

    }
}