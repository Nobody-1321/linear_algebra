// ConstRandomAccessIterator.inl

namespace line
{

  namespace ranges
  {

    template <typename T>
    ConstRandomAccessIterator<T>::ConstRandomAccessIterator(pointer ptr)
        : ptr{ptr}
    {}

    template <typename T>
    typename ConstRandomAccessIterator<T>::reference
    ConstRandomAccessIterator<T>::operator*() const
    {
      return *ptr;
    }

    template <typename T>
    typename ConstRandomAccessIterator<T>::pointer
    ConstRandomAccessIterator<T>::operator->() const
    {
      return ptr;
    }

    template <typename T>
    ConstRandomAccessIterator<T> &ConstRandomAccessIterator<T>::operator++()
    {
      ++ptr;
      return *this;
    }

    template <typename T>
    ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator++(int)
    {
      ConstRandomAccessIterator temp = *this;
      ++(*this);
      return temp;
    }

    template <typename T>
    ConstRandomAccessIterator<T> &ConstRandomAccessIterator<T>::operator--()
    {
      --ptr;
      return *this;
    }

    template <typename T>
    ConstRandomAccessIterator<T> ConstRandomAccessIterator<T>::operator--(int)
    {
      ConstRandomAccessIterator temp = *this;
      --(*this);
      return temp;
    }

    template <typename T>
    ConstRandomAccessIterator<T>
    ConstRandomAccessIterator<T>::operator+(difference_type n) const
    {
      return ConstRandomAccessIterator(ptr + n);
    }

    template <typename T>
    ConstRandomAccessIterator<T>
    ConstRandomAccessIterator<T>::operator-(difference_type n) const
    {
      return ConstRandomAccessIterator(ptr - n);
    }

    template <typename T>
    typename ConstRandomAccessIterator<T>::difference_type
    ConstRandomAccessIterator<T>::operator-(
      const ConstRandomAccessIterator &other) const
    {
      return ptr - other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator==(
      const ConstRandomAccessIterator &other) const
    {
      return ptr == other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator!=(
      const ConstRandomAccessIterator &other) const
    {
      return ptr != other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator<(
      const ConstRandomAccessIterator &other) const
    {
      return ptr < other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator<=(
      const ConstRandomAccessIterator &other) const
    {
      return ptr <= other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator>(
      const ConstRandomAccessIterator &other) const
    {
      return ptr > other.ptr;
    }

    template <typename T>
    bool ConstRandomAccessIterator<T>::operator>=(
      const ConstRandomAccessIterator &other) const
    {
      return ptr >= other.ptr;
    }

  } // namespace iterator

} // namespace line
