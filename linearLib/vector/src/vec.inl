//#pragma once
//#include "../include/vec.hpp"
namespace line
{
    using namespace detail;
    
    template <length_t L, IsNumber T>
    vec<L, T>::vec(const vec<L, T> &v)
    {
        data_v->fill(std::nullopt);
        std::copy_n(v.begin(), L, data_v->begin());
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(const vec<L, T> &v, T fill_value)
    {
        data_v->fill(fill_value);
        std::copy_n(v.begin(), L, data_v->begin());
    }

    template <length_t L, IsNumber T>
    template <length_t L2>
    vec<L, T>::vec(const vec<L2, T> &v)
    {
        data_v->fill(std::nullopt);
        std::copy_n(v.begin(), std::min(L, L2), data_v->begin());
    }

    template <length_t L, IsNumber T>
    template <length_t L2>
    vec<L, T>::vec(const vec<L2, T> &v, T fill_value)
    {
        data_v->fill(fill_value);
        std::copy_n(v.begin(), std::min(L, L2), data_v->begin());
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(vec<L, T> &&v) noexcept {
        data_v = std::move(v.data_v);
        v.data_v = nullptr;
    }

    template <length_t L, IsNumber T>
    template <typename... Args>
        requires detail::AreSameAndNumbers<T, Args...>
    vec<L, T>::vec(Args &&...args)
    {
        data_v->fill(std::nullopt);
        std::size_t index = 0;
        ((index < L && (data_v->at(index++) = static_cast<T>(args))), ...);
        
        //std::initializer_list<T> arg_list = {static_cast<T>(args)...};
        //std::copy_n(arg_list.begin(), std::min(L, sizeof...(args)), data_v->begin()); 
    }

    template <length_t L, IsNumber T>
    vec<L, T>::vec(T fill_value)
    {
        data_v->fill(fill_value);
    }


    //access to elements
    template<length_t L, IsNumber T>
    typename vec<L,T>::optional_type &vec<L, T>::operator[](const std::size_t &i) noexcept
    {
        return (*data_v)[i];
    }

    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::operator[](const std::size_t &i) const noexcept
    {
        return (*data_v)[i];
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type *vec<L, T>::data() noexcept
    {
        return data_v->data();
    }

    template <length_t L, IsNumber T>
    typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &i) noexcept
    {
        return data_v->at(i);
    }
    
    template <length_t L, IsNumber T>
    const typename vec<L, T>::optional_type &vec<L, T>::at(const std::size_t &i) const noexcept
    {
        return data_v->at(i);
    }
 
    //functions

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


    //iterators
     
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

};