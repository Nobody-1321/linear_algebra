//#pragma once
//#include "../include/vec3.hpp"

namespace line {

    // Constructors

    template<IsNumber T>
    vec<3, T>::vec(T x, T y, T z) : x(x), y(y), z(z) {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<3, T>& v) : x(v.x), y(v.y) , z(v.z) {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<2, T>& v, T z) : x(v.x), y(v.y), z(z) {}

    template<IsNumber T>
    vec<3, T>::vec(vec<3, T>&& v) noexcept : x(v.x), y(v.y), z(v.z) {}

    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(const vec<3, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        return *this;
    }

    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(vec<3, T>&& v) noexcept {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumber T>
    vec<3, T> vec<3, T>::operator + (const vec<3, T>& v) const {
        return vec<3, T>(x + v.x, y + v.y, z + v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator - (const vec<3, T>& v) const{
       return vec<3, T>(x - v.x, y - v.y, z - v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const vec<3, T>& v) const{
        return vec<3, T>(x * v.x, y * v.y, z * v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const T& v) const{
        return vec<3, T>(x * v, y * v, z * v);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator / (const T& t) const{
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        
        return vec<3, T>(x / t, y / t, z / t);
    }

    // comparison operators
    template<IsNumber T>
    bool vec<3, T>::operator == (const vec<3, T>& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z);
    }

    // index operator
    template<IsNumber T>
    const T& vec<3, T>::operator [] (const std::size_t& i) const {
        return *(&x + i);
    }

    template<IsNumber T>
    T& vec<3, T>::operator [] (const std::size_t& i) {
        return *(&x + i);
    }

    // functions
    template<IsNumber T>
    std::size_t vec<3, T>::size() const {
        return 3;
    }

    template<IsNumber T>
    T* vec<3, T>::data() {
        return &x;
    }

    template<IsNumber T>
    const T& vec<3, T>::at(const std::size_t& i) const {
        if ( i < 3) {
            return *(&x + i);
        } 
        
        throw std::out_of_range("Index out of range");   
    }

    template<IsNumber T>
    T& vec<3, T>::at(const std::size_t& i) {
        if ( i < 3) {
            return *(&x + i);
        } 
        
        throw std::out_of_range("Index out of range");   
    }

    template<IsNumber T>
    typename vec<3, T>::iterator vec<3, T>::begin() {
        return iterator(&x);
    }

    template<IsNumber T>
    typename vec<3, T>::iterator vec<3, T>::end() {
        return iterator(&z + 1);
    }

    template<IsNumber T>
    typename vec<3, T>::const_iterator vec<3, T>::cbegin() const {
        return const_iterator(&x);
    }

    template<IsNumber T>
    typename vec<3, T>::const_iterator vec<3, T>::cend() const {
        return const_iterator(&z + 1);
    }

    //destructors
    template<IsNumber T>
    vec<3, T>::~vec() {}

    template<IsNumber U>
    vec<3, U> operator / (const U& t, const vec<3, U>& v) {
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        return vec<3, U>(v.x / t, v.y / t, v.z / t);
    }

    template<IsNumber U>
    vec<3, U> operator * (const U& t, const vec<3, U>& v) {
        return vec<3, U>(t * v.x, t * v.y, t * v.z);
    }
}