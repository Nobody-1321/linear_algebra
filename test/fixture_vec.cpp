#include <gtest/gtest.h>
//#include <types_vec.hpp>
#include <setup_vec.hpp>

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

// Clase Fixture con plantilla
template <typename VecType>
class Fixture_Vec4 : public ::testing::Test {
public: 
    using Vec = typename VecType::type;
};
