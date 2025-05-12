#pragma once
#include "../detail/simd_config.hpp"
#include "vector_arithmetic_dispatch.hpp"
#include <iostream>
#include <assert.h>
#include "../detail/concepts_det.hpp"
#include <algorithm>

namespace line
{
  namespace vector
  {
    namespace math
    {
      namespace concepts = detail::concepts;

      // vector + vector = vectorR
      template <concepts::vector T,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      // vector += vector
      template <concepts::vector T,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(T &vecR, const T &vecB, BinaryOp op = {});

      // vector + scalar = vectorR
      template <concepts::vector T, typename U,
                typename BinaryOp = std::plus<typename T::value_type>>
      void
      AddVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector += scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::plus<typename T::value_type>>
      void AddVector(T &vecR, const U &scalar, BinaryOp op = {});

      //------------------------------------------------
      // vector - vector = vectorR
      template <concepts::vector T,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      // vector -= vector
      template <concepts::vector T,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(T &vecR, const T &vecB, BinaryOp op = {});

      // vector - scalar = vectorR
      template <concepts::vector T, typename U,
                typename BinaryOp = std::minus<typename T::value_type>>
      void
      SubVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector -= scalar
      template <concepts::vector T, typename U,
                typename BinaryOp = std::minus<typename T::value_type>>
      void SubVector(T &vecR, const U &scalar, BinaryOp op = {});

      // vector * vector = vectorR
      template <concepts::vector T,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void MulVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op = {});

      // vector *= vector
      template <concepts::vector T,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void MulVector(T &vecR, const T &vecA, BinaryOp op = {});

      // vector * scalar = vectorR
      template <concepts::vector T, typename U,
                typename BinaryOp = std::multiplies<typename T::value_type>>
      void
      MulVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op = {});

      // vector *= scalar
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