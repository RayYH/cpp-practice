/**
 * Boilerplate tests code to initialise framework.
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"


int main(int argc, char *argv[])
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
