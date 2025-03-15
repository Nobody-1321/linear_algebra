#pragma once

#include <optional>
#include <array>
#include <algorithm>
#include <memory>
#include <assert.h>
#include <execution>
#include <iostream>
#include "../iterator/iterator_.hpp"
#include "../iterator/iterator_const.hpp"
#include "../detail/structs_det.hpp"
#include "../detail/types_det.hpp"
#include "../detail/concepts_det.hpp"

namespace line
{

  namespace nsp_types = types::detail;
  namespace nsp_concepts = concepts::detail;

  template <nsp_types::length_t L, nsp_concepts::is_numeric T>
  struct SVec
  {

    using value_type = T;
    using type = SVec<L, T>;
    using length = std::integral_constant<nsp_types::length_t, L>;
    using array_type = std::array<value_type, L>;
    using iterator = line::iterator::iterator<value_type>;
    using const_iterator = line::iterator::const_iterator<value_type>;

    // constructors
    SVec();
    SVec(const SVec<L, T> &vec_);

    template <typename... Args>
      requires nsp_concepts::same_numeric_type<T, Args...>
    SVec(Args &&...args);

    // list initialization
    SVec(std::initializer_list<T> init_list);

    SVec(SVec<L, T> &&vec_) noexcept;
    SVec(T fill_value);

    /// assignment operators
    SVec<L, T> &operator=(const SVec<L, T> &vec_);
    SVec<L, T> &operator=(SVec<L, T> &&vec_) noexcept;

    // arithmetic operators
    SVec<L, T> operator+(const SVec<L, T> &vec_) const;
    SVec<L, T> operator-(const SVec<L, T> &vec_) const;
    SVec<L, T> operator*(const SVec<L, T> &vec_) const;
    SVec<L, T> operator*(const T &scalar) const;
    SVec<L, T> operator/(const T &scalar) const;

    SVec<L, T> &operator+=(const SVec<L, T> &vec_);
    SVec<L, T> &operator-=(const SVec<L, T> &vec_);
    SVec<L, T> &operator*=(const SVec<L, T> &vec_);
    SVec<L, T> &operator*=(const T &scalar);
    SVec<L, T> &operator/=(const T &scalar);

    // comparison operators
    bool operator==(const SVec<L, T> &vec_) const;
    bool operator!=(const SVec<L, T> &vec_) const;

    // access to elements
    value_type &operator[](const std::size_t &idx) noexcept;
    const value_type &operator[](const std::size_t &idx) const noexcept;

    value_type *data() noexcept;

    // functions
    constexpr std::size_t max_size() const noexcept;
    void fill(T fill_value);
    void swap(SVec<L, T> &vec_) noexcept;
    bool is_empty() const noexcept;

    // iterator
    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    ~SVec();

  private:
    // smart pointer to array
    std::unique_ptr<array_type> data_v;
    bool is_empty_;
  };

  // multiplication by scalar
  template <nsp_types::length_t U, nsp_concepts::is_numeric R>
  SVec<U, R> operator*(const R &scalar, const SVec<U, R> &vec_);

};

#include "./SVec.inl"