#pragma once
#include "../include/mat.hpp"
namespace line{

    // constructors

        // identity matrix
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(): rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (std::size_t i = 0; i < R; i++)
        {
            
            (*rows)[i] = vec<C, T>(0);
            //(*rows)[i][i] = static_cast<T>(1); //access out of bounds
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(T val_t) : rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (std::size_t i = 0; i < R; i++)
        {
            rows[i] = vec<C, T>(val_t);
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(const mat<R, C, T> &mat_) : rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] = mat_[i];
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(mat<R, C, T> &&mat_) noexcept : rows{std::move(mat_.rows)}
    {
    }
    
            // multiple arguments       
    template <length_t R, length_t C, IsNumeric T>
    template <typename... Args>
    requires detail::AreSameAndNumbers<T, Args...>
    mat<R, C, T>::mat(Args &&...args) : rows{std::make_unique<std::array<row_type, R>>()}
    {
        static_assert(sizeof...(Args) == R * C, "Number of arguments must be equal to the number of elements in the matrix");
        for (std::size_t i = 0; i < R; i++)
        {
            (*rows)[i] = vec<C, T>();
        }
        std::size_t index = 0;
        ((index < sizeof...(Args) && ((*rows)[index / C][index % C] = static_cast<T>(std::forward<Args>(args)), index++)), ...);
    }

    // list initialization
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(std::initializer_list<std::initializer_list<T>> init_list) : rows{std::make_unique<std::array<row_type, R>>()}
    {

        assert(init_list.size() == R);
        for (int i = 0; i < R; i++)
        {
            assert(init_list.begin()[i].size() == C);
            (*rows)[i] = vec<C, T>(init_list.begin()[i]);
        }
    }

    // assignment operators
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator=(const mat<R, C, T> &mat_)
    {
        if (this != &mat_)
        {
            for (int i = 0; i < R; i++)
            {
                (*rows)[i] = mat_[i];
            }
        }

        return *this;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator=(mat<R, C, T> &&mat_) noexcept 
    {
        if (this != &mat_)
        {
            rows = std::move(mat_.rows);
        }

        return *this;
    }

    // arithmetic operators
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator+(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (std::size_t i = 0; i < R; i++)
        {
            result[i] = (*rows)[i] + mat_[i];
        }

        return result;
    }
    
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator-(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = (*rows)[i] - mat_[i];
        }

        return result;
    }

 template <length_t R, length_t C, IsNumeric T>
    template <length_t R2, length_t C2>
    mat<R, C2, T> mat<R, C, T>::operator*(const mat<R2, C2, T> &mat_) const
    {
        // Verificar que el número de columnas de la primera matriz sea igual al número de filas de la segunda matriz
        static_assert(C == R2, "Matrix dimensions do not match for multiplication");

        mat<R, C2, T> result;

        // Realizar la multiplicación de matrices
        for (std::size_t i = 0; i < R; i++)
        {
            for (std::size_t j = 0; j < C2; j++)
            {
                for (std::size_t k = 0; k < C; k++)
                {
                    result[i][j] += (*rows)[i][k] * mat_.at(k)[j];
                }
            }
        }

        return result;
    }

    // Multiplicación de matriz por vector
    template <length_t R, length_t C, IsNumeric T>
    vec<R, T> mat<R, C, T>::operator*(const vec<R, T> &vec_) const
    {
        
        static_assert(C == R, "Matrix dimensions do not match for multiplication");

        vec<R, T> result;


    for (int i = 0; i < R; i++)
    {
        result[i] = 0; // Asegúrate de inicializar el resultado a 0
        for (int j = 0; j < C; j++)
        {
            result[i] += (*rows)[i][j] * vec_[j];
        }
    }

        return result;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator*(const T &sca) const
    {
        mat<R, C, T> result;

        for( std::size_t i = 0; i < size_row(); i++)
        {
            result[i] = (*rows)[i] * sca;
        }

        return result;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator/(const T &sca) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = (*rows)[i] / sca;
        }

        return result;
    }

    // compound assignment operators
    template <length_t R, length_t C, IsNumeric T>  
    mat<R, C, T> &mat<R, C, T>::operator+=(const mat<R, C, T> &mat_)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] += mat_[i];
        }

        return *this;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator-=(const mat<R, C, T> &mat_)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] -= mat_[i];
        }

        return *this;
    }

    template <length_t R, length_t C, IsNumeric T>
    template <length_t R2, length_t C2>
    mat<R, C2, T> &mat<R, C, T>::operator*=(const mat<R2, C2, T> &mat_)
    {
        static_assert(C == R2, "Matrix dimensions do not match for multiplication");
        
        // Realizar la multiplicación de matrices
        for (std::size_t i = 0; i < R; i++)
        {
            for (std::size_t j = 0; j < C2; j++)
            {
                for (std::size_t k = 0; k < C; k++)
                {
                    (*rows)[i][j] += (*rows)[i][k] * mat_.at(k)[j];
                }
            }
        }

        return *this;
    }
    
    template <length_t R, length_t C, IsNumeric T>
    vec<R, T> &mat<R, C, T>::operator*=(const vec<R, T> &vec_)
    {
        static_assert(C == R, "Matrix dimensions do not match for multiplication");


        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                (*rows)[i] += (*rows)[i][j] * vec_[j];
            }
        }

        return *this;
    }


    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator*=(const T &sca)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] *= sca;
        }

        return *this;
    }

    


    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator/=(const T &sca)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] /= sca;
        }

        return *this;
    }

    // comparison operators
    template <length_t R, length_t C, IsNumeric T>
    bool mat<R, C, T>::operator==(const mat<R, C, T> &mat_) const
    {
        for (std::size_t i = 0; i < R; i++)
        {
            if ((*rows)[i] != mat_[i])
            {
                return false;
            }
        }

        return true;
    }
    
    // functions
    template <length_t R, length_t C, IsNumeric T>
    constexpr std::size_t mat<R, C, T>::size_row() const noexcept
    {
        return R;
    }

    template <length_t R, length_t C, IsNumeric T>
    constexpr std::size_t mat<R, C, T>::size_col() const noexcept
    {
        return C;
    }

    template <length_t R, length_t C, IsNumeric T>
    bool mat<R, C, T>::is_square() const noexcept
    {
        return R == C;
    }

    template <length_t R, length_t C, IsNumeric T>
    void mat<R, C, T>::fill(T fill_value)
    {
        for (std::size_t i = 0; i < R; i++)
        {
            (*rows)[i].fill(fill_value);
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    void mat<R, C, T>::swap(mat<R, C, T> &mat_) noexcept
    {
        std::swap(rows, mat_.rows);
    }

    template <length_t R, length_t C, IsNumeric T>
    void mat<R, C, T>::dirmemory()
    {
        std::cout << "Memory address of the first element: " << &(*rows) << std::endl;
    }

    // access to elements
    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type &mat<R, C, T>::operator[](int idx) noexcept
    {
        return (*rows)[idx];
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type const &mat<R, C, T>::operator[](int idx) const noexcept
    {
        return (*rows)[idx];
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type &mat<R, C, T>::at(int idx)
    {
        return rows->at(idx);
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type const &mat<R, C, T>::at(int idx) const
    {
        return rows->at(idx);
    }

    // iterators
    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type::iterator mat<R, C, T>::begin() noexcept
    {
        return rows[0]->begin();
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type::iterator mat<R, C, T>::end() noexcept
    {
        return rows[R - 1]->end();
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type::const_iterator mat<R, C, T>::cbegin() const noexcept
    {
        return rows[0]->cbegin();
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type::const_iterator mat<R, C, T>::cend() const noexcept
    {
        return rows[R - 1]->cend();
    }

    //destructors
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::~mat(){};

    // free functions
    // scalar multiplication
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> operator*(const T &sca, const mat<R, C, T> &mat_)
    {
        mat<R, C, T> result;

        for (std::size_t i = 0; i < R; i++)
        {
            result[i] = sca * mat_[i];
        }

        return result;
    }
    

};