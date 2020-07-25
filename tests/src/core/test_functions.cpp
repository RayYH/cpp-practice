#include "gtest/gtest.h"
#include <cmath>

// function prototype
int Add(int, int);

TEST(functions, simple_add) {
    ASSERT_EQ(Add(1, 2), 3);
}

TEST(functions, std_functions) {
    double number, squareRoot;
    number = 25.0;
    // sqrt() is a library function to calculate the square root
    squareRoot = sqrt(number);
    ASSERT_FLOAT_EQ(squareRoot, 5.0);
}

// function definition
int Add(int a, int b) {
    return (a + b);
}

// function overloading
// function with float type parameter
float absolute(float var) {
    if (var < 0.0)
        var = -var;
    return var;
}

// function with int type parameter
int absolute(int var) {
    if (var < 0)
        var = -var;
    return var;
}

// function with int type parameter
int absolute(int var1, int var2) {
    int var = var1 + var2;
    if (var < 0)
        var = -var;
    return var;
}

TEST(functions, overloading) {
    ASSERT_EQ(absolute(1), 1);
    ASSERT_EQ(absolute(-1), 1);
    ASSERT_EQ(absolute(1.0f), 1.0f);
    ASSERT_EQ(absolute(-1.0f), 1.0f);
    ASSERT_EQ(absolute(1, 2), 3);
    ASSERT_EQ(absolute(1, -2), 1);
}

// function default parameters
// If we are defining the default arguments in the function definition
// instead of the function prototype, then the function must be defined
// before the function call.
std::string greet(std::string name = "World") {
    return "Hello " + name;
}

TEST(functions, default_parameters) {
    ASSERT_EQ(greet(), "Hello World");
    ASSERT_EQ(greet("Ray"), "Hello Ray");
}

// Recursion functions
int factorial(int);

TEST(functions, calc_factorial) {
    ASSERT_EQ(factorial(4), 24);
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

// return by reference

// Global variable
int num;

// Function declaration
int &test();

int &test() {
    return num;
}

TEST(functions, change_value_via_reference) {
    test() = 5;
    ASSERT_EQ(num, 5);
}