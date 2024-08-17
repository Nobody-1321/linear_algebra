#include <gtest/gtest.h>
#include <mat2x2.hpp>
#include "../linearLib/detail/setup_structs.hpp"
#include "fixture_mat.cpp"

//./tests --gtest_filter=Fixture_Mat*/*.*
typedef ::testing::Types<
    MatType<2, 2, int>,
    MatType<2, 2, float>,
    MatType<2, 2, double>
> MyMatTypes_2M;

TYPED_TEST_SUITE(Fixture_Mat2, MyMatTypes_2M);

// (AB)C = A(BC)
TYPED_TEST(Fixture_Mat2, Associativity) {
    typename TestFixture::Mat A{2, 4, 8, 1};
    typename TestFixture::Mat B{7, 5, 1, 0};
    typename TestFixture::Mat C{12, 2, 8, 6};
    typename TestFixture::Mat R1 = (A * B) * C;
    typename TestFixture::Mat R2 = A * (B * C);

    ASSERT_EQ(R1, R2);
}

// (A + B)C = AC + BC
TYPED_TEST(Fixture_Mat2, DistributivityRight) {
    typename TestFixture::Mat A{2, 4, 8, 1};
    typename TestFixture::Mat B{7, 5, 1, 0};
    typename TestFixture::Mat C{12, 2, 8, 6};
    typename TestFixture::Mat R1 = (A + B) * C;
    typename TestFixture::Mat R2 = (A * C) + (B * C);

    ASSERT_EQ(R1, R2);
}

// P(Q + R) = PQ + PR
TYPED_TEST(Fixture_Mat2, DistributivityLeft) {
    typename TestFixture::Mat P{2, 4, 8, 1};
    typename TestFixture::Mat Q{7, 5, 1, 0};
    typename TestFixture::Mat R{12, 2, 8, 6};
    typename TestFixture::Mat R1 = P * (Q + R);
    typename TestFixture::Mat R2 = (P * Q) + (P * R);

    ASSERT_EQ(R1, R2);
}

// k(AB) = (kA)B = A(kB)
TYPED_TEST(Fixture_Mat2, ScalarMultiplicationAssociativity) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat A{2, 4, 8, 1};
    typename TestFixture::Mat B{7, 5, 1, 0};
    T k = 3;
    typename TestFixture::Mat R1 = k * (A * B);
    typename TestFixture::Mat R2 = (k * A) * B;
    typename TestFixture::Mat R3 = A * (k * B);

    ASSERT_EQ(R1, R2);
    ASSERT_EQ(R1, R3);
}


typedef ::testing::Types<
    MatType<3, 3, int>,
    MatType<3, 3, float>,
    MatType<3, 3, double>
> MyMatTypes_3M;

TYPED_TEST_SUITE(Fixture_Mat3, MyMatTypes_3M);

// (AB)C = A(BC)
TYPED_TEST(Fixture_Mat3, Associativity) {
    typename TestFixture::Mat A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    typename TestFixture::Mat B{9, 8, 7, 6, 5, 4, 3, 2, 1};
    typename TestFixture::Mat C{1, 0, 0, 0, 1, 0, 0, 0, 1};
    typename TestFixture::Mat R1 = (A * B) * C;
    typename TestFixture::Mat R2 = A * (B * C);

    ASSERT_EQ(R1, R2);
}

// (A + B)C = AC + BC
TYPED_TEST(Fixture_Mat3, DistributivityRight) {
    typename TestFixture::Mat A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    typename TestFixture::Mat B{9, 8, 7, 6, 5, 4, 3, 2, 1};
    typename TestFixture::Mat C{1, 0, 0, 0, 1, 0, 0, 0, 1};
    typename TestFixture::Mat R1 = (A + B) * C;
    typename TestFixture::Mat R2 = (A * C) + (B * C);

    ASSERT_EQ(R1, R2);
}

// P(Q + R) = PQ + PR
TYPED_TEST(Fixture_Mat3, DistributivityLeft) {
    typename TestFixture::Mat P{1, 2, 3, 4, 5, 6, 7, 8, 9};
    typename TestFixture::Mat Q{9, 8, 7, 6, 5, 4, 3, 2, 1};
    typename TestFixture::Mat R{1, 0, 0, 0, 1, 0, 0, 0, 1};
    typename TestFixture::Mat R1 = P * (Q + R);
    typename TestFixture::Mat R2 = (P * Q) + (P * R);

    ASSERT_EQ(R1, R2);
}

// k(AB) = (kA)B = A(kB)
TYPED_TEST(Fixture_Mat3, ScalarMultiplicationAssociativity) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    typename TestFixture::Mat B{9, 8, 7, 6, 5, 4, 3, 2, 1};
    T k = 3;
    typename TestFixture::Mat R1 = k * (A * B);
    typename TestFixture::Mat R2 = (k * A) * B;
    typename TestFixture::Mat R3 = A * (k * B);

    ASSERT_EQ(R1, R2);
    ASSERT_EQ(R1, R3);
}
