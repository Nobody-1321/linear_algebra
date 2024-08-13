// #pragma once
// #include "../include/vec.hpp"
namespace line
{
    using namespace detail;

    template <length_t L, IsNumber T>
    vec<L, T>::vec(const vec<L, T> &vec_)
    {
        data_v->fill(std::nullopt);
        std::copy_n(vec_.begin(), L, data_v->begin());
    }

    template <length_t L, IsNumber T>
    template <length_t L2>
    vec<L, T>::vec(const vec<L2, T> &vec_)
    {
        data_v->fill(std::nullopt);
        std::copy_n(vec_.begin(), std::min(L, L2), data_v->begin());
    }

    template <length_t L, IsNumber T>
    template <length_t L2>
    vec<L, T>::vec(const vec<L2, T> &vec_, T fill_value)
    {
        data_v->fill(fill_value);
        std::copy_n(vec_.begin(), std::min(L, L2), data_v->begin());
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(vec<L, T> &&vec_) noexcept
        : data_v(std::move(vec_.data_v)) // Utilizando lista de inicialización
    {
        vec_.data_v = nullptr;
    }

    template <length_t L, IsNumber T>
    template <typename... Args>
        requires detail::AreSameAndNumbers<T, Args...>
    vec<L, T>::vec(Args &&...args)
    {
        data_v->fill(std::nullopt);
        std::size_t index = 0;
        ((index < L && (data_v->at(index++) = static_cast<T>(std::forward<Args>(args)))), ...);
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(T fill_value)
    {
        data_v->fill(fill_value);
    }

    // assignment operators
    template <length_t L, IsNumber T>
    vec<L, T> &vec<L, T>::operator=(const vec<L, T> &vec_)
    {
        if (this != &vec_)
        {
            std::copy_n(vec_.begin(), L, data_v->begin());
        }

        return *this;
    }

    template <length_t L, IsNumber T>
    vec<L, T> &vec<L, T>::operator=(vec<L, T> &&vec_) noexcept
    {
        if (this != &vec_)
        {
            data_v = std::move(vec_.data_v);
            vec_.data_v = nullptr;
        }
        return *this;
    }

    template <length_t L, IsNumber T>
    vec<L, T> vec<L, T>::operator+(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->begin(), this->end(),
            vec_.begin(),
            result.begin(),
            [](const std::optional<T> &valL, const std::optional<T> &valR) -> std::optional<T>
            {
                if (valL.has_value() && valR.has_value())
                {
                    return valL.value() + valR.value();
                }
                return std::nullopt;
            });

        return result;
    }

    template <length_t L, IsNumber T>
    vec<L, T> vec<L, T>::operator-(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->begin(), this->end(),
            vec_.begin(),
            result.begin(),
            [](const std::optional<T> &valL, const std::optional<T> &valR) -> std::optional<T>
            {
                if (valL.has_value() && valR.has_value())
                {
                    return valL.value() - valR.value();
                }
                return std::nullopt;
            });

        return result;
    }

    template <length_t L, IsNumber T>
    vec<L, T> vec<L, T>::operator*(const vec<L, T> &vec_) const
    {
        vec<L, T> result(0);

        std::transform(
            this->begin(), this->end(),
            vec_.begin(),
            result.begin(),
            [](const std::optional<T> &valL, const std::optional<T> &valR) -> std::optional<T>
            {
                if (valL.has_value() && valR.has_value())
                {
                    return valL.value() * valR.value();
                }
                return std::nullopt;
            });

        return result;
    }

    template <length_t L, IsNumber T>
    vec<L, T> vec<L, T>::operator*(const T &scalar) const
    {
        vec<L, T> result(0);

        std::transform(
            this->begin(), this->end(),
            result.begin(),
            [scalar](const std::optional<T> &val) -> std::optional<T>
            {
                if (val.has_value())
                {
                    return val.value() * scalar;
                }
                return std::nullopt;
            });

        return result;
    }

    template <length_t L, IsNumber T>
    vec<L, T> vec<L, T>::operator/(const T &scalar) const
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero");
        }

        vec<L, T> result(0);

        std::transform(
            this->begin(), this->end(),
            result.begin(),
            [scalar](const std::optional<T> &val) -> std::optional<T>
            {
                if (val.has_value())
                {
                    return val.value() / scalar;
                }
                return std::nullopt;
            });

        return result;
    }    

    // comparison operators
    template <length_t L, IsNumber T>
    bool vec<L, T>::operator==(const vec<L, T> &vec_) const
    {
        return std::equal(this->begin(), this->end(), vec_.begin());
    }

    // access to elements
    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type &vec<L, T>::operator[](const std::size_t &idx) noexcept
    {
        return (*data_v)[idx];
    }

    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::operator[](const std::size_t &idx) const noexcept
    {
        return (*data_v)[idx];
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type *vec<L, T>::data() noexcept
    {
        return data_v->data();
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &idx)
    {
        return data_v->at(idx);
    }

    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &idx) const
    {
        return data_v->at(idx);
    }

    // functions

    template <length_t L, IsNumber T>
    constexpr std::size_t vec<L, T>::size() const noexcept
    {
        return L;
    }

    template <length_t L, IsNumber T>
    void vec<L, T>::fill(T fill_value)
    {
        data_v->fill(fill_value);
    }

    template <length_t L, IsNumber T>
    void vec<L, T>::swap(vec<L, T> &vec_) noexcept
    {
        std::swap(*data_v, *vec_.data_v);
    }

    // iterators

    template <length_t L, IsNumber T>
    typename vec<L, T>::iterator vec<L, T>::begin() noexcept
    {
        return iterator(data_v->begin());
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::iterator vec<L, T>::end() noexcept
    {
        return iterator(data_v->end());
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::const_iterator vec<L, T>::begin() const noexcept
    {
        return const_iterator(data_v->begin());
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::const_iterator vec<L, T>::end() const noexcept
    {
        return const_iterator(data_v->end());
    }

    template <length_t L, IsNumber T>
    vec<L, T>::~vec() {}

    // free functions
    template <length_t U, IsNumber R>
    vec<U, R> operator/(const R &scalar, const vec<U, R> &vec_)
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero");
        }

        vec<U, R> result(0);

        std::transform(
            vec_.begin(), vec_.end(),
            result.begin(),
            [scalar](const std::optional<R> &val) -> std::optional<R>
            {
                if (val.has_value())
                {
                    return scalar / val.value();
                }
                return std::nullopt;
            });

        return result;
    }

    // scalar * vector
    template <length_t U, IsNumber R>
    vec<U, R> operator*(const R &scalar, const vec<U, R> &vec_)
    {
        vec<U, R> result(0);

        std::transform(
            vec_.begin(), vec_.end(),
            result.begin(),
            [scalar](const std::optional<R> &val) -> std::optional<R>
            {
                if (val.has_value())
                {
                    return scalar * val.value();
                }
                return std::nullopt;
            });

        return result;
    }


};