#pragma once

#include <iterator>
#include <cstddef>

namespace line
{

  namespace ranges
  {

    template <typename T> struct ConstRandomAccessIterator
    {
      using iterator_category = std::random_access_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = const T *;
      using reference = const T &;

      pointer ptr;

      ConstRandomAccessIterator(pointer ptr);

      reference operator*() const;
      pointer operator->() const;

      ConstRandomAccessIterator &operator++();
      ConstRandomAccessIterator operator++(int);

      ConstRandomAccessIterator &operator--();
      ConstRandomAccessIterator operator--(int);

      ConstRandomAccessIterator operator+(difference_type n) const;
      ConstRandomAccessIterator operator-(difference_type n) const;
      difference_type operator-(const ConstRandomAccessIterator &other) const;

      bool operator==(const ConstRandomAccessIterator &other) const;
      bool operator!=(const ConstRandomAccessIterator &other) const;

      bool operator<(const ConstRandomAccessIterator &other) const;
      bool operator<=(const ConstRandomAccessIterator &other) const;
      bool operator>(const ConstRandomAccessIterator &other) const;
      bool operator>=(const ConstRandomAccessIterator &other) const;
    };

  } // namespace iterator

} // namespace line

#include "./const_random_access_iterator.inl"
