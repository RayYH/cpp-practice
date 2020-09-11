#include "gtest/gtest.h"

/*
   C-style comments can contain
   multiple lines
 */

/* or just one */

/*******************************
 * you can insert any *, but you
 * can't make comments nested
 *******************************
 */

// C++-style comments can comment one line

TEST(comments, macro) {
  // comments are removed before preprocessing,
  // so ABC is "1", not "1//2134"
#define ABC 1//2134
  ASSERT_EQ(1, ABC);
}