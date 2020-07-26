#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

// Every variable in C++ has two features: type and storage class.
// Type specifies the type of data that can be stored in a variable. For
// example: int, float, char etc.
// And, storage class controls two different properties of a variable:
// lifetime (determines how long a variable can exist)
// and scope (determines which part of the program can access it).

void LocalVariable() {
  // The life of a local variable ends when the function exits.
}

TEST(storage_classes, local_variable) {
  LocalVariable();
}

// Global variable declaration
int c = 12;

void ChangeGlobalVariable() {
  ++c;
}

TEST(storage_classes, global_variable) {
  ASSERT_EQ(c, 12);
  ChangeGlobalVariable();
  ASSERT_EQ(c, 13);
}

TEST(storage_classes, static_local_variable) {
  int i = 0;
  while (i < 10) {
    static int j = 0;
    ASSERT_EQ(j, i);
    j++;
    i++;
  }
}

// Register Variable (Deprecated in C++11)

// thread_local keyword
thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string &thread_name) {
  ++rage; // modifying outside a lock is okay; this is a thread-local variable
  std::lock_guard<std::mutex> lock(cout_mutex);
  ASSERT_EQ(rage, 2);
  std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}

TEST(functions, thread_local_keyword) {
  testing::internal::CaptureStdout();
  std::thread a(increase_rage, "a"), b(increase_rage, "b");
  {
    std::lock_guard<std::mutex> lock(cout_mutex);
    ASSERT_EQ(rage, 1);
    std::cout << "Rage counter for main: " << rage << '\n';
  }
  a.join();
  b.join();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_TRUE(output.find("Rage counter for a: 2") != std::string::npos);
  ASSERT_TRUE(output.find("Rage counter for main: 1") != std::string::npos);
  ASSERT_TRUE(output.find("Rage counter for b: 2") != std::string::npos);
}
