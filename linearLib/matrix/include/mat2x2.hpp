#pragma once
#include "setup_mat.hpp"
#include "../../vector/include/vec2.hpp"

namespace line{
    template<IsNumberM T> 
    struct mat<2, 2, T>
    {    

        
        public:
        
        using col_type = vec<2, T>;
        using type = mat<2, 2, T>;
        using value_type = T;

        //constructors
        mat(T t); 
        mat(T t1, T t2, T t3, T t4); 
        mat(const mat<2, 2, T>& m); 
        mat(const col_type& v1, const col_type& v2);
        mat<2, 2, T>& operator=(const mat<2, 2, T>& m);

        // arithmetic operators
        mat<2, 2, T> operator + (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator - (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator * (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator * (const T& t) const;
        mat<2, 2, T> operator / (const T& t) const;

        // comparison operators
        bool operator == (const mat<2, 2, T>& m) const;
        
        col_type  & operator[](int i) ; 
        col_type const & operator[](int i) const; 

        T size_row() const;
        T size_col() const;

        ~mat();

        private:
        vec<2, T> cols[2];
    };
    
    template<IsNumberM U>
    mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m); 
     

}

#include "../src/mat2x2.inl"