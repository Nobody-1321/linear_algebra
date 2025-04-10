
namespace line
{
  namespace ranges
  {
    template <typename T>
    RandomAccessIterator<T>::RandomAccessIterator(pointer ptr) : ptr{ptr}
    {}

    template <typename T>
    typename RandomAccessIterator<T>::reference
    RandomAccessIterator<T>::operator*() const
    {
      return *ptr;
    }

    template <typename T>
    typename RandomAccessIterator<T>::pointer
    RandomAccessIterator<T>::operator->()
    {
      return ptr;
    }

    template <typename T>
    RandomAccessIterator<T> &RandomAccessIterator<T>::operator++()
    {
      ++ptr;
      return *this;
    }

    template <typename T>
    RandomAccessIterator<T> RandomAccessIterator<T>::operator++(int)
    {
      RandomAccessIterator temp = *this;
      ++(*this);
      return temp;
    }

    template <typename T>
    RandomAccessIterator<T> &RandomAccessIterator<T>::operator--()
    {
      --ptr;
      return *this;
    }

    template <typename T>
    RandomAccessIterator<T> RandomAccessIterator<T>::operator--(int)
    {
      RandomAccessIterator temp = *this;
      --(*this);
      return temp;
    }

    template <typename T>
    RandomAccessIterator<T>
    RandomAccessIterator<T>::operator+(difference_type n) const
    {
      return RandomAccessIterator(ptr + n);
    }

    template <typename T>
    RandomAccessIterator<T>
    RandomAccessIterator<T>::operator-(difference_type n) const
    {
      return RandomAccessIterator(ptr - n);
    }

    template <typename T>
    typename RandomAccessIterator<T>::difference_type
    RandomAccessIterator<T>::operator-(const RandomAccessIterator &other) const
    {
      return ptr - other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator==(const RandomAccessIterator &other) const
    {
      return ptr == other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator!=(const RandomAccessIterator &other) const
    {
      return ptr != other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator<(const RandomAccessIterator &other) const
    {
      return ptr < other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator<=(const RandomAccessIterator &other) const
    {
      return ptr <= other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator>(const RandomAccessIterator &other) const
    {
      return ptr > other.ptr;
    }

    template <typename T>
    bool
    RandomAccessIterator<T>::operator>=(const RandomAccessIterator &other) const
    {
      return ptr >= other.ptr;
    }
  } // namespace ranges

} // namespace line
