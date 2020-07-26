#include "gtest/gtest.h"

TEST(operators, arithmetic_operators) {
  int a, b;
  a = 7;
  b = 2;
  EXPECT_EQ(a + b, 9);
  EXPECT_EQ(a - b, 5);
  EXPECT_EQ(a * b, 14);
  EXPECT_EQ(a / b, 3);
  // The % operator can only be used with integers.
  EXPECT_EQ(a % b, 1);

  // Division Operator /
  EXPECT_EQ(7 / 2, 3);
  EXPECT_EQ(7.0 / 2, 3.5);
  EXPECT_EQ(7 / 2.0, 3.5);
  EXPECT_EQ(7.0 / 2.0, 3.5);
}

TEST(operators, increment_decrement_operators) {
  int a = 10, b = 100;
  EXPECT_EQ(++a, 11);
  EXPECT_EQ(--b, 99);
}

TEST(operators, assignment_operators) {
  int a = 7, b = 2;
  a += b;
  EXPECT_EQ(a, 9);
  a -= b;
  EXPECT_EQ(a, 7);
  a *= b;
  EXPECT_EQ(a, 14);
  a /= b;
  EXPECT_EQ(a, 7);
  a %= b;
  EXPECT_EQ(a, 1);
}

TEST(operators, relational_operators) {
  int a, b;
  a = 3;
  b = 5;
  EXPECT_EQ(a == b, false);
  EXPECT_EQ(a != b, true);
  EXPECT_EQ(a > b, false);
  EXPECT_EQ(a < b, true);
  EXPECT_EQ(a >= b, false);
  EXPECT_EQ(a <= b, true);
}

TEST(operators, logical_operators) {
  int a = 3, b = 5;
  EXPECT_EQ((a != b) && (a < b), true);
  EXPECT_EQ((a == b) && (a < b), false);
  EXPECT_EQ((a == b) && (a > b), false);
  EXPECT_EQ((a != b) || (a < b), true);
  EXPECT_EQ((a != b) || (a > b), true);
  EXPECT_EQ((a == b) || (a < b), true);
  // ! logical not operator: True only if the operand is false.
}

TEST(operators, bitwise_and_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  EXPECT_EQ(a & b, 0);
  EXPECT_EQ(a & c, 0);
  EXPECT_EQ(c & a, 0);
  EXPECT_EQ(c & d, 1);
}

TEST(operators, bitwise_or_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  EXPECT_EQ(a | b, 0);
  EXPECT_EQ(a | c, 1);
  EXPECT_EQ(c | a, 1);
  EXPECT_EQ(c | d, 1);
}

TEST(operators, bitwise_xor_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  EXPECT_EQ(a ^ b, 0);
  EXPECT_EQ(a ^ c, 1);
  EXPECT_EQ(c ^ a, 1);
  EXPECT_EQ(c ^ d, 0);
}

TEST(operators, bitwise_operators) {
  // 5 = 0000 0101
  int a = 5;
  // 9 = 0000 1001
  int b = 9;
  /*
   * And
   * 5 & 9
   * 5 = 0000 0101
   * 9 = 0000 1001
   * -------------
   *   = 0000 0001
   *   = 1
   */
  EXPECT_EQ(1, a & b);

  /*
   * Or
   *  5 | 9
   * 5 = 0000 0101
   * 9 = 0000 1001
   * -------------
   *   = 0000 1101
   *   = 1 + 4 + 8
   */
  EXPECT_EQ(1 + 4 + 8, a | b);

  /*
   * Xor
   * 5 ^ 9
   * 5 = 0000 0101
   * 9 = 0000 1001
   * -------------
   *   = 0000 1100
   *   = 4 + 8
   */
  EXPECT_EQ(4 + 8, a ^ b);

  /*
   * Complement
   * 4
   * 0000 0100 - 原码 (正数的原码即为真值)
   * 1111 1011 - 取反，得到的结果在计算机中存储的形式是补码，此补码指示其值是一个负数 (最高位是1)
   * 1111 1010 - -1 (负数的补码由其原码取反 +1 而得，因此我们需要 -1 再对符号位之外的各位取反)
   * 1000 0101 - 取反 (1 + 4)
   *
   * There is a simple rule: A + (~A) = -1
   */
  EXPECT_EQ(-(1 + 4), ~4);
}

TEST(operators, shift_operators) {
  EXPECT_EQ(212 >> 0, 212);
  EXPECT_EQ(212 >> 1, 212 / 2);
  EXPECT_EQ(212 >> 2, 212 / 4);
  EXPECT_EQ(212 >> 3, 212 / 8);
  EXPECT_EQ(212 << 0, 212);
  EXPECT_EQ(212 << 1, 424);
  EXPECT_EQ(212 << 2, 848);
  EXPECT_EQ(212 << 3, 1696);
}