#pragma once

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

  template <nsp_concepts::is_numeric T>
  struct DVec
  {

    using value_type = T;
    using type = DVec<T>;
    using array_type = std::vector<value_type>;
    using iterator = line::iterator::iterator<value_type>;
    using const_iterator = line::iterator::const_iterator<value_type>;

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

} // namespace line

#include "./DVec.inl"