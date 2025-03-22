namespace line
{
    namespace structs{



        // constructors for smart pointers

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::SVec() : data_v{std::make_unique<array_type>()}
        {
            data_v->fill(0);
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::SVec(const SVec<L, T> &vec_) : data_v{std::make_unique<array_type>()}
        {
            std::copy_n(vec_.cbegin(), L, data_v->begin());
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        template <typename... Args>
            requires nsp_concepts::same_numeric_type<T, Args...>
        SVec<L, T>::SVec(Args &&...args) : data_v{std::make_unique<array_type>()}
        {
            static_assert(sizeof...(Args) == L, "Number of arguments must be equal to the length of the vector");
            std::size_t index = 0;
            ((index < sizeof...(Args) && ((*data_v)[index++] = static_cast<T>(std::forward<Args>(args)))), ...);
        }

        // list initialization
        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::SVec(std::initializer_list<T> init_list) : data_v{std::make_unique<array_type>()}
        {
            assert(init_list.size() == L);
            std::copy(init_list.begin(), init_list.end(), data_v->begin());
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::SVec(SVec<L, T> &&vec_) noexcept
            : data_v(std::move(vec_.data_v))
        {
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::SVec(T fill_value) : data_v{std::make_unique<array_type>()}
        {
            data_v->fill(fill_value);
        }

        // assignment operators
        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator=(const SVec<L, T> &vec_)
        {
            if (this != &vec_)
            {
                std::copy_n(vec_.cbegin(), L, data_v->begin());
            }

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator=(SVec<L, T> &&vec_) noexcept
        {

            if (this != &vec_)
            {
                data_v = std::move(vec_.data_v);
            }

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> SVec<L, T>::operator+(const SVec<L, T> &vec_) const
        {
            SVec<L, T> result(0);

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

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> SVec<L, T>::operator-(const SVec<L, T> &vec_) const
        {
            SVec<L, T> result(0);

            std::transform(
                this->cbegin(), this->cend(),
                vec_.cbegin(),
                result.begin(),
                [](const T &valL, const T &valR) -> T
                {
                    return valL - valR;
                });

            return result;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> SVec<L, T>::operator*(const SVec<L, T> &vec_) const
        {
            SVec<L, T> result(0);

            std::transform(
                this->cbegin(), this->cend(),
                vec_.cbegin(),
                result.begin(),
                [](const T &valL, const T &valR) -> T
                {
                    return valL * valR;
                });

            return result;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> SVec<L, T>::operator*(const T &scalar) const
        {
            SVec<L, T> result(0);

            std::transform(
                this->cbegin(), this->cend(),
                result.begin(),
                [scalar](const T &val)
                {
                    return val * scalar;
                });

            return result;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> SVec<L, T>::operator/(const T &scalar) const
        {
            // division by zero is undefined
            SVec<L, T> result(0);

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

        // compound assignment operators
        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator+=(const SVec<L, T> &vec_)
        {
            std::transform(
                this->begin(), this->end(),
                vec_.cbegin(),
                this->begin(),
                std::plus<T>());

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator-=(const SVec<L, T> &vec_)
        {
            std::transform(
                this->begin(), this->end(),
                vec_.cbegin(),
                this->begin(),
                std::minus<T>());

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator*=(const SVec<L, T> &vec_)
        {
            std::transform(
                this->begin(), this->end(),
                vec_.cbegin(),
                this->begin(),
                std::multiplies<T>());

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator*=(const T &scalar)
        {
            std::transform(
                this->begin(), this->end(),
                this->begin(),
                [scalar](const T &val)
                {
                    return val * scalar;
                });

            return *this;
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T> &SVec<L, T>::operator/=(const T &scalar)
        {
            // division by zero is undefined

            std::transform(
                this->begin(), this->end(),
                this->begin(),
                [scalar](const T &val)
                {
                    return val / scalar;
                });

            return *this;
        }

        // access to elements
        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        typename SVec<L, T>::value_type &SVec<L, T>::operator[](const std::size_t &idx) noexcept
        {
            return (*data_v)[idx];
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        const typename SVec<L, T>::value_type &SVec<L, T>::operator[](const std::size_t &idx) const noexcept
        {
            return (*data_v)[idx];
        }

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        typename SVec<L, T>::value_type *SVec<L, T>::data() noexcept
        {
            return data_v->data();
        }

        // functions

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        constexpr std::size_t SVec<L, T>::max_size() const noexcept
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

        // iterators

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

        template <nsp_types::length_t L, nsp_concepts::is_numeric T>
        SVec<L, T>::~SVec() {}

        // scalar * vector
        template <nsp_types::length_t U, nsp_concepts::is_numeric R>
        SVec<U, R> operator*(const R &scalar, const SVec<U, R> &vec_)
        {
            SVec<U, R> result(0);

            std::transform(
                vec_.cbegin(), vec_.cend(),
                result.begin(),
                [scalar](const R &val)
                {
                    return val * scalar;
                });

            return result;
        }
    }
};