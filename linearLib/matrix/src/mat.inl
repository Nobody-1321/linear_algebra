
namespace line{

    // constructors

        // identity matrix
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat()
    {
        for (int i = 0; i < R; i++)
        {
            rows[i] = vec<C, T>(0);
            rows[i][i] = 1;
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(T val_t)
    {
        for (int i = 0; i < R; i++)
        {
            rows[i] = vec<C, T>(val_t);
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(const mat<R, C, T> &mat_)
    {
        for (int i = 0; i < R; i++)
        {
            rows[i] = mat_[i];
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(mat<R, C, T> &&mat_) noexcept
    {
        for (int i = 0; i < R; i++)
        {
            rows[i] = std::move(mat_[i]);
        }
    }
    
            // multiple arguments       
    template <length_t R, length_t C, IsNumeric T>
    template <typename... Args>
    requires detail::AreSameAndNumbers<T, Args...>
    mat<R, C, T>::mat(Args &&...args)
    {
        static_assert(sizeof...(Args) <= R * C, "Too many arguments provided to mat constructor");
        for (int i = 0; i < R; i++)
        {
            rows[i] = vec<C, T>();
        }
        std::size_t index = 0;
        ((index < sizeof...(Args) && (rows[index / C][index % C] = static_cast<T>(std::forward<Args>(args)), index++)), ...);
    }


    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T>::mat(std::initializer_list<std::initializer_list<T>> init_list) {
        assert(init_list.size() == R);
        for (int i = 0; i < R; i++)
        {
            //assert(init_list.begin()[i].size() == C);
            rows[i] = vec<C, T>(init_list.begin()[i]);
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
                rows[i] = mat_[i];
            }
        }

        return *this;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> &mat<R, C, T>::operator=(mat<R, C, T> &&mat_) noexcept
    {
        if (this != &mat_)
        {
            for (int i = 0; i < R; i++)
            {
                rows[i] = std::move(mat_[i]);
            }
        }

        return *this;
    }

    // arithmetic operators
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator+(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = rows[i] + mat_[i];
        }

        return result;
    }
    
    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator-(const mat<R, C, T> &mat_) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = rows[i] - mat_[i];
        }

        return result;
    }

    template <length_t R, length_t C, IsNumeric T>
    template<length_t R2, length_t C2>
    mat<R, C2, T> mat<R, C, T>::operator*(const mat<R2, C2, T> &mat_) const
    {
        mat<R, C2, T> result(0);

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C2; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    if (rows[i][k].has_value() && mat_[k][j].has_value())
                    {
                        result[i][j] = result[i][j].value() + rows[i][k].value() * mat_[k][j].value();
                    }
                }
            }
        }

        return result;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator*(const T &sca) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = rows[i] * sca;
        }

        return result;
    }

    template <length_t R, length_t C, IsNumeric T>
    mat<R, C, T> mat<R, C, T>::operator/(const T &sca) const
    {
        mat<R, C, T> result;

        for (int i = 0; i < R; i++)
        {
            result[i] = rows[i] / sca;
        }

        return result;
    }

    // comparison operators
    template <length_t R, length_t C, IsNumeric T>
    bool mat<R, C, T>::operator==(const mat<R, C, T> &mat_) const
    {
        for (int i = 0; i < R; i++)
        {
            if (rows[i] != mat_[i])
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
    bool mat<R, C, T>::contains_nullopt() const noexcept
    {
        for (int i = 0; i < R; i++)
        {
            if (rows[i].contains_nullopt())
            {
                return true;
            }
        }

        return false;
    }

    template <length_t R, length_t C, IsNumeric T>
    void mat<R, C, T>::fill(T fill_value)
    {
        for (int i = 0; i < R; i++)
        {
            rows[i].fill(fill_value);
        }
    }

    template <length_t R, length_t C, IsNumeric T>
    void mat<R, C, T>::swap(mat<R, C, T> &mat_) noexcept
    {
        for (int i = 0; i < R; i++)
        {
            rows[i].swap(mat_[i]);
        }
    }

    // access to elements
    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type &mat<R, C, T>::operator[](int idx) noexcept
    {
        return rows[idx];
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type const &mat<R, C, T>::operator[](int idx) const noexcept
    {
        return rows[idx];
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type &mat<R, C, T>::at(int idx)
    {
        return rows.at(idx);
    }

    template <length_t R, length_t C, IsNumeric T>
    typename mat<R, C, T>::row_type const &mat<R, C, T>::at(int idx) const
    {
        return rows.at(idx);
    }
    
    // free functions
    template<length_t R, length_t C, IsNumeric T>
    mat<R, C, T> operator*(const T& sca, const mat<R, C, T>& mat_)
    {
        return mat_ * sca;
    }
};