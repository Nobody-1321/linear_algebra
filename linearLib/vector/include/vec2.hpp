#pragma once
#include "setup.hpp"
#include "types.hpp"
#include <stdexcept>
#include <stdint.h>
#include <iostream>

namespace line{
 
    template<IsNumber T> 
    struct vec<2, T>{
        
        using value_type = T;
        
        union {
            struct { T x,  y ;};
            struct { T s,  t ;};
            struct { T r,  g ;};
        };
        // constructors 
        vec(T x, T y);  

        vec(const vec<2, T>& v); 

        template <IsNumber U>
        vec(const vec<2, U>& v);

        vec<2, T>& operator = (const vec<2, T>& v); 

        template <IsNumber U>
        vec<2, T>& operator = (const vec<2, U>& v);

        // arithmetic operators
        vec<2, T> operator + (const vec<2, T>& v) const; 
        vec<2, T> operator - (const vec<2, T>& v) const; 
        vec<2, T> operator * (const vec<2, T>& v) const; 
        vec<2, T> operator * (const T& t) const; 
        vec<2, T> operator / (const T& t) const;
        

        bool operator==(const vec<2, T>& v) const; 
        T operator [] (const int& i) const;         
        size_t size() const;

    };

    template<IsNumber U>
    vec<2, U> operator/(const U& t, const vec<2, U>& v);

    template<IsNumber U, IsNumber V>
    vec<2, U> operator/(const V& t, const vec<2, U>& v);

    template<IsNumber U>
    vec<2, U> operator*(const U& t, const vec<2, U>& v);

    template<IsNumber U, IsNumber V>
    vec<2, U> operator*(const V& t, const vec<2, U>& v);

};

#include "../src/vec2.inl"
