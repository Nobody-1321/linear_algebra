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

    template <nsp_concepts::is_numeric T>
    template <typename... Args>
      requires(sizeof...(Args) > 2)
              && nsp_concepts::same_numeric_type<T, Args...>
    DVec<T>::DVec(Args &&...args) : data_v{std::forward<Args>(args)...}
    {
      static_assert(sizeof...(Args) > 0,
                    " Number of arguments must be greater than zero");
    }

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
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator+");
      DVec<T> result(data_v.size());
      vector::math::AddVector(*this, vec_, result);

      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator+=(const DVec<T> &vec_)
    {
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator+=");

      vector::math::AddVector(*this, vec_);
      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator+(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      vector::math::AddVector(*this, result, scalar_, [scalar_](const T &val) {
        return val + scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator+=(const T &scalar_)
    {
      vector::math::AddVector(
        *this, scalar_, [scalar_](const T &val) { return val + scalar_; });
      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator-(const DVec<T> &vec_) const
    {
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator-");

      DVec<T> result(data_v.size());

      vector::math::SubVector(*this, vec_, result);
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator-=(const DVec<T> &vec_)
    {
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator-=");

      vector::math::SubVector(*this, vec_);

      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator-(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      vector::math::SubVector(*this, result, scalar_, [scalar_](const T &val) {
        return val - scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator-=(const T &scalar_)
    {
      vector::math::SubVector(
        *this, scalar_, [scalar_](const T &val) { return val - scalar_; });
      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator*(const DVec<T> &vec_) const
    {
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator*");

      DVec<T> result(data_v.size());

      vector::math::MulVector(*this, vec_, result);
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator*=(const DVec<T> &vec_)
    {
      assert(data_v.size() == vec_.data_v.size()
             && "Vector size mismatch in operator*=");

      vector::math::MulVector(*this, vec_);
      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator*(const T &scalar_) const
    {
      DVec<T> result(data_v.size());

      vector::math::MulVector(*this, result, scalar_, [scalar_](const T &val) {
        return val * scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator*=(const T &scalar_)
    {
      vector::math::MulVector(
        *this, scalar_, [scalar_](const T &val) { return val * scalar_; });
      return *this;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> DVec<T>::operator/(const T &scalar_) const
    {
      assert(scalar_ != 0 && "Division by zero in operator/");

      DVec<T> result(data_v.size());

      vector::math::DivVector(*this, result, scalar_, [scalar_](const T &val) {
        return val / scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> &DVec<T>::operator/=(const T &scalar_)
    {
      assert(scalar_ != 0 && "Division by zero in operator/=");

      vector::math::DivVector(
        *this, scalar_, [scalar_](const T &val) { return val / scalar_; });
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
      assert(index < data_v.size() && "Index out of bounds in operator[]");
      return data_v[index];
    }

    template <nsp_concepts::is_numeric T>
    const T &DVec<T>::operator[](std::size_t index) const
    {
      assert(index < data_v.size() && "Index out of bounds in operator[]");
      return data_v[index];
    }

    // data pointer
    template <nsp_concepts::is_numeric T> T *DVec<T>::data() noexcept
    {
      return data_v.data();
    }

    // const data
    template <nsp_concepts::is_numeric T>
    const T *DVec<T>::data() const noexcept
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

    template <nsp_concepts::is_numeric T> T DVec<T>::magnitude() const noexcept
    {
      T sum = std::accumulate(
        this->cbegin(), this->cend(), static_cast<T>(0),
        [](const T &acc, const T &val) { return acc + val * val; });
      return std::sqrt(sum);
    }

    /*
    template <nsp_concepts::is_numeric T>
    void DVec<T>::resize(std::size_t new_size)
    {
      data_v.resize(new_size);
    }
    */

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    template <nsp_concepts::is_numeric T>
    DVec<T> operator*(const T &scalar_, const DVec<T> &vec_)
    {
      DVec<T> result(vec_.size());
      vector::math::MulVector(vec_, result, scalar_, [scalar_](const T &val) {
        return val * scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> operator+(const T &scalar_, const DVec<T> &vec_)
    {
      DVec<T> result(vec_.size());
      vector::math::AddVector(vec_, result, scalar_, [scalar_](const T &val) {
        return val + scalar_;
      });
      return result;
    }

    template <nsp_concepts::is_numeric T>
    DVec<T> operator-(const T &scalar_, const DVec<T> &vec_)
    {
      DVec<T> result(vec_.size());

      vector::math::SubVector(vec_, result, scalar_, [scalar_](const T &val) {
        return scalar_ - val;
      });

      return result;
    }

  } // namespace structs
} // namespace line