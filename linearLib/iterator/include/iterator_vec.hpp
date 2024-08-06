// iterator.h
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

    iterator(pointer ptr) : ptr(ptr) {}

    reference operator*() const { return *ptr; }
    pointer operator->() { return ptr; }

    iterator& operator++() { ++ptr; return *this; }
    iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }

    iterator& operator--() { --ptr; return *this; }
    iterator operator--(int) { iterator temp = *this; --(*this); return temp; }

    iterator operator+(difference_type n) const { return iterator(ptr + n); }
    iterator operator-(difference_type n) const { return iterator(ptr - n); }
    difference_type operator-(const iterator& other) const { return ptr - other.ptr; }

    bool operator==(const iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const iterator& other) const { return ptr != other.ptr; }

    bool operator<(const iterator& other) const { return ptr < other.ptr; }
    bool operator<=(const iterator& other) const { return ptr <= other.ptr; }
    bool operator>(const iterator& other) const { return ptr > other.ptr; }
    bool operator>=(const iterator& other) const { return ptr >= other.ptr; }

};

} // namespace line
