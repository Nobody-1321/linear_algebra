#include "../include/mat2x2.hpp"

namespace line{

    //constructors    
    template<IsNumber T> 
    mat<2, 2, T>::mat(T val_t): cols{col_type{val_t,0} ,col_type{0,val_t}} {

    }

    template<IsNumber T>
    mat<2, 2, T>::mat(T val_t1, T val_t2, T val_t3, T val_t4): cols{col_type{val_t1,val_t2} ,col_type{val_t3,val_t4} } {
    }
    
    template<IsNumber T> 
    mat<2, 2, T>::mat(const mat<2, 2, T> & mat_ ): cols{mat_[0],mat_[1]} {
    }
    
    template<IsNumber T> 
    mat<2, 2, T>::mat(const mat<2, 2, T> && mat_ )noexcept :cols(std::move(mat_.cols)){
    }

    template<IsNumber T>
    mat<2, 2, T> & mat<2, 2, T>::operator=(const mat<2, 2, T> &mat_){

        if (this != &mat_) {
            cols[0] = mat_[0];
            cols[1] = mat_[1];
        }
       
        return *this;
    }


template<IsNumber T>
    mat<2, 2, T> & mat<2, 2, T>::operator=(mat<2, 2, T> &&mat_) noexcept { 

        if (this != &mat_) {
            cols[0] = mat_[0];
            cols[1] = mat_[1];
        }
       
        return *this;
    }

    //functions
    template<IsNumber T> 
    constexpr std::size_t mat<2, 2, T>::size_row() const noexcept{
        return 2;
    }

    template<IsNumber T> 
    constexpr std::size_t mat<2, 2, T>::size_col() const noexcept{
        return 2;
    }   

    template<IsNumber T> 
    typename mat<2, 2, T>::col_type  & mat<2, 2, T>::operator[](int idx){
        return cols[idx];

    }     
    
    template<IsNumber T>
    typename mat<2, 2, T>::col_type const  & mat<2, 2, T>::operator[](int idx) const{
        return cols[idx];
    }

    // comparison operators      
    template<IsNumber T> 
    bool mat<2, 2, T>::operator == (const mat<2, 2, T>& mat_) const{
        return (cols[0] == mat_[0]) && (cols[1] == mat_[1]);
    }

    template<IsNumber T>
    mat<2, 2, T>::~mat(){
    }
/*




    template<IsNumber T> 
    mat<2, 2, T>::mat(const mat<2, 2, T>::col_type &v1 , const mat<2, 2, T>::col_type &v2): cols{col_type{v1},col_type{v2}} {
    }

    template<IsNumber T>
    mat<2, 2, T> mat<2, 2, T>::operator + (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0] + m[0], 
                                cols[1] + m[1]
                            );

    }

    template<IsNumber T>
    mat<2, 2, T> mat<2, 2, T>::operator - (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0] - m[0], 
                                cols[1] - m[1]
                            );

    }

    template<IsNumber T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const mat<2, 2, T>& m) const{
        return  mat<2, 2, T>(   cols[0][0] * m[0][0] + cols[0][1] * m[1][0],
                                cols[0][0] * m[0][1] + cols[0][1] * m[1][1],
                                cols[1][0] * m[0][0] + cols[1][1] * m[1][0],
                                cols[1][0] * m[0][1] + cols[1][1] * m[1][1]
                            );

    }

    template<IsNumber T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const T& t) const{
        return  mat<2, 2, T>(   cols[0] * t,
                                cols[1] * t
                            );
    }

    template<IsNumber T>
    mat<2, 2, T> mat<2, 2, T>::operator / (const T& t) const{
        return  mat<2, 2, T>(   cols[0] / t,
                                cols[1] / t
                            );
    }

    template<IsNumber T>
    bool mat<2, 2, T>::operator == (const mat<2, 2, T>& m) const{
        
        return (cols[0] == m[0]) && (cols[1] == m[1]); 
    }
    
    template<IsNumber T>
    typename mat<2, 2, T>::col_type  & mat<2, 2, T>::operator[](int i) {

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumber T>
    typename mat<2, 2, T>::col_type const & mat<2, 2, T>::operator[](int i) const{

        if (i == 0)
            return cols[0];

        if (i == 1)
            return cols[1];

    throw std::out_of_range("In mat2x2 __index ("+ std::to_string(i) + ") is out of range");

    }

    template<IsNumber T>
    T mat<2, 2, T>::size_row() const{
        return 2;
    }

    template<IsNumber T>
    T mat<2, 2, T>::size_col() const{
        return 2;
    }

    template<IsNumber U>
    mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m){ 
        return  mat<2, 2, U>(   m[0] * t,
                                m[1] * t
                            );   
    } 


    template<IsNumber U>
    mat<2, 2, U> operator / ( const U& t, const mat<2, 2, U>& m){ 
        return  mat<2, 2, U>(   m[0] / t,
                                m[1] / t
                            );   
    } 

*/
}