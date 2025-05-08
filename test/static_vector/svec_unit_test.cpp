#include <gtest/gtest.h>
#include "../../src/vector/SVec.hpp"
#include <iostream>
#include "fixture_svec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<VecType<2, int>, VecType<2, float>, VecType<2, double>>
  MyVecTypes_2V;

typedef ::testing::Types<VecType<15, int>> MyVecTypes_15V;

// Usa TYPED_TEST_SUITE para definir el caso de prueba
TYPED_TEST_SUITE(Fixture_VecN_2V, MyVecTypes_2V);
TYPED_TEST_SUITE(Fixture_VecN_15V, MyVecTypes_15V);

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

// +---------------------------------------------+
// |                 Constructors                |
// +---------------------------------------------+

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

  ASSERT_EQ(15, u.size());
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

  ASSERT_EQ(15, u.size());
}

// +---------------------------------------------+
// |           assignment operators              |
// +---------------------------------------------+

// copy assignment
TYPED_TEST(Fixture_VecN_15V, CopyAssignment)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v;
  v = u;
  ASSERT_EQ(u, v);
}

// move assignment
TYPED_TEST(Fixture_VecN_15V, MoveAssignment)
{
  typename TestFixture::Vec u(225);
  auto *refdata = u.data();

  typename TestFixture::Vec v;
  v = std::move(u);
  auto *refdata2 = v.data();

  ASSERT_EQ(refdata, refdata2);
  ASSERT_FALSE(u.is_valid());
  ASSERT_TRUE(v.is_valid());
}

// +---------------------------------------------+
// |           arithmetic operators              |
// +---------------------------------------------+

// Addition operator tests
TYPED_TEST(Fixture_VecN_15V, AdditionOperator)
{
  using Vec = typename TestFixture::Vec;
  using T = typename Vec::value_type;

  // Test: vector + vector
  Vec u(1);      // [1]
  Vec v(2);      // [2]
  Vec w = u + v; // [3]
  ASSERT_EQ(w[0], 3) << "u + v failed";

  // Test: vector += vector
  Vec a(5); // [5]
  Vec b(7); // [7]
  a += b;   // a = [12]
  ASSERT_EQ(a[0], 12) << "a += b failed";

  // Test: scalar + vector
  Vec c(8);         // [8]
  Vec d = T(4) + c; // [12]
  ASSERT_EQ(d[0], 12) << "scalar + vector failed";

  /*
      // Test: vector + scalar
      Vec e(3);         // [3]
      Vec f = e + T(9); // [12]
      ASSERT_EQ(f[0], 12) << "vector + scalar failed";

      // Test: vector += scalar
      Vec g(10); // [10]
      g += T(5); // [15]
      ASSERT_EQ(g[0], 15) << "vector += scalar failed";
      */
}

// Subtraction operator tests
TYPED_TEST(Fixture_VecN_15V, SubtractionOperator)
{
  using Vec = typename TestFixture::Vec;
  using T = typename Vec::value_type;

  // Test: vector - vector
  Vec u(5);      // [5]
  Vec v(2);      // [2]
  Vec w = u - v; // [3]
  ASSERT_EQ(w[0], 3) << "u - v failed";

  // Test: vector -= vector
  Vec a(10); // [10]
  Vec b(7);  // [7]
  a -= b;    // a = [3]
  ASSERT_EQ(a[0], 3) << "a -= b failed";

  // Test: scalar - vector
  Vec c(8);          // [8]
  Vec d = T(12) - c; // [4]
  ASSERT_EQ(d[0], 4) << "scalar - vector failed";

  // Test: vector - scalar
  Vec e(10);        // [10]
  Vec f = e - T(5); // [5]
  ASSERT_EQ(f[0], 5) << "vector - scalar failed";

  // Test: vector -= scalar
  Vec g(15); // [15]
  g -= T(5); // [10]
  ASSERT_EQ(g[0], 10) << "vector -= scalar failed";
}

// Multiplication operator tests
TYPED_TEST(Fixture_VecN_15V, MultiplicationOperator)
{
  using Vec = typename TestFixture::Vec;
  using T = typename Vec::value_type;

  // Test: vector * vector
  Vec u(2);      // [2]
  Vec v(3);      // [3]
  Vec w = u * v; // [6]
  ASSERT_EQ(w[0], 6) << "u * v failed";

  // Test: vector *= vector
  Vec a(5); // [5]
  Vec b(7); // [7]
  a *= b;   // a = [35]
  ASSERT_EQ(a[0], 35) << "a *= b failed";

  // Test: scalar * vector
  Vec c(4);         // [4]
  Vec d = T(3) * c; // [12]
  ASSERT_EQ(d[0], 12) << "scalar * vector failed";

  // Test: vector * scalar
  Vec e(6);         // [6]
  Vec f = e * T(2); // [12]
  ASSERT_EQ(f[0], 12) << "vector * scalar failed";

  // Test: vector *= scalar
  Vec g(8);  // [8]
  g *= T(3); // [24]
  ASSERT_EQ(g[0], 24) << "vector *= scalar failed";
}

// Division operator tests
// Division operator tests
TYPED_TEST(Fixture_VecN_15V, DivisionByScalarOperator)
{
  using Vec = typename TestFixture::Vec;
  using T = typename Vec::value_type;

  // Test: vector / scalar
  Vec u(10);        // [10]
  Vec v = u / T(2); // [5]
  ASSERT_EQ(v[0], 5) << "vector / scalar failed";

  // Test: vector /= scalar
  Vec w(12); // [12]
  w /= T(3); // [4]
  ASSERT_EQ(w[0], 4) << "vector /= scalar failed";
}

// +---------------------------------------------+
// |           comparison operators              |
// +---------------------------------------------+

// Equality operator
TYPED_TEST(Fixture_VecN_15V, EqualityOperator)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(1);
  ASSERT_EQ(u, v);
}

// Inequality operator
TYPED_TEST(Fixture_VecN_15V, InequalityOperator)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(2);
  ASSERT_NE(u, v);
}

// +---------------------------------------------+
// |           element access operators          |
// +---------------------------------------------+
// Subscript operator
TYPED_TEST(Fixture_VecN_15V, SubscriptOperator)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(2);
  ASSERT_EQ(u[0], 1);
  ASSERT_EQ(v[0], 2);
}

// Data method
TYPED_TEST(Fixture_VecN_15V, DataMethod)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(2);
  auto *data_u = u.data();
  auto *data_v = v.data();
  ASSERT_EQ(data_u[0], 1);
  ASSERT_EQ(data_v[0], 2);
}

// +---------------------------------------------+
// |               iterators                     |
// +---------------------------------------------+

// Begin method
TYPED_TEST(Fixture_VecN_15V, BeginMethod)
{
  typename TestFixture::Vec u(1);
  auto it = u.begin();
  ASSERT_EQ(*it, 1);
}

// End method
TYPED_TEST(Fixture_VecN_15V, EndMethod)
{
  typename TestFixture::Vec u(1);
  auto it = u.end();
  ASSERT_EQ(*(it - 1), 1);
}

// Cbegin method
TYPED_TEST(Fixture_VecN_15V, CbeginMethod)
{
  typename TestFixture::Vec u(1);
  auto it = u.cbegin();
  ASSERT_EQ(*it, 1);
}

// Cend method
TYPED_TEST(Fixture_VecN_15V, CendMethod)
{
  typename TestFixture::Vec u(1);
  auto it = u.cend();
  ASSERT_EQ(*(it - 1), 1);
}

// +---------------------------------------------+
// |              functions                      |
// +---------------------------------------------+

// Fill method
TYPED_TEST(Fixture_VecN_15V, FillMethod)
{
  typename TestFixture::Vec u(1);
  u.fill(5);
  for(auto i = u.begin(); i != u.end(); ++i)
    {
      EXPECT_EQ(*i, 5);
    }
}
// Swap method
TYPED_TEST(Fixture_VecN_15V, SwapMethod)
{
  typename TestFixture::Vec u(1);
  typename TestFixture::Vec v(2);
  u.swap(v);
  ASSERT_EQ(u[0], 2);
  ASSERT_EQ(v[0], 1);
}

// Is valid method
TYPED_TEST(Fixture_VecN_15V, IsValidMethod)
{
  using Vec = typename TestFixture::Vec;

  Vec u(1);
  ASSERT_TRUE(u.is_valid());

  Vec v(std::move(u));
  ASSERT_FALSE(u.is_valid());
}

// Magnitude method

TYPED_TEST(Fixture_VecN_2V, MagnitudeMethod)
{
  using Vec = typename TestFixture::Vec;
  using T = typename Vec::value_type;

  Vec u(3);

  T val_ex = 3 * 3 + 3 * 3;

  ASSERT_EQ(u.magnitude(), static_cast<T>(std::sqrt(val_ex)));
}

// +---------------------------------------------+
// |           non-member operators              |
// +---------------------------------------------+