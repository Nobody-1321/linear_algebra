#pragma once
#include "../vector/SVec.hpp"
#include <memory>
#include <iostream>
#include <assert.h>
#include <array>

namespace line
{
  namespace structs
  {

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    struct SMat
    {
      using row_type = SVec<C, T>;
      using type = SMat<R, C, T>;
      using row_length = std::integral_constant<nsp_types::length_t, R>;
      using col_length = std::integral_constant<nsp_types::length_t, C>;
      using value_type = T;
      using iterator = ranges::RandomAccessIterator<row_type>;
      using const_iterator = ranges::ConstRandomAccessIterator<row_type>;

      // constructors

      // +---------------------------------------------+
      // |                 Constructors                |
      // +---------------------------------------------+

      SMat();
      SMat(T val_t);
      SMat(const SMat<R, C, T> &mat_);
      SMat(SMat<R, C, T> &&mat_) noexcept;
      template <typename... Args>
        requires nsp_concepts::same_numeric_type<T, Args...>
      SMat(Args &&...args);
      SMat(std::initializer_list<std::initializer_list<T>> init_list);

      // +---------------------------------------------+
      // |           assignment operators              |
      // +---------------------------------------------+

      SMat<R, C, T> &operator=(const SMat<R, C, T> &mat_);
      SMat<R, C, T> &operator=(SMat<R, C, T> &&mat_) noexcept;

      // +---------------------------------------------+
      // |           arithmetic operators              |
      // +---------------------------------------------+

      SMat<R, C, T> operator+(const SMat<R, C, T> &mat_) const;
      SMat<R, C, T> &operator+=(const SMat<R, C, T> &mat_);
      SMat<R, C, T> operator+(const T &sca) const;
      SMat<R, C, T> &operator+=(const T &sca);

      SMat<R, C, T> operator-(const SMat<R, C, T> &mat_) const;
      SMat<R, C, T> &operator-=(const SMat<R, C, T> &mat_);
      SMat<R, C, T> operator-(const T &sca) const;
      SMat<R, C, T> &operator-=(const T &sca);

      //***********************************************
      // |           matrix multiplication             |
      //***********************************************

      template <nsp_types::length_t R2, nsp_types::length_t C2>
      SMat<R, C2, T> operator*(const SMat<R2, C2, T> &mat_) const;

      template <nsp_types::length_t R2, nsp_types::length_t C2>
      SMat<R, C2, T> &operator*=(const SMat<R2, C2, T> &mat_);

      SMat<R, C, T> operator*(const T &sca) const;
      SMat<R, C, T> &operator*=(const T &sca);

      SMat<R, C, T> operator/(const T &sca) const;
      SMat<R, C, T> &operator/=(const T &sca);

      // +---------------------------------------------+
      // |           element access operators          |
      // +---------------------------------------------+

      row_type &operator[](int idx) noexcept;
      row_type const &operator[](int idx) const noexcept;

      // +---------------------------------------------+
      // |           comparison operators              |
      // +---------------------------------------------+
      bool operator!=(const SMat<R, C, T> &mat_) const;
      bool operator==(const SMat<R, C, T> &mat_) const;

      // +---------------------------------------------+
      // |               functions                     |
      // +---------------------------------------------+

      constexpr std::size_t size_row() const noexcept;
      constexpr std::size_t size_col() const noexcept;
      bool is_square() const noexcept;
      void fill(T fill_value);
      void swap(SMat<R, C, T> &mat_) noexcept;
      bool is_valid();

      // +---------------------------------------------+
      // |               iterators                     |
      // +---------------------------------------------+

      iterator begin() noexcept;
      iterator end() noexcept;
      const_iterator cbegin() const noexcept;
      const_iterator cend() const noexcept;
      ~SMat();

    private:
      // std::array<row_type, R> rows;
      std::unique_ptr<std::array<row_type, R>> rows;
    };

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    // scalar multiplication
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator*(const T &sca, const SMat<R, C, T> &mat_);

    // scalar addition
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator+(const T &sca, const SMat<R, C, T> &mat_);

    // scalar subtraction
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator-(const T &sca, const SMat<R, C, T> &mat_);

  }

}
#include "./SMat.inl"