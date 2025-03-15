
#pragma once
#include <iterator>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include "../../detail/types_det.hpp"
#include "../../detail/concepts_det.hpp"
#include "../iterator/include/iterator_.hpp"
#include "../iterator/include/iterator_const.hpp"

namespace line
{

    // to degrees
    template <is_numeric T>
    T to_degrees(T rad);

    // to radians
    template <is_numeric T>
    T to_radians(T deg);

    // magnitude of a vector
    //  Función para calcular la magnitud de un vector
    template <typename Iterator>
    typename std::iterator_traits<Iterator>::value_type magnitude(Iterator begin, Iterator end);

    // unit vector
    // returns a new vector with the same direction as the input vector but with a magnitude of 1
    template <length_t L, is_numeric T>
    SVec<L, T> unit_vector(const SVec<L, T> &vec_);

    // distance between two vectors
    template <length_t L, is_numeric T>
    T distance(const SVec<L, T> &vec1, const SVec<L, T> &vec2);

    // dot product
    template <length_t L, is_numeric T>
    T dot_product(const SVec<L, T> &vec1, const SVec<L, T> &vec2);

    // angle between two vectors
    template <length_t L, is_numeric T>
    T angle_between(const SVec<L, T> &vec1, const SVec<L, T> &vec2);

    // projection of a vector
    template <length_t L, is_numeric T>
    SVec<L, T> project(const SVec<L, T> &vec1, const SVec<L, T> &vec2);

    // cross product
    template <length_t L, is_numeric T>
    SVec<L, T> cross_product(const SVec<L, T> &vec1, const SVec<L, T> &vec2);

    // Matrix

    // transpose
    template <length_t R, length_t C, is_numeric T>
    SMat<C, R, T> transpose(const SMat<R, C, T> &mat_);

}

#include "./math.inl"