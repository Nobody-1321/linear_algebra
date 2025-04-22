#include <gtest/gtest.h>
#include "../../src/vector/SVec.hpp"
#include <iostream>
#include "fixture_svec.cpp"

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<VecType<10000, long double>, VecType<10000, float>,
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

// scalat and magnitude
// ||p|| = sqrt(p * p)
// ||p|| => 0
// ||p|| = 0 only if p<0,0,0..>
// a||p|| = ||ap||
// ||p + q|| <= ||p|| + ||q|

// Explanation of the issue with integer overflow and precision loss:
//
// 1. Integer Overflow:
//    - When using `int` for calculations involving large vectors or large
//    values,
//      the intermediate results (e.g., the sum of squares in magnitude
//      calculation) can exceed the maximum value that an `int` can represent.
//    - This causes an integer overflow, leading to incorrect results (e.g.,
//    negative values).
//    - To avoid this, we use `long double` or another higher-precision type
//    for intermediate calculations.
//
// 2. Precision Loss in Floating-Point Arithmetic:
//    - Floating-point numbers (e.g., `float`, `double`, `long double`) are
//    represented in a finite
//      precision format, which can lead to small rounding errors during
//      arithmetic operations.
//    - These errors accumulate when performing operations like summing squares
//    or taking square roots.
//    - For example, multiplying or dividing very large and very small numbers
//    can result in a loss of precision.
//    - To mitigate this, we use `long double` for intermediate calculations,
//    as it provides higher precision
//      than `float` or `double`. Additionally, we use `EXPECT_NEAR` in tests
//      to allow for small tolerances when comparing floating-point results.
//
// 3. Why `long double` Solves the Problem:
//    - `long double` has a larger range and higher precision compared to
//    `int`, `float`, or `double`.
//    - It reduces the risk of overflow and minimizes precision loss during
//    intermediate calculations.
//    - By using `long double` for intermediate results and converting back to
//    the desired type (`U`)
//      only at the end, we ensure that the calculations are as accurate as
//      possible.
//
// Example:
//    - Using `int` for magnitude calculation:
//        int val = 0;
//        for (std::size_t i = 0; i < u.max_size(); ++i) {
//            val += u[i] * u[i]; // Risk of overflow here
//        }
//        return std::sqrt(val); // Incorrect result if overflow occurs
//
//    - Using `long double` for magnitude calculation:
//        long double val = 0;
//        for (std::size_t i = 0; i < u.max_size(); ++i) {
//            val += static_cast<long double>(u[i]) * static_cast<long
//            double>(u[i]);
//        }
//        return static_cast<U>(std::sqrt(val)); // Accurate result with
//        reduced precision loss
// 4. Testing with Tolerances:
//    - When comparing floating-point results, direct equality (`EXPECT_EQ`) is
//    often unreliable due to
//      small differences caused by rounding errors.
//    - Instead, we use `EXPECT_NEAR` with a small tolerance (e.g., `1e-3`) to
//    account for these differences
//      and ensure the test passes if the results are "close enough."

TYPED_TEST(Fixture_VecN, MagnitudandScalar)
{
  using U = TestFixture::Vec::value_type;
  constexpr std::size_t large_size = 10000;
  typename TestFixture::Vec u = TestFixture::random_vector(large_size);

  // sum of squares
  U val_ex = 0;

  for(std::size_t i = 0; i < u.size(); ++i)
    {
      val_ex += u[i] * u[i];
    }

  EXPECT_EQ(u.magnitude(), static_cast<U>(std::sqrt(val_ex)))
    << "magnitude does not match";

  // ||p|| => 0
  EXPECT_GE(u.magnitude(), static_cast<U>(0)) << "magnitude is negative";

  // a||p|| = ||ap||

  U a = static_cast<U>(2);
  U result1 = static_cast<U>(a * u.magnitude());

  typename TestFixture::Vec z(a * u);
  U result2 = static_cast<U>(z.magnitude());

  EXPECT_NEAR(result1, result2, 1e-3) << "a||p|| != ||ap||";

  // ||p + q|| <= ||p|| + ||q||
  typename TestFixture::Vec v = TestFixture::random_vector(large_size);
  typename TestFixture::Vec w = u + v;
  U result3 = static_cast<U>(w.magnitude());
  U result4 = static_cast<U>(u.magnitude() + v.magnitude());

  EXPECT_LE(result3, result4) << "||p + q|| > ||p|| + ||q||";
}