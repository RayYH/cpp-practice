#include "gtest/gtest.h"

using namespace std;

TEST(basic_io, output_string) {
    testing::internal::CaptureStdout();
    std::cout << "This is C++ Programming";
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "This is C++ Programming");
}

TEST(basic_io, numbers_and_characters_output) {
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