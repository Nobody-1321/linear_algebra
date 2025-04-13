#pragma once

#include <optional>
#include <array>
#include <algorithm>
#include <memory>
#include <assert.h>
#include <execution>
#include <iostream>
#include "../ranges/const_random_access_iterator.hpp"
#include "../ranges/random_access_iterator.hpp"
#include "../detail/types_det.hpp"
#include "../detail/concepts_det.hpp"

namespace line
{
  /// @namespace nsp_types
  /// Alias for `detail::types` to simplify access to types used in the library.
  namespace nsp_types = detail::types;

  /// @namespace nsp_concepts
  /// Alias for `detail::concepts` to simplify access to concepts used in the
  /// library.
  namespace nsp_concepts = detail::concepts;

  namespace structs
  {
    /**
     * @brief A fixed-length vector for storing numerical values.
     *
     * This template struct `SVec` represents a fixed-size vector that can hold
     * a specified number of elements of a given numeric type. It supports
     * basic arithmetic and comparison operations, as well as iterators for
     * easy traversal of the vector's elements.
     *
     * @tparam L The length of the vector.
     * @tparam T The type of the elements in the vector.
     */
    template <nsp_types::length_t L, nsp_concepts::is_numeric T> struct SVec
    {
      /// The type of elements stored in the vector.
      using value_type = T;

      /// The type of the vector itself.
      using type = SVec<L, T>;

      /// The length of the vector, represented as a constant.
      using length = std::integral_constant<nsp_types::length_t, L>;

      /// The internal array type used to store vector elements.
      using array_type = std::array<value_type, L>;

      /// Iterator type for the vector.
      using iterator = ranges::RandomAccessIterator<value_type>;

      /// Constant iterator type for the vector.
      using const_iterator = ranges::ConstRandomAccessIterator<value_type>;

      // +---------------------------------------------+
      // |                 Constructors                |
      // +---------------------------------------------+

      /**
       * @brief Default constructor for `SVec`.
       * Initializes the vector with default values.
       */
      SVec();

      /**
       * @brief Copy constructor for `SVec`.
       * @param vec_ The vector to copy.
       */
      SVec(const SVec<L, T> &vec_);

      /**
       * @brief Variadic constructor that initializes the vector with a list of
       * arguments.
       * @tparam Args Types of the arguments passed.
       * @param args The values used to initialize the vector.
       */
      template <typename... Args>
        requires(sizeof...(Args) > 1)
                && nsp_concepts::same_numeric_type<T, Args...>
      SVec(Args &&...args);

      /**
       * @brief Constructor for list initialization.
       * @param init_list An initializer list used to initialize the vector.
       */
      SVec(std::initializer_list<T> init_list);

      /**
       * @brief Move constructor for `SVec`.
       * @param vec_ The vector to move from.
       */
      SVec(SVec<L, T> &&vec_) noexcept;

      /**
       * @brief Constructor that fills the vector with a specific value.
       * @param fill_value The value to initialize the vector with.
       */
      explicit SVec(T fill_value);

      // +---------------------------------------------+
      // |           assignment operators              |
      // +---------------------------------------------+

      /**
       * @brief Copy assignment operator.
       * @param vec_ The vector to copy from.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator=(const SVec<L, T> &vec_);

      /**
       * @brief Move assignment operator.
       * @param vec_ The vector to move from.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator=(SVec<L, T> &&vec_) noexcept;

      // +---------------------------------------------+
      // |           arithmetic operators              |
      // +---------------------------------------------+

      /**
       * @brief Vector addition.
       * @param vec_ The vector to add.
       * @return A new vector representing the sum of the two vectors.
       */
      SVec<L, T> operator+(const SVec<L, T> &vec_) const;

      /**
       * @brief Vector addition assignment.
       * @param vec_ The vector to add.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator+=(const SVec<L, T> &vec_);

      /**
       * @brief Scalar addition.
       * @param scalar The scalar value to add.
       * @return A new vector representing the sum of the vector and the scalar.
       */
      SVec<L, T> operator+(const T &scalar) const;

      /**
       * @brief Scalar addition assignment.
       * @param scalar The scalar value to add.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator+=(const T &scalar);

      /**
       * @brief Vector subtraction.
       * @param vec_ The vector to subtract.
       * @return A new vector representing the difference of the two vectors.
       */
      SVec<L, T> operator-(const SVec<L, T> &vec_) const;

      /**
       * @brief Vector subtraction assignment.
       * @param vec_ The vector to subtract.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator-=(const SVec<L, T> &vec_);

      /**
       * @brief Scalar subtraction.
       * @param scalar The scalar value to subtract.
       * @return A new vector representing the difference of the vector and the
       * scalar.
       */
      SVec<L, T> operator-(const T &scalar) const;

      /**
       * @brief Scalar subtraction assignment.
       * @param scalar The scalar value to subtract.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator-=(const T &scalar);

      /**
       * @brief Vector multiplication.
       * @param vec_ The vector to multiply.
       * @return A new vector representing the product of the two vectors.
       */
      SVec<L, T> operator*(const SVec<L, T> &vec_) const;

      /**
       * @brief Vector multiplication assignment.
       * @param vec_ The vector to multiply.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator*=(const SVec<L, T> &vec_);

      /**
       * @brief Scalar multiplication.
       * @param scalar The scalar value to multiply by.
       * @return A new vector representing the scaled vector.
       */
      SVec<L, T> operator*(const T &scalar) const;

      /**
       * @brief Scalar multiplication assignment.
       * @param scalar The scalar value to multiply by.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator*=(const T &scalar);

      /**
       * @brief Scalar division assignment.
       * @param scalar The scalar value to divide by.
       * @return A reference to the current vector.
       */
      SVec<L, T> &operator/=(const T &scalar);

      /**
       * @brief Scalar division.
       * @param scalar The scalar value to divide by.
       * @return A new vector representing the scaled vector.
       */
      SVec<L, T> operator/(const T &scalar) const;

      // +---------------------------------------------+
      // |           comparison operators              |
      // +---------------------------------------------+

      /**
       * @brief Equality comparison operator.
       * @param vec_ The vector to compare.
       * @return `true` if the vectors are equal, `false` otherwise.
       */
      bool operator==(const SVec<L, T> &vec_) const;

      /**
       * @brief Inequality comparison operator.
       * @param vec_ The vector to compare.
       * @return `true` if the vectors are not equal, `false` otherwise.
       */
      bool operator!=(const SVec<L, T> &vec_) const;

      // +---------------------------------------------+
      // |           element access operators          |
      // +---------------------------------------------+

      /**
       * @brief Accesses the element at a specified index.
       * @param idx The index of the element.
       * @return A reference to the element at the specified index.
       */
      value_type &operator[](const std::size_t &idx) noexcept;

      /**
       * @brief Accesses the element at a specified index (const version).
       * @param idx The index of the element.
       * @return A reference to the element at the specified index.
       */
      const value_type &operator[](const std::size_t &idx) const noexcept;

      /**
       * @brief Returns a pointer to the underlying data array.
       * @return A pointer to the data array.
       */
      value_type *data() noexcept;

      // +---------------------------------------------+
      // |              functions                      |
      // +---------------------------------------------+

      /**
       * @brief Returns the maximum size of the vector.
       * @return The maximum size of the vector.
       */
      constexpr std::size_t max_size() const noexcept;

      /**
       * @brief Fills the vector with a specified value.
       * @param fill_value The value to fill the vector with.
       */
      void fill(T fill_value);

      /**
       * @brief Swaps the contents of this vector with another vector.
       * @param vec_ The vector to swap with.
       */
      void swap(SVec<L, T> &vec_) noexcept;

      /**
       * @brief Checks if the vector is valid.
       * @return `true` if the vector is valid, `false` otherwise.
       */
      bool is_valid() const noexcept;

      // +---------------------------------------------+
      // |               iterators                     |
      // +---------------------------------------------+

      /**
       * @brief Returns an iterator to the beginning of the vector.
       * @return An iterator to the first element.
       */
      iterator begin() noexcept;

      /**
       * @brief Returns an iterator to the end of the vector.
       * @return An iterator to the past-the-end element.
       */
      iterator end() noexcept;

      /**
       * @brief Returns a constant iterator to the beginning of the vector.
       * @return A constant iterator to the first element.
       */
      const_iterator cbegin() const noexcept;

      /**
       * @brief Returns a constant iterator to the end of the vector.
       * @return A constant iterator to the past-the-end element.
       */
      const_iterator cend() const noexcept;

      /**
       * @brief Destructor for `SVec`.
       */
      ~SVec();

    private:
      /// Pointer to the internal array holding the vector data.
      std::unique_ptr<array_type> data_v;

      /// Flag indicating whether the vector is empty.
    };

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    /**
     * @brief Scalar multiplication for `SVec`.
     * @param scalar The scalar to multiply by.
     * @param vec_ The vector to multiply.
     * @return A new vector representing the scaled vector.
     */
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator*(const R &scalar, const SVec<U, R> &vec_);
    // scalar + vector
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator+(const R &scalar, const SVec<U, R> &vec_);
    // scalar - vector
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator-(const R &scalar, const SVec<U, R> &vec_);

  }
};

#include "./SVec.inl"
