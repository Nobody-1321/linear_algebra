#include <benchmark/benchmark.h>
#include <vec2.hpp>
#include <types_vec.hpp>
#include <setup_vec.hpp>
#include <iostream>
#include <vec4.hpp>
#include <iterator_vec.hpp>
#include <iterator_cvec.hpp>



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

static void BM_vec2_iterate(benchmark::State& state) {
    line::vec2_f vec1(1.0f, 2.0f);
    
    for (auto _ : state) {
        for (auto it = vec1.begin(); it != vec1.end(); ++it) {
            benchmark::DoNotOptimize(*it);
        }
    }
}


static void BM_vec2_iterate2(benchmark::State& state) {
    line::vec2_f vec1(1.0f, 2.0f);
    
    for (auto _ : state) {
        for (int i = 0; i < vec1.size();  i++) {
            benchmark::DoNotOptimize(vec1[i]);
        }
    }
}

BENCHMARK(BM_vec2_iterate)->Iterations(700);
BENCHMARK(BM_vec2_iterate2)->Iterations(700);
BENCHMARK(BM_vec2_copy)->Iterations(700);
BENCHMARK(BM_vec2_cop)->Iterations(700);


BENCHMARK_MAIN();