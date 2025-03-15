#pragma once
#include <iterator>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include "../detail/types_det.hpp"
#include "../detail/concepts_det.hpp"
#include "../iterator/iterator_.hpp"
#include "../iterator/iterator_const.hpp"

namespace line
{
    namespace math
    {

        // transpose
        template <nsp_types::length_t R, nsp_types::length_t C, nsp_concepts::is_numeric T>
        SMat<C, R, T> transpose(const SMat<R, C, T> &mat_);

    }
}

#include "./math_matrix.inl"