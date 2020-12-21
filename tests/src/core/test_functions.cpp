#include "gtest/gtest.h"
#include <cmath>

// function prototype
int Add(int, int);

// function definition
int Add(int a, int b) {
  return (a + b);
}

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

/// function overloading

// function with float type parameter
float Absolute(float var) {
  if (var < 0.0)
    var = -var;
  return var;
}

// function with int type parameter
int Absolute(int var) {
  if (var < 0)
    var = -var;
  return var;
}

// function with int type parameter
int Absolute(int var1, int var2) {
  int var = var1 + var2;
  if (var < 0)
    var = -var;
  return var;
}

TEST(functions, overloading) {
  ASSERT_EQ(Absolute(1), 1);
  ASSERT_EQ(Absolute(-1), 1);
  ASSERT_EQ(Absolute(1.0f), 1.0f);
  ASSERT_EQ(Absolute(-1.0f), 1.0f);
  ASSERT_EQ(Absolute(1, 2), 3);
  ASSERT_EQ(Absolute(1, -2), 1);
}

/// function default parameters

// If we are defining the default arguments in the function definition
// instead of the function prototype, then the function must be defined
// before the function call.
std::string Greet(std::string name = "World") {
  return "Hello " + name;
}

TEST(functions, default_parameters) {
  ASSERT_EQ(Greet(), "Hello World");
  ASSERT_EQ(Greet("Ray"), "Hello Ray");
}

// Recursion functions
int Factorial(int);

int Factorial(int n) {
  if (n > 1) {
    return n * Factorial(n - 1);
  } else {
    return 1;
  }
}

TEST(functions, calc_factorial) {
  ASSERT_EQ(Factorial(4), 24);
}

// global variable
int num;

/// return by reference
// function declaration
int &MyFunc();

int &MyFunc() {
  return num;
}

TEST(functions, change_value_via_reference) {
  MyFunc() = 5;
  ASSERT_EQ(num, 5);
}
