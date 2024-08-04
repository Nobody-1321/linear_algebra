#pragma once
#include "setup_mat.hpp"
#include "../../vector/include/vec3.hpp"

namespace line{
    template<IsNumberM T> 
    struct mat<3, 3, T>
    {   private:  

        vec<3, T> cols[3];
        
        public:
        
        using col_type = vec<3, T>;
        using type = mat<3, 3, T>;
        using value_type = T;

        //constructors
        mat(T t); 
        mat(T t1, T t2, T t3, T t4, T t5, T t6, T t7, T t8, T t9); 
        mat(const mat<3, 3, T>& m); 
        mat(const col_type& v1, const col_type& v2, const col_type& v3);
        mat<3, 3, T>& operator=(const mat<3, 3, T>& m);

        // arithmetic operators
        mat<3, 3, T> operator + (const mat<3, 3, T>& m) const;
        mat<3, 3, T> operator - (const mat<3, 3, T>& m) const;
        mat<3, 3, T> operator * (const mat<3, 3, T>& m) const;
        mat<3, 3, T> operator * (const T& t) const;
        mat<3, 3, T> operator / (const T& t) const;

        // comparison operators
        bool operator == (const mat<3, 3, T>& m) const;
               
        col_type  & operator[](int i) ; 
        col_type const & operator[](int i) const; 

        T size_row() const;
        T size_col() const;

    };
    
    template<IsNumberM U>
    mat<3, 3, U> operator * ( const U& t, const mat<3, 3, U>& m); 
     
    template<IsNumberM U>
    mat<3, 3, U> operator / ( const U& t, const mat<3, 3, U>& m); 
    
}

#include "../src/mat3x3.inl"