#include "gtest/gtest.h"
/**
 * A stream is a sequence of characters.
 *
 * cin of istream type (pronounced see-in).
 * cout of ostream type (pronounced see-out).
 *
 * There are two other types: cerr and clog.
 */
#include <iostream>

using namespace std;

TEST(basic_io, print_a_simple_string) {
  testing::internal::CaptureStdout();
  std::cout << "This is C++ Programming";
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "This is C++ Programming");
}

TEST(basic_io, print_numbers_and_characters) {
  testing::internal::CaptureStdout();
  int num1 = 70;
  double num2 = 256.783;
  char ch = 'A';
  cout << num1 << endl;    // print integer
  cout << num2 << endl;    // print double
  cout << "character: " << ch << endl;    // print char
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "70\n256.783\ncharacter: A\n");
}

TEST(basic_io, get_input_from_user) {
  // mock standard io
  istringstream in("3 7");
  ostringstream out;
  int v1 = 0, v2 = 0;
  in >> v1 >> v2;
  out << "The sum is " << (v1 + v2) << endl;
  EXPECT_EQ(out.str(), "The sum is 10\n");
}