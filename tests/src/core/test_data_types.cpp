#include "gtest/gtest.h"

/**
 * The c++ type system is very annoying!
 */
TEST(data_types, types_size) {
  /**
   * maybe 2 or 4.
   */
  ASSERT_GE(sizeof(int), 2);
  EXPECT_EQ(sizeof(float), 4);
  EXPECT_EQ(sizeof(double), 8);
  EXPECT_EQ(sizeof(char), 1);
  EXPECT_EQ(sizeof(bool), 1);
  /**
   * Unlike Windows UTF-16 2-byte wide chars, wchar_t
   * on Linux and OS X is 4 bytes UTF-32 (gcc/g++ and XCode).
   * On cygwin it is 2 (cygwin uses Windows APIs).
   */
  ASSERT_GE(sizeof(wchar_t), 2);

  int anInt = 1;
  ASSERT_GE(sizeof(anInt), 2);
  ASSERT_EQ(anInt, 1);

  float aFloat = 64.74;
  ASSERT_FLOAT_EQ(sizeof(aFloat), 4);
  ASSERT_FLOAT_EQ(aFloat, 64.74);

  double aDouble = 45E12;
  EXPECT_EQ(sizeof(aDouble), 8);
  ASSERT_DOUBLE_EQ(aDouble, 45E12);

  char aChar = 'A';
  EXPECT_EQ(sizeof(aChar), 1);
  ASSERT_EQ(aChar, 'A');

  wchar_t aWchar = L'你';
  ASSERT_GE(sizeof(aWchar), 2);
  ASSERT_EQ(aWchar, L'你');

  bool aBool = false;
  EXPECT_EQ(sizeof(aBool), 1);
  ASSERT_FALSE(aBool);
}

TEST(data_types, type_conversion) {
  int num_int = 9;
  double num_double;
  num_double = num_int;
  ASSERT_DOUBLE_EQ(num_double, 9);
  num_double = (double) num_int;
  ASSERT_DOUBLE_EQ(num_double, 9);
  num_double = 9.55;
  num_int = (int) num_double;
  EXPECT_EQ(num_int, 9);
}
