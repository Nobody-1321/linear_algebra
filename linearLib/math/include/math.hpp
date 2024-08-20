
#pragma once
#include <iterator>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include "../../detail/types_d.hpp"
#include "../iterator/include/iterator_vec.hpp"
#include "../iterator/include/iterator_cvec.hpp"

namespace line{


    //to degrees
    template<IsNumeric T>
    T to_degrees(T rad);

    //to radians
    template<IsNumeric T>
    T to_radians(T deg);

    //magnitude of a vector
        // Función para calcular la magnitud de un vector
    template <typename Iterator>
    typename std::iterator_traits<Iterator>::value_type magnitude(Iterator begin, Iterator end);

    //unit vector
    //returns a new vector with the same direction as the input vector but with a magnitude of 1
    template <length_t L, IsNumeric T>
    vec<L, T> unit_vector(const vec<L, T>& vec_);

    //distance between two vectors
    template <length_t L, IsNumeric T>
    T distance(const vec<L, T>& vec1, const vec<L, T>& vec2);


    //dot product
    template <length_t L, IsNumeric T>
    T dot_product(const vec<L, T>& vec1, const vec<L, T>& vec2);

    //angle between two vectors
    template <length_t L, IsNumeric T>
    T angle_between(const vec<L, T>& vec1, const vec<L, T>& vec2);

    //projection of a vector
    template <length_t L, IsNumeric T>
    vec<L, T> project(const vec<L, T>& vec1, const vec<L, T>& vec2);

    //cross product
    template <length_t L, IsNumeric T>
    vec<L, T> cross_product(const vec<L, T>& vec1, const vec<L, T>& vec2);

    //Matrix 



    //transpose
    template <length_t R, length_t C, IsNumeric T>
    mat<C, R, T> transpose(const mat<R, C, T>& mat_);

}

#include "../src/math.inl"