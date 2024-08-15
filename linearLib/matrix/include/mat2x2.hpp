#pragma once
#include "../../vector/include/vec2.hpp"
#include "../../detail/setup_structs.hpp"
#include <memory>
#include <array>

namespace line{
    template<IsNumber T> 
    struct mat<2, 2, T>
    {    

        
        public:
        
        using col_type = vec<2, T>;
        using type = mat<2, 2, T>;
        using row_length = std::integral_constant<length_t, 2>;
        using col_length = std::integral_constant<length_t, 2>;
        using value_type = T;

        //constructors
        mat(T val_t);
        mat(T val_t1, T val_t2, T val_t3, T val_t4); 
        mat(const mat<2, 2, T>& mat_); 
        mat(const mat<2, 2, T>&& mat_) noexcept;
        
        //assignment operators
        mat<2, 2, T>& operator=(const mat<2, 2, T>& mat_);
        mat<2, 2, T>& operator=(mat<2, 2, T>&& mat_) noexcept;
        
        col_type  & operator[](int idx) ; 
        col_type const & operator[](int idx) const; 

        ~mat();
        private:
        std::array<col_type, 2> cols;   
    };
    
  //  template<IsNumberM U>
 //   mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m); 
     

}

#include "../src/mat2x2.inl"
        /*
        mat(const col_type& v1, const col_type& v2);

        // arithmetic operators
        mat<2, 2, T> operator + (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator - (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator * (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator * (const T& t) const;
        mat<2, 2, T> operator / (const T& t) const;

        // comparison operators
        bool operator == (const mat<2, 2, T>& m) const;
        


        T size_row() const;
        T size_col() const;

        ~mat();
        */