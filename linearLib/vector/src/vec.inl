#include "../include/vec.hpp"

namespace line
{
    template <length_t L, IsNumberV T>
    vec<L, T>::vec()
    {
        std::fill(data_v.begin(), data_v.end(), std::nullopt);
    }

    template <length_t L, IsNumberV T>
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

    // Operadores de índice
    template <length_t L, IsNumberV T>
    const typename vec<L, T>::optional_type &vec<L, T>::operator[](const int &i) const
    {
        if (i >= 0 && i < L)
        {
            return data_v[i];
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    template <length_t L, IsNumberV T>
    vec<L, T> &vec<L, T>::operator=(const vec<L, T> &v)
    {
        if (this != &v)
        {
            std::copy(v.cbegin(), v.cend(), data_v.begin());
        }
        return *this;
    }

    template <length_t L, IsNumberV T>
    vec<L, T>::vec(const vec<L, T> &v) : data_v(v.data_v) {}

    template <length_t L, IsNumberV T>
    typename vec<L, T>::optional_type &vec<L, T>::operator[](const int &i)
    {
        if (i >= 0 && i < L)
        {
            return data_v[i];
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    // functions

    template <length_t L, IsNumberV T>
    int vec<L, T>::size() const
    {
        return L;
    }


    // iterators

    template <length_t L, IsNumberV T>
    typename vec<L, T>::iterator vec<L, T>::begin()
    {
        return iterator(data_v.data());
    }

    template <length_t L, IsNumberV T>
    typename vec<L, T>::iterator vec<L, T>::end()
    {
        return iterator(data_v.data() + L);
    }

    template <length_t L, IsNumberV T>
    typename vec<L, T>::const_iterator vec<L, T>::cbegin() const
    {
        return const_iterator(data_v.data());
    }

    template <length_t L, IsNumberV T>
    typename vec<L, T>::const_iterator vec<L, T>::cend() const
    {
        return const_iterator(data_v.data() + L);
    }

};