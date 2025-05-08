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
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR,
                                          std::plus<typename T::value_type>());
        }

        // vector +=  vector
        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        // vector +  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        // scalar += scalar
        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        /// sub operaciones ******************************
        // vector -  vector = vectorR
        template <concepts::vector T, typename F>
        void sub(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOp(
            vecA, vecB, vecR, std::minus<typename T::value_type>());
        }

        // vector -=  vector
        template <concepts::vector T, typename F>
        void sub(T &vecR, const T &vecB, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        // vector -  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void sub(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        // scalar -= scalar
        template <concepts::vector T, typename U, typename F>
        void sub(T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        /// mult operaciones ******************************
        // vector *  vector = vectorR
        template <concepts::vector T, typename F>
        void mul(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOp(
            vecA, vecB, vecR, std::multiplies<typename T::value_type>());
        }

        // vector *=  vector
        template <concepts::vector T, typename F>
        void mul(T &vecR, const T &vecB, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        // vector *  scalar = vectorR
        template <concepts::vector T, typename U, typename F>
        void mul(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        // scalar *= scalar
        template <concepts::vector T, typename U, typename F>
        void mul(T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        // +---------------------------------------------+
        // |                 SSEImpl                     |
        // +---------------------------------------------+

        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::add(vecA.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR,
                                          std::plus<typename T::value_type>());
        }

        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::add(vecR.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::add(vecA.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::add(vecR.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        template <concepts::vector T, typename F>
        void sub(const T &vecA, const T &vecB, T &vecR, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::sub(vecA.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOp(
            vecA, vecB, vecR, std::minus<typename T::value_type>());
        }

        template <concepts::vector T, typename F>
        void sub(T &vecR, const T &vecB, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::sub(vecR.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        template <concepts::vector T, typename U, typename F>
        void sub(const T &vecA, T &vecR, const U &scalar, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::sub(vecA.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        template <concepts::vector T, typename U, typename F>
        void sub(T &vecR, const U &scalar, F &&op, SSEImpl)
        {
          std::cout << "SSEImpl" << std::endl;
          // simd_sse::sub(vecR.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        // AVX2Impl
        //  +---------------------------------------------+
        //  |                 AVX2Impl                    |
        //  +---------------------------------------------+

        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::add(vecA.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR,
                                          std::plus<typename T::value_type>());
        }

        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::add(vecR.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::add(vecA.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::add(vecR.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        template <concepts::vector T, typename F>
        void sub(const T &vecA, const T &vecB, T &vecR, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::sub(vecA.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOp(
            vecA, vecB, vecR, std::minus<typename T::value_type>());
        }

        template <concepts::vector T, typename F>
        void sub(T &vecR, const T &vecB, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::sub(vecR.data(), vecB.data(), vecR.data());
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        template <concepts::vector T, typename U, typename F>
        void sub(const T &vecA, T &vecR, const U &scalar, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::sub(vecA.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        template <concepts::vector T, typename U, typename F>
        void sub(T &vecR, const U &scalar, F &&op, AVX2Impl)
        {
          std::cout << "AVX2Impl" << std::endl;
          // simd_avx2::sub(vecR.data(), scalar, vecR.data());
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }
      }
    }
  }

}