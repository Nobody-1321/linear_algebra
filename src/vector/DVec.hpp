#pragma once

#include <assert.h>

#include <algorithm>
#include <array>
#include <execution>
#include <iostream>
#include <memory>

#include "../detail/concepts_det.hpp"
#include "../detail/types_det.hpp"
#include "../ranges/iterator_.hpp"
#include "../ranges/iterator_const.hpp"

namespace line
{

namespace structs
{

template <nsp_concepts::is_numeric T>
struct DVec
{
    using value_type = T;
    using type = DVec<T>;
    using array_type = std::vector<value_type>;
    using iterator = line::ranges::iterator<value_type>;
    using const_iterator = line::ranges::const_iterator<value_type>;

    // constructors
    DVec();
    DVec(std::size_t size_);
    DVec(const DVec<T> &vec_);

    // functions
    void fill(T fill_value);
    std::size_t size();
    std::size_t capacity();
    void reserve(std::size_t new_capacity);

   private:
    array_type data_v;
};
}  // namespace structs
}  // namespace line

#include "./DVec.inl"