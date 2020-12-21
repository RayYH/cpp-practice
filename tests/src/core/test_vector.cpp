#include "gtest/gtest.h"
#include "std_lib_facilities.hpp"

TEST(vectors, basic) {
  // vector of 6 ints
  vector<int> ints = {5, 7, 9, 4, 8, 6};
  // vector of 4 strings
  vector<string> philosopher = {"Kant", "Plato", "Hume", "Kierkegaard"};
  // vector of 6 ints initialized to 0
  vector<int> vi(6);
  // vector of 4 strings initialized to “”
  vector<string> vs(4);

  // Traversing a vector
  for (int i = 0; i < vi.size(); i++) {
    ASSERT_EQ(vi[i], 0);
  }
  for (int item: ints) {
    ASSERT_GE(item, 0);
  }
  for (int i = 0; i < vs.size(); i++) {
    ASSERT_EQ(vs[i], "");
  }
  for (string s: philosopher) {
    ASSERT_NE(s, "");
  }
}

TEST(vecotrs, push_back) {
  vector<double> v;
  ASSERT_EQ(v.size(), 0);
  v.push_back(2.7);
  v.push_back(5.6);
  v.push_back(7.9);
  ASSERT_EQ(v.size(), 3);
  ASSERT_EQ(v[0], 2.7);
  ASSERT_EQ(v[1], 5.6);
  ASSERT_EQ(v[2], 7.9);
}
