#pragma once

#include <iterator>
#include <cstddef>

namespace line {

template<typename T>
struct iterator {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    pointer ptr;

    iterator(pointer ptr);

    reference operator*() const;
    pointer operator->();

    iterator& operator++();
    iterator operator++(int);

    iterator& operator--();
    iterator operator--(int);

    iterator operator+(difference_type n) const;
    iterator operator-(difference_type n) const;
    difference_type operator-(const iterator& other) const;

    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;

    bool operator<(const iterator& other) const;
    bool operator<=(const iterator& other) const;
    bool operator>(const iterator& other) const;
    bool operator>=(const iterator& other) const;
};

} // namespace line

#include "../src/iterator_vec.inl"
