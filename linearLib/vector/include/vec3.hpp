#pragma once

#include "setup_vec.hpp"
#include "types_vec.hpp"
#include <stdexcept>
#include <stdint.h>
#include <iostream>

namespace line{
 
    template<IsNumberV T> 
    struct vec<3, T>{
        
        using value_type = T;
        using type = vec<3, T>;
        
         T x,  y, z;

        // constructors 
        vec(T x, T y , T z);  
    
        vec(const vec<3, T>& v); 

        vec(const vec<2, T>& v, T z);

        // assignment operators
        vec<3, T>& operator = (const vec<3, T>& v); 

        // arithmetic operators
        vec<3, T> operator + (const vec<3, T>& v) const; 
        vec<3, T> operator - (const vec<3, T>& v) const; 
        vec<3, T> operator * (const vec<3, T>& v) const; 
        vec<3, T> operator * (const T& t) const; 
        vec<3, T> operator / (const T& t) const;
        

        bool operator == (const vec<3, T>& v) const; 
        
        const T& operator [] (const int& i) const ;
        T& operator [] (const int& i);
         
        int size() const;

    };


    template<IsNumberV U>
    vec<3, U> operator/(const U& t, const vec<3, U>& v);

    template<IsNumberV U>
    vec<3, U> operator * (const U& t, const vec<3, U>& v);
};

#include "../src/vec3.inl"
