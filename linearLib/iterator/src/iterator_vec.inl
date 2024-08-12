
namespace line {

template<typename T>
iterator<T>::iterator(pointer ptr) : ptr{ptr} {}

template<typename T>
typename iterator<T>::reference iterator<T>::operator*() const { 
    return *ptr; 
}

template<typename T>
typename iterator<T>::pointer iterator<T>::operator->() { 
    return ptr; 
}

template<typename T>
iterator<T>& iterator<T>::operator++() { 
    ++ptr; 
    return *this; 
}

template<typename T>
iterator<T> iterator<T>::operator++(int) { 
    iterator temp = *this; 
    ++(*this); 
    return temp; 
}

template<typename T>
iterator<T>& iterator<T>::operator--() { 
    --ptr; 
    return *this; 
}

template<typename T>
iterator<T> iterator<T>::operator--(int) { 
    iterator temp = *this; 
    --(*this); 
    return temp; 
}

template<typename T>
iterator<T> iterator<T>::operator+(difference_type n) const { 
    return iterator(ptr + n); 
}

template<typename T>
iterator<T> iterator<T>::operator-(difference_type n) const { 
    return iterator(ptr - n); 
}

template<typename T>
typename iterator<T>::difference_type iterator<T>::operator-(const iterator& other) const { 
    return ptr - other.ptr; 
}

template<typename T>
bool iterator<T>::operator==(const iterator& other) const { 
    return ptr == other.ptr; 
}

template<typename T>
bool iterator<T>::operator!=(const iterator& other) const { 
    return ptr != other.ptr; 
}

template<typename T>
bool iterator<T>::operator<(const iterator& other) const { 
    return ptr < other.ptr; 
}

template<typename T>
bool iterator<T>::operator<=(const iterator& other) const { 
    return ptr <= other.ptr; 
}

template<typename T>
bool iterator<T>::operator>(const iterator& other) const { 
    return ptr > other.ptr; 
}

template<typename T>
bool iterator<T>::operator>=(const iterator& other) const { 
    return ptr >= other.ptr; 
}

} // namespace line
