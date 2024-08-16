#pragma once
#include "../../vector/include/vec2.hpp"
#include "../../detail/setup_structs.hpp"
#include <memory>
#include <array>

namespace line{
    template<IsNumeric T> 
    struct mat<2, 2, T>
    {            
        
        using col_type = vec<2, T>;
        using type = mat<2, 2, T>;
        using row_length = std::integral_constant<length_t, 2>;
        using col_length = std::integral_constant<length_t, 2>;
        using value_type = T;

        //constructors
        mat(T val_t);
        mat(T val_t1, T val_t2, T val_t3, T val_t4); 
        mat(const col_type& vec_1, const col_type& vec_2);
        mat(const mat<2, 2, T>& mat_); 
        mat(const mat<2, 2, T>&& mat_) noexcept; 
        //assignment operators
        mat<2, 2, T>& operator=(const mat<2, 2, T>& mat_);
        mat<2, 2, T>& operator=(mat<2, 2, T>&& mat_) noexcept;
        
        // arithmetic operators
        mat<2, 2, T> operator + (const mat<2, 2, T>& mat_) const;
        mat<2, 2, T> operator - (const mat<2, 2, T>& mat_) const;
        mat<2, 2, T> operator * (const mat<2, 2, T>& mat_) const;
        mat<2, 2, T> operator * (const T& sca) const;
        mat<2, 2, T> operator / (const T& sca) const; 

        // access to elements      
        col_type  & operator[](int idx) ; 
        col_type const & operator[](int idx) const; 

        constexpr std::size_t size_row() const noexcept;
        constexpr std::size_t size_col() const noexcept;

        // comparison operators
        bool operator == (const mat<2, 2, T>& mat_) const;
        
        ~mat();
        
        private:
        std::array<col_type, 2> cols;   

    };
    
  //  template<IsNumberM U>
 //   mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m); 
     

}

#include "../src/mat2x2.inl"