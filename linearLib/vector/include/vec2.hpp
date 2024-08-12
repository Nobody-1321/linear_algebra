#pragma once

#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include "../../detail/setup_vec.hpp"

namespace line
{

    template <IsNumber T>
    struct vec<2, T>
    {

        using value_type = T;
        using type = vec<2, T>;
        using length = std::integral_constant<length_t, 2>;
        using iterator = line::iterator<T>;
        using const_iterator = line::const_iterator<T>;

        // constructors
        vec(T x, T y);
        vec(const vec<2, T> &v);
        vec(vec<2, T> &&v) noexcept;
        
        // assignment operators
        vec<2, T> &operator=(const vec<2, T> &v);
        vec<2, T> &operator=(vec<2, T> &&v) noexcept;

        // arithmetic operators
        vec<2, T> operator+(const vec<2, T> &v) const;
        vec<2, T> operator-(const vec<2, T> &v) const;
        vec<2, T> operator*(const vec<2, T> &v) const;
        vec<2, T> operator*(const T &t) const;
        vec<2, T> operator/(const T &t) const;

        // comparison operators
        bool operator==(const vec<2, T> &v) const;

        // access to elements
        const T &operator[](const std::size_t &i) const noexcept;
        T &operator[](const std::size_t &i) noexcept;

        T *data() noexcept;
        const T &at(const std::size_t &i) const;
        T &at(const std::size_t &i);

        // functions
        constexpr std::size_t size() const noexcept;
        void  swap(vec<2, T> &v) noexcept;

        //iterators
        iterator begin() noexcept;
        iterator end() noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        ~vec();
        
        T x, y;

    };

    ////// free functions //////
    template <IsNumber U>
    vec<2, U> operator/(const U &t, const vec<2, U> &v);

    template <IsNumber U>
    vec<2, U> operator*(const U &t, const vec<2, U> &v);
};

#include "../src/vec2.inl"
