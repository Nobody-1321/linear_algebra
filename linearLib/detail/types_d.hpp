#pragma once
#include <concepts>
#include <type_traits>

namespace line
{
    namespace detail
    {

        template <typename T>
        concept IsNumber = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;

        typedef std::size_t length_t;

    }
}