#include "gtest/gtest.h"

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

enum season { spring = 34, summer = 4, autumn = 9, winter = 32 };

enum designFlags { ITALICS = 1, BOLD = 2, UNDERLINE = 4 } button;

TEST(enums, week) {
  week w;
  w = Sunday;
  ASSERT_EQ(w + 1, Monday);
  ASSERT_EQ(w + 2, Tuesday);
  ASSERT_EQ(w + 3, Wednesday);
  ASSERT_EQ(w + 4, Thursday);
  ASSERT_EQ(w + 5, Friday);
  ASSERT_EQ(w + 6, Saturday);
}

TEST(enums, season) {
  season s;
  s = spring;
  ASSERT_EQ(s, 34);
  s = summer;
  ASSERT_EQ(s, 4);
  s = autumn;
  ASSERT_EQ(s, 9);
  s = winter;
  ASSERT_EQ(s, 32);
}

TEST(enums, design_flags) {
  int myDesign = ITALICS | BOLD;
  ASSERT_TRUE(myDesign & ITALICS);
  ASSERT_TRUE(myDesign & BOLD);
  ASSERT_FALSE(myDesign & UNDERLINE);
}