#include "setup.hpp"
#include "types.hpp"
#include <stdexcept>
#include <stdint.h>
#include <iostream>

namespace line{
 
    template<IsNumber T> 
    struct vec<4, T>{
        
        using value_type = T;
        
         T x,  y, z, w;

        // constructors 
        vec(T x, T y , T z , T w);
    
        vec(const vec<4, T>& v); 

        vec(const vec<2, T>& v, T z, T w);
        
        vec(const vec<3, T>& v, T w);

        // assignment operators
        vec<4, T>& operator = (const vec<4, T>& v); 

        // arithmetic operators
        vec<4, T> operator + (const vec<4, T>& v) const; 
        vec<4, T> operator - (const vec<4, T>& v) const; 
        vec<4, T> operator * (const vec<4, T>& v) const; 
        vec<4, T> operator * (const T& t) const; 
        vec<4, T> operator / (const T& t) const;
        

        bool operator == (const vec<4, T>& v) const; 
        T operator [] (const int& i) const;         
        int size() const;

    };

    template<IsNumber U>
    vec<4, U> operator/(const U& t, const vec<3, U>& v);

    template<IsNumber U>
    vec<4, U> operator*(const U& t, const vec<3, U>& v);
};

#include "../src/vec4.inl"
