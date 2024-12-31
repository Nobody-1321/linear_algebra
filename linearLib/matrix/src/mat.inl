#pragma once
#include "../include/mat.hpp"
namespace line{

    // constructors

        // identity matrix
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T>::mat(): rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (std::size_t i = 0; i < R; i++)
        {
            
            (*rows)[i] = vec<C, T>(0);
        }
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T>::mat(T val_t) : rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (std::size_t i = 0; i < R; i++)
        {
            (*rows)[i] = vec<C, T>(val_t);
        }
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T>::mat(const mat<R, C, T> &mat_) : rows{std::make_unique<std::array<row_type, R>>()}
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] = mat_[i];
        }
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T>::mat(mat<R, C, T> &&mat_) noexcept : rows{std::move(mat_.rows)}
    {
    }
    
            // multiple arguments       
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    template <typename... Args>
    requires nsp_concepts::same_numeric_type<T, Args...>
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
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> &mat<R, C, T>::operator=(mat<R, C, T> &&mat_) noexcept 
    {
        if (this != &mat_)
        {
            rows = std::move(mat_.rows);
        }

        return *this;
    }

    // arithmetic operators
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> mat<R, C, T>::operator+(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (std::size_t i = 0; i < R; i++)
        {
            result[i] = (*rows)[i] + mat_[i];
        }

        return result;
    }
    
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> mat<R, C, T>::operator-(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = (*rows)[i] - mat_[i];
        }

        return result;
    }

 template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    template <nsp_length::length_t R2, nsp_length::length_t C2>
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
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> mat<R, C, T>::operator*(const T &sca) const
    {
        mat<R, C, T> result;

        for( std::size_t i = 0; i < size_row(); i++)
        {
            result[i] = (*rows)[i] * sca;
        }

        return result;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>  
    mat<R, C, T> &mat<R, C, T>::operator+=(const mat<R, C, T> &mat_)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] += mat_[i];
        }

        return *this;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> &mat<R, C, T>::operator-=(const mat<R, C, T> &mat_)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] -= mat_[i];
        }

        return *this;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    template <nsp_length::length_t R2, nsp_length::length_t C2>
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
    
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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


    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> &mat<R, C, T>::operator*=(const T &sca)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] *= sca;
        }

        return *this;
    }

    


    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T> &mat<R, C, T>::operator/=(const T &sca)
    {
        for (int i = 0; i < R; i++)
        {
            (*rows)[i] /= sca;
        }

        return *this;
    }

    // comparison operators
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    constexpr std::size_t mat<R, C, T>::size_row() const noexcept
    {
        return R;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    constexpr std::size_t mat<R, C, T>::size_col() const noexcept
    {
        return C;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    bool mat<R, C, T>::is_square() const noexcept
    {
        return R == C;
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    void mat<R, C, T>::fill(T fill_value)
    {
        for (std::size_t i = 0; i < R; i++)
        {
            (*rows)[i].fill(fill_value);
        }
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    void mat<R, C, T>::swap(mat<R, C, T> &mat_) noexcept
    {
        std::swap(rows, mat_.rows);
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    void mat<R, C, T>::dirmemory()
    {
        std::cout << "Memory address of the first element: " << &(*rows) << std::endl;
    }

    // access to elements
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::row_type &mat<R, C, T>::operator[](int idx) noexcept
    {
        return (*rows)[idx];
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::row_type const &mat<R, C, T>::operator[](int idx) const noexcept
    {
        return (*rows)[idx];
    }

    // iterators
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::iterator mat<R, C, T>::begin() noexcept
    {
        return iterator(rows->data());
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::iterator mat<R, C, T>::end() noexcept
    {
        return iterator(rows->data() + R);
    }
    

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::const_iterator mat<R, C, T>::cbegin() const noexcept
    {
        return const_iterator(rows->data());
    }

    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    typename mat<R, C, T>::const_iterator mat<R, C, T>::cend() const noexcept
    {
        return const_iterator(rows->data() + R);
    }

    //destructors
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
    mat<R, C, T>::~mat(){};

    // free functions
    // scalar multiplication
    template <nsp_length::length_t R, nsp_length::length_t C, nsp_concepts::is_numeric T>
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