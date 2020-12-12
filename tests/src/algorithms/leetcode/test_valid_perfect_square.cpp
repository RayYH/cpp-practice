#include "gtest/gtest.h"

/**
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Solutions:
 *
 * 1 = 1
 * 4 = 1 + 3
 * 9 = 1 + 3 + 5
 *
 * since: (n+1)^2-n^2=2n+1.
 *
 * @param num
 * @return
 */
bool isPerfectSquare(int num) {
  int decrement = 1;
  while (num > 0) {
    num = num - decrement;
    decrement += 2;
  }

  return num == 0;
}

TEST(leetcode, valid_perfect_square) {
  ASSERT_TRUE(isPerfectSquare(16));
  ASSERT_FALSE(isPerfectSquare(14));
}
