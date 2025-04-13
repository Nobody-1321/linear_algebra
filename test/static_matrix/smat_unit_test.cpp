#include <gtest/gtest.h>
#include "../../src/matrix/SMat.hpp"
#include "../../src/vector/SVec.hpp"
#include "fixture_mat.cpp"

//./tests --gtest_filter=Fixture_Mat*/*.*
typedef ::testing::Types<MatType<2, 2, int>, MatType<2, 2, float>,
                         MatType<2, 2, double>>
  MyMatTypes_2M;

// mat 3x3
typedef ::testing::Types<MatType<3, 3, int>, MatType<3, 3, float>,
                         MatType<3, 3, double>>
  MyMatTypes_3M;

TYPED_TEST_SUITE(Fixture_MatN22, MyMatTypes_2M);
TYPED_TEST_SUITE(Fixture_MatN33, MyMatTypes_3M);

// +---------------------------------------------+
// |                 Constructors                |
// +---------------------------------------------+

// Default constructor
TYPED_TEST(Fixture_MatN22, DefaultConstructor)
{
  using Mat = typename TestFixture::Mat;
  Mat A;
  ASSERT_EQ(A.size_row(), 2);
  ASSERT_EQ(A.size_col(), 2);
}

// Constructor with scalar
TYPED_TEST(Fixture_MatN22, ScalarConstructor)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{static_cast<T>(1)};
  ASSERT_EQ(A.size_row(), 2);
  ASSERT_EQ(A.size_col(), 2);

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(A[i][j], static_cast<T>(1));
        }
    }
}

// copy constructor
TYPED_TEST(Fixture_MatN22, CopyConstructor)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  Mat B(A);

  ASSERT_EQ(A, B);

  ASSERT_EQ(A.size_row(), B.size_row());
  ASSERT_EQ(A.size_col(), B.size_col());

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(A[i][j], B[i][j]);
        }
    }
}

// constructor with multiple arguments
TYPED_TEST(Fixture_MatN22, MultipleArgumentsConstructor)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A(static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4));

  ASSERT_EQ(A.size_row(), 2);
  ASSERT_EQ(A.size_col(), 2);

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(A[i][j], static_cast<T>(i * A.size_col() + j + 1));
        }
    }
}

// move constructor
TYPED_TEST(Fixture_MatN22, MoveConstructor)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  Mat B(std::move(A));

  ASSERT_EQ(B.size_row(), 2);
  ASSERT_EQ(B.size_col(), 2);

  for(std::size_t i = 0; i < B.size_row(); ++i)
    {
      for(std::size_t j = 0; j < B.size_col(); ++j)
        {
          ASSERT_EQ(B[i][j], static_cast<T>(i * B.size_col() + j + 1));
        }
    }
}

// list constructor
TYPED_TEST(Fixture_MatN22, ListConstructor)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{{static_cast<T>(1), static_cast<T>(2)},
        {static_cast<T>(3), static_cast<T>(4)}};

  ASSERT_EQ(A.size_row(), 2);
  ASSERT_EQ(A.size_col(), 2);

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(A[i][j], static_cast<T>(i * A.size_col() + j + 1));
        }
    }
}

// +---------------------------------------------+
// |           assignment operators              |
// +---------------------------------------------+

// copy assignment operator
TYPED_TEST(Fixture_MatN22, CopyAssignmentOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  Mat B{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};
  B = A;

  ASSERT_EQ(A, B);
}

// move assignment operator
TYPED_TEST(Fixture_MatN22, MoveAssignmentOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;
  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  Mat B{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};
  B = std::move(A);

  ASSERT_EQ(B.size_row(), 2);
  ASSERT_EQ(B.size_col(), 2);

  for(std::size_t i = 0; i < B.size_row(); ++i)
    {
      for(std::size_t j = 0; j < B.size_col(); ++j)
        {
          ASSERT_EQ(B[i][j], static_cast<T>(i * B.size_col() + j + 1));
        }
    }
}

// +---------------------------------------------+
// |           arithmetic operators              |
// +---------------------------------------------+

// addition operator
TYPED_TEST(Fixture_MatN22, AdditionOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  Mat B{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};

  Mat R{static_cast<T>(6), static_cast<T>(8), static_cast<T>(10),
        static_cast<T>(12)};

  Mat C = A + B;

  ASSERT_EQ(C.size_row(), 2);
  ASSERT_EQ(C.size_col(), 2);

  for(std::size_t i = 0; i < C.size_row(); ++i)
    {
      for(std::size_t j = 0; j < C.size_col(); ++j)
        {
          ASSERT_EQ(C[i][j], R[i][j]);
        }
    }

  Mat Z({static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
         static_cast<T>(4)});

  Z += B;

  ASSERT_EQ(Z.size_row(), 2);
  ASSERT_EQ(Z.size_col(), 2);

  for(std::size_t i = 0; i < Z.size_row(); ++i)
    {
      for(std::size_t j = 0; j < Z.size_col(); ++j)
        {
          ASSERT_EQ(Z[i][j], R[i][j]);
        }
    }

  Mat J({static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
         static_cast<T>(4)});

  J = A + static_cast<T>(5);

  ASSERT_EQ(J.size_row(), 2);
  ASSERT_EQ(J.size_col(), 2);

  for(std::size_t i = 0; i < J.size_row(); ++i)
    {
      for(std::size_t j = 0; j < J.size_col(); ++j)
        {
          ASSERT_EQ(J[i][j], static_cast<T>(i * J.size_col() + j + 6));
        }
    }

  Mat K({static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
         static_cast<T>(4)});

  K += static_cast<T>(5);

  ASSERT_EQ(K.size_row(), 2);
  ASSERT_EQ(K.size_col(), 2);

  for(std::size_t i = 0; i < K.size_row(); ++i)
    {
      for(std::size_t j = 0; j < K.size_col(); ++j)
        {
          ASSERT_EQ(K[i][j], static_cast<T>(i * K.size_col() + j + 6));
        }
    }
}

// subtraction operator
TYPED_TEST(Fixture_MatN22, SubtractionOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};

  Mat B{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  Mat R{static_cast<T>(4), static_cast<T>(4), static_cast<T>(4),
        static_cast<T>(4)};

  // A - B
  Mat C = A - B;
  ASSERT_EQ(C.size_row(), 2);
  ASSERT_EQ(C.size_col(), 2);

  for(std::size_t i = 0; i < C.size_row(); ++i)
    {
      for(std::size_t j = 0; j < C.size_col(); ++j)
        {
          ASSERT_EQ(C[i][j], R[i][j]);
        }
    }

  // A -= B
  Mat Z({static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
         static_cast<T>(8)});

  Z -= B;

  ASSERT_EQ(Z.size_row(), 2);
  ASSERT_EQ(Z.size_col(), 2);

  for(std::size_t i = 0; i < Z.size_row(); ++i)
    {
      for(std::size_t j = 0; j < Z.size_col(); ++j)
        {
          ASSERT_EQ(Z[i][j], R[i][j]);
        }
    }

  // A - escalar
  Mat J({static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
         static_cast<T>(8)});

  J = A - static_cast<T>(1);

  ASSERT_EQ(J.size_row(), 2);
  ASSERT_EQ(J.size_col(), 2);

  for(std::size_t i = 0; i < J.size_row(); ++i)
    {
      for(std::size_t j = 0; j < J.size_col(); ++j)
        {
          ASSERT_EQ(J[i][j], static_cast<T>(i * J.size_col() + j + 4));
        }
    }

  // A -= escalar
  Mat K({static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
         static_cast<T>(8)});

  K -= static_cast<T>(1);

  ASSERT_EQ(K.size_row(), 2);
  ASSERT_EQ(K.size_col(), 2);

  for(std::size_t i = 0; i < K.size_row(); ++i)
    {
      for(std::size_t j = 0; j < K.size_col(); ++j)
        {
          ASSERT_EQ(K[i][j], static_cast<T>(i * K.size_col() + j + 4));
        }
    }
}

// multiplication operator
TYPED_TEST(Fixture_MatN33, MultiplicationOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4), static_cast<T>(5), static_cast<T>(6),
        static_cast<T>(7), static_cast<T>(8), static_cast<T>(9)};

  Mat B{static_cast<T>(5),  static_cast<T>(6),  static_cast<T>(7),
        static_cast<T>(8),  static_cast<T>(9),  static_cast<T>(10),
        static_cast<T>(11), static_cast<T>(12), static_cast<T>(13)};

  Mat R{static_cast<T>(54),  static_cast<T>(60),  static_cast<T>(66),
        static_cast<T>(126), static_cast<T>(141), static_cast<T>(156),
        static_cast<T>(198), static_cast<T>(222), static_cast<T>(246)};

  // A * B
  Mat C = A * B;
  ASSERT_EQ(C.size_row(), 3);
  ASSERT_EQ(C.size_col(), 3);

  for(std::size_t i = 0; i < C.size_row(); ++i)
    {
      for(std::size_t j = 0; j < C.size_col(); ++j)
        {
          ASSERT_EQ(C[i][j], R[i][j]);
        }
    }

  // z B * A

  Mat RR({static_cast<T>(78), static_cast<T>(96), static_cast<T>(114),
          static_cast<T>(114), static_cast<T>(141), static_cast<T>(168),
          static_cast<T>(150), static_cast<T>(186), static_cast<T>(222)});

  Mat Z(B * A);

  ASSERT_EQ(Z.size_row(), 3);
  ASSERT_EQ(Z.size_col(), 3);

  for(std::size_t i = 0; i < Z.size_row(); ++i)
    {
      for(std::size_t j = 0; j < Z.size_col(); ++j)
        {
          ASSERT_EQ(Z[i][j], RR[i][j]);
        }
    }

  Mat K;
  K = B * A;

  ASSERT_EQ(K.size_row(), 3);
  ASSERT_EQ(K.size_col(), 3);

  for(std::size_t i = 0; i < K.size_row(); ++i)
    {
      for(std::size_t j = 0; j < K.size_col(); ++j)
        {
          ASSERT_EQ(K[i][j], RR[i][j]);
        }
    }

  // A * escalar
  Mat J(Mat(5) * static_cast<T>(5));

  ASSERT_EQ(J.size_row(), 3);
  ASSERT_EQ(J.size_col(), 3);

  for(std::size_t i = 0; i < J.size_row(); ++i)
    {
      for(std::size_t j = 0; j < J.size_col(); ++j)
        {
          ASSERT_EQ(J[i][j], static_cast<T>(25));
        }
    }

  // A *= escalar
  Mat P(5);
  P *= static_cast<T>(5);

  ASSERT_EQ(K.size_row(), 3);
  ASSERT_EQ(K.size_col(), 3);

  for(std::size_t i = 0; i < P.size_row(); ++i)
    {
      for(std::size_t j = 0; j < P.size_col(); ++j)
        {
          ASSERT_EQ(P[i][j], static_cast<T>(25));
        }
    }
}

// +---------------------------------------------+
// |           element access operators          |
// +---------------------------------------------+

// +---------------------------------------------+
// |           comparison operators              |
// +---------------------------------------------+

TYPED_TEST(Fixture_MatN22, ComparisonOperator)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  Mat B{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  ASSERT_EQ(A, B);

  Mat C{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};

  ASSERT_NE(A, C);
}

// +---------------------------------------------+
// |               functions                     |
// +---------------------------------------------+

TYPED_TEST(Fixture_MatN22, SizeFunctions)
{
  using Mat = typename TestFixture::Mat;

  Mat A;
  ASSERT_EQ(A.size_row(), 2);
  ASSERT_EQ(A.size_col(), 2);
  ASSERT_TRUE(A.is_square());
}

TYPED_TEST(Fixture_MatN22, FillFunction)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};
  A.fill(static_cast<T>(5));

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(A[i][j], static_cast<T>(5));
        }
    }
}

TYPED_TEST(Fixture_MatN22, SwapFunction)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  Mat B{static_cast<T>(5), static_cast<T>(6), static_cast<T>(7),
        static_cast<T>(8)};

  A.swap(B);

  for(std::size_t i = 0; i < A.size_row(); ++i)
    {
      for(std::size_t j = 0; j < A.size_col(); ++j)
        {
          ASSERT_EQ(B[i][j], static_cast<T>(i * B.size_col() + j + 1));
        }
    }
}

// +---------------------------------------------+
// |               iterators                     |
// +---------------------------------------------+

TYPED_TEST(Fixture_MatN22, Iterators)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  std::size_t i = 0;
  for(auto it = A.begin(); it != A.end(); ++it)
    {
      // Si *it es un SVec, accede a sus elementos
      const auto &vec = *it; // Suponiendo que *it devuelve un SVec
      for(std::size_t j = 0; j < vec.max_size(); ++j)
        {
          ASSERT_EQ(vec[j], static_cast<T>(i + 1));
          ++i;
        }
    }
}

TYPED_TEST(Fixture_MatN22, ConstIterators)
{
  using Mat = typename TestFixture::Mat;
  using T = typename Mat::value_type;

  Mat A{static_cast<T>(1), static_cast<T>(2), static_cast<T>(3),
        static_cast<T>(4)};

  std::size_t i = 0;
  for(auto it = A.cbegin(); it != A.cend(); ++it)
    {
      // Si *it es un SVec, accede a sus elementos
      const auto &vec = *it; // Suponiendo que *it devuelve un SVec
      for(std::size_t j = 0; j < vec.max_size(); ++j)
        {
          ASSERT_EQ(vec[j], static_cast<T>(i + 1));
          ++i;
        }
    }
}

// +---------------------------------------------+
// |           non-member operators              |
// +---------------------------------------------+
