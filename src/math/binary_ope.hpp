#pragma once
#include <iostream>
#include <assert.h>
#include "../detail/concepts_det.hpp"
#include <functional>
#include <algorithm>

namespace line
{
  namespace vector
  {
    namespace concepts = line::detail::concepts;
    namespace utils
    {

      template <concepts::vector T, typename F>
      void
      ApplyElementwiseBinaryOp(const T &vecA, const T &vecB, T &vecR, F &&op);

      // Operaciones binarias donde el resultado se acumula en el primer
      // operando
      template <concepts::vector T, typename F>
      void ApplyElementwiseBinaryOpInplace(T &vecR, const T &vecB, F &&op);

      // Operaciones entre vector y escalar
      template <concepts::vector T, typename U, typename F>
      void ApplyElementwiseScalarOp(const T &vecA, T &vecR, const U &scalar,
                                    F &&op);

      // Operación escalar inplace
      template <concepts::vector T, typename U, typename F>
      void ApplyElementwiseScalarOpInplace(T &vecR, const U &scalar, F &&op);
    }
  }
}

#include "binary_ope.inl"