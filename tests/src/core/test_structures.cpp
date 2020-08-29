#include "gtest/gtest.h"
using namespace std;

struct Person {
  char name[50];
  int age;
  float salary;
};

struct Distance {
  int feet;
  float inch;
};

void DisplayPerson(Person p) {
  cout << "\nDisplaying Information." << endl;
  cout << "Name: " << p.name << endl;
  cout << "Age: " << p.age << endl;
  cout << "Salary: " << p.salary;
}

TEST(structs, basic_struct) {
  Person p;
  std::string name = "Ray";
  p.age = 10;
  p.salary = 1000.0;
  strcpy(p.name, name.c_str());
  ASSERT_STREQ(p.name, "Ray");
  ASSERT_EQ(10, p.age);
  ASSERT_FLOAT_EQ(1000.0, p.salary);
}

TEST(structs, display_person) {
  testing::internal::CaptureStdout();
  Person p;
  std::string name = "Ray";
  strcpy(p.name, name.c_str());
  p.age = 10;
  p.salary = 1000.0;
  DisplayPerson(p);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "\nDisplaying Information.\nName: Ray\nAge: 10\nSalary: "
                    "1000");
}

TEST(structs, pointers_to_structure) {
  Distance *ptr, d;
  ptr = &d;
  d.feet = 1;
  d.inch = 2.0;
  ASSERT_EQ((*ptr).feet, 1);
  ASSERT_FLOAT_EQ((*ptr).inch, 2.0);
}