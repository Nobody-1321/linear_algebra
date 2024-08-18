#include <gtest/gtest.h>
#include <vec.hpp>
#include <iostream>
#include "fixture_vec.cpp"

//./tests --gtest_filter=Fixture_VecN/.context_test_sum

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<2, float>
    //VecType<2, float>,
    //VecType<2, double>
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
/*
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

*/
/*
// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<3, int>,
    VecType<3, float>,
    VecType<3, double>
> MyVecTypes_3V;

TYPED_TEST_SUITE(Fixture_Vec3, MyVecTypes_3V);


// u + v = v + u
TYPED_TEST(Fixture_Vec3, Commutativity) {

    typename TestFixture::Vec u(8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2);
    typename TestFixture::Vec result1 = u + v;
    typename TestFixture::Vec result2 = v + u;
    ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_Vec3, Associativity) {

    typename TestFixture::Vec u(8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2);
    typename TestFixture::Vec w(3, 3, 3);
    typename TestFixture::Vec result1 = (u + v) + w;
    typename TestFixture::Vec result2 = u + (v + w);
    ASSERT_EQ(result1, result2);
}

// u + 0 = u
TYPED_TEST(Fixture_Vec3, AdditiveIdentity) {

    typename TestFixture::Vec u(8, 8, 8);
    typename TestFixture::Vec zero(0, 0, 0);
    typename TestFixture::Vec result = u + zero;
    ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_Vec3, AdditiveInverse) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8);
    typename TestFixture::Vec neg_u(8, 8, 8);
    U c = static_cast<U>(-1);
    typename TestFixture::Vec result = u + (c * neg_u);
    typename TestFixture::Vec zero(0, 0, 0);
    ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_Vec3, DistributivityScalarAddition) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2);
    U c = static_cast<U>(2);
    typename TestFixture::Vec result1 = (u + v) * c;
    typename TestFixture::Vec result2 = (u * c) + (v * c);
    ASSERT_EQ(result1, result2);
}

// (c + d)u = cu + du
TYPED_TEST(Fixture_Vec3, DistributivityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = (c + d) * u;
    typename TestFixture::Vec result2 = (c * u) + (d * u);
    ASSERT_EQ(result1, result2);
}

// c(du) = (cd)u
TYPED_TEST(Fixture_Vec3, AssociativityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = c * (d * u);
    typename TestFixture::Vec result2 = (c * d) * u;
    ASSERT_EQ(result1, result2);
}

// 1u = u
TYPED_TEST(Fixture_Vec3, MultiplicativeIdentity) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8);
    U c = static_cast<U>(1);
    typename TestFixture::Vec result = u * c;
    ASSERT_EQ(u, result);
}


// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<4, int>,
    VecType<4, float>,
    VecType<4, double>
> MyVecTypes_4V;

TYPED_TEST_SUITE(Fixture_Vec4, MyVecTypes_4V);


// u + v = v + u
TYPED_TEST(Fixture_Vec4, Commutativity) {

    typename TestFixture::Vec u(8, 8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2, 2);
    typename TestFixture::Vec result1 = u + v;
    typename TestFixture::Vec result2 = v + u;
    ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_Vec4, Associativity) {

    typename TestFixture::Vec u(8, 8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2, 2);
    typename TestFixture::Vec w(3, 3, 3, 3);
    typename TestFixture::Vec result1 = (u + v) + w;
    typename TestFixture::Vec result2 = u + (v + w);
    ASSERT_EQ(result1, result2);
}

// u + 0 = u
TYPED_TEST(Fixture_Vec4, AdditiveIdentity) {

    typename TestFixture::Vec u(8, 8, 8, 8);
    typename TestFixture::Vec zero(0, 0, 0, 0);
    typename TestFixture::Vec result = u + zero;
    ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_Vec4, AdditiveInverse) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8, 8);
    typename TestFixture::Vec neg_u(8, 8, 8, 8);
    U c = static_cast<U>(-1);
    typename TestFixture::Vec result = u + (c * neg_u);
    typename TestFixture::Vec zero(0, 0, 0, 0);
    ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_Vec4, DistributivityScalarAddition) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8, 8);
    typename TestFixture::Vec v(2, 2, 2, 2);
    U c = static_cast<U>(2);
    typename TestFixture::Vec result1 = c * (u + v);
    typename TestFixture::Vec result2 = c * u + c * v;
    ASSERT_EQ(result1, result2);
}

// (c + d)u = cu + du
TYPED_TEST(Fixture_Vec4, DistributivityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = (c + d) * u;
    typename TestFixture::Vec result2 = (c * u) + (d * u);
    ASSERT_EQ(result1, result2);
}

// c(du) = (cd)u
TYPED_TEST(Fixture_Vec4, AssociativityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = c * (d * u);
    typename TestFixture::Vec result2 = (c * d) * u;
    ASSERT_EQ(result1, result2);
}

// 1u = u
TYPED_TEST(Fixture_Vec4, MultiplicativeIdentity) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8, 8, 8);
    U c = static_cast<U>(1);
    typename TestFixture::Vec result = c * u;
    ASSERT_EQ(u, result);
}




typedef ::testing::Types<
    VecType<15, int>,
    VecType<15, float>,
    VecType<15, double>
> MyVecTypes_NV;

TYPED_TEST_SUITE(Fixture_VecN, MyVecTypes_NV);


// constructors test

TYPED_TEST(Fixture_VecN, Constructors)
{
    using U = TestFixture::Vec::value_type;

    {
        typename TestFixture::Vec u(1);
        bool flag = true;
        U val = static_cast<U>(1);
        for (auto i = u.begin(); i != u.end(); ++i)
        {
            if (i->value() != val)
            {
                flag = false;
                break;
            }
        }
        ASSERT_EQ(flag, true);
    }

    {
        typename TestFixture::Vec v(static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10), static_cast<U>(11), static_cast<U>(12),
                                    static_cast<U>(13), static_cast<U>(14), static_cast<U>(15)
                                    );
        bool flag = true;

        for (auto i = v.begin(); i != v.end(); ++i)
        {
            if (i->has_value() == false)
            {
                flag = false;
                break;
            }
        }

        ASSERT_EQ(flag, true);
    }

    {
        typename TestFixture::Vec w = {static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10), static_cast<U>(11), static_cast<U>(12),
                                    static_cast<U>(13), static_cast<U>(14), static_cast<U>(15)
                                    };
        bool flag = true;

        for (auto i = w.begin(); i != w.end(); ++i)
        {
            if (i->has_value() == false)
            {
                flag = false;
                break;
            }
        }

        ASSERT_EQ(flag, true);
    }

    {
        typename TestFixture::Vec x = {static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10), static_cast<U>(11), static_cast<U>(12),
                                    static_cast<U>(13), static_cast<U>(14), static_cast<U>(15)
                                    };
        typename TestFixture::Vec y = x;

        ASSERT_EQ(x, y);
    }



    {
        line::vec<15, U> z = {static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10), static_cast<U>(11), static_cast<U>(12),
                                    static_cast<U>(13), static_cast<U>(14), static_cast<U>(15)
                                    };

        line::vec<10, U> l{z};

        bool flag = true;

        for (auto i = l.begin(); i != l.end(); ++i)
        {


            if (i->has_value() == false )
            {
                flag = false;
                break;
            }
        }

        ASSERT_EQ(flag, true);

    }

    {
        line::vec<15, U> l = {static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10)
                                    };


        bool flag = false;

        for (auto i = l.begin() + 10 ; i != l.end(); ++i){
            if (i->has_value() == true)
            {
                flag = true;
                break;
            }
        }

        ASSERT_EQ(flag, false);
    }

    {
        line::vec<10, U> l = {static_cast<U>(1), static_cast<U>(2), static_cast<U>(3),
                                    static_cast<U>(4), static_cast<U>(5), static_cast<U>(6),
                                    static_cast<U>(7), static_cast<U>(8), static_cast<U>(9),
                                    static_cast<U>(10)
                                    };

        line::vec<15, U> m = l;

        bool flag = false;

        for (auto i = l.begin(); i != l.end(); ++i){
            if (i->has_value() == true)
            {
                flag = true;
                break;
            }
        }

        ASSERT_EQ(flag, false);
    }



}
*/