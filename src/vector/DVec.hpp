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
  /// @namespace nsp_types
  /// Alias for `detail::types` to simplify access to types used in the library.
  namespace nsp_types = detail::types;

  /// @namespace nsp_concepts
  /// Alias for `detail::concepts` to simplify access to concepts used in the
  /// library.
  namespace nsp_concepts = detail::concepts;

  namespace structs
  {

    template <nsp_concepts::is_numeric T> struct DVec
    {
      using value_type = T;
      using type = DVec<T>;
      using array_type = std::vector<value_type>;
      using iterator = ranges::iterator<value_type>;
      using const_iterator = ranges::const_iterator<value_type>;

      // constructors
      DVec();
      DVec(std::size_t size_);
      DVec(const DVec<T> &vec_);

      // arithmetic operators

      // access to elements
      value_type &operator[](std::size_t index);
      const value_type &operator[](std::size_t index) const;
      value_type *data() noexcept;

      // iterators
      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

      // functions
      void fill(T fill_value);
      void push_back(T value);
      void pop_back();
      std::size_t size();
      std::size_t capacity();
      void reserve(std::size_t new_capacity);
      void clear();
      // void resize(std::size_t new_size);

    private:
      array_type data_v;
    };
  } // namespace structs
} // namespace line

#include "./DVec.inl"