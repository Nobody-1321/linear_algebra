#pragma once

namespace line
{
  namespace simd_scalar
  {

    template <typename T> // transform vector, parman iterators
    void
    transform(T *begin, T *end, T *result, std::function<T(const T &)> func)
    {
      for(T *it = begin; it != end; ++it)
        {
          *result++ = func(*it);
        }
    }

  }
}