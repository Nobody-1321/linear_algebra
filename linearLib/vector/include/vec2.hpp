#pragma once
#include "setup_vec.hpp"
#include "types_vec.hpp"
#include <stdexcept>
#include <stdint.h>
#include <iostream>
#include "../../iterator/include/iterator_vec.hpp"
#include <type_traits>
namespace line{
 
    template<IsNumberV T> 
    struct vec<2, T>{
        
        using value_type = T;
        using type = vec<2, T>;
        using length = std::integral_constant<length_t, 2>;


        T x, y;
        
        //constructors
        vec(T x, T y);  
        vec(const vec<2, T>& v); 
        vec<2, T>& operator = (const vec<2, T>& v); 

        // arithmetic operators
        vec<2, T> operator + (const vec<2, T>& v) const; 
        vec<2, T> operator - (const vec<2, T>& v) const; 
        vec<2, T> operator * (const vec<2, T>& v) const; 
        vec<2, T> operator * (const T& t) const; 
        vec<2, T> operator / (const T& t) const;
        
        // comparison operators
        bool operator==(const vec<2, T>& v) const; 

        // index operator
        const T& operator [] (const int& i) const;         
        T& operator [] (const int& i);         

        int size() const;
        
        T* data(){return &x;};

        using iterator = line::iterator<T>;
        using const_iterator = line::iterator<const T>;

        iterator begin();// { return iterator(&x); }
        iterator end();// { return iterator(&y + 1); }

        const_iterator begin() const;// { return const_iterator(&x); }
        const_iterator end() const; //{ return const_iterator(&y + 1); }
    };

    template<IsNumberV U>
    vec<2, U> operator/(const U& t, const vec<2, U>& v);

    template<IsNumberV U>
    vec<2, U> operator*(const U& t, const vec<2, U>& v);
};

#include "../src/vec2.inl"
