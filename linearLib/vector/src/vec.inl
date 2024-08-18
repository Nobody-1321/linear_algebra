namespace line
{
    using namespace detail;

    // constructors for smart pointers

    template <length_t L, IsNumeric T>
    vec<L, T>::vec() : data_v{std::unique_ptr<array_type>()}
    {
        this->fill(0);
    }

    template <length_t L, IsNumeric T>
    vec<L, T>::vec(const vec<L, T> &vec_) : data_v{std::make_unique<array_type>()}
    {
        std::copy_n(vec_.cbegin(), L, data_v->begin());
    }



    template <length_t L, IsNumeric T>
    template <typename... Args>
        requires detail::AreSameAndNumbers<T, Args...>
    vec<L, T>::vec(Args &&...args) : data_v{std::make_unique<array_type>()}
    {
        static_assert(sizeof...(Args) == L, "Too many arguments provided to vec constructor");
        std::size_t index = 0;
        ((index < sizeof...(Args) && (data_v.at(index++) = static_cast<T>(std::forward<Args>(args)))), ...);
    }

    // list initialization
    template <length_t L, IsNumeric T>
    vec<L, T>::vec(std::initializer_list<T> init_list): data_v{std::make_unique<array_type>()}
    {
        if (init_list.size() != L)
        {
            throw std::invalid_argument("Invalid size of initializer list");
        }

        std::copy(init_list.begin(), init_list.end(), data_v.begin());
    }

    template <length_t L, IsNumeric T>
    vec<L, T>::vec(vec<L, T> &&vec_) noexcept
        : data_v(std::move(vec_.data_v)) // Utilizando lista de inicialización
    {
    }

    template <length_t L, IsNumeric T>
    vec<L, T>::vec(T fill_value): data_v(L)
    {
        this->fill(fill_value);
    }

    // assignment operators
    template <length_t L, IsNumeric T>
    vec<L, T> &vec<L, T>::operator=(const vec<L, T> &vec_)
    {
        if (this != &vec_)
        {
            std::copy_n(vec_.cbegin(), L, data_v->begin());
        }

        return *this;
    }

    template <length_t L, IsNumeric T>
    vec<L, T> &vec<L, T>::operator=(vec<L, T> &&vec_) noexcept
    {
        
        if (this != &vec_)
        {
            data_v = std::move(vec_.data_v);
        }
        
        return *this;
    }

    template <length_t L, IsNumeric T>
    vec<L, T> vec<L, T>::operator+(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->cbegin(), this->cend(),
            vec_.cbegin(),
            result.begin(),
            [](const T &valL, const T &valR) -> T
            {
                return valL + valR;
            });

        return result;
    }    




    template <length_t L, IsNumeric T>
    vec<L, T> vec<L, T>::operator-(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->cbegin(), this->cend(),
            vec_.cbegin(),
            result.begin(),
            [](const T &valL, const T &valR) 
            {
                return valL - valR;
            });

        return result;
    }

    template <length_t L, IsNumeric T>
    vec<L, T> vec<L, T>::operator*(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->cbegin(), this->cend(),
            vec_.cbegin(),
            result.begin(),
            [](const T &valL, const T &valR)
            {
                return valL * valR;
            });

        return result;
    }

    template <length_t L, IsNumeric T>
    vec<L, T> vec<L, T>::operator*(const T &scalar) const
    {
        vec<L, T> result(0);

        std::transform(
            this->cbegin(), this->cend(),
            result.begin(),
            [scalar](const T &val)
            {
                return val * scalar;
            });

        return result;
    }

    template <length_t L, IsNumeric T>
    vec<L, T> vec<L, T>::operator/(const T &scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero");
        }

        vec<L, T> result(0);

        std::transform(
            this->cbegin(), this->cend(),
            result.begin(),
            [scalar](const T &val)
            {
                return val / scalar;
            });

        return result;
    }    

    // comparison operators
    template <length_t L, IsNumeric T>
    bool vec<L, T>::operator==(const vec<L, T> &vec_) const
    {
        return std::equal(this->cbegin(), this->cend(), vec_.cbegin());
    }

    template <length_t L, IsNumeric T>
    bool vec<L, T>::operator!=(const vec<L, T> &vec_) const
    {
        return !(*this == vec_);
    }


    // access to elements
    template <length_t L, IsNumeric T>
    typename vec<L, T>::value_type &vec<L, T>::operator[](const std::size_t &idx) noexcept
    {
        return data_v[idx];
    }

    template <length_t L, IsNumeric T>
    const typename vec<L, T>::value_type &vec<L, T>::operator[](const std::size_t &idx) const noexcept
    {
        return data_v[idx];
    }



    template <length_t L, IsNumeric T>
    typename vec<L, T>::value_type *vec<L, T>::data() noexcept
    {
        return data_v.data();
    }

    template <length_t L, IsNumeric T>
    typename vec<L, T>::value_type &vec<L, T>::at(const std::size_t &idx)
    {
        return data_v.at(idx);
    }

    template <length_t L, IsNumeric T>
    const typename vec<L, T>::value_type &vec<L, T>::at(const std::size_t &idx) const
    {
        return data_v.at(idx);
    }

    // functions

    template <length_t L, IsNumeric T>
    constexpr std::size_t vec<L, T>::size() const noexcept
    {
        return vec<L, T>::length::value;
    }

    template <length_t L, IsNumeric T>
    void vec<L, T>::fill(T fill_value)
    {
        std::fill(data_v.begin(), data_v.end(), fill_value);
    }

    template <length_t L, IsNumeric T>
    void vec<L, T>::swap(vec<L, T> &vec_) noexcept
    {
        std::swap(data_v, vec_.data_v);
    }


    // iterators

    template <length_t L, IsNumeric T>
    typename vec<L, T>::iterator vec<L, T>::begin() noexcept
    {
        return iterator(data_v.data());
    }

    template <length_t L, IsNumeric T>
    typename vec<L, T>::iterator vec<L, T>::end() noexcept
    {
        return iterator(data_v.data() + L);
    }

    template <length_t L, IsNumeric T>
    typename vec<L, T>::const_iterator vec<L, T>::cbegin() const noexcept
    {
        return const_iterator(data_v.data());
    }

    template <length_t L, IsNumeric T>
    typename vec<L, T>::const_iterator vec<L, T>::cend() const noexcept
    {
        return const_iterator(data_v.data() + L);
    }

    template <length_t L, IsNumeric T>
    vec<L, T>::~vec(){}


    // scalar * vector
    template <length_t U, IsNumeric R>
    vec<U, R> operator*(const R &scalar, const vec<U, R> &vec_)
    {
        vec<U, R> result(0);

        std::transform(
            vec_.cbegin(), vec_.cend(),
            result.begin(),
            [scalar](const R &val)
            {
                return val * scalar;
            });

        return result;
    }


};