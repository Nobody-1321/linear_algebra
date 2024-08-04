#pragma once
#include "setup_mat.hpp"
#include "../../vector/include/vec4.hpp"

namespace line{
    template<IsNumberM T> 
    struct mat<4, 4, T>
    {   
        private:  
            vec<4, T> cols[4];
        
        public:
        
            using col_type = vec<4, T>;
            using type = mat<4, 4, T>;
            using value_type = T;

            //constructors
            mat(T t); 
            mat(T t1, T t2, T t3, T t4, T t5, T t6, T t7, T t8, T t9, T t10, T t11, T t12, T t13, T t14, T t15, T t16); 
            mat(const mat<4, 4, T>& m); 
            mat(const col_type& v1, const col_type& v2, const col_type& v3, const col_type& v4);
            mat<4, 4, T>& operator=(const mat<4, 4, T>& m);

            // arithmetic operators
            mat<4, 4, T> operator + (const mat<4, 4, T>& m) const;
            mat<4, 4, T> operator - (const mat<4, 4, T>& m) const;
            mat<4, 4, T> operator * (const mat<4, 4, T>& m) const;
            mat<4, 4, T> operator * (const T& t) const;
            mat<4, 4, T> operator / (const T& t) const;

            // comparison operators
            bool operator == (const mat<4, 4, T>& m) const;
               
            col_type  & operator[](int i); 
            col_type const & operator[](int i) const; 

            T size_row() const;
            T size_col() const;

    };
    
    template<IsNumberM U>
    mat<4, 4, U> operator * (const U& t, const mat<4, 4, U>& m); 
     
    template<IsNumberM U>
    mat<4, 4, U> operator / (const U& t, const mat<4, 4, U>& m); 
    
}

#include "../src/mat4x4.inl"    
