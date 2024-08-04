#include "../include/mat2x2.hpp"

namespace line{

    //constructors    
    template<IsNumberM T> 
    mat<2, 2, T>::mat(T t): cols{col_type{t,0} ,col_type{0,t} } {
    }

    template<IsNumberM T>
    mat<2, 2, T>::mat(T t1, T t2, T t3, T t4): cols{col_type{t1,t2} ,col_type{t3,t4} } {
    }

    template<IsNumberM T> 
    mat<2, 2, T>::mat(const mat<2, 2, T> & m ): cols{m[0],m[1]} {
    }

    template<IsNumberM T> 
    mat<2, 2, T>::mat(const mat<2, 2, T>::col_type &v1 , const mat<2, 2, T>::col_type &v2): cols{col_type{v1},col_type{v2}} {
    }

    template<IsNumberM T>
    mat<2, 2, T> & mat<2, 2, T>::operator=(const mat<2, 2, T> &m){

        if (this != &m) {
            cols[0] = m[0];
            cols[1] = m[1];
        }
       
        return *this;
    }

    template<IsNumberM T>
    mat<2, 2, T> mat<2, 2, T>::operator + (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0] + m[0], 
                                cols[1] + m[1]
                            );

    }

    template<IsNumberM T>
    mat<2, 2, T> mat<2, 2, T>::operator - (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0] - m[0], 
                                cols[1] - m[1]
                            );

    }

    template<IsNumberM T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0][0] * m[0][0] + cols[0][1] * m[1][0],
                                cols[0][0] * m[0][1] + cols[0][1] * m[1][1],
                                cols[1][0] * m[0][0] + cols[1][1] * m[1][0],
                                cols[1][0] * m[0][1] + cols[1][1] * m[1][1]
                            );

    }

    template<IsNumberM T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const T& t) const{
        return  mat<2, 2, T>(   cols[0] * t,
                                cols[1] * t
                            );
    }

    template<IsNumberM T>
    mat<2, 2, T> mat<2, 2, T>::operator / (const T& t) const{
        return  mat<2, 2, T>(   cols[0] / t,
                                cols[1] / t
                            );
    }

    template<IsNumberM T>
    bool mat<2, 2, T>::operator == (const mat<2, 2, T>& m) const{
        
        return (cols[0] == m[0]) && (cols[1] == m[1]); 
    }
    
    template<IsNumberM T>
    typename mat<2, 2, T>::col_type  & mat<2, 2, T>::operator[](int i) {

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumberM T>
    typename mat<2, 2, T>::col_type const & mat<2, 2, T>::operator[](int i) const{

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumberM T>
    T mat<2, 2, T>::size_row() const{
        return 2;
    }

    template<IsNumberM T>
    T mat<2, 2, T>::size_col() const{
        return 2;
    }

    template<IsNumberM U>
    mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m){ 
        return  mat<2, 2, U>(   m[0] * t,
                                m[1] * t
                            );   
    } 


    template<IsNumberM U>
    mat<2, 2, U> operator / ( const U& t, const mat<2, 2, U>& m){ 
        return  mat<2, 2, U>(   m[0] / t,
                                m[1] / t
                            );   
    } 


}