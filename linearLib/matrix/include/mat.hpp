#pragma once
#include "../../vector/include/vec.hpp"
#include "../../detail/structs_det.hpp"
#include <memory>
#include <iostream>
#include <assert.h>
#include <array>

namespace line{
    
    template<nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    struct mat
    {            
        
        using row_type = vec<C, T>;
        using type = mat<R, C, T>;
        using row_length = std::integral_constant<nsp_length::length_t, R>;
        using col_length = std::integral_constant<nsp_length::length_t, C>;
        using value_type = T;
        using iterator = line::iterator::iterator<row_type>;
        using const_iterator = line::iterator::const_iterator<row_type>;

        //constructors

            //identity matrix
        mat();
        mat(T val_t);
        mat(const mat<R, C, T>& mat_);
        mat(mat<R, C, T>&& mat_) noexcept;
            
            //multiple arguments
        template<typename... Args>
        requires nsp_concepts::same_numeric_type<T, Args...>
        mat(Args&&... args);

        mat(std::initializer_list<std::initializer_list<T>> init_list);

        //assignment operators
        mat<R, C, T>& operator=(const mat<R, C, T>& mat_);
        mat<R, C, T>& operator=(mat<R, C, T>&& mat_) noexcept;

        //arithmetic operators
        mat<R, C, T> operator + (const mat<R, C, T>& mat_) const;
        mat<R, C, T> operator - (const mat<R, C, T>& mat_) const;
        
        template<nsp_length::length_t R2, nsp_length::length_t C2>
        mat<R, C2, T> operator * (const mat<R2, C2, T>& mat_) const;

        //multiplication by vector
        vec<R, T> operator * (const vec<R, T>& vec_) const;

        mat<R, C, T> operator * (const T& sca) const;
        mat<R, C, T> operator / (const T& sca) const;

        //compound assignment operators
        mat<R, C, T>& operator += (const mat<R, C, T>& mat_);
        mat<R, C, T>& operator -= (const mat<R, C, T>& mat_);
        mat<R, C, T>& operator *= (const T& sca);

        template<nsp_length::length_t R2, nsp_length::length_t C2>
        mat<R, C2, T>& operator *= (const mat<R2, C2, T>& mat_);

        vec<R, T>& operator *= (const vec<R, T>& vec_);

        mat<R, C, T>& operator /= (const T& sca);

        //access to elements
        row_type & operator[](int idx) noexcept;
        row_type const & operator[](int idx) const noexcept;


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
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        ~mat();

        private:
        //std::array<row_type, R> rows;
        std::unique_ptr<std::array<row_type, R>> rows;
    };

    // free functions
    //scalar multiplication
    template<nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> operator*(const T& sca, const mat<R, C, T>& mat_);

}
    
#include "../src/mat.inl"