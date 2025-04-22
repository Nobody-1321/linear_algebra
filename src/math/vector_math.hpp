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
    namespace concepts = line::detail::concepts;

    template <concepts::vector T>
    void AddVector(const T &vecA, const T &vecB, T &vecR);

    // operacion para vector mutable vec A y vecB
    template <concepts::vector T> void AddVector(T &vecR, const T &vecB);

    // vector + scalar
    template <concepts::vector T, typename U>
    void AddVector(const T &vecA, T &vecR, const U &scalar);

    // vector + scalar
    template <concepts::vector T, typename U>
    void AddVector(const T &vecR, const U &scalar);

    // vector - vector
    template <concepts::vector T>
    void SubVector(const T &vecA, const T &vecB, T &vecR);

    template <concepts::vector T> void SubVector(T &vecR, const T &vecB);

    // vector - scalar
    template <concepts::vector T, typename U>
    void SubVector(const T &vecA, T &vecR, const U &scalar);

    // scalar - vector
    template <concepts::vector T, typename U>
    void SubVector(const U &scalar, const T &vecA, T &vecR);

    template <concepts::vector T, typename U>
    void SubVector(T &vecR, const U &scalar);

    // vector * vector
    template <concepts::vector T>
    void MulVector(const T &vecA, const T &vecB, T &vecR);

    // vector * scalar
    template <concepts::vector T, typename U>
    void MulVector(const T &vecA, T &vecR, const U &scalar);
    // vector * vector
    template <concepts::vector T> void MulVector(T &vecR, const T &vecA);

    // vector * scalar
    template <concepts::vector T, typename U>
    void MulVector(const T &vecA, T &vecR, const U &scalar);

    // vector * scalar
    template <concepts::vector T, typename U>
    void MulVector(T &vecR, const U &scalar);

    // vector / scalar
    template <concepts::vector T, typename U>
    void DivVector(const T &vecA, T &vecR, const U &scalar);

    // vector / scalar
    template <concepts::vector T, typename U>
    void DivVector(T &vecR, const U &scalar);

  }

}

#include "vector_math.inl"