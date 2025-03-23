#include <gtest/gtest.h>
#include "../../src/vector/SVec.hpp"
#include <random>

template <typename U> struct TestValues
{
  static U zero() { return static_cast<U>(0); }
  static U scalarOne() { return static_cast<U>(1); }
  static U scalarNegOne() { return static_cast<U>(-1); }
};

template <int N, typename T> struct VecType
{
  using type = line::structs::SVec<N, T>;
};

template <typename VecType> class Fixture_VecN_2V : public ::testing::Test
{
public:
  using Vec = typename VecType::type;
};

template <typename VecType> class Fixture_VecN_15V : public ::testing::Test
{
public:
  using Vec = typename VecType::type;
};

template <typename VecType> class Fixture_VecN_1MV : public ::testing::Test
{
public:
  using Vec = typename VecType::type;

  static Vec
  random_vector(std::size_t size, int min_val = -1000, int max_val = 1000)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min_val, max_val);

    Vec vec;
    for(std::size_t i = 0; i < size; ++i)
      {
        vec[i] = static_cast<typename Vec::value_type>(dist(gen));
      }
    return vec;
  }
};
