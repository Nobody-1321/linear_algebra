#include <gtest/gtest.h>
#include "../src/detail/structs_det.hpp"
#include "../src/vector/SVec.hpp"

template<typename U>
struct TestValues {
    static U zero() { return static_cast<U>(0); }
    static U scalarOne() { return static_cast<U>(1); }
    static U scalarNegOne() { return static_cast<U>(-1); }
};

template <int N, typename T>
struct VecType {
    using type = line::SVec<N, T>;
};

template <typename VecType>
class Fixture_VecN : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};

template <typename VecType>
class Fixture_Vec3N : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};

template <typename VecType>
class Fixture_Vec15N : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};