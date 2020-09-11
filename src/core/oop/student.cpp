#include "student.hpp"

Student::Student(double m) {
  marks1_ = m;
}

Student::Student() {}

double Student::CalculateAverage() {
  return (marks1_ + marks2_) / 2;
}

double CalculateAverage(Student s1, Student s2) {
  return (s1.marks1_ + s2.marks1_) / 2;
}

Student CreateStudent() {
  Student student;
  student.marks1_ = 96.5;
  student.marks2_ = 75;

  return student;
}