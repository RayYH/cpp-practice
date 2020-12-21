#include "gtest/gtest.h"

constexpr double pi = 3.14;
constexpr int max = 100;

/**
 * @see https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const
 *
 * `const` applies for variables, and prevents them from being modified in your
 * code.
 *
 * `constexpr` tells the compiler that this expression results in a compile
 * time constant value, so it can be used in places like array lengths,
 * assigning to const variables
 */
TEST(constants, basic) {
  ASSERT_DOUBLE_EQ(pi, 3.14);
  ASSERT_EQ(max, 100);
  constexpr int v = max + 100;
  ASSERT_EQ(v, 200);
  const int v2 = v + 100;
  ASSERT_EQ(v2, 300);
}
