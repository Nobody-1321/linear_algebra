#pragma once

#include "setup_vec.hpp"
#include "types_vec.hpp"
#include <stdexcept>
#include <stdint.h>
#include <iostream>

namespace line{
 
    template<IsNumberV T> 
    struct vec<4, T>{
        
        using value_type = T;
        using type = vec<4, T>;
        using length = std::integral_constant<length_t, 4>;
        using iterator = line::iterator<T>;
        using const_iterator = line::const_iterator<T>;


        // constructors 
        vec(T x, T y , T z , T w);
        vec(const vec<4, T>& v); 
        vec(const vec<2, T>& v, T z, T w);
        vec(const vec<3, T>& v, T w);
        vec<4, T>& operator = (const vec<4, T>& v); 

        // arithmetic operators
        vec<4, T> operator + (const vec<4, T>& v) const; 
        vec<4, T> operator - (const vec<4, T>& v) const; 
        vec<4, T> operator * (const vec<4, T>& v) const; 
        vec<4, T> operator * (const T& t) const; 
        vec<4, T> operator / (const T& t) const;
        

        // comparison operators
        bool operator == (const vec<4, T>& v) const;

        // index operator
        const T& operator [] (const std::size_t& i) const;         
        T& operator [] (const std::size_t& i);

        // functions 
        std::size_t size() const;
        T* data();
        const T& at(const std::size_t& i) const;
        T& at(const std::size_t& i);

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;
        
        T x,  y, z, w;
    };

    template<IsNumberV U>
    vec<4, U> operator/(const U& t, const vec<4, U>& v);
    //vec<4, U> operator/(const U& t, const vec<3, U>& v); bug por ambiguedad
    template<IsNumberV U>
    vec<4, U> operator*(const U& t, const vec<4, U>& v);
    //vec<4, U> operator*(const U& t, const vec<3, U>& v); bbug por ambiguedad. 
};

#include "../src/vec4.inl"
