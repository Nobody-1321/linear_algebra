#include <gtest/gtest.h>
#include <vec2.hpp>
#include <types.hpp>
#include <setup.hpp>

template<typename U>
struct TestValues {
    static U zero() { return static_cast<U>(0); }
    static U scalarOne() { return static_cast<U>(1); }
    static U scalarNegOne() { return static_cast<U>(-1); }
};


template <int N, typename T>
struct VecType {
    using type = line::vec<N, T>;
};

template <typename VecType>
class Fixture_Vec2 : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};


// Clase Fixture con plantilla
template <typename VecType>
class Fixture_Vec3 : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};


template <typename Vec>
void test_copy_v(const Vec &vec1, const Vec & expected) {
    Vec vec2(vec1);
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec1[i] == expected[i];
        if (!are_equal) break;
    }
    
    ASSERT_TRUE(are_equal);
}


template <typename Vec>
void test_assign_v(const Vec &vec1, const Vec & expected) {
    Vec vec2 = vec1;
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec1[i] == expected[i];
        if (!are_equal) break;
    }

    ASSERT_TRUE(are_equal);
}


template <typename Vec>
void test_add_v(const Vec &vec1, const Vec &vec2, const Vec & expected) {
    Vec vec3 = vec1 + vec2;
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec3[i] == expected[i];
        if (!are_equal) break;
    }

    ASSERT_TRUE(are_equal);
}


template <typename Vec>
void test_sub_v(const Vec &vec1, const Vec &vec2, const Vec & expected) {
    Vec vec3 = vec1 - vec2;
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec3[i] == expected[i];
        if (!are_equal) break;
    }

    ASSERT_TRUE(are_equal);
}


template <typename Vec>
void test_mul_v(const Vec &vec1, const Vec &vec2, const Vec & expected) {
    Vec vec3 = vec1 * vec2;
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec3[i] == expected[i];
        if (!are_equal) break;
    }

    ASSERT_TRUE(are_equal);   
}


template <typename Vec>
void test_mul_scalar_v(const Vec &vec1, const typename Vec::value_type & scalar, const Vec & expected) {
    Vec vec2 = vec1 * scalar;
    bool are_equal = false;

    for (int i = 0; i < vec1.size(); i++) {
        are_equal = vec2[i] == expected[i];
        if (!are_equal) break;
    }

    ASSERT_TRUE(are_equal);
}
