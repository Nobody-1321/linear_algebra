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

        // vector +  vector = vectorR
        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl);

        // vector +=  vector
        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, ScalarImpl);

        // vector +  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl);

        // scalar += scalar
        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, ScalarImpl);

        /// sub operaciones ******************************
        // vector -  vector = vectorR
        template <concepts::vector T, typename F>
        void sub(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl);

        // vector -=  vector
        template <concepts::vector T, typename F>
        void sub(T &vecR, const T &vecB, F &&op, ScalarImpl);

        // vector -  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void sub(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl);

        // scalar -= scalar
        template <concepts::vector T, typename U, typename F>
        void sub(T &vecR, const U &scalar, F &&op, ScalarImpl);

        /// mult operaciones ******************************
        // vector *  vector = vectorR
        template <concepts::vector T, typename F>
        void mul(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl);

        // vector *=  vector
        template <concepts::vector T, typename F>
        void mul(T &vecR, const T &vecB, F &&op, ScalarImpl);

        // vector *  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void mul(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl);

        // scalar *= scalar
        template <concepts::vector T, typename U, typename F>
        void mul(T &vecR, const U &scalar, F &&op, ScalarImpl);

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