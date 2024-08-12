#pragma once
#include "../include/vec3.hpp"

namespace line {

    // Constructors

    template<IsNumber T>
    vec<3, T>::vec(T coordX, T coordY, T coordZ) : x{coordX}, y{coordY}, z{coordZ} {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<3, T>& vec_) : x{vec_.x}, y{vec_.y} , z{vec_.z} {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<2, T>& vec_, T coordZ) : x{vec_.x}, y{vec_.y}, z{coordZ} {}

    template<IsNumber T>
    vec<3, T>::vec(vec<3, T>&& vec_) noexcept : x{vec_.x}, y{vec_.y}, z{vec_.z} {}




    /// assignment operators ///
    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(const vec<3, T>& vec_) {
        
        if(this != &vec_){
            x = vec_.x;
            y = vec_.y;
            z = vec_.z;
        }

        return *this;
    }

    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(vec<3, T>&& vec_) noexcept {
        
        if(this != &vec_){
            x = vec_.x;
            y = vec_.y;
            z = vec_.z;
        }

        return *this;
    }



    // arithmetic operators
    template<IsNumber T>
    vec<3, T> vec<3, T>::operator + (const vec<3, T>& vec_) const {
        return vec<3, T>(x + vec_.x, y + vec_.y, z + vec_.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator - (const vec<3, T>& vec_) const{
       return vec<3, T>(x - vec_.x, y - vec_.y, z - vec_.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const vec<3, T>& vec_) const{
        return vec<3, T>(x * vec_.x, y * vec_.y, z * vec_.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const T& sca) const{
        return vec<3, T>(x * sca, y * sca, z * sca);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator / (const T& sca) const{
        if (sca == 0) {throw std::invalid_argument("Division by zero not allowed");}
        
        return vec<3, T>(x / sca, y / sca, z / sca);
    }



    // comparison operators
    template<IsNumber T>
    constexpr bool vec<3, T>::operator == (const vec<3, T>& vec_) const noexcept{
        return (x == vec_.x) && (y == vec_.y) && (z == vec_.z);
    }


    
    // access to elements//
    template<IsNumber T>
    const T& vec<3, T>::operator [] (const std::size_t& idx) const noexcept {
        return *(&x + idx);
    }

    template<IsNumber T>
    T& vec<3, T>::operator [] (const std::size_t& idx) noexcept {
        return *(&x + idx);
    }

    template<IsNumber T>
    T* vec<3, T>::data() noexcept {
        return &x;
    }

    template<IsNumber T>
    const T& vec<3, T>::at(const std::size_t& idx) const {
        if ( idx < 3) {
            return *(&x + idx);
        } 
        
        throw std::out_of_range("Index _i_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }

    template<IsNumber T>
    T& vec<3, T>::at(const std::size_t& idx) {
        if ( idx < 3) {
            return *(&x + idx);
        } 
        
        throw std::out_of_range("Index _i_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }



    // functions
    template<IsNumber T>
    constexpr std::size_t vec<3, T>::size() const noexcept{
        return 3;
    }

    template<IsNumber T>
    void vec<3, T>::swap(vec<3, T>& vec_) noexcept {
        std::swap(x, vec_.x);
        std::swap(y, vec_.y);
        std::swap(z, vec_.z);
    }



    /// iterators ///
    template<IsNumber T>
    typename vec<3, T>::iterator vec<3, T>::begin() noexcept {
        return iterator(&x);
    }

    template<IsNumber T>
    typename vec<3, T>::iterator vec<3, T>::end() noexcept{
        return iterator(&z + 1);
    }

    template<IsNumber T>
    typename vec<3, T>::const_iterator vec<3, T>::cbegin() const noexcept{
        return const_iterator(&x);
    }

    template<IsNumber T>
    typename vec<3, T>::const_iterator vec<3, T>::cend() const noexcept {
        return const_iterator(&z + 1);
    }



    //destructors
    template<IsNumber T>
    vec<3, T>::~vec() {}




    // free functions
    template<IsNumber U>
    vec<3, U> operator / (const U& sca, const vec<3, U>& vec_) {
        if (sca == 0) {throw std::invalid_argument("Division by zero not allowed");}
        return vec<3, U>(vec_.x / sca, vec_.y / sca, vec_.z / sca);
    }

    template<IsNumber U>
    vec<3, U> operator * (const U& sca, const vec<3, U>& vec_) {
        return vec<3, U>(sca * vec_.x, sca * vec_.y, sca * vec_.z);
    }
}