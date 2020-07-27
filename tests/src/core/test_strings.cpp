#include "gtest/gtest.h"
#include "string"
#include "cctype"
#include "algorithm"

std::string LowerCase(std::string data) {
  std::transform(data.begin(), data.end(), data.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return data;
}

TEST(strings, string_declaration) {
  char str1[] = "C++";
  char str2[4] = "C++";
  char str3[] = {'C', '+', '+', '\0'};
  char str4[4] = {'C', '+', '+', '\0'};
  ASSERT_STREQ(str1, str2);
  ASSERT_STREQ(str2, str3);
  ASSERT_STREQ(str3, str4);
}

TEST(strings, string_function) {
  char str[] = {'S', 'o', 'm', 'e', '\0'};
  std::string r = LowerCase(str);
  ASSERT_EQ(r, "some");
}