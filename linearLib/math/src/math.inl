
namespace line
{

    // to degrees
    template <IsNumeric T>
    T to_degrees(T rad)
    {
        return rad * 180 / M_PI;
    }

    // to radians
    template <IsNumeric T>
    T to_radians(T deg)
    {
        return deg * M_PI / 180;
    }

    // magnitude of a vector
    //  Función para calcular la magnitud de un vector
    template <typename Iterator>
    typename std::iterator_traits<Iterator>::value_type magnitude(Iterator begin, Iterator end)
    {
        using value_type = typename std::iterator_traits<Iterator>::value_type;
        // Usa std::inner_product para calcular la suma de los cuadrados
        value_type sum_of_squares = std::inner_product(begin, end, begin, value_type(0),
                                                       std::plus<value_type>(),
                                                       [](value_type a, value_type b)
                                                       { return a * a; });

        return std::sqrt(sum_of_squares);
    }

    // unit vector
    // returns a new vector with the same direction as the input vector but with a magnitude of 1
    template <length_t L, IsNumeric T>
    vec<L, T> unit_vector(const vec<L, T> &vec_)
    {

        T mag = magnitude(vec_.cbegin(), vec_.cend());

        if (mag == 0)
        {
            throw std::runtime_error("Can't normalize a zero vector");
        }

        vec<L, T> unit_vec;
        std::transform(vec_.cbegin(), vec_.cend(), unit_vec.begin(), [mag](T val)
                       { return val / mag; });

        return unit_vec;
    }

    // distance between two vectors
    template <length_t L, IsNumeric T>
    T distance(const vec<L, T> &vec1, const vec<L, T> &vec2)
    {
        vec<L, T> diff = vec1 - vec2;
        return magnitude(diff.cbegin(), diff.cend());
    }

    // dot product
    template <length_t L, IsNumeric T>
    T dot_product(const vec<L, T> &vec1, const vec<L, T> &vec2)
    {
        return std::inner_product(vec1.cbegin(), vec1.cend(), vec2.cbegin(), T(0));
    }

    // angle between two vectors
    template <length_t L, IsNumeric T>
    T angle_between(const vec<L, T> &vec1, const vec<L, T> &vec2)
    {
        T dot = dot_product(vec1, vec2);
        T mag1 = magnitude(vec1.cbegin(), vec1.cend());
        T mag2 = magnitude(vec2.cbegin(), vec2.cend());

        return std::acos(dot / (mag1 * mag2));
    }

    // projection of a vector
    template <length_t L, IsNumeric T>
    vec<L, T> project(const vec<L, T> &vec1, const vec<L, T> &vec2)
    {
        T mag2 = magnitude(vec2.cbegin(), vec2.cend());

        if (mag2 == 0)
        {
            throw std::runtime_error("Can't project onto a zero vector");
        }

        T dot = dot_product(vec1, vec2);

        return vec2 * (dot / (mag2 * mag2));
    }

    // cross product
    template <length_t L, IsNumeric T>
    vec<L, T> cross_product(const vec<L, T> &vec1, const vec<L, T> &vec2)
    {
        static_assert(L == 3, "Cross product is only defined for 3D vectors");
        return vec<L, T>{
            vec1[1] * vec2[2] - vec1[2] * vec2[1], // Componente x
            vec1[2] * vec2[0] - vec1[0] * vec2[2], // Componente y
            vec1[0] * vec2[1] - vec1[1] * vec2[0]  // Componente z
        };
    }

    // Matrix
    // transpose
    template <length_t R, length_t C, IsNumeric T>
    mat<C, R, T> transpose(const mat<R, C, T> &mat_)
    {
        mat<C, R, T> result(0);

        for (length_t i = 0; i < R; ++i)
        {
            for (length_t j = 0; j < C; ++j)
            {
                result[j][i] = mat_[i][j];
            }
        }

        return result;
    }
}
