//#pragma once
//#include "../include/vec2.hpp"
namespace line {

    ////// constructors //////
    
    template<IsNumber T>
    vec<2, T>::vec(T x, T y) : x{x}, y{y} {
    }

    template<IsNumber T>
    vec<2, T>::vec(const vec<2, T>& v) : x{v.x}, y{v.y} {
    }

    template<IsNumber T>
    vec<2, T>::vec(vec<2, T>&& v) noexcept : x{v.x}, y{v.y} {
    }
    




    /////// assignment operators ///////
    
    template<IsNumber T>
    vec<2, T>& vec<2, T>::operator=(vec<2, T>&& v) noexcept {
        
        if (this != &v) {
            x = v.x;
            y = v.y;
        }

        return *this;
    }

    template<IsNumber T>
    vec<2, T>& vec<2, T>::operator=(const vec<2, T>& v) {
        
        if (this != &v) {
            x = v.x;
            y = v.y;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumber T>
    vec<2, T> vec<2, T>::operator + (const vec<2, T>& v) const {
        return vec<2, T>(x + v.x, y + v.y);
    }

    template<IsNumber T>
    vec<2, T> vec<2, T>::operator - (const vec<2, T>& v) const{
       return vec<2, T>(x - v.x, y - v.y);
    }

    template<IsNumber T>
    vec<2, T> vec<2, T>::operator * (const vec<2, T>& v) const{
        return vec<2, T>(x * v.x, y * v.y);
    }

    template<IsNumber T>
    vec<2, T> vec<2, T>::operator * (const T& t) const{
        return vec<2, T>(x * t, y * t);
    }

    template<IsNumber T>
    vec<2, T> vec<2, T>::operator / (const T& t) const {
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");

        return vec<2, T>(x / t,y / t);
    }



    ///// comparison operators /////
    template<IsNumber T>
    bool vec<2, T>::operator==(const vec<2, T>& v) const {
        return this->x == v.x && this->y == v.y;
    }
    
    // access to elements
    template<IsNumber T>
    const T & vec<2, T>::operator [] (const std::size_t& i) const noexcept {
        return *(&x + i);
    }

    template<IsNumber T>
    T & vec<2, T>::operator [] (const std::size_t& i)  noexcept{
        return *(&x + i);
    }

    template<IsNumber T>
    T* vec<2, T>::data() noexcept{
        return &x;
    }

    template<IsNumber T>
    const T& vec<2, T>::at(const std::size_t& i) const {
        if ( i < 2) {
            return *(&x + i);
        } 
        
        throw std::out_of_range("Index _i_ (which is " + std::to_string(i) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }

    template<IsNumber T>
    T& vec<2, T>::at(const std::size_t& i) {
        if ( i < 2) {
            return *(&x + i);
        } 

        throw std::out_of_range("Index _i_ (which is " + std::to_string(i) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }
    
    // functions    
    template<IsNumber T>
    constexpr std::size_t vec<2, T>::size() const noexcept{
        return 2;
    }

    template<IsNumber T>
    void vec<2, T>::swap(vec<2, T>& v) noexcept{
        std::swap(x, v.x);
        std::swap(y, v.y);
    }

    
    
    
    ////// iterator  //////
    template<IsNumber T>
    typename vec<2, T>::iterator vec<2, T>::begin() noexcept{
        return iterator(&x);
    }

    template<IsNumber T>
    typename vec<2, T>::iterator vec<2, T>::end() noexcept{
        return iterator(&y + 1);
    }

    template<IsNumber T>
    typename vec<2, T>::const_iterator vec<2, T>::cbegin() const noexcept {
        return const_iterator(&x);
    }

    template<IsNumber T>
    typename vec<2, T>::const_iterator vec<2, T>::cend() const noexcept{
        return const_iterator(&y + 1);
    }

    
    ////// destructors //////
    template<IsNumber T>
    vec<2, T>::~vec(){}


    
    
    //////  free functions //////

    template<IsNumber U>
    vec<2, U> operator / (const U& t, const vec<2, U>& v) {
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        
        return vec<2, U>(v.x / t, v.y / t);
    }

    template<IsNumber U>
    vec<2, U> operator * (const U& t, const vec<2, U>& v) {
        return vec<2, U>(v.x * t, v.y * t);
    }

}