#include "gtest/gtest.h"
#include "ppp_std_lib_facilities.hpp"

/**
 * A simple function output message.
 *
 * @return
 */
int HelloWorld() {
  cout << "Hello, World!\n";
  return 0;
}

TEST(hello_world, output_hello_world) {
  testing::internal::CaptureStdout();
  HelloWorld();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ("Hello, World!\n", output);
}
