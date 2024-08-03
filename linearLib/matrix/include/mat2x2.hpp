#pragma once
#include "setup_mat.hpp"
#include "../../vector/include/vec2.hpp"

namespace line{
    template<IsNumberM T> 
    struct mat<2, 2, T>
    {   private:  

        vec<2, T> cols[2];
        
        public:

        using col_type = vec<2, T>;
        using type = mat<2, 2, T>;
        using value_type = T;

        
        mat(T t); // ok

        mat(T t1, T t2, T t3, T t4); // is it ok ?

        mat(const mat<2, 2, T>& m); //ok
        
        mat(const col_type& v1, const col_type& v2); //ok
        
        col_type  & operator[](int i) ; //ok
        col_type const & operator[](int i) const; //ok

        mat<2, 2, T>& operator=(const mat<2, 2, T>& m);

        // arithmetic operators
        mat<2, 2, T> operator + (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator - (const mat<2, 2, T>& m) const;
        mat<2, 2, T> operator * (const mat<2, 2, T>& m) const;

        mat<2, 2, T> operator * (const T& t) const;
        mat<2, 2, T> operator / (const T& t) const;

        // comparison operators
        bool operator == (const mat<2, 2, T>& m) const;

    };
    
    template<IsNumberM U>
    mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m); 
     
    template<IsNumberM U>
    mat<2, 2, U> operator / ( const U& t, const mat<2, 2, U>& m); 
 

}

#include "../src/mat2x2.inl"