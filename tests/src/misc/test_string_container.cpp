// Test framework
#include "gtest/gtest.h"
#include "gmock/gmock.h"

// Fixtures
#include "fixtures/strings.hpp"

// Mocks
#include "mocks/mock_string_container.hpp"

// Functions to tests
#include "string_container.hpp"
#include "string_container.cpp"
#include "string_container_operations.hpp"
#include "string_container_operations.cpp"

// Add useful testing functions to namespace
using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::Exactly;

TEST(get_number_test, returns_correct_value) {
    StringContainer stringContainer;
    ASSERT_EQ(stringContainer.GetNumber(), 5);
}

TEST_P(StringsFixture, test_string_valid) {
    // Retrieve the tests parameter from the fixture
    auto test_str = this->GetParam();

    StringContainer stringContainer;
    ASSERT_EQ(
            stringContainer.IsValid(test_str),
            test_str.find("Kano") == 0
    );
}

TEST(string_container_test, test_string_container_operations_with_mocks) {
    MockStringContainer stringContainer;

    EXPECT_CALL(stringContainer, IsValid(_))
            .Times(Exactly(1))
            .WillRepeatedly(Return(true));

    EXPECT_CALL(stringContainer, GetNumber())
            .Times(AtLeast(2))
            .WillOnce(Return(8))
            .WillRepeatedly(Return(7));

    EXPECT_TRUE(CheckStringContainer(stringContainer));
}
