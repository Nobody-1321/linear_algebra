#include <gtest/gtest.h>
#include <setup_structs.hpp>

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
class Fixture_VecN : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};
