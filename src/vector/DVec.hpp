#pragma once

#include <assert.h>
#include <algorithm>
#include <array>
#include <execution>
#include <iostream>
#include <memory>
#include "../detail/concepts_det.hpp"
#include "../detail/types_det.hpp"
#include "../ranges/const_random_access_iterator.hpp"
#include "../ranges/random_access_iterator.hpp"

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

    template <nsp_concepts::is_numeric T> struct DVec
    {
      using value_type = T;
      using type = DVec<T>;
      using array_type = std::vector<value_type>;
      using iterator = ranges::RandomAccessIterator<value_type>;
      using const_iterator = ranges::ConstRandomAccessIterator<value_type>;

      // +---------------------------------------------+
      // |                 Constructors                |
      // +---------------------------------------------+

      DVec();
      DVec(std::size_t size_);
      DVec(const DVec<T> &vec_);
      DVec(DVec<T> &&vec_) noexcept;
      DVec(std::size_t size_, const T &value);
      DVec(std::initializer_list<T> list);
      template <typename... Args>
        requires(sizeof...(Args) > 2)
                && nsp_concepts::same_numeric_type<T, Args...>
      DVec(Args &&...args);

      /*
      template <typename... Args>
        requires nsp_concepts::same_numeric_type<T, Args...>
      DVec(Args &&...args);
      */

      // +---------------------------------------------+
      // |           assignment operators              |
      // +---------------------------------------------+

      DVec &operator=(const DVec<T> &vec_);
      DVec &operator=(DVec<T> &&vec_) noexcept;

      // +---------------------------------------------+
      // |           arithmetic operators              |
      // +---------------------------------------------+

      DVec operator+(const DVec<T> &vec_) const;
      DVec &operator+=(const DVec<T> &vec_);
      DVec operator+(const T &scalar_) const;
      DVec &operator+=(const T &scalar_);

      DVec operator-(const DVec<T> &vec_) const;
      DVec &operator-=(const DVec<T> &vec_);
      DVec operator-(const T &scalar_) const;
      DVec &operator-=(const T &scalar_);

      DVec operator*(const DVec<T> &vec_) const;
      DVec &operator*=(const DVec<T> &vec_);
      DVec operator*(const T &scalar_) const;
      DVec &operator*=(const T &scalar_);

      DVec operator/(const T &scalar_) const;
      DVec &operator/=(const T &scalar_);

      // +---------------------------------------------+
      // |           comparison operators              |
      // +---------------------------------------------+

      bool operator==(const DVec<T> &vec_) const;
      bool operator!=(const DVec<T> &vec_) const;

      // +---------------------------------------------+
      // |           element access operators          |
      // +---------------------------------------------+

      value_type &operator[](std::size_t index);
      const value_type &operator[](std::size_t index) const;
      value_type *data() noexcept;

      // +---------------------------------------------+
      // |               iterators                     |
      // +---------------------------------------------+

      iterator begin();
      iterator end();
      const_iterator cbegin() const;
      const_iterator cend() const;

      // +---------------------------------------------+
      // |               functions                     |
      // +---------------------------------------------+

      void fill(T fill_value);
      std::size_t size() const;
      std::size_t capacity();
      void reserve(std::size_t new_capacity);
      void push_back(T value);
      void pop_back();
      void clear();
      bool is_valid();
      void swap(DVec<T> &vec_);
      // void resize(std::size_t new_size);

    private:
      array_type data_v;
    };

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    // scalar + vector
    template <nsp_concepts::is_numeric T>
    DVec<T> operator+(const T &scalar_, const DVec<T> &vec_);

    // scalar - vector
    template <nsp_concepts::is_numeric T>
    DVec<T> operator-(const T &scalar_, const DVec<T> &vec_);

    // scalar * vector
    template <nsp_concepts::is_numeric T>
    DVec<T> operator*(const T &scalar_, const DVec<T> &vec_);

  } // namespace structs
} // namespace line

#include "./DVec.inl"