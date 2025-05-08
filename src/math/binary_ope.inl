namespace line
{
  namespace vector
  {
    namespace utils
    {
      namespace concepts = line::detail::concepts;
      template <concepts::vector T, typename F>
      void
      ApplyElementwiseBinaryOp(const T &vecA, const T &vecB, T &vecR, F &&op)
      {
        assert(vecA.size() == vecB.size());
        assert(vecA.size() == vecR.size());

        std::transform(vecA.cbegin(), vecA.cend(), vecB.cbegin(), vecR.begin(),
                       std::forward<F>(op));
      }

      // Operaciones binarias donde el resultado se acumula en el primer operando
      template <concepts::vector T, typename F>
      void ApplyElementwiseBinaryOpInplace(T &vecR, const T &vecB, F &&op)
      {
        assert(vecR.size() == vecB.size());

        std::transform(vecR.begin(), vecR.end(), vecB.cbegin(), vecR.begin(),
                       std::forward<F>(op));
      }

      // Operaciones entre vector y escalar
      template <concepts::vector T, typename U, typename F>
      void
      ApplyElementwiseScalarOp(const T &vecA, T &vecR, const U &scalar, F &&op)
      {
        assert(vecA.size() == vecR.size());

        std::transform(vecA.cbegin(), vecA.cend(), vecR.begin(),
                       std::forward<F>(op));
      }

      // Operación escalar inplace
      template <concepts::vector T, typename U, typename F>
      void ApplyElementwiseScalarOpInplace(T &vecR, const U &scalar, F &&op)
      {
        std::transform(vecR.begin(), vecR.end(), vecR.begin(),
                       std::forward<F>(op));
      }

    }
  }
}