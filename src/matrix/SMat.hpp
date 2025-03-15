#pragma once
#include "../vector/SVec.hpp"
#include "../detail/structs_det.hpp"
#include <memory>
#include <iostream>
#include <assert.h>
#include <array>

namespace line
{

    template <nsp_types::length_t R, nsp_types::length_t C, nsp_concepts::is_numeric T>
    struct SMat
    {

        using row_type = SVec<C, T>;
        using type = SMat<R, C, T>;
        using row_length = std::integral_constant<nsp_types::length_t, R>;
        using col_length = std::integral_constant<nsp_types::length_t, C>;
        using value_type = T;
        using iterator = line::iterator::iterator<row_type>;
        using const_iterator = line::iterator::const_iterator<row_type>;

        // constructors

        // identity matrix
        SMat();
        SMat(T val_t);
        SMat(const SMat<R, C, T> &mat_);
        SMat(SMat<R, C, T> &&mat_) noexcept;

        // multiple arguments
        template <typename... Args>
            requires nsp_concepts::same_numeric_type<T, Args...>
        SMat(Args &&...args);

        SMat(std::initializer_list<std::initializer_list<T>> init_list);

        // assignment operators
        SMat<R, C, T> &operator=(const SMat<R, C, T> &mat_);
        SMat<R, C, T> &operator=(SMat<R, C, T> &&mat_) noexcept;

        // arithmetic operators
        SMat<R, C, T> operator+(const SMat<R, C, T> &mat_) const;
        SMat<R, C, T> operator-(const SMat<R, C, T> &mat_) const;

        template <nsp_types::length_t R2, nsp_types::length_t C2>
        SMat<R, C2, T> operator*(const SMat<R2, C2, T> &mat_) const;

        // multiplication by vector
        SVec<R, T> operator*(const SVec<R, T> &vec_) const;

        SMat<R, C, T> operator*(const T &sca) const;
        SMat<R, C, T> operator/(const T &sca) const;

        // compound assignment operators
        SMat<R, C, T> &operator+=(const SMat<R, C, T> &mat_);
        SMat<R, C, T> &operator-=(const SMat<R, C, T> &mat_);
        SMat<R, C, T> &operator*=(const T &sca);

        template <nsp_types::length_t R2, nsp_types::length_t C2>
        SMat<R, C2, T> &operator*=(const SMat<R2, C2, T> &mat_);

        SVec<R, T> &operator*=(const SVec<R, T> &vec_);

        SMat<R, C, T> &operator/=(const T &sca);

        // access to elements
        row_type &operator[](int idx) noexcept;
        row_type const &operator[](int idx) const noexcept;

        // comparison operators
        bool operator==(const SMat<R, C, T> &mat_) const;

        // functions
        constexpr std::size_t size_row() const noexcept;
        constexpr std::size_t size_col() const noexcept;
        bool is_square() const noexcept;
        void fill(T fill_value);
        void swap(SMat<R, C, T> &mat_) noexcept;
        void dirmemory();

        // iterators
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        ~SMat();

    private:
        // std::array<row_type, R> rows;
        std::unique_ptr<std::array<row_type, R>> rows;
    };

    // free functions
    // scalar multiplication
    template <nsp_types::length_t R, nsp_types::length_t C, nsp_concepts::is_numeric T>
    SMat<R, C, T> operator*(const T &sca, const SMat<R, C, T> &mat_);

}

#include "./SMat.inl"