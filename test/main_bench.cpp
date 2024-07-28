#include <benchmark/benchmark.h>
#include <vec2.hpp>
#include <types.hpp>
#include <setup.hpp>
#include <iostream>



static void BM_vec2_copy(benchmark::State& state) {
    line::vec2_f vec1(1.0f, 2.0f);
    line::vec2_f expected(1.0f, 2.0f);
    for (auto _ : state) {
        for (int i = 0; i < 1000; ++i) {
            vec1 +  expected;  
        }
    }
}

BENCHMARK(BM_vec2_copy)->Iterations(700);


BENCHMARK_MAIN();