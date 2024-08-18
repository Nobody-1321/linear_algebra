#pragma once

#include <iterator>
#include <cstddef>

namespace line {

template<typename T>
struct const_iterator {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    pointer ptr;

    const_iterator(pointer ptr);

    reference operator*() const;
    pointer operator->() const;

    const_iterator& operator++();
    const_iterator operator++(int);

    const_iterator& operator--();
    const_iterator operator--(int);

    const_iterator operator+(difference_type n) const;
    const_iterator operator-(difference_type n) const;
    difference_type operator-(const const_iterator& other) const;

    bool operator==(const const_iterator& other) const;
    bool operator!=(const const_iterator& other) const;

    bool operator<(const const_iterator& other) const;
    bool operator<=(const const_iterator& other) const;
    bool operator>(const const_iterator& other) const;
    bool operator>=(const const_iterator& other) const;
};

} // namespace line

#include "../src/iterator_cvec.inl"
