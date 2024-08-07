// const_iterator.inl

namespace line {

template<typename T>
const_iterator<T>::const_iterator(pointer ptr) : ptr(ptr) {}

template<typename T>
typename const_iterator<T>::reference const_iterator<T>::operator*() const { 
    return *ptr; 
}

template<typename T>
typename const_iterator<T>::pointer const_iterator<T>::operator->() { 
    return ptr; 
}

template<typename T>
const_iterator<T>& const_iterator<T>::operator++() { 
    ++ptr; 
    return *this; 
}

template<typename T>
const_iterator<T> const_iterator<T>::operator++(int) { 
    const_iterator temp = *this; 
    ++(*this); 
    return temp; 
}

template<typename T>
const_iterator<T>& const_iterator<T>::operator--() { 
    --ptr; 
    return *this; 
}

template<typename T>
const_iterator<T> const_iterator<T>::operator--(int) { 
    const_iterator temp = *this; 
    --(*this); 
    return temp; 
}

template<typename T>
const_iterator<T> const_iterator<T>::operator+(difference_type n) const { 
    return const_iterator(ptr + n); 
}

template<typename T>
const_iterator<T> const_iterator<T>::operator-(difference_type n) const { 
    return const_iterator(ptr - n); 
}

template<typename T>
typename const_iterator<T>::difference_type const_iterator<T>::operator-(const const_iterator& other) const { 
    return ptr - other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator==(const const_iterator& other) const { 
    return ptr == other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator!=(const const_iterator& other) const { 
    return ptr != other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator<(const const_iterator& other) const { 
    return ptr < other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator<=(const const_iterator& other) const { 
    return ptr <= other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator>(const const_iterator& other) const { 
    return ptr > other.ptr; 
}

template<typename T>
bool const_iterator<T>::operator>=(const const_iterator& other) const { 
    return ptr >= other.ptr; 
}

} // namespace line
