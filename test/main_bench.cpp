#include <benchmark/benchmark.h>
#include <vec2.hpp>
#include <types_vec.hpp>
#include <setup_vec.hpp>
#include <iostream>



static void BM_vec2_copy(benchmark::State& state) {
    line::vec2_f vec1(1.0f, 2.0f);
    line::vec2_f expected(1.0f, 2.0f);

    for (auto _ : state) {
        for (int i = 0; i < 1000; ++i) {
            vec1[0]= expected[0];
            
        }
    }
}

static void BM_vec2_cop(benchmark::State& state) {
    line::vec2_f vec1(1.0f, 2.0f);
    line::vec2_f expected(1.0f, 2.0f);

    for (auto _ : state) {
        for (int i = 0; i < 1000; ++i) {
            vec1[0] = 0;
        }
    }
}

BENCHMARK(BM_vec2_copy)->Iterations(700);
BENCHMARK(BM_vec2_cop)->Iterations(700);


BENCHMARK_MAIN();