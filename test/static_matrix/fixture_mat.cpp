#include <gtest/gtest.h>
#include "../src/vector/SVec.hpp"
#include "../src/matrix/SMat.hpp"

template <int R, int C, typename T> struct MatType
{
  using type = line::structs::SMat<R, C, T>;
};

template <typename MatType> class Fixture_MatN22 : public ::testing::Test
{
public:
  using Mat = typename MatType::type;
};

template <typename MatType> class Fixture_MatN52 : public ::testing::Test
{
public:
  using Mat = typename MatType::type;
};

template <typename MatType> class Fixture_MatN : public ::testing::Test
{
public:
  using Mat = typename MatType::type;
};

template <typename MatType> class Fixture_MatN33 : public ::testing::Test
{
public:
  using Mat = typename MatType::type;
};
