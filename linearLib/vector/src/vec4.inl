//#pragma once
//#include "../include/vec4.hpp"

namespace line {

    // Constructors

    template<IsNumber T>
    vec<4, T>::vec(T coordX, T coordY, T coordZ, T coordW) : x{coordX}, y{coordY}, z{coordZ}, w{coordW} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<4, T>& vec_) : x{vec_.x}, y{vec_.y} , z{vec_.z} , w{vec_.w} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<2, T>& vec_, T coordZ, T coordW) : x{vec_.x}, y{vec_.y}, z{coordZ} , w{coordW} {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<3, T>& vec_, T coordW) : x{vec_.x}, y{vec_.y}, z{vec_.z} , w{coordW} {}

    template<IsNumber T>
    vec<4, T>::vec(vec<4, T>&& vec_) noexcept : x{vec_.x}, y{vec_.y}, z{vec_.z}, w{vec_.w} {}


    // assignment operators
    template<IsNumber T>
    vec<4, T>& vec<4, T>::operator=(const vec<4, T>& vec_) {
        
        if(this != &vec_){
            x = vec_.x;
            y = vec_.y;
            z = vec_.z;
            w = vec_.w;
        }

        return *this;
    }

    template<IsNumber T>
    vec<4, T>& vec<4, T>::operator=(vec<4, T>&& vec_) noexcept {
        
        if(this != &vec_){
            x = vec_.x;
            y = vec_.y;
            z = vec_.z;
            w = vec_.w;
        }

        return *this;
    }




    // arithmetic operators
    template<IsNumber T>
    vec<4, T> vec<4, T>::operator + (const vec<4, T>& vec_) const {
        return vec<4, T>(x + vec_.x, y + vec_.y, z + vec_.z, w + vec_.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator - (const vec<4, T>& vec_) const{
       return vec<4, T>(x - vec_.x, y - vec_.y, z - vec_.z, w - vec_.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const vec<4, T>& vec_) const{
        return vec<4, T>(x * vec_.x, y * vec_.y, z * vec_.z, w * vec_.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const T& sca) const{
        return vec<4, T>(x * sca, y * sca, z * sca, w * sca);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator / (const T& sca) const{
        if (sca == 0) { throw std::invalid_argument("Division by zero not allowed");}
        
        return vec<4, T>(x / sca, y / sca, z / sca, w / sca);
    }

    // comparison operators
    template<IsNumber T>
    constexpr bool vec<4, T>::operator == (const vec<4, T>& vec_) const noexcept {
        return (x == vec_.x) && (y == vec_.y) && (z == vec_.z) && (w == vec_.w);
    }



 
    template<IsNumber T>
    constexpr std::size_t vec<4, T>::size() const noexcept{
        return 4;
    }

    template<IsNumber T>
    void vec<4, T>::swap(vec<4, T>& vec_) noexcept{
        std::swap(x, vec_.x);
        std::swap(y, vec_.y);
        std::swap(z, vec_.z);
        std::swap(w, vec_.w);
    }


    //// access to elements
    template<IsNumber T>
    const T&  vec<4, T>::operator [] (const std::size_t& idx) const noexcept {
        return *(&x + idx);
    }

    template<IsNumber T>
    T&  vec<4, T>::operator [] (const size_t& idx) noexcept {
        return *(&x + idx);
    }
    template<IsNumber T>
    T* vec<4, T>::data() noexcept{
        return &x;
    }

    template<IsNumber T>
    const T& vec<4, T>::at(const std::size_t& idx) const {
        if(idx < 4){
            return *(&x + idx);
        }

        throw std::out_of_range("Index _idx_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(4) + ")");
    }

    template<IsNumber T>
    T& vec<4, T>::at(const std::size_t& idx){
        if(idx < 4){
            return *(&x + idx);
        }

        throw std::out_of_range("Index _idx_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(4) + ")");
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
    vec<4, U> operator/(const U& sca, const vec<4, U>& vec_){
        if(sca == 0) { throw std::invalid_argument("Division by zero not allowed");}
   
        return vec<4, U>(vec_.x / sca, vec_.y / sca, vec_.z / sca, vec_.w / sca);
    }

    template<IsNumber U>
    vec<4, U> operator*(const U& sca, const vec<4, U>& vec_){
        return vec<4, U>(sca * vec_.x, sca * vec_.y, sca * vec_.z, sca * vec_.w);
    }
    
}