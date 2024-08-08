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

        // index operator
        const T &operator[](const std::size_t &i) const;
        T &operator[](const std::size_t &i);

        // functions
        std::size_t size() const;
        T *data();
        const T &at(const std::size_t &i) const;
        T &at(const std::size_t &i);

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        ~vec();
        
        T x, y;

    };

    template <IsNumber U>
    vec<2, U> operator/(const U &t, const vec<2, U> &v);

    template <IsNumber U>
    vec<2, U> operator*(const U &t, const vec<2, U> &v);
};

#include "../src/vec2.inl"
