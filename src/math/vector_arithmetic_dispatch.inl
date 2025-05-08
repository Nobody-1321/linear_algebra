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
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOp(vecA, vecB, vecR,
                                          std::plus<typename T::value_type>());
        }

        // Operaciones binarias donde el resultado se acumula en el primer
        // operando
        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseBinaryOpInplace(vecR, vecB, op);
        }

        // Operaciones entre vector y escalar
        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOp(vecA, vecR, scalar, op);
        }

        // Operación escalar inplace
        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, ScalarImpl)
        {
          utils::ApplyElementwiseScalarOpInplace(vecR, scalar, op);
        }

        // +---------------------------------------------+
        // |                 SSEImpl                     |
        // +---------------------------------------------+

        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, SSEImpl)
        {}

        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, SSEImpl)
        {}

        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, SSEImpl)
        {}

        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, SSEImpl)
        {}

        // AVX2Impl
        //  +---------------------------------------------+
        //  |                 AVX2Impl                    |
        //  +---------------------------------------------+

        template <concepts::vector T, typename F>
        void add(const T &vecA, const T &vecB, T &vecR, F &&op, AVX2Impl)
        {}
        template <concepts::vector T, typename F>
        void add(T &vecR, const T &vecB, F &&op, AVX2Impl)
        {}
        template <concepts::vector T, typename U, typename F>
        void add(const T &vecA, T &vecR, const U &scalar, F &&op, AVX2Impl)
        {}

        template <concepts::vector T, typename U, typename F>
        void add(T &vecR, const U &scalar, F &&op, AVX2Impl)
        {}

      }
    }
  }

}