namespace line
{
  namespace math
  {
    // del tipo SVec<L, T> donde L es el tamaño del vector y T es el tipo de
    // dato tambien DVec<T> donde T es el tipo de dato
    template <line::detail::concepts::vector T>
    void AddVector(const T &vecA, const T &vecB, T &vecR)
    {
      assert(vecA.size() == vecB.size()
             && "Los vectores no tienen el mismo tamaño");
      assert(vecA.size() == vecR.size()
             && "Los vectores no tienen el mismo tamaño");

#if defined(SIMD_USE_AVX2)
      // proxima  mente se implementara el uso de avx2
#elif defined(SIMD_USE_SSE)
      simd_sse::add(vecA.data(), vecB.data(), vecR.data());
#elif defined(SIMD_USE_SCALAR)
      std::transform(vecA.cbegin(), vecA.cend(), vecB.cbegin(), vecR.begin(),
                     std::plus<typename T::value_type>());
#endif
    }

  }
}