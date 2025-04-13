#include <gtest/gtest.h>
#include "../../src/vector/DVec.hpp"
#include <iostream>
#include "fixture_dvec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<DVecType<int>, DVecType<float>, DVecType<double>>
  MyVecTypes;

// Usa TYPED_TEST_SUITE para definir el caso de prueba
TYPED_TEST_SUITE(Fixture_DVec, MyVecTypes);

// +---------------------------------------------+
// |                 Constructors                |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, DefaultConstructor)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u;
  ASSERT_EQ(u.size(), 0);
}

TYPED_TEST(Fixture_DVec, SizeConstructor)
{
  using U = TestFixture::Vec::value_type;
  typename TestFixture::Vec u(10);
  ASSERT_EQ(u.size(), 10);
}

// copy constructor
TYPED_TEST(Fixture_DVec, CopyConstructor)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  Vec v(u);

  ASSERT_EQ(u.size(), v.size()) << "size does not match";

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], v[i]) << "value at position " << i << " does not match";
}

// move constructor
TYPED_TEST(Fixture_DVec, MoveConstructor)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  auto *refdata = u.data();

  Vec v(std::move(u));
  auto *refdata2 = v.data();

  ASSERT_EQ(refdata, refdata2) << "data pointers do not match";
  ASSERT_EQ(v.size(), 10) << "size does not match";
  ASSERT_FALSE(u.is_valid()) << "u should be invalid after move";
  ASSERT_TRUE(v.is_valid()) << "v should be valid after move";

  for(std::size_t i = 0; i < v.size(); ++i)
    EXPECT_EQ(v[i], static_cast<U>(i))
      << "value at position " << i << " does not match";
}

// size and fill constructor
TYPED_TEST(Fixture_DVec, SizeAndFillConstructor)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10, static_cast<U>(5));
  ASSERT_EQ(u.size(), 10) << "size does not match";

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], static_cast<U>(5))
      << "value at position " << i << " does not match";
}

// initializer list constructor
TYPED_TEST(Fixture_DVec, InitializerListConstructor)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u{1, 2, 3, 4, 5};
  ASSERT_EQ(u.size(), 5) << "size does not match";

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], static_cast<U>(i + 1))
      << "value at position " << i << " does not match";
}

// args constructor
TYPED_TEST(Fixture_DVec, ArgsConstructor)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
        static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
        static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
        static_cast<U>(10));

  // capacity

  ASSERT_EQ(u.capacity(), static_cast<std::size_t>(10))
    << "capacity does not match";

  ASSERT_EQ(u.size(), static_cast<std::size_t>(10)) << "size does not match";

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], static_cast<U>(i + 1))
      << "value at position " << i << " does not match";
}

// +---------------------------------------------+
// |           assignment operators              |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, CopyAssignmentOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  Vec v;
  v = u;

  ASSERT_EQ(u.size(), v.size()) << "size does not match";

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], v[i]) << "value at position " << i << " does not match";
}

TYPED_TEST(Fixture_DVec, MoveAssignmentOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  auto *refdata = u.data();

  Vec v;
  v = std::move(u);
  auto *refdata2 = v.data();

  ASSERT_EQ(refdata, refdata2) << "data pointers do not match";
  ASSERT_EQ(v.size(), 10) << "size does not match";
  ASSERT_FALSE(u.is_valid()) << "u should be invalid after move";
  ASSERT_TRUE(v.is_valid()) << "v should be valid after move";

  for(std::size_t i = 0; i < v.size(); ++i)
    EXPECT_EQ(v[i], static_cast<U>(i))
      << "value at position " << i << " does not match";
}

// +---------------------------------------------+
// |           arithmetic operators              |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, AdditionOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  // Case 1: Addition of two vectors
  Vec u(10), v(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    {
      u[i] = static_cast<U>(i);
      v[i] = static_cast<U>(i + 1);
    }

  Vec w = u + v;

  ASSERT_EQ(w.size(), u.size()) << "Vector + Vector: size mismatch";
  for(std::size_t i = 0; i < w.size(); ++i)
    {
      EXPECT_EQ(w[i], static_cast<U>(2 * i + 1))
        << "Vector + Vector: incorrect value at index " << i;
    }

  // Case 2: Addition of vector and scalar
  Vec z{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Vec w2 = z + static_cast<U>(9);

  ASSERT_EQ(w2.size(), z.size()) << "Vector + Scalar: size mismatch";
  for(std::size_t i = 0; i < w2.size(); ++i)
    {
      EXPECT_EQ(w2[i], static_cast<U>(i + 10))
        << "Vector + Scalar: incorrect value at index " << i;
    }

  // Case 3: Compound assignment with scalar (+= scalar)
  z += static_cast<U>(9);
  ASSERT_EQ(z.size(), w2.size()) << "Vector += Scalar: size mismatch";
  for(std::size_t i = 0; i < z.size(); ++i)
    {
      EXPECT_EQ(z[i], static_cast<U>(i + 10))
        << "Vector += Scalar: incorrect value at index " << i;
    }

  // Case 4: Compound assignment with another vector (+= vector)
  Vec a = u;
  a += v;
  ASSERT_EQ(a.size(), u.size()) << "Vector += Vector: size mismatch";
  for(std::size_t i = 0; i < a.size(); ++i)
    {
      EXPECT_EQ(a[i], static_cast<U>(2 * i + 1))
        << "Vector += Vector: incorrect value at index " << i;
    }
}

TYPED_TEST(Fixture_DVec, SubtractionOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  // Case 1: Subtraction of two vectors
  Vec u(10), v(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    {
      u[i] = static_cast<U>(i + 1);
      v[i] = static_cast<U>(i);
    }

  Vec w = u - v;

  ASSERT_EQ(w.size(), u.size()) << "Vector - Vector: size mismatch";
  for(std::size_t i = 0; i < w.size(); ++i)
    {
      EXPECT_EQ(w[i], static_cast<U>(1))
        << "Vector - Vector: incorrect value at index " << i;
    }

  // Case 2: Subtraction of scalar from vector
  Vec z{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Vec w2 = z - static_cast<U>(9);

  ASSERT_EQ(w2.size(), z.size()) << "Vector - Scalar: size mismatch";
  for(std::size_t i = 0; i < w2.size(); ++i)
    {
      EXPECT_EQ(w2[i], static_cast<U>(static_cast<U>(i) - 8))
        << "Vector - Scalar: incorrect value at index " << i;
    }

  // Case 3: Compound assignment with scalar (-= scalar)
  z -= static_cast<U>(9);
  ASSERT_EQ(z.size(), w2.size()) << "Vector -= Scalar: size mismatch";
  for(std::size_t i = 0; i < z.size(); ++i)
    {
      EXPECT_EQ(z[i], static_cast<U>(static_cast<U>(i) - 8))
        << "Vector -= Scalar: incorrect value at index " << i;
    }

  // Case 4: Compound assignment with another vector (-= vector)
  Vec a = u;
  a -= v;
  ASSERT_EQ(a.size(), u.size()) << "Vector -= Vector: size mismatch";
  for(std::size_t i = 0; i < a.size(); ++i)
    {
      EXPECT_EQ(a[i], static_cast<U>(1))
        << "Vector -= Vector: incorrect value at index " << i;
    }
}

TYPED_TEST(Fixture_DVec, MultiplicationOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  // Case 1: Multiplication of two vectors
  Vec u(10), v(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    {
      u[i] = static_cast<U>(i + 1);
      v[i] = static_cast<U>(i + 2);
    }

  Vec w = u * v;

  ASSERT_EQ(w.size(), u.size()) << "Vector * Vector: size mismatch";
  for(std::size_t i = 0; i < w.size(); ++i)
    {
      EXPECT_EQ(w[i], static_cast<U>((i + 1) * (i + 2)))
        << "Vector * Vector: incorrect value at index " << i;
    }

  // Case 2: Multiplication of vector and scalar
  Vec z{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Vec w2 = z * static_cast<U>(2);

  ASSERT_EQ(w2.size(), z.size()) << "Vector * Scalar: size mismatch";
  for(std::size_t i = 0; i < w2.size(); ++i)
    {
      EXPECT_EQ(w2[i],
                static_cast<U>(static_cast<U>(i + 1) * static_cast<U>(2)))
        << "Vector * Scalar: incorrect value at index " << i;
    }

  // Case 3: Compound assignment with scalar (*= scalar)
  z *= static_cast<U>(2);
  ASSERT_EQ(z.size(), w2.size()) << "Vector *= Scalar: size mismatch";
  for(std::size_t i = 0; i < z.size(); ++i)
    {
      EXPECT_EQ(z[i], static_cast<U>(static_cast<U>(i + 1) * static_cast<U>(2)))
        << "Vector *= Scalar: incorrect value at index " << i;
    }

  // Case 4: Compound assignment with another vector (*= vector)
  Vec a = u;
  a *= v;
  ASSERT_EQ(a.size(), u.size()) << "Vector *= Vector: size mismatch";
  for(std::size_t i = 0; i < a.size(); ++i)
    {
      EXPECT_EQ(a[i], static_cast<U>((i + 1) * (i + 2)))
        << "Vector *= Vector: incorrect value at index " << i;
    }
}

TYPED_TEST(Fixture_DVec, DivisionOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  // Case 1: Division of two vectors
  Vec u(10), v(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    {
      u[i] = static_cast<U>(i + 2);
      v[i] = static_cast<U>(i + 1);
    }

  // Case 2: Division of vector by scalar
  Vec z{2, 4, 6, 8, 10};
  Vec w2 = z / static_cast<U>(2);

  ASSERT_EQ(w2.size(), z.size()) << "Vector / Scalar: size mismatch";
  for(std::size_t i = 0; i < w2.size(); ++i)
    {
      EXPECT_EQ(w2[i], static_cast<U>(static_cast<U>(i + 1)))
        << "Vector / Scalar: incorrect value at index " << i;
    }

  // Case 3: Compound assignment with scalar (/= scalar)
  z /= static_cast<U>(2);
  ASSERT_EQ(z.size(), w2.size()) << "Vector /= Scalar: size mismatch";
  for(std::size_t i = 0; i < z.size(); ++i)
    {
      EXPECT_EQ(z[i], static_cast<U>(static_cast<U>(i + 1)))
        << "Vector /= Scalar: incorrect value at index " << i;
    }
}

// +---------------------------------------------+
// |           comparison operators              |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, EqualityOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  Vec v(10);
  for(std::size_t i = 0; i < v.size(); ++i)
    v[i] = static_cast<U>(i);

  EXPECT_TRUE(u == v) << "vectors should be equal";
}

TYPED_TEST(Fixture_DVec, InequalityOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  Vec v(10);
  for(std::size_t i = 0; i < v.size(); ++i)
    v[i] = static_cast<U>(i + 1);

  EXPECT_TRUE(u != v) << "vectors should not be equal";
}

// +---------------------------------------------+
// |           element access operators          |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, SubscriptOperator)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], static_cast<U>(i))
      << "value at position " << i << " does not match";
}

TYPED_TEST(Fixture_DVec, SubscriptOperatorConst)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  const Vec u{0, 1, 2, 3, 4};
  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(u[i], static_cast<U>(i))
      << "value at position " << i << " does not match";
}

TYPED_TEST(Fixture_DVec, DataMethod)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  auto *data = u.data();

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ(data[i], static_cast<U>(i))
      << "value at position " << i << " does not match";
}

// +---------------------------------------------+
// |               iterators                     |
// +---------------------------------------------+

TYPED_TEST(Fixture_DVec, BeginMethod)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  auto it = u.begin();

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ((*it) + i, static_cast<U>(i))
      << "value at position " << i << " does not match";
}

TYPED_TEST(Fixture_DVec, EndMethod)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  Vec u(10);
  for(std::size_t i = 0; i < u.size(); ++i)
    u[i] = static_cast<U>(i);

  auto it = u.end();

  --it; // Move to the last element

  EXPECT_EQ(*it, static_cast<U>(u.size() - 1))
    << "value at last position does not match";
}

TYPED_TEST(Fixture_DVec, BeginMethodConst)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  const Vec u{0, 1, 2, 3, 4};
  auto it = u.cbegin();

  for(std::size_t i = 0; i < u.size(); ++i)
    EXPECT_EQ((*it) + i, static_cast<U>(i))
      << "value at position " << i << " does not match";
}

TYPED_TEST(Fixture_DVec, EndMethodConst)
{
  using Vec = typename TestFixture::Vec;
  using U = typename Vec::value_type;

  const Vec u{0, 1, 2, 3, 4};
  auto it = u.cend();

  --it; // Move to the last element

  EXPECT_EQ(*it, static_cast<U>(u.size() - 1))
    << "value at last position does not match";
}

// +---------------------------------------------+
// |           non-member operators              |
// +---------------------------------------------+
