#include "../include/mat4x4.hpp"

namespace line{

    // Constructors    
    template<IsNumberM T> 
    mat<4, 4, T>::mat(T t) : cols{col_type{t,0,0,0}, col_type{0,t,0,0}, col_type{0,0,t,0}, col_type{0,0,0,t}} {
    }

    template<IsNumberM T>
    mat<4, 4, T>::mat(T t1, T t2, T t3, T t4,
                      T t5, T t6, T t7, T t8,
                      T t9, T t10, T t11, T t12,
                      T t13, T t14, T t15, T t16) 
        : cols{col_type{t1, t2, t3, t4}, 
               col_type{t5, t6, t7, t8}, 
               col_type{t9, t10, t11, t12}, 
               col_type{t13, t14, t15, t16}} {
    }

    template<IsNumberM T> 
    mat<4, 4, T>::mat(const mat<4, 4, T>& m) : cols{m[0], m[1], m[2], m[3]} {
    }

    template<IsNumberM T> 
    mat<4, 4, T>::mat(const mat<4, 4, T>::col_type& v1, 
                      const mat<4, 4, T>::col_type& v2, 
                      const mat<4, 4, T>::col_type& v3,
                      const mat<4, 4, T>::col_type& v4) 
        : cols{v1, v2, v3, v4} {  
    }

    template<IsNumberM T>
    mat<4, 4, T>& mat<4, 4, T>::operator=(const mat<4, 4, T>& m) {
        if (this != &m) {
            cols[0] = m[0];
            cols[1] = m[1];
            cols[2] = m[2];
            cols[3] = m[3];
        }
        return *this;
    }

    // Arithmetic operators
    template<IsNumberM T>
    mat<4, 4, T> mat<4, 4, T>::operator+(const mat<4, 4, T>& m) const {
        return mat<4, 4, T>(cols[0] + m[0], 
                            cols[1] + m[1], 
                            cols[2] + m[2], 
                            cols[3] + m[3]);
    }

    template<IsNumberM T>
    mat<4, 4, T> mat<4, 4, T>::operator-(const mat<4, 4, T>& m) const {
        return mat<4, 4, T>(cols[0] - m[0], 
                            cols[1] - m[1], 
                            cols[2] - m[2], 
                            cols[3] - m[3]);
    }

    template<IsNumberM T>
    mat<4, 4, T> mat<4, 4, T>::operator*(const mat<4, 4, T>& m) const {
        return mat<4, 4, T>(
            // Primera fila
            cols[0][0] * m[0][0] + cols[0][1] * m[1][0] + cols[0][2] * m[2][0] + cols[0][3] * m[3][0],
            cols[0][0] * m[0][1] + cols[0][1] * m[1][1] + cols[0][2] * m[2][1] + cols[0][3] * m[3][1],
            cols[0][0] * m[0][2] + cols[0][1] * m[1][2] + cols[0][2] * m[2][2] + cols[0][3] * m[3][2],
            cols[0][0] * m[0][3] + cols[0][1] * m[1][3] + cols[0][2] * m[2][3] + cols[0][3] * m[3][3],

            // Segunda fila
            cols[1][0] * m[0][0] + cols[1][1] * m[1][0] + cols[1][2] * m[2][0] + cols[1][3] * m[3][0],
            cols[1][0] * m[0][1] + cols[1][1] * m[1][1] + cols[1][2] * m[2][1] + cols[1][3] * m[3][1],
            cols[1][0] * m[0][2] + cols[1][1] * m[1][2] + cols[1][2] * m[2][2] + cols[1][3] * m[3][2],
            cols[1][0] * m[0][3] + cols[1][1] * m[1][3] + cols[1][2] * m[2][3] + cols[1][3] * m[3][3],

            // Tercera fila
            cols[2][0] * m[0][0] + cols[2][1] * m[1][0] + cols[2][2] * m[2][0] + cols[2][3] * m[3][0],
            cols[2][0] * m[0][1] + cols[2][1] * m[1][1] + cols[2][2] * m[2][1] + cols[2][3] * m[3][1],
            cols[2][0] * m[0][2] + cols[2][1] * m[1][2] + cols[2][2] * m[2][2] + cols[2][3] * m[3][2],
            cols[2][0] * m[0][3] + cols[2][1] * m[1][3] + cols[2][2] * m[2][3] + cols[2][3] * m[3][3],

            // Cuarta fila
            cols[3][0] * m[0][0] + cols[3][1] * m[1][0] + cols[3][2] * m[2][0] + cols[3][3] * m[3][0],
            cols[3][0] * m[0][1] + cols[3][1] * m[1][1] + cols[3][2] * m[2][1] + cols[3][3] * m[3][1],
            cols[3][0] * m[0][2] + cols[3][1] * m[1][2] + cols[3][2] * m[2][2] + cols[3][3] * m[3][2],
            cols[3][0] * m[0][3] + cols[3][1] * m[1][3] + cols[3][2] * m[2][3] + cols[3][3] * m[3][3]
        );
    }

    template<IsNumberM T>
    mat<4, 4, T> mat<4, 4, T>::operator*(const T& t) const {
        return mat<4, 4, T>(cols[0] * t,
                            cols[1] * t,
                            cols[2] * t,
                            cols[3] * t);
    }

    template<IsNumberM T>
    mat<4, 4, T> mat<4, 4, T>::operator/(const T& t) const {
        return mat<4, 4, T>(cols[0] / t,
                            cols[1] / t,
                            cols[2] / t,
                            cols[3] / t);
    }

    template<IsNumberM T>
    bool mat<4, 4, T>::operator==(const mat<4, 4, T>& m) const {
        return (cols[0] == m[0]) && 
               (cols[1] == m[1]) && 
               (cols[2] == m[2]) && 
               (cols[3] == m[3]); 
    }

    template<IsNumberM T>
    typename mat<4, 4, T>::col_type& mat<4, 4, T>::operator[](int i) {
        if (i == 0) return cols[0];
        if (i == 1) return cols[1];
        if (i == 2) return cols[2];
        if (i == 3) return cols[3];
        
        throw std::out_of_range("In mat4x4 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumberM T>
    typename mat<4, 4, T>::col_type const& mat<4, 4, T>::operator[](int i) const {
        if (i == 0) return cols[0];
        if (i == 1) return cols[1];
        if (i == 2) return cols[2];
        if (i == 3) return cols[3];
        
        throw std::out_of_range("In mat4x4 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumberM T>
    T mat<4, 4, T>::size_row() const {
        return 4;
    }

    template<IsNumberM T>
    T mat<4, 4, T>::size_col() const {
        return 4;
    }

    template<IsNumberM U>
    mat<4, 4, U> operator*(const U& t, const mat<4, 4, U>& m) {
        return mat<4, 4, U>(m[0] * t,
                            m[1] * t,
                            m[2] * t,
                            m[3] * t);
    }

    template<IsNumberM U>
    mat<4, 4, U> operator/(const U& t, const mat<4, 4, U>& m) {
        return mat<4, 4, U>(m[0] / t,
                            m[1] / t,
                            m[2] / t,
                            m[3] / t);
    }

}
