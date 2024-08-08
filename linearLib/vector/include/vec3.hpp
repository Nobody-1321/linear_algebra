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
        vec(T x, T y , T z);  
        vec(const vec<3, T>& v); 
        vec(const vec<2, T>& v, T z);
        vec(vec<3, T>&& v) noexcept;
        vec<3, T>& operator = (const vec<3, T>& v); 
        vec<3, T>& operator = (vec<3, T>&& v) noexcept;

        // arithmetic operators
        vec<3, T> operator + (const vec<3, T>& v) const; 
        vec<3, T> operator - (const vec<3, T>& v) const; 
        vec<3, T> operator * (const vec<3, T>& v) const; 
        vec<3, T> operator * (const T& t) const; 
        vec<3, T> operator / (const T& t) const;
        
        // comparison operators
        bool operator == (const vec<3, T>& v) const; 
        
        // index operator
        const T& operator [] (const std::size_t& i) const ;
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
        
        ~vec();
        
        T x, y, z;
    };


    template<IsNumber U>
    vec<3, U> operator/(const U& t, const vec<3, U>& v);

    template<IsNumber U>
    vec<3, U> operator * (const U& t, const vec<3, U>& v);
};

#include "../src/vec3.inl"
