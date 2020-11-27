#include "gtest/gtest.h"

int GetSum(int *arr, int len) {
  int i, sum = 0;
  for (i = 0; i < len; i++) {
    sum += *(arr + i);
  }

  return sum;
}

int Calc(int a, int b, char op) {
  int v;
  switch (op) {
    case '+':
    default:
      // invalid operators will be regarded as '+'
      v = a + b;
      break;
    case '-':v = a - b;
      break;
    case '*':v = a * b;
      break;
    case '/':v = a / b;
      break;
  }
  return v;
}

TEST(if_elseif_else_stament, if_statement) {
  int num = 1;
  if (num < 0) {
    ASSERT_EQ(2, 3);
  }
  ASSERT_EQ(3, 3);
}

TEST(if_elseif_else_stament, if_else_statement) {
  int num = 1;
  if (num < 0) {
    ASSERT_LE(num, 0);
  } else {
    ASSERT_GE(num, 0);
  }
}

TEST(if_elseif_else_stament, if_elseif_else_statement) {
  int num = 1;
  if (num < 0) {
    ASSERT_LE(num, 0);
  } else if (num > 1) {
    ASSERT_GE(num, 1);
  } else {
    ASSERT_EQ(num, 1);
  }
}

TEST(for_loop, basic_for_loop) {
  int i, j = 0;
  for (i = 0; i < 5; i++) {
    ASSERT_EQ(i, j++);
  }
}

TEST(while_loop, basic_while_loop) {
  int i = 0, j = 0;
  while (i < 5) {
    ASSERT_EQ(i, j++);
    i++;
  }
}

TEST(while_loop, sum_of_input_values) {
  int sum = 0, value = 0;
  std::istringstream in("3 7 10 12 16 11");
  while (in >> value) {
    sum += value;
  }
  ASSERT_EQ(59, sum);
  // encounter non-numeric chars will stop input
  // The eol flag on *nix is Ctrl+D
  std::istringstream in2("3 7 10 zzz 12 16 11");
  sum = 0;
  while (in2 >> value) {
    sum += value;
  }
  ASSERT_EQ(20, sum);
}

TEST(do_while_loop, basic_do_while_loop) {
  int i = 0, j = 0;
  do {
    ASSERT_EQ(i, j++);
    i++;
  } while (i < 5);
}

TEST(for_loop, use_for_loop_get_sum) {
  int a[5] = {1, 2, 3, 4, 5};
  ASSERT_EQ(GetSum(a, 5), 15);
  ASSERT_EQ(GetSum(&a[0], 5), 15);
}

// In C++11, a new range-based for loop was introduced to work with collections
// such as arrays and vectors.
TEST(for_loop, for_in_loop) {
  int i, j = 0, length = 10;
  int num[length];
  for (i = 0; i < length; i++) {
    num[i] = i;
  }
  // for-in loop
  for (int element:num) {
    ASSERT_EQ(element, j++);
  }
}

TEST(for_loop, infinite_for_loop) {
  int i;
  // Infinite for loop
  for (i = 1; i > 0; i++) {
    if (i == 10) {
      break;
    }
  }
  ASSERT_EQ(i, 10);
}

TEST(while_loop, infinite_while_loop) {
  int i = 0;
  // Infinite while loop
  while (true) {
    if (i == 10) {
      break;
    }
    i++;
  }
  ASSERT_EQ(i, 10);
}

TEST(break_continue, usage_inside_loop) {
  testing::internal::CaptureStdout();
  for (int i = 1; i <= 5; i++) {
    if (i == 2) {
      continue;
    }
    // break condition
    if (i == 4) {
      break;
    }
    std::cout << i;
  }
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "13");
}

TEST(switch_statement, basic_switch) {
  ASSERT_EQ(Calc(4, 2, '+'), 6);
  ASSERT_EQ(Calc(4, 2, '|'), 6);
  ASSERT_EQ(Calc(4, 2, '-'), 2);
  ASSERT_EQ(Calc(4, 2, '*'), 8);
  ASSERT_EQ(Calc(4, 2, '/'), 2);
}

TEST(goto_statement, avoid_using_goto_statement) {
  // The goto statement gives power to jump to any part of program but,
  // makes the logic of the program complex and tangled.
  // In modern programming, goto statement is considered a harmful
  // construct and a bad programming practice.
}