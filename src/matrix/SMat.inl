#pragma once
#include "./SMat.hpp"
namespace line
{
  namespace structs
  {

    // +---------------------------------------------+
    // |                 Constructors                |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::SMat() : rows{std::make_unique<std::array<row_type, R>>()}
    {
      for(std::size_t i = 0; i < R; i++)
        {
          (*rows)[i] = SVec<C, T>();
        }
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::SMat(T val_t)
        : rows{std::make_unique<std::array<row_type, R>>()}
    {
      for(std::size_t i = 0; i < R; i++)
        {
          (*rows)[i] = SVec<C, T>(val_t);
        }
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::SMat(const SMat<R, C, T> &mat_)
        : rows{std::make_unique<std::array<row_type, R>>()}
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] = mat_[i];
        }
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::SMat(SMat<R, C, T> &&mat_) noexcept
        : rows{std::move(mat_.rows)}
    {}

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    template <typename... Args>
      requires nsp_concepts::same_numeric_type<T, Args...>
    SMat<R, C, T>::SMat(Args &&...args)
        : rows{std::make_unique<std::array<row_type, R>>()}
    {
      static_assert(sizeof...(Args) == R * C,
                    " Number of arguments must be equal to the number of "
                    "elements in the matrix");
      for(std::size_t i = 0; i < R; i++)
        {
          (*rows)[i] = SVec<C, T>();
        }

      std::size_t index = 0;
      ((index < sizeof...(Args)
        && ((*rows)[index / C][index % C]
            = static_cast<T>(std::forward<Args>(args)),
            index++)),
       ...);
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::SMat(
      std::initializer_list<std::initializer_list<T>> init_list)
        : rows{std::make_unique<std::array<row_type, R>>()}
    {
      assert(init_list.size() == R);

      for(int i = 0; i < R; i++)
        {
          assert(init_list.begin()[i].size() == C);
          (*rows)[i] = SVec<C, T>(init_list.begin()[i]);
        }
    }

    // +---------------------------------------------+
    // |           assignment operators              |
    // +---------------------------------------------+

    // assignment operators
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator=(const SMat<R, C, T> &mat_)
    {
      if(this != &mat_)
        {
          for(int i = 0; i < R; i++)
            {
              (*rows)[i] = mat_[i];
            }
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator=(SMat<R, C, T> &&mat_) noexcept
    {
      if(this != &mat_)
        {
          rows = std::move(mat_.rows);
        }

      return *this;
    }

    // +---------------------------------------------+
    // |           arithmetic operators              |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator+(const SMat<R, C, T> &mat_) const
    {
      SMat<R, C, T> result;

      for(std::size_t i = 0; i < R; i++)
        {
          result[i] = (*rows)[i] + mat_[i];
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator+=(const SMat<R, C, T> &mat_)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] += mat_[i];
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator+(const T &sca) const
    {
      SMat<R, C, T> result;

      for(int i = 0; i < R; i++)
        {
          result[i] = (*rows)[i] + sca;
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator+=(const T &sca)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] += sca;
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator-(const SMat<R, C, T> &mat_) const
    {
      SMat<R, C, T> result;

      for(int i = 0; i < R; i++)
        {
          result[i] = (*rows)[i] - mat_[i];
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator-=(const SMat<R, C, T> &mat_)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] -= mat_[i];
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator-(const T &sca) const
    {
      SMat<R, C, T> result;

      for(int i = 0; i < R; i++)
        {
          result[i] = (*rows)[i] - sca;
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator-=(const T &sca)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] -= sca;
        }

      return *this;
    }

    //***********************************************
    // |           matrix multiplication             |
    //***********************************************

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    template <nsp_types::length_t R2, nsp_types::length_t C2>
    SMat<R, C2, T> SMat<R, C, T>::operator*(const SMat<R2, C2, T> &mat_) const
    {
      // Verificar que el número de columnas de la primera matriz sea igual al
      // número de filas de la segunda matriz
      static_assert(C == R2,
                    "Matrix dimensions do not match for multiplication");

      SMat<R, C2, T> result;

      // Realizar la multiplicación de matrices
      for(std::size_t i = 0; i < R; i++)
        {
          for(std::size_t j = 0; j < C2; j++)
            {
              for(std::size_t k = 0; k < C; k++)
                {
                  result[i][j] += (*rows)[i][k] * mat_[k][j];
                }
            }
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator*(const T &sca) const
    {
      SMat<R, C, T> result;

      for(std::size_t i = 0; i < size_row(); i++)
        {
          result[i] = (*rows)[i] * sca;
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    template <nsp_types::length_t R2, nsp_types::length_t C2>
    SMat<R, C2, T> &SMat<R, C, T>::operator*=(const SMat<R2, C2, T> &mat_)
    {
      static_assert(C == R2,
                    "Matrix dimensions do not match for multiplication");

      // Realizar la multiplicación de matrices
      for(std::size_t i = 0; i < R; i++)
        {
          for(std::size_t j = 0; j < C2; j++)
            {
              for(std::size_t k = 0; k < C; k++)
                {
                  (*rows)[i][j] += (*rows)[i][k] * mat_.at(k)[j];
                }
            }
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator*=(const T &sca)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] *= sca;
        }

      return *this;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> SMat<R, C, T>::operator/(const T &sca) const
    {
      SMat<R, C, T> result;

      for(int i = 0; i < R; i++)
        {
          result[i] = (*rows)[i] / sca;
        }

      return result;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> &SMat<R, C, T>::operator/=(const T &sca)
    {
      for(int i = 0; i < R; i++)
        {
          (*rows)[i] /= sca;
        }

      return *this;
    }

    // +---------------------------------------------+
    // |           comparison operators              |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    bool SMat<R, C, T>::operator==(const SMat<R, C, T> &mat_) const
    {
      for(std::size_t i = 0; i < R; i++)
        {
          if((*rows)[i] != mat_[i])
            {
              return false;
            }
        }

      return true;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    bool SMat<R, C, T>::operator!=(const SMat<R, C, T> &mat_) const
    {
      for(std::size_t i = 0; i < R; i++)
        {
          if((*rows)[i] != mat_[i])
            {
              return true;
            }
        }

      return false;
    }

    // +---------------------------------------------+
    // |               functions                     |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    constexpr std::size_t SMat<R, C, T>::size_row() const noexcept
    {
      return R;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    constexpr std::size_t SMat<R, C, T>::size_col() const noexcept
    {
      return C;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    bool SMat<R, C, T>::is_square() const noexcept
    {
      return R == C;
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    void SMat<R, C, T>::fill(T fill_value)
    {
      for(std::size_t i = 0; i < R; i++)
        {
          (*rows)[i].fill(fill_value);
        }
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    void SMat<R, C, T>::swap(SMat<R, C, T> &mat_) noexcept
    {
      std::swap(rows, mat_.rows);
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    bool SMat<R, C, T>::is_valid()
    {
      return rows != nullptr;
    }

    // +---------------------------------------------+
    // |           element access operators          |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::row_type &
    SMat<R, C, T>::operator[](int idx) noexcept
    {
      return (*rows)[idx];
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::row_type const &
    SMat<R, C, T>::operator[](int idx) const noexcept
    {
      return (*rows)[idx];
    }

    // +---------------------------------------------+
    // |               iterators                     |
    // +---------------------------------------------+

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::iterator SMat<R, C, T>::begin() noexcept
    {
      return iterator(rows->data());
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::iterator SMat<R, C, T>::end() noexcept
    {
      return iterator(rows->data() + R);
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::const_iterator
    SMat<R, C, T>::cbegin() const noexcept
    {
      return const_iterator(rows->data());
    }

    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    typename SMat<R, C, T>::const_iterator SMat<R, C, T>::cend() const noexcept
    {
      return const_iterator(rows->data() + R);
    }

    // destructors
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T>::~SMat(){};

    // +---------------------------------------------+
    // |           non-member operators              |
    // +---------------------------------------------+

    // scalar multiplication
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator*(const T &sca, const SMat<R, C, T> &mat_)
    {
      SMat<R, C, T> result;

      for(std::size_t i = 0; i < R; i++)
        {
          result[i] = sca * mat_[i];
        }

      return result;
    }

    // scalar addition
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator+(const T &sca, const SMat<R, C, T> &mat_)
    {
      SMat<R, C, T> result;

      for(std::size_t i = 0; i < R; i++)
        {
          result[i] = sca + mat_[i];
        }

      return result;
    }

    // scalar subtraction
    template <nsp_types::length_t R, nsp_types::length_t C,
              nsp_concepts::is_numeric T>
    SMat<R, C, T> operator-(const T &sca, const SMat<R, C, T> &mat_)
    {
      SMat<R, C, T> result;

      for(std::size_t i = 0; i < R; i++)
        {
          result[i] = sca - mat_[i];
        }

      return result;
    }
  }
};