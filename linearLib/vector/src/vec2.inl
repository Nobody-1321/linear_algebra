//#pragma once
//#include "../include/vec2.hpp"
namespace line {

    ////// constructors //////
    template<IsNumeric T>
    vec<2, T>::vec() : x{0}, y{0} {
    }

    template<IsNumeric T>
    vec<2, T>::vec(T coordX, T coordY) : x{coordX}, y{coordY} {
    }

    template<IsNumeric T>
    vec<2, T>::vec(const vec<2, T>& vec_) : x{vec_.x}, y{vec_.y} {
    }

    template<IsNumeric T>
    vec<2, T>::vec(vec<2, T>&& vec_) noexcept : x{vec_.x}, y{vec_.y} {
    }
    




    /////// assignment operators ///////
    
    template<IsNumeric T>
    vec<2, T>& vec<2, T>::operator=(vec<2, T>&& vec_) noexcept {
        
        if (this != &vec_) {
            x = vec_.x;
            y = vec_.y;
        }

        return *this;
    }

    template<IsNumeric T>
    vec<2, T>& vec<2, T>::operator=(const vec<2, T>& vec_) {
        
        if (this != &vec_) {
            x = vec_.x;
            y = vec_.y;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumeric T>
    vec<2, T> vec<2, T>::operator + (const vec<2, T>& vec_) const {
        return vec<2, T>(x + vec_.x, y + vec_.y);
    }

    template<IsNumeric T>
    vec<2, T> vec<2, T>::operator - (const vec<2, T>& vec_) const{
       return vec<2, T>(x - vec_.x, y - vec_.y);
    }

    template<IsNumeric T>
    vec<2, T> vec<2, T>::operator * (const vec<2, T>& vec_) const{
        return vec<2, T>(x * vec_.x, y * vec_.y);
    }

    template<IsNumeric T>
    vec<2, T> vec<2, T>::operator * (const T& sca) const{
        return vec<2, T>(x * sca, y * sca);
    }

    template<IsNumeric T>
    vec<2, T> vec<2, T>::operator / (const T& sca) const {
        if (sca == 0){ throw std::invalid_argument("Division by zero not allowed");}

        return vec<2, T>(x / sca,y / sca);
    }



    ///// comparison operators /////
    template<IsNumeric T>
    constexpr bool vec<2, T>::operator==(const vec<2, T>& vec_) const noexcept {
        return this->x == vec_.x && this->y == vec_.y;
    }
    
    // access to elements
    template<IsNumeric T>
    const T & vec<2, T>::operator [] (const std::size_t& idx) const noexcept {
        return *(&x + idx);
    }

    template<IsNumeric T>
    T & vec<2, T>::operator [] (const std::size_t& idx)  noexcept{
        return *(&x + idx);
    }

    template<IsNumeric T>
    T* vec<2, T>::data() noexcept{
        return &x;
    }

    template<IsNumeric T>
    const T& vec<2, T>::at(const std::size_t& idx) const {
        if ( idx < 2) {
            return *(&x + idx);
        } 
        
        throw std::out_of_range("Index _idx_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }

    template<IsNumeric T>
    T& vec<2, T>::at(const std::size_t& idx) {
        if ( idx < 2) {
            return *(&x + idx);
        } 

        throw std::out_of_range("Index _idx_ (which is " + std::to_string(idx) + ") >= this->size() (which is " + std::to_string(2) + ")");
    }
    
    // functions    
    template<IsNumeric T>
    constexpr std::size_t vec<2, T>::size() const noexcept{
        return 2;
    }

    template<IsNumeric T>
    void vec<2, T>::swap(vec<2, T>& vec_) noexcept{
        std::swap(x, vec_.x);
        std::swap(y, vec_.y);
    }

    
    
    
    ////// iterator  //////
    template<IsNumeric T>
    typename vec<2, T>::iterator vec<2, T>::begin() noexcept{
        return iterator(&x);
    }

    template<IsNumeric T>
    typename vec<2, T>::iterator vec<2, T>::end() noexcept{
        return iterator(&y + 1);
    }

    template<IsNumeric T>
    typename vec<2, T>::const_iterator vec<2, T>::cbegin() const noexcept {
        return const_iterator(&x);
    }

    template<IsNumeric T>
    typename vec<2, T>::const_iterator vec<2, T>::cend() const noexcept{
        return const_iterator(&y + 1);
    }

    
    ////// destructors //////
    template<IsNumeric T>
    vec<2, T>::~vec(){}


    
    
    //////  free functions //////
    template<IsNumeric U>
    vec<2, U> operator * (const U& sca, const vec<2, U>& vec_) {
        return vec<2, U>(vec_.x * sca, vec_.y * sca);
    }

}