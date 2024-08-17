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
    //list initialization
    //vec(std::initializer_list<T> init_list);
    vec(const vec<L, T> &vec_);

    template <typename... Args>
      requires detail::AreSameAndNumbers<T, Args...>
    vec(Args &&...args);

    vec(vec<L, T> &&vec_) noexcept;

    vec(T fill_value);
    
//    template <length_t L2>
//    explicit vec(const vec<L2, T> &vec_);

//    template <length_t L2>
//    vec(const vec<L2, T> &vec_, T fill_value);

/*

    /// assignment operators
    vec<L, T> &operator=(const vec<L, T> &vec_);
    vec<L, T> &operator=(vec<L, T> &&vec_) noexcept;

    // arithmetic operators
    vec<L, T> operator+(const vec<L, T> &vec_) const;
    vec<L, T> operator-(const vec<L, T> &vec_) const;
    vec<L, T> operator*(const vec<L, T> &vec_) const;
    vec<L, T> operator*(const T &scalar) const;
    vec<L, T> operator/(const T &scalar) const;

    // comparison operators
    bool operator==(const vec<L, T> &vec_) const;
    bool operator!=(const vec<L, T> &vec_) const;

    // access to elements
    optional_type &operator[](const std::size_t &idx) noexcept;
    const optional_type &operator[](const std::size_t &idx) const noexcept;

    optional_type *data() noexcept;
    optional_type &at(const std::size_t &idx);
    const optional_type &at(const std::size_t &idx) const;

    // functions
    constexpr std::size_t size() const noexcept;
    void fill(T fill_value);
    void swap(vec<L, T> &vec_) noexcept;
    bool contains_nullopt() const;

    // iterator
    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    ~vec();
*/
  private:
    std::unique_ptr<array_type> data_v = std::make_unique<array_type>();
  };
  
  // multiplication by scalar
  //template <length_t U, IsNumeric R>
  //vec<U, R> operator*(const R &scalar, const vec<U, R> &vec_);

};

#include "../src/vec.inl"