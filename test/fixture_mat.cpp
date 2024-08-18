#include <gtest/gtest.h>
#include <vec.hpp>
#include "../linearLib/detail/setup_structs.hpp"
//#include <mat4x4.hpp>

template<int R, int C, typename T> 
struct MatType {
    using type = line::mat<R, C, T>;
};

template <typename MatType>
class Fixture_MatN : public ::testing::Test {
public: 
    using Mat = typename MatType::type;
};
template <typename MatType>
class Fixture_MatN1 : public ::testing::Test {
public: 
    using Mat = typename MatType::type;
    using row_length = typename Mat::row_length;
    using col_length = typename Mat::col_length;
};

