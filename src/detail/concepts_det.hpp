#pragma once
#include <concepts>
#include <type_traits>

namespace line
{
  /// @brief Contains implementation details for various concepts used
  /// internally.
  namespace detail
  {
    /// @brief Defines a set of concepts related to type constraints.
    namespace concepts
    {

      /// @brief Concept that checks if a type is a numeric type (arithmetic
      /// types excluding char).
      ///
      /// This concept evaluates to `true` if the type `T` is an arithmetic
      /// type (integer or floating-point) and not of type `char`.
      ///
      /// @tparam T Type to be checked.
      /// @see std::is_arithmetic_v, std::is_same_v
      template <typename T>
      concept is_numeric = std::is_arithmetic_v<T> && !std::is_same_v<T, char>;
      // char is not numeric but is_arithmetic and it can be used as a number
      // there are many cases where char is used as a number
      //  so we exclude char from numeric types o be able to use it as a number

      /// @brief Concept that checks if all types in a parameter pack are of
      /// the same numeric type.
      ///
      /// This concept ensures that all types in the pack `Args...` are numeric
      /// types and that they are all the same type as the first type `T`.
      ///
      /// @tparam T The reference type to compare other types against.
      /// @tparam Args A pack of types to check.
      /// @see is_numeric
      template <typename T, typename... Args>
      concept same_numeric_type
        = (is_numeric<Args> && ...) && (std::is_same_v<T, Args> && ...);

      template <typename T>
      concept vector = requires(T a) {
        typename T::value_type;

        { a.size() } -> std::convertible_to<std::size_t>;
        { a.data() } -> std::convertible_to<typename T::value_type *>;

        {
          std::as_const(a).data()
        } -> std::convertible_to<const typename T::value_type *>;
      };

    }
  }
}
