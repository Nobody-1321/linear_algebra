#include <gtest/gtest.h>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
//#include <types_vec.hpp>
#include <iostream>
#include <setup_vec.hpp>
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

// constructors test
TYPED_TEST(Fixture_Vec2, Constructors) {

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec v(u);
    typename TestFixture::Vec w = u;
    ASSERT_EQ(w, u);

    typename TestFixture::Vec x{2, 2};
    typename TestFixture::Vec y = {x};
    ASSERT_EQ(x, y);

    typename TestFixture::Vec z = {2, 2};
    typename TestFixture::Vec l = std::move(z);
    ASSERT_EQ(x, z);
}

// access to elements test
TYPED_TEST(Fixture_Vec2, AccessToElements) {

    typename TestFixture::Vec u{8, 8};
    ASSERT_EQ(u[0], 8);
    ASSERT_EQ(u[1], 8);
    ASSERT_EQ(u.at(0), 8);
    ASSERT_EQ(u.at(1), 8);
    ASSERT_EQ(u.x, 8);
    ASSERT_EQ(u.y, 8);
    auto v = u.data();
    ASSERT_EQ( &(*v), &u.x);
    ASSERT_EQ( &(*(v+1)), &u.y);
    ASSERT_THROW(u.at(2), std::out_of_range);

}
//iterators test
TYPED_TEST(Fixture_Vec2, Iterators) {

    typename TestFixture::Vec u{8, 10};
    auto it = u.begin();
    auto it2 = u.end();
    ASSERT_EQ(*it, 8);
    ASSERT_EQ(*(it+1), 8+2);
    ASSERT_EQ(it2-it, 2);
    ASSERT_EQ(*u.cbegin(), *u.begin());
    ASSERT_EQ(*u.cend(), *u.end());
}


// u + v = v + u
TYPED_TEST(Fixture_Vec2, Commutativity) {

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec v(2, 2);
    typename TestFixture::Vec result1 = u + v;
    typename TestFixture::Vec result2 = v + u;
    ASSERT_EQ(result1, result2);
}

// (u + v) + w = u + (v + w)
TYPED_TEST(Fixture_Vec2, Associativity) {

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec v(2, 2);
    typename TestFixture::Vec w(3, 3);
    typename TestFixture::Vec result1 = (u + v) + w;
    typename TestFixture::Vec result2 = u + (v + w);
    ASSERT_EQ(result1, result2);
}

// u + 0 = u
TYPED_TEST(Fixture_Vec2, AdditiveIdentity) {

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec zero(0, 0);
    typename TestFixture::Vec result = u + zero;
    ASSERT_EQ(u, result);
}

// u + (-u) = 0
TYPED_TEST(Fixture_Vec2, AdditiveInverse) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec neg_u(8, 8);
    U c = static_cast<U>(-1);
    typename TestFixture::Vec result = u + (c * neg_u);
    typename TestFixture::Vec zero(0, 0);
    ASSERT_EQ(result, zero);
}

// c(u + v) = cu + cv
TYPED_TEST(Fixture_Vec2, DistributivityScalarAddition) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8);
    typename TestFixture::Vec v(2, 2);
    U c = static_cast<U>(2);
    typename TestFixture::Vec result1 = c * (u + v);
    typename TestFixture::Vec result2 = c * u + c * v;
    ASSERT_EQ(result1, result2);
}

// (c + d)u = cu + du
TYPED_TEST(Fixture_Vec2, DistributivityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = (c + d) * u;
    typename TestFixture::Vec result2 = (c * u) + (d * u);
    ASSERT_EQ(result1, result2);
}

// c(du) = (cd)u
TYPED_TEST(Fixture_Vec2, AssociativityScalarMultiplication) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8);
    U c = static_cast<U>(2);
    U d = static_cast<U>(3);
    typename TestFixture::Vec result1 = c * (d * u);
    typename TestFixture::Vec result2 = (c * d) * u;
    ASSERT_EQ(result1, result2);
}

// 1u = u
TYPED_TEST(Fixture_Vec2, MultiplicativeIdentity) {
    using U = TestFixture::Vec::value_type;

    typename TestFixture::Vec u(8, 8);
    U c = static_cast<U>(1);
    typename TestFixture::Vec result = c * u;
    ASSERT_EQ(u, result);
}

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
