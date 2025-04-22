#pragma once
#include <cstddef>
#include <iostream>
namespace line
{
  namespace simd_sse
  {

    template <typename T> void add(const T *vala, const T *valb, T *valr)
    {
      std::cout << "SSE2 ssssssssssss" << std::endl;
    }

  }
}