#pragma once

#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include "../../detail/setup_vec.hpp"

namespace line{
 
    template<IsNumber T> 
    struct vec<4, T>{
        
        using value_type = T;
        using type = vec<4, T>;
        using length = std::integral_constant<length_t, 4>;
        using iterator = line::iterator<T>;
        using const_iterator = line::const_iterator<T>;


        // constructors 
        vec(T coordX, T coordY , T coordZ , T coordW);
        vec(const vec<4, T>& vec_); 
        vec(vec<4, T>&& vec_) noexcept;
        vec(const vec<2, T>& vec_, T coordZ, T coordW);
        vec(const vec<3, T>& vec_, T coordW);

        // assignment operators
        vec<4, T>& operator = (const vec<4, T>& vec_); 
        vec<4, T>& operator = (vec<4, T>&& vec_) noexcept;

        // arithmetic operators
        vec<4, T> operator + (const vec<4, T>& vec_) const; 
        vec<4, T> operator - (const vec<4, T>& vec_) const; 
        vec<4, T> operator * (const vec<4, T>& vec_) const; 
        vec<4, T> operator * (const T& sca) const; 
        vec<4, T> operator / (const T& sca) const;
        

        // comparison operators
        constexpr bool operator == (const vec<4, T>& vec_) const noexcept;


        // functions 
        constexpr std::size_t size() const noexcept;
        void swap(vec<4, T>& vec_) noexcept;

        // access to elements
        const T& operator [] (const std::size_t& idx) const noexcept;
        T& operator [] (const std::size_t& idx) noexcept;
        T* data() noexcept;
        const T& at(const std::size_t& idx) const;
        T& at(const std::size_t& idx);

        //iterators
        iterator begin() noexcept;
        iterator end() noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

       ~vec();

        T x,  y, z, w;
    };

    /// free functions
    template<IsNumber U>
    vec<4, U> operator/(const U& sca, const vec<4, U>& vec_);
  
    template<IsNumber U>
    vec<4, U> operator*(const U& sca, const vec<4, U>& vec);
};

#include "../src/vec4.inl"
