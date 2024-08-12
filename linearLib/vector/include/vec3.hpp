#pragma once

#include "../../detail/setup_vec.hpp"
#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"


namespace line{
 
    template<IsNumber T> 
    struct vec<3, T>{
        
        using value_type = T;
        using type = vec<3, T>;
        using length = std::integral_constant<length_t, 3>;
        using iterator = line::iterator<T>;
        using const_iterator = line::const_iterator<T>;       

        // constructors 
        vec(T coordX, T coordY , T coordZ);  
        vec(const vec<3, T>& vec_); 
        vec(const vec<2, T>& vec_, T coordZ);
        vec(vec<3, T>&& vec_) noexcept;

        // assignment operators
        vec<3, T>& operator = (const vec<3, T>& vec_); 
        vec<3, T>& operator = (vec<3, T>&& vec_) noexcept;

        // arithmetic operators
        vec<3, T> operator + (const vec<3, T>& vec_) const; 
        vec<3, T> operator - (const vec<3, T>& vec_) const; 
        vec<3, T> operator * (const vec<3, T>& vec_) const; 
        vec<3, T> operator * (const T& sca) const; 
        vec<3, T> operator / (const T& sca) const;
        
        // comparison operators
        constexpr bool operator == (const vec<3, T>& vec_) const noexcept; 
        
        // access to elements
        const T& operator [] (const std::size_t& idx) const noexcept;
        T& operator [] (const std::size_t& idx) noexcept;
        T* data() noexcept;
        const T& at(const std::size_t& idx) const;
        T& at(const std::size_t& idx);

        // functions
        constexpr std::size_t size() const noexcept;
        void swap(vec<3, T>& vec_) noexcept;

        //iterators
        iterator begin() noexcept;
        iterator end() noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        
        ~vec();
        
        T x, y, z;
    };

    /// free functions
    template<IsNumber U>
    vec<3, U> operator/(const U& sca, const vec<3, U>& vec_);

    template<IsNumber U>
    vec<3, U> operator * (const U& sca, const vec<3, U>& vec_);
};

#include "../src/vec3.inl"
