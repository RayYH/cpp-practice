#include "gtest/gtest.h"
#include "algorithms/coding_interviews/c_my_string.hpp"
#include "algorithms/coding_interviews/c_my_string.cpp"

TEST(coding_interviews, assignment_operator_case_1) {
  char const *text = "Hello World";
  CMyString str1(text);
  CMyString str2;
  str2 = str1;
  testing::internal::CaptureStdout();
  str2.Print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Hello World");
}

TEST(coding_interviews, assignment_operator_case_2) {
  char const *text = "Hello World";
  CMyString str1(text);
  str1 = str1;
  testing::internal::CaptureStdout();
  str1.Print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Hello World");
}

TEST(coding_interviews, assignment_operator_case_3) {
  char const *text = "Hello World";
  CMyString str1(text);
  CMyString str2, str3;
  str3 = str2 = str1;
  testing::internal::CaptureStdout();
  str2.Print();
  str3.Print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Hello WorldHello World");
}
