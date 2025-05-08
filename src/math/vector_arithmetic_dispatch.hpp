#pragma once
#include <iostream>
#include <assert.h>
#include "../detail/concepts_det.hpp"
#include "binary_ope.hpp"
#include <functional>
#include <algorithm>

namespace line
{
  namespace vector
  {
    namespace dispatch
    {
      namespace arithmetic
      {
        // +---------------------------------------------+
        // |                ScalarImpl                   |
        // +---------------------------------------------+

        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl);

        // Operaciones binarias donde el resultado se acumula en el primer
        // operando
        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, ScalarImpl);

        // Operaciones entre vector y escalar
        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl);

        // Operación escalar inplace
        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, ScalarImpl);

        // +---------------------------------------------+
        // |                 SSEImpl                     |
        // +---------------------------------------------+
        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, SSEImpl);

        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, SSEImpl);

        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, SSEImpl);

        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, SSEImpl);

      }
    }
  }

}

#include "vector_arithmetic_dispatch.inl"