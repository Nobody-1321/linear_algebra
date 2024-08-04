#include "../include/mat3x3.hpp"

namespace line{

    //constructors    
    template<IsNumberM T> 
    mat<3, 3, T>::mat(T t): cols{col_type{t,0,0} ,col_type{0,t,0} ,col_type{0,0,t}} {
    }


    template<IsNumberM T>
    mat<3, 3, T>::mat(T t1, T t2, T t3, T t4, T t5, T t6, T t7, T t8, T t9): cols{col_type{t1,t2,t3} ,col_type{t4,t5,t6} ,col_type{t7,t8,t9}} {
    }
    

    template<IsNumberM T> 
    mat<3, 3, T>::mat(const mat<3, 3, T> & m ): cols{m[0],m[1],m[2]} {
    }


    template<IsNumberM T> 
    mat<3, 3, T>::mat(const mat<3, 3, T>::col_type &v1 , const mat<3, 3, T>::col_type &v2, const mat<3, 3, T>::col_type &v3): cols{col_type{v1},col_type{v2},col_type{v3}}{  
    }
    

    template<IsNumberM T>
    mat<3, 3, T> & mat<3, 3, T>::operator=(const mat<3, 3, T> &m){

        if (this != &m) {
            cols[0] = m[0];
            cols[1] = m[1];
            cols[2] = m[2];
        }

        return *this;
    }


    template<IsNumberM T>
    mat<3, 3, T> mat<3, 3, T>::operator + (const mat<3, 3, T>& m) const{
        return  mat<3, 3, T>(   cols[0] + m[0], 
                                cols[1] + m[1],
                                cols[2] + m[2]
                            );

    }

    template<IsNumberM T>
    mat<3, 3, T> mat<3, 3, T>::operator - (const mat<3, 3, T>& m) const{
        return  mat<3, 3, T>(   cols[0][0] - m[0][0], 
                                cols[0][1] - m[0][1],
                                cols[1][0] - m[1][0],
                                cols[1][1] - m[1][1] 
                            );

    }

    template<IsNumberM T>
    mat<3, 3, T> mat<3, 3, T>::operator*(const mat<3, 3, T>& m) const {
        return mat<3, 3, T>(
            // Primera fila
            cols[0][0] * m[0][0] + cols[0][1] * m[1][0] + cols[0][2] * m[2][0],
            cols[0][0] * m[0][1] + cols[0][1] * m[1][1] + cols[0][2] * m[2][1],
            cols[0][0] * m[0][2] + cols[0][1] * m[1][2] + cols[0][2] * m[2][2],

            // Segunda fila
            cols[1][0] * m[0][0] + cols[1][1] * m[1][0] + cols[1][2] * m[2][0],
            cols[1][0] * m[0][1] + cols[1][1] * m[1][1] + cols[1][2] * m[2][1],
            cols[1][0] * m[0][2] + cols[1][1] * m[1][2] + cols[1][2] * m[2][2],

            // Tercera fila
            cols[2][0] * m[0][0] + cols[2][1] * m[1][0] + cols[2][2] * m[2][0],
            cols[2][0] * m[0][1] + cols[2][1] * m[1][1] + cols[2][2] * m[2][1],
            cols[2][0] * m[0][2] + cols[2][1] * m[1][2] + cols[2][2] * m[2][2]
        );
    }

    template<IsNumberM T>
    mat<3, 3, T> mat<3, 3, T>::operator * (const T& t) const{
        return  mat<3, 3, T>(   cols[0] * t,
                                cols[1] * t,
                                cols[2] * t
                            );
    }

    template<IsNumberM T>
    mat<3, 3, T> mat<3, 3, T>::operator / (const T& t) const{
        return  mat<3, 3, T>(   cols[0] / t,
                                cols[1] / t,
                                cols[2] / t
                            );
    }

    template<IsNumberM T>
    bool mat<3, 3, T>::operator == (const mat<3, 3, T>& m) const{
        
        return (cols[0] == m[0]) && (cols[1] == m[1]) && (cols[2] == m[2]); 
    }
    
    template<IsNumberM T>
    typename mat<3, 3, T>::col_type  & mat<3, 3, T>::operator[](int i) {

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

        if (i == 2)
            return cols[2];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumberM T>
    typename mat<3, 3, T>::col_type const & mat<3, 3, T>::operator[](int i) const{

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

        if (i == 2)
            return cols[2];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumberM T>
    T mat<3, 3, T>::size_row() const{
        return 3;
    }

    template<IsNumberM T>
    T mat<3, 3, T>::size_col() const{
        return 3;
    }
    
    template<IsNumberM U>
    mat<3, 3, U> operator * ( const U& t, const mat<3, 3, U>& m){ 
        return  mat<3, 3, U>(   m[0] * t,
                                m[1] * t,
                                m[2] * t
                            );   
    } 


    template<IsNumberM U>
    mat<3, 3, U> operator / ( const U& t, const mat<3, 3, U>& m){ 
        return  mat<3, 3, U>(   m[0] / t,
                                m[1] / t,
                                m[2] / t
                            );   
    } 

}