cmake_minimum_required(VERSION 3.25)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

include(GoogleTest)

add_executable(tests 
    main_test.cpp
    vec_test.cpp
    fixture_vec.cpp
    #mat_test.cpp
    #fixture_mat.cpp
)

target_link_libraries(tests 
    GTest::GTest 
    GTest::Main
    lineal
)

add_executable(benchmarks 
    main_bench.cpp
)

target_link_libraries(benchmarks 
    benchmark::benchmark
    lineal
)


gtest_discover_tests(tests)

add_test(NAME tests COMMAND ./tests)
