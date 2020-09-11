#include "gtest/gtest.h"
using namespace std;

TEST(arrays, declaration) {
  testing::internal::CaptureStdout();
  int x[6] = {1, 2, 3, 4, 5, 6};
  int y[6] = {1, 2, 3};
  int z[] = {6, 7, 8, 9};

  // modify array elements
  y[2] = 4;

  // range based for loop
  for (const int &n : x) { // const int &n - memory-efficient
    cout << n;
  }

  cout << " ";

  for (const int &n : y) {
    cout << n;
  }

  cout << " ";
  // normal for loop
  for (int i = 0; i < 4; i++) {
    cout << z[i];
  }

  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "123456 124000 6789");
}

TEST(arrays, calc_sum_and_average) {
  // initialize an array without specifying size
  double numbers[] = {7, 5, 6, 12, 35, 27};
  double sum = 0;
  int count = 0;
  double average;

  for (const double &n : numbers) {
    sum += n;
    count++;
  }

  if (count > 0) {
    average = sum / count;
  } else {
    average = 0;
  }

  ASSERT_FLOAT_EQ(sum, 92);
  ASSERT_EQ(count, 6);
  ASSERT_FLOAT_EQ(average, 15.333333);
}

TEST(arrays, multi_dimensional_array) {
  int x[2][3] = {2, 4, 5, 9, 0, 19};
  int y[2][3] = {{2, 4, 5}, {9, 0, 19}};
  int p[2][3][4] = {3, 4, 2, 3, 0, -3, 9, 11, 23, 12, 23,
                    2, 13, 4, 56, 3, 5, 9, 3, 5, 5, 1, 4, 9};
  int q[2][3][4] = {
      {{3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}},
      {{13, 4, 56, 3}, {5, 9, 3, 5}, {5, 1, 4, 9}}
  };

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(x[i][j], y[i][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        ASSERT_EQ(p[i][j][k], q[i][j][k]);
      }
    }
  }
}

int Sum(double numbers[5]) {
  double sum = 0;

  for (int i = 0; i < 5; i++) {
    sum += numbers[i];
  }

  return sum;
}

TEST(arrays, passing_array_to_function) {
  double numbers[5] = {1, 2, 3, 4, 5};
  ASSERT_FLOAT_EQ(15, Sum(numbers));
}