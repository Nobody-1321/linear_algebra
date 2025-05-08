namespace line
{
  namespace vector
  {
    namespace math
    {
      // del tipo SVec<L, T> donde L es el tamaño del vector y T es el tipo de
      // dato tambien DVec<T> donde T es el tipo de dato
      template <concepts::vector T, typename BinaryOp>
      void AddVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)

      // template <concepts::vector T>
      // void AddVector(const T &vecA, const T &vecB, T &vecR)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        // proxima  mente se implementara el uso de sse
#elif defined(SIMD_USE_SCALAR)
        // std::transform(vecA.cbegin(), vecA.cend(), vecB.cbegin(),
        // vecR.begin(),
        //                std::plus<typename T::value_type>());
        utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR,
                                        std::plus<typename T::value_type>());
#endif
      }

      template <concepts::vector T, typename BinaryOp>
      void AddVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        // proxima  mente se implementara el uso de sse
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void AddVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        // proxima  mente se implementara el uso de sse
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void AddVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::add(vecR.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename BinaryOp>
      void SubVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::sub(vecA.data(), vecB.data(), vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR, op);
#endif
      }

      template <concepts::vector T, typename BinaryOp>
      void SubVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::sub(vecR.data(), vecB.data(), vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void SubVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::sub(vecA.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void SubVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::sub(vecR.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename BinaryOp>
      void MulVector(const T &vecA, const T &vecB, T &vecR, BinaryOp op)
      {
        assert(vecA.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecA.data(), vecB.data(), vecR.data());
#elif defined(SIMD_USE_SCALAR)
        // std::transform(vecA.cbegin(), vecA.cend(), vecB.cbegin(),
        // vecR.begin(),
        //                std::multiplies<typename T::value_type>());
        utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR, op);

#endif
      }

      template <concepts::vector T, typename BinaryOp>
      void MulVector(T &vecR, const T &vecB, BinaryOp op)
      {
        assert(vecR.size() == vecB.size()
               && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecR.data(), vecB.data(), vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void MulVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecA.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);

#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void MulVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecR.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void DivVector(const T &vecA, T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecA.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecA.data(), scalar, vecR.data());
#elif defined(SIMD_USE_SCALAR)
        utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
#endif
      }

      template <concepts::vector T, typename U, typename BinaryOp>
      void DivVector(T &vecR, const U &scalar, BinaryOp op)
      {
        assert(vecR.size() == vecR.size()
               && "Los vectores no tienen el mismo tamaño");
#if defined(SIMD_USE_AVX2)
        // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
        simd_sse::mul(vecR.data(), scalar, vecR.data());
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