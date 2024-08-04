#include <gtest/gtest.h>
#include <mat2x2.hpp>
#include <mat3x3.hpp>
//#include <mat4x4.hpp>
#include <types_mat.hpp>
#include <setup_mat.hpp>

template<int C, int R, IsNumberM T> 
struct MatType {
    using type = line::mat<C, R, T>;
};

template <typename MatType>
class Fixture_Mat2 : public ::testing::Test {
public: 
    using Mat = typename MatType::type;
};

template <typename MatType>
class Fixture_Mat3 : public ::testing::Test {
public: 
    using Mat = typename MatType::type;
};

template <typename MatType>
class Fixture_Mat4 : public ::testing::Test {
public: 
    using Mat = typename MatType::type;
};
