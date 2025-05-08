namespace line
{
  namespace vector
  {
    namespace math
    {
      // vector + vector = vectorR
      template <concepts::vector T, typename BinaryOp>
      void AddVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::add(vecA, vecB, vecR, op, SimdImpl{});
      }

      // vector += vector
      template <concepts::vector T, typename BinaryOp>
      void AddVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::add(vecR, vecB, op, SimdImpl{});
      }

      // vector + scalar = vectorR
      template <concepts::vector T, typename U, typename BinaryOp>
      void AddVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::add(vecA, vecR, scalar, op, SimdImpl{});
      }

      // scalar += scalar
      template <concepts::vector T, typename U, typename BinaryOp>
      void AddVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::add(vecR, scalar, op, SimdImpl{});
      }

      // vector - vector = vectorR
      template <concepts::vector T, typename BinaryOp>
      void SubVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::sub(vecA, vecB, vecR, op, SimdImpl{});
      }

      // vector -= vector
      template <concepts::vector T, typename BinaryOp>
      void SubVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");

        dispatch::arithmetic::sub(vecR, vecB, op, SimdImpl{});
      }

      // vector - scalar = vectorR
      template <concepts::vector T, typename U, typename BinaryOp>
      void SubVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

        dispatch::arithmetic::sub(vecA, vecR, scalar, op, SimdImpl{});
      }

      // scalar -= scalar
      template <concepts::vector T, typename U, typename BinaryOp>
      void SubVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

        dispatch::arithmetic::sub(vecR, scalar, op, SimdImpl{});
      }

      // vector * vector = vectorR
      template <concepts::vector T, typename BinaryOp>
      void MulVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

        dispatch::arithmetic::mul(vecA, vecB, vecR, op, SimdImpl{});
      }

      // vector *= vector
      template <concepts::vector T, typename BinaryOp>
      void MulVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::mul(vecR, vecB, op, SimdImpl{});
      }

      // vector * scalar = vectorR
      template <concepts::vector T, typename U, typename BinaryOp>
      void MulVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::mul(vecA, vecR, scalar, op, SimdImpl{});
      }

      // scalar *= scalar
      template <concepts::vector T, typename U, typename BinaryOp>
      void MulVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
        dispatch::arithmetic::mul(vecR, scalar, op, SimdImpl{});
      }

      // vector / scalar = vectorR
      template <concepts::vector T, typename U, typename BinaryOp>
      void DivVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        // simd_sse::mul(vecA.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
#endif
      }

      // scalar /= scalar
      template <concepts::vector T, typename U, typename BinaryOp>
      void DivVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        // simd_sse::mul(vecR.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        // std::transform(
        //   vecR.begin(), vecR.end(), vecR.begin(),
        //   [scalar](const typename T::value_type &val) { return val / scalar;
        //   });
        utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
#endif
      }

    }
  }
}