#pragma once

#include <optional>
#include <array>
#include <algorithm>
#include <memory>
#include <assert.h>
#include <execution>
#include <iostream>
#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include "../../detail/setup_structs.hpp"
#include "../../detail/types_d.hpp"

namespace line
{
  template <length_t L, IsNumeric T>
  struct vec
  {

    using value_type = T;
    using type = vec<L, T>;
    using length = std::integral_constant<length_t, L>;
    using array_type = std::array<value_type, L>;
    using iterator = line::iterator<value_type>;
    using const_iterator = line::const_iterator<value_type>;

    // constructors
    vec();
    vec(const vec<L, T> &vec_);

    template <typename... Args>
      requires detail::AreSameAndNumbers<T, Args...>    
    vec(Args &&...args);

      //list initialization
    vec(std::initializer_list<T> init_list);
    
    vec(vec<L, T> &&vec_) noexcept;
    vec(T fill_value);

    /// assignment operators
    vec<L, T> &operator=(const vec<L, T> &vec_);
    vec<L, T> &operator=(vec<L, T> &&vec_) noexcept;



    // arithmetic operators
    vec<L, T> operator+(const vec<L, T> &vec_) const;
    vec<L, T> operator-(const vec<L, T> &vec_) const;
    vec<L, T> operator*(const vec<L, T> &vec_) const;
    vec<L, T> operator*(const T &scalar) const;
    vec<L, T> operator/(const T &scalar) const;

    vec<L, T> &operator+=(const vec<L, T> &vec_);
    vec<L, T> &operator-=(const vec<L, T> &vec_);
    vec<L, T> &operator*=(const vec<L, T> &vec_);
    vec<L, T> &operator*=(const T &scalar);
    vec<L, T> &operator/=(const T &scalar);


    // comparison operators
    bool operator==(const vec<L, T> &vec_) const;
    bool operator!=(const vec<L, T> &vec_) const;

    // access to elements
    value_type &operator[](const std::size_t &idx) noexcept;
    const value_type &operator[](const std::size_t &idx) const noexcept;

    value_type *data() noexcept;
    value_type &at(const std::size_t &idx);
    const value_type &at(const std::size_t &idx) const;

    // functions
    constexpr std::size_t size() const noexcept;
    void fill(T fill_value);
    void swap(vec<L, T> &vec_) noexcept;

    // iterator
    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    ~vec();

  private:
  // smart pointer to array
    std::unique_ptr<array_type> data_v;
  };
  
  // multiplication by scalar
  template <length_t U, IsNumeric R>
  vec<U, R> operator*(const R &scalar, const vec<U, R> &vec_);

};

#include "../src/vec.inl"