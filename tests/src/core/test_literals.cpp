#include "gtest/gtest.h"

const int LIGHT_SPEED = 299792458;

TEST(literals, integers) {
    int dec1 = 0;
    int dec2 = -9;
    int dec3 = 22;
    ASSERT_EQ(dec1, 0);
    ASSERT_EQ(dec2, -9);
    ASSERT_EQ(dec3, 22);
    int oct1 = 021;
    int oct2 = 077;
    int oct3 = 033;
    ASSERT_EQ(oct1, 1 + 2 * 8);
    ASSERT_EQ(oct2, 7 + 7 * 8);
    ASSERT_EQ(oct3, 3 + 3 * 8);
    int hex1 = 0x7f;
    int hex2 = 0x2a;
    int hex3 = 0x521;
    ASSERT_EQ(hex1, 15 + 7 * 16);
    ASSERT_EQ(hex2, 10 + 2 * 16);
    ASSERT_EQ(hex3, 1 + 2 * 16 + 5 * 16 * 16);
}

TEST(literals, floatingPointLiterals) {
    float float1 = -2.0;
    float float2 = 0.0000234;
    float float3 = -0.22E-5;
    ASSERT_FLOAT_EQ(float1, -2.0);
    ASSERT_FLOAT_EQ(float2, 0.0000234);
    ASSERT_FLOAT_EQ(float3, -0.0000022);
}

TEST(literals, characters) {
    char aChar = 'A';
    ASSERT_EQ(aChar, 'A');
    ASSERT_EQ(aChar, 65);
}

TEST(literals, strings) {
    std::string str = "good";
    ASSERT_EQ(str, "good");
}

TEST(literals, constants) {
    ASSERT_EQ(LIGHT_SPEED, 299792458);
}