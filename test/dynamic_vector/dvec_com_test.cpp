#include <gtest/gtest.h>
#include "../../src/vector/DVec.hpp"
#include <iostream>
#include "fixture_dvec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<DVecType<int>, DVecType<float>, DVecType<double>>
  MyVecTypes_LV;

TYPED_TEST_SUITE(Fixture_DVec, MyVecTypes_LV);

// u + v = v + u
TYPED_TEST(Fixture_DVec, Commutativity)
{
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);

  typename TestFixture::Vec result1 = u + v;
  typename TestFixture::Vec result2 = v + u;

  ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_DVec, Associativity)
{
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);
  typename TestFixture::Vec w = TestFixture::random_vector(large_size);

  typename TestFixture::Vec result1 = (u + v) + w;
  typename TestFixture::Vec result2 = u + (v + w);
  ASSERT_EQ(result1, result2);
}

// u + 0 = u
TYPED_TEST(Fixture_DVec, AdditiveIdentity)
{
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec zero(large_size);

  typename TestFixture::Vec result = u + zero;
  ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_DVec, AdditiveInverse)
{
  using U = TestFixture::Vec::value_type;

  constexpr std::size_t large_size = 10000;

  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec neg_u = static_cast<U>(-1) * u;

  typename TestFixture::Vec result = u + neg_u;
  typename TestFixture::Vec zero(large_size);
  ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_DVec, DistributivityScalarAddition)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;

  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);
  U c = static_cast<U>(2);

  typename TestFixture::Vec result1 = c * (u + v);
  typename TestFixture::Vec result2 = c * u + c * v;

  ASSERT_EQ(result1, result2);
}

// (c + d)u = cu + du
TYPED_TEST(Fixture_DVec, DistributivityScalarMultiplication)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;

  typename TestFixture::Vec u = TestFixture::random_vector(large_size);

  U c = static_cast<U>(2);
  U d = static_cast<U>(3);

  typename TestFixture::Vec result1 = (c + d) * u;
  typename TestFixture::Vec result2 = (c * u) + (d * u);

  ASSERT_EQ(result1, result2);
}

// c(du) = (cd)u
TYPED_TEST(Fixture_DVec, AssociativityScalarMultiplication)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;

  typename TestFixture::Vec u = TestFixture::random_vector(large_size);

  U c = static_cast<U>(2);
  U d = static_cast<U>(3);

  typename TestFixture::Vec result1 = c * (d * u);
  typename TestFixture::Vec result2 = (c * d) * u;

  ASSERT_EQ(result1, result2);
}

// 1u = u
TYPED_TEST(Fixture_DVec, MultiplicativeIdentity)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  U c = static_cast<U>(1);
  typename TestFixture::Vec result = c * u;
  ASSERT_EQ(u, result);
}
