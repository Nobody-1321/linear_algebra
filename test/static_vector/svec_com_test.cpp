#include <gtest/gtest.h>
#include "../../src/vector/SVec.hpp"
#include <iostream>
#include "fixture_svec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<VecType<10000, int>, VecType<10000, float>,
                         VecType<10000, double>>
  MyVecTypes_LV;

TYPED_TEST_SUITE(Fixture_VecN, MyVecTypes_LV);

// u + v = v + u
TYPED_TEST(Fixture_VecN, Commutativity)
{
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);

  typename TestFixture::Vec result1 = u + v;
  typename TestFixture::Vec result2 = v + u;

  ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_VecN, Associativity)
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
TYPED_TEST(Fixture_VecN, AdditiveIdentity)
{
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec zero;

  typename TestFixture::Vec result = u + zero;
  ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_VecN, AdditiveInverse)
{
  using U = TestFixture::Vec::value_type;

  constexpr std::size_t large_size = 10000;

  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec neg_u = static_cast<U>(-1) * u;

  typename TestFixture::Vec result = u + neg_u;
  typename TestFixture::Vec zero;
  ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_VecN, DistributivityScalarAddition)
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
TYPED_TEST(Fixture_VecN, DistributivityScalarMultiplication)
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
TYPED_TEST(Fixture_VecN, AssociativityScalarMultiplication)
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
TYPED_TEST(Fixture_VecN, MultiplicativeIdentity)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  U c = static_cast<U>(1);
  typename TestFixture::Vec result = c * u;
  ASSERT_EQ(u, result);
}
