#include "../include/mat2x2.hpp"

namespace line{

    //constructors    
    template<IsNumeric T> 
    mat<2, 2, T>::mat(T val_t): cols{col_type{val_t,0} ,col_type{0,val_t}} {

    }

    template<IsNumeric T>
    mat<2, 2, T>::mat(T val_t1, T val_t2, T val_t3, T val_t4): cols{col_type{val_t1,val_t2} ,col_type{val_t3,val_t4} } {
    }
 
    template<IsNumeric T> 
    mat<2, 2, T>::mat(const mat<2, 2, T>::col_type &vec_1 , const mat<2, 2, T>::col_type &vec_2): cols{col_type{vec_1},col_type{vec_2}} {
    }

   
    template<IsNumeric T> 
    mat<2, 2, T>::mat(const mat<2, 2, T> & mat_ ): cols{mat_[0],mat_[1]} {
    }
    
    template<IsNumeric T> 
    mat<2, 2, T>::mat(const mat<2, 2, T> && mat_ )noexcept :cols(std::move(mat_.cols)){
    }

    template<IsNumeric T>
    mat<2, 2, T> & mat<2, 2, T>::operator=(const mat<2, 2, T> &mat_){

        if (this != &mat_) {
            cols[0] = mat_[0];
            cols[1] = mat_[1];
        }
       
        return *this;
    }


template<IsNumeric T>
    mat<2, 2, T> & mat<2, 2, T>::operator=(mat<2, 2, T> &&mat_) noexcept { 

        if (this != &mat_) {
            cols[0] = mat_[0];
            cols[1] = mat_[1];
        }
       
        return *this;
    }

    //arithmetic operators
    template<IsNumeric T>
    mat<2, 2, T> mat<2, 2, T>::operator + (const mat<2, 2, T>& mat_) const{
        return  mat<2, 2, T>(   cols[0] + mat_[0], 
                                cols[1] + mat_[1]
                            );
    }

    template<IsNumeric T>
    mat<2, 2, T> mat<2, 2, T>::operator - (const mat<2, 2, T>& mat_) const{
        return  mat<2, 2, T>(   cols[0] - mat_[0], 
                                cols[1] - mat_[1]
                            );

    }

    template<IsNumeric T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const mat<2, 2, T>& mat_) const{
        return  mat<2, 2, T>(   cols[0][0] * mat_[0][0] + cols[0][1] * mat_[1][0],
                                cols[0][0] * mat_[0][1] + cols[0][1] * mat_[1][1],
                                cols[1][0] * mat_[0][0] + cols[1][1] * mat_[1][0],
                                cols[1][0] * mat_[0][1] + cols[1][1] * mat_[1][1]
                            );

    }

    template<IsNumeric T>
    mat<2, 2, T> mat<2, 2, T>::operator * (const T& sca) const{
        return  mat<2, 2, T>(   cols[0] * sca,
                                cols[1] * sca
                            );
    }

    template<IsNumeric T>
    mat<2, 2, T> mat<2, 2, T>::operator / (const T& sca) const{
        return  mat<2, 2, T>(   cols[0] / sca,
                                cols[1] / sca
                            );
    }
 


    //functions
    template<IsNumeric T> 
    constexpr std::size_t mat<2, 2, T>::size_row() const noexcept{
        return 2;
    }

    template<IsNumeric T> 
    constexpr std::size_t mat<2, 2, T>::size_col() const noexcept{
        return 2;
    }   

    template<IsNumeric T> 
    typename mat<2, 2, T>::col_type  & mat<2, 2, T>::operator[](int idx){
        return cols[idx];

    }     
    
    template<IsNumeric T>
    typename mat<2, 2, T>::col_type const  & mat<2, 2, T>::operator[](int idx) const{
        return cols[idx];
    }

    // comparison operators      
    template<IsNumeric T> 
    bool mat<2, 2, T>::operator == (const mat<2, 2, T>& mat_) const{
        return (cols[0] == mat_[0]) && (cols[1] == mat_[1]);
    }

    template<IsNumeric T>
    mat<2, 2, T>::~mat(){
    }
/*






  
       template<IsNumeric U>
    mat<2, 2, U> operator * ( const U& t, const mat<2, 2, U>& m){ 
        return  mat<2, 2, U>(   m[0] * t,
                                m[1] * t
                            );   
    } 

*/
}