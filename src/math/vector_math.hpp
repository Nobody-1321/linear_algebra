#pragma once
#include "config.hpp"
#include <iostream>
#include <assert.h>
#include "../detail/concepts_det.hpp"
#include <algorithm>

#if defined(SIMD_USE_AVX2)
#include "avx2_ope.hpp"
#elif defined(SIMD_USE_SSE)
#include "sse_ope.hpp"
#elif defined(SIMD_USE_SCALAR)
#include "scalar_ope.hpp"
#endif

namespace line
{
  namespace math
  {
    template <line::detail::concepts::vector T>
    void AddVector(const T &vecA, const T &vecB, T &vecR);
  }
}

#include "vector_math.inl"