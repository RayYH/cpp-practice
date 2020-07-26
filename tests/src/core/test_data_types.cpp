#include "gtest/gtest.h"

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
   * Unlike Windows UTF-16 2-byte wide chars, wchar_t on Linux and OS X is
   * 4 bytes UTF-32 (gcc/g++ and XCode). On cygwin it is 2
   * (cygwin uses Windows APIs).
   */
  ASSERT_GE(sizeof(wchar_t), 2);

  int anInt = 1;
  ASSERT_GE(sizeof(anInt), 2);

  float aFloat = 64.74;
  ASSERT_FLOAT_EQ(sizeof(aFloat), 4);

  double aDouble = 45E12;
  EXPECT_EQ(sizeof(aDouble), 8);

  char aChar = 'A';
  EXPECT_EQ(sizeof(aChar), 1);

  wchar_t aWchar = L'你';
  ASSERT_GE(sizeof(aWchar), 2);

  bool aBool = false;
  EXPECT_EQ(sizeof(aBool), 1);
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