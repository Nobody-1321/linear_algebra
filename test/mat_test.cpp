#include <gtest/gtest.h>
#include <mat.hpp>
#include "../linearLib/detail/setup_structs.hpp"
#include "../linearLib/detail/types_d.hpp"
#include "fixture_mat.cpp"

//./tests --gtest_filter=Fixture_Mat*/*.*
typedef ::testing::Types<
    MatType<2, 2, int>,
    MatType<2, 2, float>,
    MatType<2, 2, double>
> MyMatTypes_2M;

TYPED_TEST_SUITE(Fixture_MatN, MyMatTypes_2M);


// (AB)C = A(BC)
TYPED_TEST(Fixture_MatN, Associativity) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat A{static_cast<T>(2), static_cast<T>(4), static_cast<T>(8), static_cast<T>(1)};
    typename TestFixture::Mat B{static_cast<T>(7), static_cast<T>(5), static_cast<T>(1), static_cast<T>(0)};
    typename TestFixture::Mat C{static_cast<T>(12), static_cast<T>(2), static_cast<T>(8), static_cast<T>(6)};
    typename TestFixture::Mat R1 = (A * B) * C;
    typename TestFixture::Mat R2 = A * (B * C);

    ASSERT_EQ(R1, R2);
}

// (A + B)C = AC + BC
TYPED_TEST(Fixture_MatN, DistributivityRight) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat A{static_cast<T>(2), static_cast<T>(4), static_cast<T>(8), static_cast<T>(1)};
    typename TestFixture::Mat B{static_cast<T>(7), static_cast<T>(5), static_cast<T>(1), static_cast<T>(0)};
    typename TestFixture::Mat C{static_cast<T>(12), static_cast<T>(2), static_cast<T>(8), static_cast<T>(6)};
    typename TestFixture::Mat R1 = (A + B) * C;
    typename TestFixture::Mat R2 = (A * C) + (B * C);

    ASSERT_EQ(R1, R2);
}

// P(Q + R) = PQ + PR
TYPED_TEST(Fixture_MatN, DistributivityLeft) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat P{static_cast<T>(2), static_cast<T>(4), static_cast<T>(8), static_cast<T>(1)};
    typename TestFixture::Mat Q{static_cast<T>(7), static_cast<T>(5), static_cast<T>(1), static_cast<T>(0)};
    typename TestFixture::Mat R{static_cast<T>(12), static_cast<T>(2), static_cast<T>(8), static_cast<T>(6)};
    typename TestFixture::Mat R1 = P * (Q + R);
    typename TestFixture::Mat R2 = (P * Q) + (P * R);

    ASSERT_EQ(R1, R2);
}

// k(AB) = (kA)B = A(kB)
TYPED_TEST(Fixture_MatN, ScalarMultiplicationAssociativity) {
    using T = typename TestFixture::Mat::value_type;
    typename TestFixture::Mat A{static_cast<T>(2), static_cast<T>(4), static_cast<T>(8), static_cast<T>(1)};
    typename TestFixture::Mat B{static_cast<T>(7), static_cast<T>(5), static_cast<T>(1), static_cast<T>(0)};
    T k = static_cast<T>(3);
    typename TestFixture::Mat R1 = k * (A * B);
    typename TestFixture::Mat R2 = (k * A) * B;
    typename TestFixture::Mat R3 = A * (k * B);

    ASSERT_EQ(R1, R2);
    ASSERT_EQ(R1, R3);
}


typedef ::testing::Types<
    line::mat<5, 2, int>,
    line::mat<5, 2, float>,
    line::mat<5, 2, double>
> MyMatTypes_5x2;


TYPED_TEST_SUITE(Fixture_MatN1, MyMatTypes_5x2);

TYPED_TEST(Fixture_MatN1, ScalarMultiplication) {
    using Mat = typename TestFixture::Mat;
    using T = typename Mat::value_type;

    // Usando static_cast para asegurar que los valores sean del tipo correcto
    Mat A{
        static_cast<T>(1), static_cast<T>(2), static_cast<T>(3), static_cast<T>(4), static_cast<T>(5),
        static_cast<T>(6), static_cast<T>(7), static_cast<T>(8), static_cast<T>(9), static_cast<T>(10)
    };
    
    T scalar = static_cast<T>(2);
    Mat result = A * scalar;

    // Usando static_cast para la matriz esperada también
    Mat expected{
        static_cast<T>(2),  static_cast<T>(4),
        static_cast<T>(6),  static_cast<T>(8),
        static_cast<T>(10), static_cast<T>(12),
        static_cast<T>(14), static_cast<T>(16),
        static_cast<T>(18), static_cast<T>(20)
    };

    ASSERT_EQ(result, expected);
}

/*

// Test de Suma de Matrices
TYPED_TEST(Fixture_MatN1, MatrixAddition) {
    using Mat = typename TestFixture::Mat;
    using T = typename Mat::value_type;

    // Usando static_cast para asegurar que los valores sean del tipo correcto
    Mat A{
        static_cast<T>(1), static_cast<T>(2), static_cast<T>(3), static_cast<T>(4), static_cast<T>(5),
        static_cast<T>(6), static_cast<T>(7), static_cast<T>(8), static_cast<T>(9), static_cast<T>(10)
    };
    Mat B{
        static_cast<T>(10), static_cast<T>(9), static_cast<T>(8), static_cast<T>(7), static_cast<T>(6),
        static_cast<T>(5), static_cast<T>(4), static_cast<T>(3), static_cast<T>(2), static_cast<T>(1)
    };
    Mat result = A + B;

    Mat expected{
        static_cast<T>(11), static_cast<T>(11),
        static_cast<T>(11), static_cast<T>(11),
        static_cast<T>(11), static_cast<T>(11),
        static_cast<T>(11), static_cast<T>(11),
        static_cast<T>(11), static_cast<T>(11)
    };

    ASSERT_EQ(result, expected);
}

// Test de Comparación de Matrices
TYPED_TEST(Fixture_MatN1, MatrixComparison) {
    using Mat = typename TestFixture::Mat;
    using T = typename Mat::value_type;

    // Usando static_cast para asegurar que los valores sean del tipo correcto
    Mat A{
        static_cast<T>(1), static_cast<T>(2), static_cast<T>(3), static_cast<T>(4), static_cast<T>(5),
        static_cast<T>(6), static_cast<T>(7), static_cast<T>(8), static_cast<T>(9), static_cast<T>(10)
    };
    Mat B{
        static_cast<T>(1), static_cast<T>(2), static_cast<T>(3), static_cast<T>(4), static_cast<T>(5),
        static_cast<T>(6), static_cast<T>(7), static_cast<T>(8), static_cast<T>(9), static_cast<T>(10)
    };

    ASSERT_TRUE(A == B);

    Mat C{
        static_cast<T>(10), static_cast<T>(9), static_cast<T>(8), static_cast<T>(7), static_cast<T>(6),
        static_cast<T>(5), static_cast<T>(4), static_cast<T>(3), static_cast<T>(2), static_cast<T>(1)
    };
    ASSERT_FALSE(A == C);
}

// Test de Multiplicación de Matrices
TYPED_TEST(Fixture_MatN1, MatrixMultiplication) {
    using Mat = typename TestFixture::Mat;
    using T = typename Mat::value_type;

    constexpr auto R = Mat::row_length::value;
    constexpr auto C = Mat::col_length::value;

    // Probamos la multiplicación solo si las dimensiones son compatibles
    if constexpr (R == 5 && C == 2) {
        Mat A{
            static_cast<T>(1), static_cast<T>(2), static_cast<T>(3), static_cast<T>(4), static_cast<T>(5),
            static_cast<T>(6), static_cast<T>(7), static_cast<T>(8), static_cast<T>(9), static_cast<T>(10)
        };
        line::mat<2, 3, T> B{
            static_cast<T>(11), static_cast<T>(12), static_cast<T>(13),
            static_cast<T>(14), static_cast<T>(15), static_cast<T>(16)
        };
        auto result = A * B;

        line::mat<5, 3, T> expected{
            static_cast<T>(39),  static_cast<T>(42),  static_cast<T>(45),
            static_cast<T>(89),  static_cast<T>(96),  static_cast<T>(103),
            static_cast<T>(139), static_cast<T>(150), static_cast<T>(161),
            static_cast<T>(189), static_cast<T>(204), static_cast<T>(219),
            static_cast<T>(239), static_cast<T>(258), static_cast<T>(277)
        };

        ASSERT_EQ(result, expected);
    } else {
        GTEST_SKIP() << "Test not implemented for this matrix size.";
    }
}*/