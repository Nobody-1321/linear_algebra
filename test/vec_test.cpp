#include <gtest/gtest.h>
#include <vec.hpp>
#include <iostream>
#include "fixture_vec.cpp"

//./tests --gtest_filter=Fixture_VecN/.context_test_sum

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<2, int>,
    VecType<2, float>,
    VecType<2, double>
    >
    MyVecTypes_2V;

// Usa TYPED_TEST_SUITE para definir el caso de prueba
TYPED_TEST_SUITE(Fixture_VecN, MyVecTypes_2V);

// access to elements test
TYPED_TEST(Fixture_VecN, AccessToElements)
{
    using U = TestFixture::Vec::value_type;
    typename TestFixture::Vec u{static_cast<U>(8), static_cast<U>(8)};
    ASSERT_EQ(u[0], 8);
    ASSERT_EQ(u[1], 8);
    //ASSERT_EQ(u.at(0), 8);
    //ASSERT_EQ(u.at(1), 8);
    //auto v = u.data();
    //ASSERT_THROW(u.at(2), std::out_of_range);
}

// iterators test
TYPED_TEST(Fixture_VecN, Iterators)
{
    using U = TestFixture::Vec::value_type;
    typename TestFixture::Vec u{static_cast<U>(8), static_cast<U>(8)};
    auto it = u.begin();
    auto it2 = u.end();
    ASSERT_EQ(*it, 8);
    ASSERT_EQ(*(it + 1), 8 );
    ASSERT_EQ(it2 - it, 2);
    ASSERT_EQ(*u.cbegin(), *u.begin());
    ASSERT_EQ(*u.cend(), *u.end());
}

// u + v = v + u
TYPED_TEST(Fixture_VecN, Commutativity)
{

    using U = TestFixture::Vec::value_type;
    typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
    typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2));
    typename TestFixture::Vec result1 = u + v;
    typename TestFixture::Vec result2 = v + u;
    ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_VecN, Associativity)
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
TYPED_TEST(Fixture_VecN, AdditiveIdentity)
{

    using U = TestFixture::Vec::value_type;
    typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
    typename TestFixture::Vec zero(static_cast<U>(0), static_cast<U>(0));
    typename TestFixture::Vec result = u + zero;
    ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_VecN, AdditiveInverse)
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
TYPED_TEST(Fixture_VecN, DistributivityScalarAddition)
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
TYPED_TEST(Fixture_VecN, DistributivityScalarMultiplication)
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
TYPED_TEST(Fixture_VecN, AssociativityScalarMultiplication)
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
TYPED_TEST(Fixture_VecN, MultiplicativeIdentity)
{
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8));
    U c = static_cast<U>(1);
    typename TestFixture::Vec result = c * u;
    ASSERT_EQ(u, result);
}

typedef ::testing::Types<
    VecType<3, int>,
    VecType<3, float>,
    VecType<3, double>>
    MyVecTypes_3V;

TYPED_TEST_SUITE(Fixture_Vec3N, MyVecTypes_3V);

TYPED_TEST(Fixture_Vec3N, CompoundAssignmentOperators)
{
    using U = TestFixture::Vec::value_type;

    // sum
    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2), static_cast<U>(2));
        typename TestFixture::Vec w(static_cast<U>(3), static_cast<U>(3), static_cast<U>(3));
        typename TestFixture::Vec result1 = u + v + w;
        u += v;
        u += w;
        ASSERT_EQ(u, result1);
    }

    // subtraction

    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2), static_cast<U>(2));
        typename TestFixture::Vec w(static_cast<U>(3), static_cast<U>(3), static_cast<U>(3));
        typename TestFixture::Vec result1 = u - v - w;
        u -= v;
        u -= w;
        ASSERT_EQ(u, result1);
    }


    // multiplication by scalar
    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        U c = static_cast<U>(2);
        typename TestFixture::Vec result1 = u * c * c;
        u *= c;
        u *= c;
        ASSERT_EQ(u, result1);
    }

    // division by scalar
    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        U c = static_cast<U>(2);
        typename TestFixture::Vec result1 = u / c / c;
        u /= c;
        u /= c;
        ASSERT_EQ(u, result1);
    }

    //throw exception
    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        U c = static_cast<U>(0);
        ASSERT_THROW(u /= c, std::invalid_argument);
    }

    // multiplication by vector
    {
        typename TestFixture::Vec u(static_cast<U>(8), static_cast<U>(8), static_cast<U>(8));
        typename TestFixture::Vec v(static_cast<U>(2), static_cast<U>(2), static_cast<U>(2));
        typename TestFixture::Vec result1 = u * v * v;
        u *= v;
        u *= v;
        ASSERT_EQ(u, result1);
    }

}

typedef ::testing::Types<
    VecType<15, int>>
    MyVecTypes_15V;

TYPED_TEST_SUITE(Fixture_Vec15N, MyVecTypes_15V);

// Prueba del constructor por defecto
TYPED_TEST(Fixture_Vec15N, DefaultConstructor)
{
    typename TestFixture::Vec u;
    bool flag = true;

    for (auto i = u.begin(); i != u.end(); ++i)
    {
        if (*i != 0)
        {
            flag = false;
            break;
        }
    }

    ASSERT_EQ(flag, true);
}

// Prueba del constructor con un valor de llenado
TYPED_TEST(Fixture_Vec15N, FillConstructor)
{
    typename TestFixture::Vec u(1);
    bool flag = true;
    for (auto i = u.begin(); i != u.end(); ++i)
    {
        if (*i != 1)
        {
            flag = false;
            break;
        }
    }
    ASSERT_EQ(flag, true);
}

// Prueba del constructor de copia
TYPED_TEST(Fixture_Vec15N, CopyConstructor)
{
    typename TestFixture::Vec u(1);
    typename TestFixture::Vec v(u);
    ASSERT_EQ(u, v);
}

// Prueba del constructor por movimiento
TYPED_TEST(Fixture_Vec15N, MoveConstructor)
{
    typename TestFixture::Vec u(225);
    auto *refdata = u.data();

    typename TestFixture::Vec v(std::move(u));
    auto *refdata2 = v.data();    

    ASSERT_EQ(refdata, refdata2);
}

// Prueba de la inicialización por lista
TYPED_TEST(Fixture_Vec15N, ListInitialization)
{
    typename TestFixture::Vec u{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                11, 12, 13, 14, 15};
    bool flag = true;
    std::size_t k = 1;
    for (auto i = u.begin(); i != u.end(); ++i)
    {
        if (*i != k)
        {
            flag = false;
            break;
        }
        k++;
    }

    ASSERT_EQ(15, u.size());
    ASSERT_EQ(flag, true);
}

// Prueba de la inicialización por argumentos

TYPED_TEST(Fixture_Vec15N, ArgumentInitialization)
{
    typename TestFixture::Vec u(1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                11, 12, 13, 14, 15);
    bool flag = true;
    std::size_t k = 1;
    for (auto i = u.begin(); i != u.end(); ++i)
    {
        if (*i != k)
        {
            flag = false;
            break;
        }
        k++;
    }

    ASSERT_EQ(15, u.size());
    ASSERT_EQ(flag, true);
}