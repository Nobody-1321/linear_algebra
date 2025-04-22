namespace line
{
  namespace structs
  {

    // +---------------------------------------------+
    // |                 Constructors                |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::SVec() : data_v{std::make_unique<array_type>()}
    {}

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::SVec(const SVec<L, T> &vec_)
        : data_v{std::make_unique<array_type>()}
    {
      std::copy_n(vec_.cbegin(), L, data_v->begin());
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    template <typename... Args>
      requires(sizeof...(Args) > 1)
              && nsp_concepts::same_numeric_type<T, Args...>
    SVec<L, T>::SVec(Args &&...args) : data_v{std::make_unique<array_type>()}
    {
      static_assert(
        sizeof...(Args) == L,
        "Number of arguments must be equal to the length of the vector");

      // Initialize the vector elements using fold expression.
      std::size_t index = 0;
      ((index < sizeof...(Args)
        && ((*data_v)[index++] = static_cast<T>(std::forward<Args>(args)))),
       ...);
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::SVec(std::initializer_list<T> init_list)
        : data_v{std::make_unique<array_type>()}
    {
      // `assert` is used instead of `static_assert` because the size of the
      // initializer list is only known at runtime, not at compile time.
      assert(
        init_list.size() == L
        && "Initializer list size must be equal to the length of the vector");
      std::copy(init_list.begin(), init_list.end(), data_v->begin());
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::SVec(SVec<L, T> &&vec_) noexcept
        : data_v(std::move(vec_.data_v))
    {}

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::SVec(T fill_value) : data_v{std::make_unique<array_type>()}
    {
      data_v->fill(fill_value);
    }

    // +---------------------------------------------+
    // |           assignment operators              |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator=(const SVec<L, T> &vec_)
    {
      if(this != &vec_)
        {
          std::copy_n(vec_.cbegin(), L, data_v->begin());
        }

      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator=(SVec<L, T> &&vec_) noexcept
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

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator+(const SVec<L, T> &vec_) const
    {
      SVec<L, T> result;
      line::math::AddVector(*this, vec_, result);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator+=(const SVec<L, T> &vec_)
    {
      line::math::AddVector(*this, vec_);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator+(const T &scalar) const
    {
      SVec<L, T> result;
      line::math::AddVector(*this, result, scalar);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator+=(const T &scalar)
    {
      line::math::AddVector(*this, scalar);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator-(const SVec<L, T> &vec_) const
    {
      SVec<L, T> result;
      line::math::SubVector(*this, vec_, result);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator-=(const SVec<L, T> &vec_)
    {
      line::math::SubVector(*this, vec_);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator-(const T &scalar) const
    {
      SVec<L, T> result;
      line::math::SubVector(*this, result, scalar);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator-=(const T &scalar)
    {
      line::math::SubVector(*this, scalar);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator*(const SVec<L, T> &vec_) const
    {
      SVec<L, T> result;

      line::math::MulVector(*this, vec_, result);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator*(const T &scalar) const
    {
      SVec<L, T> result;
      line::math::MulVector(*this, result, scalar);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator*=(const SVec<L, T> &vec_)
    {
      line::math::MulVector(*this, vec_);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator*=(const T &scalar)
    {
      line::math::MulVector(*this, scalar);
      return *this;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> SVec<L, T>::operator/(const T &scalar) const
    {
      assert(scalar != 0 && "Division by zero");

      SVec<L, T> result;
      line::math::DivVector(*this, result, scalar);
      return result;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T> &SVec<L, T>::operator/=(const T &scalar)
    {
      assert(scalar != 0 && "Division by zero");

      line::math::DivVector(*this, scalar);

      return *this;
    }

    // +---------------------------------------------+
    // |           comparison operators              |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    bool SVec<L, T>::operator==(const SVec<L, T> &vec_) const
    {
      return std::equal(this->cbegin(), this->cend(), vec_.cbegin());
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    bool SVec<L, T>::operator!=(const SVec<L, T> &vec_) const
    {
      return !(*this == vec_);
    }

    // +---------------------------------------------+
    // |           element access operators          |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::value_type &
    SVec<L, T>::operator[](const std::size_t &idx) noexcept
    {
      assert(idx < L && "Index out of bounds");
      return (*data_v)[idx];
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    const typename SVec<L, T>::value_type &
    SVec<L, T>::operator[](const std::size_t &idx) const noexcept
    {
      assert(idx < L && "Index out of bounds");
      return (*data_v)[idx];
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::value_type *SVec<L, T>::data() noexcept
    {
      return data_v->data();
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    const typename SVec<L, T>::value_type *SVec<L, T>::data() const noexcept
    {
      return data_v->data();
    }

    // +---------------------------------------------+
    // |              functions                      |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    constexpr std::size_t SVec<L, T>::size() const noexcept
    {
      return SVec<L, T>::length::value;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    constexpr std::size_t SVec<L, T>::capacity() const noexcept
    {
      return SVec<L, T>::length::value;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    void SVec<L, T>::fill(T fill_value)
    {
      data_v->fill(fill_value);
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    void SVec<L, T>::swap(SVec<L, T> &vec_) noexcept
    {
      std::swap(data_v, vec_.data_v);
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    bool SVec<L, T>::is_valid() const noexcept
    {
      return data_v != nullptr;
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    T SVec<L, T>::magnitude() const noexcept
    {
      T sum = std::accumulate(
        this->cbegin(), this->cend(), static_cast<T>(0),
        [](const T &acc, const T &val) { return acc + val * val; });

      return std::sqrt(sum);
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    T SVec<L, T>::square_sum() const noexcept
    {
      return std::accumulate(
        this->cbegin(), this->cend(), static_cast<T>(0),
        [](const T &acc, const T &val) { return acc + val * val; });
    }

    // +---------------------------------------------+
    // |               iterators                     |
    // +---------------------------------------------+

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::iterator SVec<L, T>::begin() noexcept
    {
      return iterator(data_v->data());
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::iterator SVec<L, T>::end() noexcept
    {
      return iterator(data_v->data() + L);
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::const_iterator SVec<L, T>::cbegin() const noexcept
    {
      return const_iterator(data_v->data());
    }

    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    typename SVec<L, T>::const_iterator SVec<L, T>::cend() const noexcept
    {
      return const_iterator(data_v->data() + L);
    }

    // destructor
    template <nsp_types::length_t L, nsp_concepts::is_numeric T>
    SVec<L, T>::~SVec()
    {}

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    // scalar * vector
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator*(const R &scalar, const SVec<U, R> &vec_)
    {
      SVec<U, R> result;

      std::transform(vec_.cbegin(), vec_.cend(), result.begin(),
                     [scalar](const R &val) { return val * scalar; });

      return result;
    }

    // scalar + vector
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator+(const R &scalar, const SVec<U, R> &vec_)
    {
      SVec<U, R> result;
      line::math::AddVector(vec_, result, scalar);
      return result;
    }

    // scalar - vector
    template <nsp_types::length_t U, nsp_concepts::is_numeric R>
    SVec<U, R> operator-(const R &scalar, const SVec<U, R> &vec_)
    {
      SVec<U, R> result;

      line::math::SubVector(scalar, vec_, result);

      return result;
    }

  }
};