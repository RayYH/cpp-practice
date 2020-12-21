#include "gtest/gtest.h"

TEST(operators, arithmetic_operators) {
  int a, b;
  a = 7;
  b = 2;
  ASSERT_EQ(a + b, 9);
  ASSERT_EQ(a - b, 5);
  ASSERT_EQ(a * b, 14);
  ASSERT_EQ(a / b, 3);
  // The % operator can only be used with integers.
  ASSERT_EQ(a % b, 1);

  // Division Operator /
  ASSERT_EQ(7 / 2, 3);
  ASSERT_EQ(7.0 / 2, 3.5);
  ASSERT_EQ(7 / 2.0, 3.5);
  ASSERT_EQ(7.0 / 2.0, 3.5);
  // a/b * b + a%b == a
}

TEST(operators, increment_decrement_operators) {
  int a = 10, b = 100;
  ASSERT_EQ(++a, 11);
  ASSERT_EQ(--b, 99);
  ASSERT_EQ(a--, 11);
  ASSERT_EQ(b++, 99);
  a += 10;
  b -= 10;
  // *= /= %= ...
  ASSERT_EQ(a, 20);
  ASSERT_EQ(b, 90);
}

TEST(operators, assignment_operators) {
  int a = 7, b = 2;
  a += b;
  ASSERT_EQ(a, 9);
  a -= b;
  ASSERT_EQ(a, 7);
  a *= b;
  ASSERT_EQ(a, 14);
  a /= b;
  ASSERT_EQ(a, 7);
  a %= b;
  ASSERT_EQ(a, 1);
}

TEST(operators, relational_operators) {
  int a, b;
  a = 3;
  b = 5;
  ASSERT_EQ(a == b, false);
  ASSERT_EQ(a != b, true);
  ASSERT_EQ(a > b, false);
  ASSERT_EQ(a < b, true);
  ASSERT_EQ(a >= b, false);
  ASSERT_EQ(a <= b, true);
  std::string c = "c";
  std::string d = "d";
  ASSERT_TRUE(c < d);
}

TEST(operators, logical_operators) {
  int a = 3, b = 5;
  ASSERT_EQ((a != b) && (a < b), true);
  ASSERT_EQ((a == b) && (a < b), false);
  ASSERT_EQ((a == b) && (a > b), false);
  ASSERT_EQ((a != b) || (a < b), true);
  ASSERT_EQ((a != b) || (a > b), true);
  ASSERT_EQ((a == b) || (a < b), true);
  // ! logical not operator: True only if the operand is false.
}

TEST(operators, bitwise_and_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  ASSERT_EQ(a & b, 0);
  ASSERT_EQ(a & c, 0);
  ASSERT_EQ(c & a, 0);
  ASSERT_EQ(c & d, 1);
}

TEST(operators, bitwise_or_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  ASSERT_EQ(a | b, 0);
  ASSERT_EQ(a | c, 1);
  ASSERT_EQ(c | a, 1);
  ASSERT_EQ(c | d, 1);
}

TEST(operators, bitwise_xor_operator) {
  int a = 0, b = 0, c = 1, d = 1;
  ASSERT_EQ(a ^ b, 0);
  ASSERT_EQ(a ^ c, 1);
  ASSERT_EQ(c ^ a, 1);
  ASSERT_EQ(c ^ d, 0);
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
  ASSERT_EQ(1, a & b);

  /*
   * Or
   *  5 | 9
   * 5 = 0000 0101
   * 9 = 0000 1001
   * -------------
   *   = 0000 1101
   *   = 1 + 4 + 8
   */
  ASSERT_EQ(1 + 4 + 8, a | b);

  /*
   * Xor
   * 5 ^ 9
   * 5 = 0000 0101
   * 9 = 0000 1001
   * -------------
   *   = 0000 1100
   *   = 4 + 8
   */
  ASSERT_EQ(4 + 8, a ^ b);

  /*
   * Complement
   * 4
   * 0000 0100 - true code -> below is an inverse form
   * 1111 1011 - will be treated as a 2's complement, this is a negative number
   *           - so, to get the true code, minus one first
   * 1111 1010 - then, inverse all numbers except the sign
   * 1000 0101
   *
   * There is a simple rule: A + (~A) = -1
   */
  ASSERT_EQ(-(1 + 4), ~4);
}

TEST(operators, shift_operators) {
  ASSERT_EQ(212 >> 0, 212);
  ASSERT_EQ(212 >> 1, 212 / 2);
  ASSERT_EQ(212 >> 2, 212 / 4);
  ASSERT_EQ(212 >> 3, 212 / 8);
  ASSERT_EQ(212 << 0, 212);
  ASSERT_EQ(212 << 1, 424);
  ASSERT_EQ(212 << 2, 848);
  ASSERT_EQ(212 << 3, 1696);
}

TEST(operators, concatenate_operator) {
  std::string str1 = "Hello";
  std::string str2 = " ";
  std::string str3 = "World";
  // use + to append characters
  ASSERT_EQ(str1 + str2 + str3, "Hello World");
  ASSERT_EQ(str1 += str3, "HelloWorld");
}
