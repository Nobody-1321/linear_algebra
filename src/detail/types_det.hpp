#pragma once
#include <concepts>
#include <type_traits>

namespace line
{

    namespace detail
    {
        
        /// @brief Contains implementation details for various types used internally.
        namespace types
        {
            /// @brief Defines a type for the length of a vector.
            /// ensuring that it is represented as a non-negative integer value. Typically, it is an alias for
            typedef std::size_t length_t;    
        }
    }
}
