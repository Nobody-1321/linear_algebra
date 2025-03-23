namespace line
{
  namespace structs
  {
    // constructors
    template <nsp_concepts::is_numeric T> DVec<T>::DVec() : data_v{} {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(std::size_t size_) : data_v(size_)
    {}

    // access to elements
    template <nsp_concepts::is_numeric T>
    T &DVec<T>::operator[](std::size_t index)
    {
      return data_v[index];
    }

    template <nsp_concepts::is_numeric T>
    const T &DVec<T>::operator[](std::size_t index) const
    {
      return data_v[index];
    }

    // data pointer
    template <nsp_concepts::is_numeric T> T *DVec<T>::data() noexcept
    {
      return data_v.data();
    }

    // functions
    template <nsp_concepts::is_numeric T> void DVec<T>::fill(T fill_value)
    {
      std::fill(data_v.begin(), data_v.end(), fill_value);
    }

    template <nsp_concepts::is_numeric T> std::size_t DVec<T>::size()
    {
      return data_v.size();
    }

    template <nsp_concepts::is_numeric T> std::size_t DVec<T>::capacity()
    {
      return data_v.capacity();
    }

    template <nsp_concepts::is_numeric T>
    void DVec<T>::reserve(std::size_t new_capacity)
    {
      data_v.reserve(new_capacity);
    }

    template <nsp_concepts::is_numeric T> void DVec<T>::push_back(T value)
    {
      data_v.push_back(value);
    }

    template <nsp_concepts::is_numeric T> void DVec<T>::pop_back()
    {
      data_v.pop_back();
    }

    template <nsp_concepts::is_numeric T> void DVec<T>::clear()
    {
      data_v.clear();
    }

    // iterators
    template <nsp_concepts::is_numeric T>
    typename DVec<T>::iterator DVec<T>::begin()
    {
      return iterator(data_v.data());
    }

    template <nsp_concepts::is_numeric T>
    typename DVec<T>::iterator DVec<T>::end()
    {
      return iterator(data_v.data() + data_v.size());
    }

    template <nsp_concepts::is_numeric T>
    typename DVec<T>::const_iterator DVec<T>::begin() const
    {
      return const_iterator(data_v.data());
    }

    template <nsp_concepts::is_numeric T>
    typename DVec<T>::const_iterator DVec<T>::end() const
    {
      return const_iterator(data_v.data() + data_v.size());
    }

    /*
    template <nsp_concepts::is_numeric T>
    void DVec<T>::resize(std::size_t new_size)
    {
      data_v.resize(new_size);
    }
    */

  } // namespace structs
} // namespace line