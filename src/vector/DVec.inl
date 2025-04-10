namespace line
{
  namespace structs
  {

    // +---------------------------------------------+
    // |                 Constructors                |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T> DVec<T>::DVec() : data_v{} {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(std::size_t size_) : data_v(size_)
    {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(const DVec<T> &vec_) : data_v(vec_.data_v)
    {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(DVec<T> &&vec_) noexcept : data_v(std::move(vec_.data_v))
    {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(std::size_t size_, const T &value) : data_v(size_, value)
    {}

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec(std::initializer_list<T> list) : data_v(list)
    {}

    // +---------------------------------------------+
    // |           assignment operators              |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator=(const DVec<T> &vec_)
    {
      if(this != &vec_)
        {
          data_v = vec_.data_v;
        }

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator=(DVec<T> &&vec_) noexcept
    {
      if(this != &vec_)
        {
          data_v = std::move(vec_.data_v);
        }

      return *this;
    }

    // +---------------------------------------------+
    // |           arithmetic operators              |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator+(const DVec<T> &vec_) const
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     result.data_v.begin(),
                     [](const T &a, const T &b) { return a + b; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator+=(const DVec<T> &vec_)
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     data_v.begin(),
                     [](const T &a, const T &b) { return a + b; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator+(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), result.data_v.begin(),
                     [scalar_](const T &a) { return a + scalar_; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator+=(const T &scalar_)
    {
      std::transform(data_v.begin(), data_v.end(), data_v.begin(),
                     [scalar_](const T &a) { return a + scalar_; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator-(const DVec<T> &vec_) const
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     result.data_v.begin(),
                     [](const T &a, const T &b) { return a - b; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator-=(const DVec<T> &vec_)
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     data_v.begin(),
                     [](const T &a, const T &b) { return a - b; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator-(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), result.data_v.begin(),
                     [scalar_](const T &a) { return a - scalar_; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator-=(const T &scalar_)
    {
      std::transform(data_v.begin(), data_v.end(), data_v.begin(),
                     [scalar_](const T &a) { return a - scalar_; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator*(const DVec<T> &vec_) const
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     result.data_v.begin(),
                     [](const T &a, const T &b) { return a * b; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator*=(const DVec<T> &vec_)
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     data_v.begin(),
                     [](const T &a, const T &b) { return a * b; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator*(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), result.data_v.begin(),
                     [scalar_](const T &a) { return a * scalar_; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator*=(const T &scalar_)
    {
      std::transform(data_v.begin(), data_v.end(), data_v.begin(),
                     [scalar_](const T &a) { return a * scalar_; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator/(const DVec<T> &vec_) const
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     result.data_v.begin(),
                     [](const T &a, const T &b) { return a / b; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator/=(const DVec<T> &vec_)
    {
      if(data_v.size() != vec_.data_v.size())
        {
          throw std::length_error("Vectors must be of the same size");
        }

      std::transform(data_v.begin(), data_v.end(), vec_.data_v.begin(),
                     data_v.begin(),
                     [](const T &a, const T &b) { return a / b; });

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator/(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      std::transform(data_v.begin(), data_v.end(), result.data_v.begin(),
                     [scalar_](const T &a) { return a / scalar_; });

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator/=(const T &scalar_)
    {
      std::transform(data_v.begin(), data_v.end(), data_v.begin(),
                     [scalar_](const T &a) { return a / scalar_; });

      return *this;
    }

    // +---------------------------------------------+
    // |           comparison operators              |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T>
    bool DVec<T>::operator==(const DVec<T> &vec_) const
    {
      return data_v == vec_.data_v;
    }

    template <nsp_concepts::is_numeric T>
    bool DVec<T>::operator!=(const DVec<T> &vec_) const
    {
      return data_v != vec_.data_v;
    }

    // +---------------------------------------------+
    // |           element access operators          |
    // +---------------------------------------------+

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

    // +---------------------------------------------+
    // |               iterators                     |
    // +---------------------------------------------+

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
    typename DVec<T>::const_iterator DVec<T>::cbegin() const
    {
      return const_iterator(data_v.data());
    }

    template <nsp_concepts::is_numeric T>
    typename DVec<T>::const_iterator DVec<T>::cend() const
    {
      return const_iterator(data_v.data() + data_v.size());
    }

    // +---------------------------------------------+
    // |               functions                     |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T> void DVec<T>::fill(T fill_value)
    {
      std::fill(data_v.begin(), data_v.end(), fill_value);
    }

    template <nsp_concepts::is_numeric T> std::size_t DVec<T>::size() const
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

    template <nsp_concepts::is_numeric T> bool DVec<T>::is_valid()
    {
      return !data_v.empty();
    }

    template <nsp_concepts::is_numeric T> void DVec<T>::swap(DVec<T> &vec_)
    {
      data_v.swap(vec_.data_v);
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