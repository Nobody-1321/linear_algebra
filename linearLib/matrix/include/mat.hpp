#pragma once
#include "../../vector/include/vec.hpp"
#include "../../detail/setup_structs.hpp"
#include <memory>
#include <iostream>
#include <assert.h>
#include <array>

namespace line{
    template<length_t R, length_t C, IsNumeric T>
    struct mat
    {            
        
        using row_type = vec<C, T>;
        using type = mat<R, C, T>;
        using row_length = std::integral_constant<length_t, R>;
        using col_length = std::integral_constant<length_t, C>;
        using value_type = T;

        //constructors

            //identity matrix
        mat();
        mat(T val_t);
        mat(const mat<R, C, T>& mat_);
        mat(mat<R, C, T>&& mat_) noexcept;
            
            //multiple arguments
        template<typename... Args>
        requires detail::AreSameAndNumbers<T, Args...>
        mat(Args&&... args);

        mat(std::initializer_list<std::initializer_list<T>> init_list);

        //assignment operators
        mat<R, C, T>& operator=(const mat<R, C, T>& mat_);
        mat<R, C, T>& operator=(mat<R, C, T>&& mat_) noexcept;

        //arithmetic operators
        mat<R, C, T> operator + (const mat<R, C, T>& mat_) const;
        mat<R, C, T> operator - (const mat<R, C, T>& mat_) const;
        
        template<length_t R2, length_t C2>
        mat<R, C2, T> operator * (const mat<R2, C2, T>& mat_) const;

        //multiplication by vector
        vec<R, T> operator * (const vec<R, T>& vec_) const;

        mat<R, C, T> operator * (const T& sca) const;
        mat<R, C, T> operator / (const T& sca) const;

        //access to elements
        row_type & operator[](int idx) noexcept;
        row_type const & operator[](int idx) const noexcept;
        row_type & at(int idx);
        row_type const & at(int idx) const;

        //comparison operators
        bool operator == (const mat<R, C, T>& mat_) const;

        //functions
        constexpr std::size_t size_row() const noexcept;
        constexpr std::size_t size_col() const noexcept;
        bool is_square() const noexcept;
        void fill(T fill_value);
        void swap(mat<R, C, T>& mat_) noexcept;
        void dirmemory();
        
        //iterators
        row_type::iterator begin() noexcept;
        row_type::iterator end() noexcept;
        row_type::const_iterator cbegin() const noexcept;
        row_type::const_iterator cend() const noexcept;

        ~mat();

        private:
        //std::array<row_type, R> rows;
        std::unique_ptr<std::array<row_type, R>> rows;
    };

    // free functions
    //scalar multiplication
    template<length_t R, length_t C, IsNumeric T>
    mat<R, C, T> operator*(const T& sca, const mat<R, C, T>& mat_);

}
    
#include "../src/mat.inl"