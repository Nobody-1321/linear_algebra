#include <gtest/gtest.h>
#include <vec2.hpp>
#include <vec3.hpp>
#include <types.hpp>
#include <iostream>
#include <setup.hpp>
#include "fixture_vec.cpp"

//./tests --gtest_filter=Fixture_Vec2/*.context_test_sum

// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<2, int>,
    VecType<2, float>,
    VecType<2, double>
> MyVecTypes_2V;


// Usa TYPED_TEST_SUITE para definir el caso de prueba
TYPED_TEST_SUITE(Fixture_Vec2, MyVecTypes_2V);

// Definir la prueba para el constructor
TYPED_TEST(Fixture_Vec2, test_copy) {
    typename TestFixture::Vec vec(8, 8);
    typename TestFixture::Vec expected(8, 8);
    test_copy_v<typename TestFixture::Vec>(vec, expected);
}

TYPED_TEST(Fixture_Vec2, test_assign) {
    typename TestFixture::Vec vec(8, 8);
    typename TestFixture::Vec expected(8, 8);
    test_assign_v<typename TestFixture::Vec>(vec, expected);
}

TYPED_TEST(Fixture_Vec2, test_add) {
    typename TestFixture::Vec vec1(8, 8);
    typename TestFixture::Vec vec2(2, 2);
    typename TestFixture::Vec expected(10, 10);
    test_add_v<typename TestFixture::Vec>(vec1, vec2, expected);
}


TYPED_TEST(Fixture_Vec2, test_sub) {
    typename TestFixture::Vec vec1(8, 8);
    typename TestFixture::Vec vec2(2, 2);
    typename TestFixture::Vec expected(6, 6);
    test_sub_v<typename TestFixture::Vec>(vec1, vec2, expected);
}

TYPED_TEST(Fixture_Vec2, test_mul) {
    typename TestFixture::Vec vec1(8, 8);
    typename TestFixture::Vec vec2(2, 2);
    typename TestFixture::Vec expected(16, 16);
    test_mul_v<typename TestFixture::Vec>(vec1, vec2, expected);
}

TYPED_TEST(Fixture_Vec2,  algebra_properties) {
// for all u,v,w in R^n and all scalars c,d:
    using U  = TestFixture::Vec::value_type;

    U zero_t = TestValues<U>::zero();
    U one_t = TestValues<U>::scalarOne();
    U neg_one_t = TestValues<U>::scalarNegOne();

    // u + v = v + u
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec v(2, 2);
        typename TestFixture::Vec result1 = u + v;
        typename TestFixture::Vec result2 = v + u;
        ASSERT_EQ(result1, result2);
    }
    
    // (u + v) + w = u + (v + w)
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec v(2, 2);
        typename TestFixture::Vec w(3, 3);
        typename TestFixture::Vec result1 = (u + v) + w;
        typename TestFixture::Vec result2 = u + (v + w);
        ASSERT_EQ(result1, result2);
    }

    // u + 0 = u
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec zero(0, 0);
        typename TestFixture::Vec result = u + zero;
        ASSERT_EQ(u, result);
    }

    // u + (-u) = 0
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec neg_u(8, 8);
        typename TestFixture::Vec result = u + neg_one_t * neg_u;
        typename TestFixture::Vec zero(0, 0);
        ASSERT_EQ(result, zero);
    }


    // c(u + v) = cu + cv
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec v(2, 2);
        U c = static_cast<U>(2);
        typename TestFixture::Vec result1 = c * (u + v);
        typename TestFixture::Vec result2 = c * u + c * v;
        ASSERT_EQ(result1, result2);
    }    

    // (c + d)u = cu + du
    {
        typename TestFixture::Vec u(8, 8);
        U c = static_cast<U>(2);
        U d = static_cast<U>(3);
        typename TestFixture::Vec result1 = (c + d) * u;
        typename TestFixture::Vec result2 = c * u + d * u;
        ASSERT_EQ(result1, result2);
    }

    // c(du) = (cd)u
    {
        typename TestFixture::Vec u(8, 8);
        U c = static_cast<U>(2);
        U d = static_cast<U>(3);
        typename TestFixture::Vec result1 = c * (d * u);
        typename TestFixture::Vec result2 = (c * d) * u;
        ASSERT_EQ(result1, result2);
    }

    // 1u = u
    {
        typename TestFixture::Vec u(8, 8);
        typename TestFixture::Vec result = one_t * u;
        ASSERT_EQ(u, result);
    }
    
    
}

/*
// Definir los tipos y tamaños que deseas probar
typedef ::testing::Types<
    VecType<3, int>,
    VecType<3, float>,
    VecType<3, double>
> MyVecTypes_3V;

TYPED_TEST_SUITE(Fixture_Vec3, MyVecTypes_3V);

TYPED_TEST(Fixture_Vec3, test_copy) {
    typename TestFixture::Vec vec(8, 8, 8);
    typename TestFixture::Vec expected(8, 8, 8);
    test_copy_v<typename TestFixture::Vec>(vec, expected);
}

TYPED_TEST(Fixture_Vec3, test_assign) {
    typename TestFixture::Vec vec(8, 8, 8);
    typename TestFixture::Vec expected(8, 8, 8);
    test_assign_v<typename TestFixture::Vec>(vec, expected);
}

TYPED_TEST(Fixture_Vec3, test_add) {
    typename TestFixture::Vec vec1(8, 8, 8);
    typename TestFixture::Vec vec2(2, 2, 2);
    typename TestFixture::Vec expected(10, 10, 10);
    test_add_v<typename TestFixture::Vec>(vec1, vec2, expected);
}

TYPED_TEST(Fixture_Vec3, test_sub) {
    typename TestFixture::Vec vec1(8, 8, 8);
    typename TestFixture::Vec vec2(2, 2, 2);
    typename TestFixture::Vec expected(6, 6, 6);
    test_sub_v<typename TestFixture::Vec>(vec1, vec2, expected);
}

TYPED_TEST(Fixture_Vec3, test_mul) {
    typename TestFixture::Vec vec1(8, 8, 8);
    typename TestFixture::Vec vec2(2, 2, 2);
    typename TestFixture::Vec expected(16, 16, 16);
    test_mul_v<typename TestFixture::Vec>(vec1, vec2, expected);
}





*/