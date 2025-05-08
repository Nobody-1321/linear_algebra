#pragma once
#include "../detail/config.hpp"
#include <iostream>
#include <assert.h>
#include "../detail/concepts_det.hpp"
#include <algorithm>

#if defined(SIMD_USE_AVX2)
#include "avx2_ope.hpp"
#elif defined(SIMD_USE_SSE)
#include "sse_ope.hpp"
#elif defined(SIMD_USE_SCALAR)
#include "binary_ope.hpp"
#endif

namespace line
{
  namespace vector
  {
    namespace math
    {
      namespace concepts = line::detail::concepts;

      template <concepts::vector T,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      // operacion para vector mutable vec A y vecB
      template <concepts::vector T,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(T &vecR, const T &vecB, BinaryOp op = {});

      // vector + scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::plus<typename T::value_type>>
      void
      AddVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector + scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(const T &vecR, const U &scalar, BinaryOp op = {});

      //------------------------------------------------
      // vector - vector
      template <concepts::vector T,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      template <concepts::vector T,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(T &vecR, const T &vecB, BinaryOp op = {});

      // vector - scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::minus<typename T::value_type>>
      void
      SubVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      template <concepts::vector T, typename U,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(T &vecR, const U &scalar, BinaryOp op = {});

      // vector * vector
      template <concepts::vector T,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void MulVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      // vector * scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void
      MulVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector * vector
      template <concepts::vector T,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void MulVector(T &vecR, const T &vecA, BinaryOp op = {});

      //************************************ */

      // vector * scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void MulVector(T &vecR, const U &scalar, BinaryOp op = {});

      // vector / scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::divides<typename T::value_type>>
      void
      DivVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector / scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::divides<typename T::value_type>>
      void DivVector(T &vecR, const U &scalar, BinaryOp op = {});

    }
  }
}

#include "vector_math.inl"