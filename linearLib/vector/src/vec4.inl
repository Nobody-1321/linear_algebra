//#pragma once
//#include "../include/vec4.hpp"

namespace line {

    // Constructors

    template<IsNumber T>
    vec<4, T>::vec(T x, T y, T z, T w) : x{x}, y{y}, z{z}, w{w} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<4, T>& v) : x{v.x}, y{v.y} , z{v.z} , w{v.w} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<2, T>& v, T z, T w) : x{v.x}, y{v.y}, z{z} , w{w} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<3, T>& v, T w) : x{v.x}, y{v.y}, z{v.z} , w{w} {}

    template<IsNumber T>
    vec<4, T>::vec(vec<4, T>&& v) noexcept : x{v.x}, y{v.y}, z{v.z}, w{v.w} {}



    // assignment operators
    template<IsNumber T>
    vec<4, T>& vec<4, T>::operator=(const vec<4, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }

        return *this;
    }

    template<IsNumber T>
    vec<4, T>& vec<4, T>::operator=(vec<4, T>&& v) noexcept {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }

        return *this;
    }




    // arithmetic operators
    template<IsNumber T>
    vec<4, T> vec<4, T>::operator + (const vec<4, T>& v) const {
        return vec<4, T>(x + v.x, y + v.y, z + v.z, w + v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator - (const vec<4, T>& v) const{
       return vec<4, T>(x - v.x, y - v.y, z - v.z, w - v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const vec<4, T>& v) const{
        return vec<4, T>(x * v.x, y * v.y, z * v.z, w * v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const T& v) const{
        return vec<4, T>(x * v, y * v, z * v, w * v);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator / (const T& t) const{
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        
        return vec<4, T>(x / t, y / t, z / t, w / t);
    }

    // comparison operators
    template<IsNumber T>
    bool vec<4, T>::operator == (const vec<4, T>& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
    }



 
    template<IsNumber T>
    constexpr std::size_t vec<4, T>::size() const noexcept{
        return 4;
    }

    template<IsNumber T>
    void vec<4, T>::swap(vec<4, T>& v) noexcept{
        std::swap(x, v.x);
        std::swap(y, v.y);
        std::swap(z, v.z);
        std::swap(w, v.w);
    }


    //// access to elements
    template<IsNumber T>
    const T&  vec<4, T>::operator [] (const std::size_t& i) const noexcept {
        return *(&x + i);
    }

    template<IsNumber T>
    T&  vec<4, T>::operator [] (const size_t& i) noexcept {
        return *(&x + i);
    }
    template<IsNumber T>
    T* vec<4, T>::data() noexcept{
        return &x;
    }

    template<IsNumber T>
    const T& vec<4, T>::at(const std::size_t& i) const {
        if(i < 4){
            return *(&x + i);
        }

        throw std::out_of_range("Index _i_ (which is " + std::to_string(i) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }

    template<IsNumber T>
    T& vec<4, T>::at(const std::size_t& i){
        if(i < 4){
            return *(&x + i);
        }

        throw std::out_of_range("Index _i_ (which is " + std::to_string(i) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }




    //// iterators
    template<IsNumber T>
    typename vec<4, T>::iterator vec<4, T>::begin() noexcept{
        return iterator(&x);
    }

    template<IsNumber T>
    typename vec<4, T>::iterator vec<4, T>::end() noexcept{
        return iterator(&w + 1);
    }

    template<IsNumber T>    
    typename vec<4, T>::const_iterator vec<4, T>::cbegin() const noexcept{
        return const_iterator(&x);
    }

    template<IsNumber T>
    typename vec<4, T>::const_iterator vec<4, T>::cend() const noexcept{
        return const_iterator(&w + 1);
    }



    template<IsNumber T>
    vec<4, T>::~vec() {}



    // free functions
    template<IsNumber U>
    vec<4, U> operator/(const U& t, const vec<4, U>& v){
        if(t == 0) throw std::invalid_argument("Division by zero not allowed");
   
        return vec<4, U>(v.x / t, v.y / t, v.z / t, v.w / t);
    }

    template<IsNumber U>
    vec<4, U> operator*(const U& t, const vec<4, U>& v){
        return vec<4, U>(t * v.x, t * v.y, t * v.z, t * v.w);
    }
    
}