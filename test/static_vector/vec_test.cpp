#include <gtest/gtest.h>
#include "../../src/vector/SVec.hpp"
#include <iostream>
#include "fixture_vec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<VecType<2, int>, VecType<2, float>, VecType<2, double>>
  MyVecTypes_2V;

typedef ::testing::Types<VecType<15, int>> MyVecTypes_15V;

typedef ::testing::Types<VecType<1000000, float>, VecType<1000000, double>>
  MyVecTypes_1MV;

// Usa TYPED_TEST_SUITE para definir el caso de prueba
TYPED_TEST_SUITE(Fixture_VecN_2V, MyVecTypes_2V);
TYPED_TEST_SUITE(Fixture_VecN_15V, MyVecTypes_15V);
TYPED_TEST_SUITE(Fixture_VecN_1MV, MyVecTypes_1MV);

//./tests --gtest_filter=Fixture_VecN/.context_test_sum

// access to elements test
TYPED_TEST(Fixture_VecN_2V, AccessToElements)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u{static_cast<U>(8), static_cast<U>(8)};
  ASSERT_EQ(u[0], 8);
  ASSERT_EQ(u[1], 8);
}

// iterators test
TYPED_TEST(Fixture_VecN_2V, Iterators)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u{static_cast<U>(8), static_cast<U>(8)};
  auto it = u.begin();
  auto it2 = u.end();
  ASSERT_EQ(*it, 8);
  ASSERT_EQ(*(it + 1), 8);
  ASSERT_EQ(it2 - it, 2);
  ASSERT_EQ(*u.cbegin(), *u.begin());
  ASSERT_EQ(*u.cend(), *u.end());
}

// u + v = v + u
TYPED_TEST(Fixture_VecN_2V, Commutativity)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2));
  typename TestFixture::Vec result1 = u + v;
  typename TestFixture::Vec result2 = v + u;
  ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_VecN_2V, Associativity)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2));
  typename TestFixture::Vec w(static_cast<U>(3), static_cast<U>(3));
  typename TestFixture::Vec result1 = (u + v) + w;
  typename TestFixture::Vec result2 = u + (v + w);
  ASSERT_EQ(result1, result2);
}

// u + 0 = u
TYPED_TEST(Fixture_VecN_2V, AdditiveIdentity)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  typename TestFixture::Vec zero(static_cast<U>(0), static_cast<U>(0));
  typename TestFixture::Vec result = u + zero;
  ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_VecN_2V, AdditiveInverse)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  typename TestFixture::Vec neg_u(static_cast<U>(8), static_cast<U>(8));
  U c = static_cast<U>(-1);
  typename TestFixture::Vec result = u + (c * neg_u);
  typename TestFixture::Vec zero(static_cast<U>(0), static_cast<U>(0));
  ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_VecN_2V, DistributivityScalarAddition)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2));
  U c = static_cast<U>(2);
  typename TestFixture::Vec result1 = c * (u + v);
  typename TestFixture::Vec result2 = c * u + c * v;
  ASSERT_EQ(result1, result2);
}

// (c + d)u = cu + du
TYPED_TEST(Fixture_VecN_2V, DistributivityScalarMultiplication)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  U c = static_cast<U>(2);
  U d = static_cast<U>(3);
  typename TestFixture::Vec result1 = (c + d) * u;
  typename TestFixture::Vec result2 = (c * u) + (d * u);
  ASSERT_EQ(result1, result2);
}

// c(du) = (cd)u
TYPED_TEST(Fixture_VecN_2V, AssociativityScalarMultiplication)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  U c = static_cast<U>(2);
  U d = static_cast<U>(3);
  typename TestFixture::Vec result1 = c * (d * u);
  typename TestFixture::Vec result2 = (c * d) * u;
  ASSERT_EQ(result1, result2);
}

// 1u = u
TYPED_TEST(Fixture_VecN_2V, MultiplicativeIdentity)
{
  using U = TestFixture::Vec::value_type;

  typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
  U c = static_cast<U>(1);
  typename TestFixture::Vec result = c * u;
  ASSERT_EQ(u, result);
}

// default constructor
TYPED_TEST(Fixture_VecN_15V, DefaultConstructor)
{
  typename TestFixture::Vec u;

  for(auto i = u.begin(); i != u.end(); ++i)
    {
      EXPECT_EQ(*i, 0);
    }
}

// fill constructor
TYPED_TEST(Fixture_VecN_15V, FillConstructor)
{
  typename TestFixture::Vec u(1);
  for(auto i = u.begin(); i != u.end(); ++i)
    {
      EXPECT_EQ(*i, 1);
    }
}

// copy constructor
TYPED_TEST(Fixture_VecN_15V, CopyConstructor)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(u);
  ASSERT_EQ(u, v);
}

// move constructor
TYPED_TEST(Fixture_VecN_15V, MoveConstructor)
{
  typename TestFixture::Vec u(225);
  auto *refdata = u.data();

  typename TestFixture::Vec v(std::move(u));
  auto *refdata2 = v.data();

  ASSERT_EQ(refdata, refdata2);
  ASSERT_FALSE(u.is_valid());
  ASSERT_TRUE(v.is_valid());
}

// list initialization
TYPED_TEST(Fixture_VecN_15V, ListInitialization)
{
  typename TestFixture::Vec u{1, 2,  3,  4,  5,  6,  7, 8,
                              9, 10, 11, 12, 13, 14, 15};
  std::size_t k = 1;
  for(auto i = u.begin(); i != u.end(); ++i)
    {
      EXPECT_EQ(*i, k);
      k++;
    }

  ASSERT_EQ(15, u.max_size());
}

// Argument initialization
TYPED_TEST(Fixture_VecN_15V, ArgumentInitialization)
{
  typename TestFixture::Vec u(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                              15);
  std::size_t k = 1;
  for(auto i = u.begin(); i != u.end(); ++i)
    {
      EXPECT_EQ(*i, k);
      k++;
    }

  ASSERT_EQ(15, u.max_size());
}

// copy assignment
TYPED_TEST(Fixture_VecN_15V, CopyAssignment)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v;
  v = u;
  ASSERT_EQ(u, v);
}

// Prueba con vectores de gran tamaño
TYPED_TEST(Fixture_VecN_1MV, LargeVectorOperations)
{
  constexpr std::size_t large_size = 1000000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);

  typename TestFixture::Vec sum = u + v;
  typename TestFixture::Vec diff = u - v;
  typename TestFixture::Vec prod = u * v;

  // EXPECT_EQ(sum.size(), large_size);
  // EXPECT_EQ(diff.size(), large_size);
  EXPECT_EQ(prod.max_size(), large_size);
}

// Prueba de valores aleatorios con verificación de reversibilidad
TYPED_TEST(Fixture_VecN_1MV, ReversibleOperations)
{
  typename TestFixture::Vec u = TestFixture::random_vector(100);
  typename TestFixture::Vec v = TestFixture::random_vector(100);

  typename TestFixture::Vec sum = u + v;
  typename TestFixture::Vec diff = sum - v;

  ASSERT_EQ(diff, u);
}