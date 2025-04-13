#include <benchmark/benchmark.h>
#include <line/matrix/SMat.hpp>
#include <iostream>

// initialize the matrix
static void BM_mat_plus(benchmark::State &state)
{
  line::structs::SMat<10, 10, float> mat1(1.0f);

  for(auto _ : state)
    {
      for(int i = 0; i < 1000; ++i)
        {
          line::structs::SMat<10, 10, float> mat2;
        }
    }
}

BENCHMARK(BM_mat_plus)->Iterations(1500);

BENCHMARK_MAIN();