#pragma once

#include <iterator>
#include <cstddef>

namespace line
{

  namespace ranges
  {

    template <typename T> struct RandomAccessIterator
    {
      using iterator_category = std::random_access_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = T *;
      using reference = T &;

      pointer ptr;

      RandomAccessIterator(pointer ptr);

      reference operator*() const;
      pointer operator->();

      RandomAccessIterator &operator++();
      RandomAccessIterator operator++(int);

      RandomAccessIterator &operator--();
      RandomAccessIterator operator--(int);

      RandomAccessIterator operator+(difference_type n) const;
      RandomAccessIterator operator-(difference_type n) const;
      difference_type operator-(const RandomAccessIterator &other) const;

      bool operator==(const RandomAccessIterator &other) const;
      bool operator!=(const RandomAccessIterator &other) const;

      bool operator<(const RandomAccessIterator &other) const;
      bool operator<=(const RandomAccessIterator &other) const;
      bool operator>(const RandomAccessIterator &other) const;
      bool operator>=(const RandomAccessIterator &other) const;
    };
  } // namespace RandomAccessIterator
} // namespace line

#include "./random_access_iterator.inl"
