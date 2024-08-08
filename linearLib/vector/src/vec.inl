//#pragma once
//#include "../include/vec.hpp"
namespace line
{
    using namespace detail;
       
    template <length_t L, IsNumber T>
    vec<L, T>::vec()
    {
        std::fill(data_v.begin(), data_v.end(), std::nullopt);
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(const std::initializer_list<T> &l)
    {
        if (l.size() <= L)
        {
            // Copiar elementos desde la lista
            std::copy(l.begin(), l.end(), data_v.begin());

            // Llenar el resto con ceros si la lista es más pequeña
            if (l.size() < L)
            {
                std::fill(data_v.begin() + l.size(), data_v.end(), std::nullopt);
            }
        }
        else
        {
            // Copiar solo los primeros L elementos si la lista es más grande
            std::copy(l.begin(), l.begin() + L, data_v.begin());
        }
    }


    template <length_t L, IsNumber T>
    template <length_t M>
    vec<L, T>::vec(const vec<M, T> &v)
    {
        if (v.size() <= L)
        {
            // Copiar elementos desde el vector origen
            std::copy(v.cbegin(), v.cbegin() + v.size(), data_v.begin());

            // Llenar el resto con ceros si el vector origen es más pequeño
            if (v.size() < L)
            {
                std::fill(data_v.begin() + v.size(), data_v.end(), std::nullopt);
            }
        }
        else
        {
            // Copiar solo los primeros L elementos si el vector origen es más grande
            std::copy(v.cbegin(), v.cbegin() + L, data_v.begin());
        }
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(const vec<L, T> &v) : data_v(v.data_v) {}

    template <length_t L, IsNumber T>
    vec<L, T> &vec<L, T>::operator=(const vec<L, T> &v)
    {
        if (this != &v)
        {
            std::copy(v.cbegin(), v.cend(), data_v.begin());
        }
        return *this;
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(vec<L, T> &&v) noexcept : data_v(std::move(v.data_v)) {}

 
    template <length_t L, IsNumber T>
    vec<L, T> &vec<L, T>::operator=(vec<L, T> &&v) noexcept
    {
        if (this != &v)
        {
            data_v = std::move(v.data_v);
        }
        return *this;
    }

 
    // Operadores de índice
    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::operator[](const std::size_t &i) const
    {
        return data_v[i];
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type &vec<L, T>::operator[](const std::size_t &i)
    {
        return data_v[i];
    }

    // functions
    template <length_t L, IsNumber T>
    std::size_t vec<L, T>::size() const
    {
        return L;
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type *vec<L, T>::data()
    {
        return data_v.data();
    }

    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &i) const
    {
        if (i < L)
        {
            return data_v[i];
        }

        throw std::out_of_range("Index out of range");
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &i)
    {
        if (i < L)
        {
            return data_v[i];
        }

        throw std::out_of_range("Index out of range");
    }
    

    // iterators

    template <length_t L, IsNumber T>
    typename vec<L, T>::iterator vec<L, T>::begin()
    {
        return iterator(data_v.data());
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::iterator vec<L, T>::end()
    {
        return iterator(data_v.data() + L);
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::const_iterator vec<L, T>::cbegin() const
    {
        return const_iterator(data_v.data());
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::const_iterator vec<L, T>::cend() const
    {
        return const_iterator(data_v.data() + L);
    }
    //destructor
    template <length_t L, IsNumber T>
    vec<L, T>::~vec() {}
};