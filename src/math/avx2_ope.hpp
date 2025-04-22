#pragma once

namespace line
{
  namespace simd_avx2
  {

    template <typename T, std::size_t N>
    void add(const T *vala, const T *valb, T *valr, std::size_t size)
    {
      for(std::size_t i = 0; i < N; ++i)
        {
          valr[i] = vala[i] + valb[i];
        }
    }

  }
}