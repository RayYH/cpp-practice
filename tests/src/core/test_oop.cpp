#include "gtest/gtest.h"
#include "core/oop/room.hpp"
#include "core/oop/room.cpp"
#include "core/oop/wall.hpp"
#include "core/oop/wall.cpp"
#include "core/oop/student.hpp"
#include "core/oop/student.cpp"
#include "core/oop/count.hpp"
#include "core/oop/count.cpp"
#include "core/oop/complex.hpp"
#include "core/oop/complex.cpp"

TEST(oop, room_object) {
  Room room;
  room.SetData(42.5, 30.8, 19.2);
  ASSERT_FLOAT_EQ(1309, room.CalculateArea());
  ASSERT_FLOAT_EQ(25132.8, room.CalculateVolume());
}

TEST(oop, wall_object) {
  Wall wall1(10.5, 8.6);
  Wall wall2 = wall1;
  ASSERT_FLOAT_EQ(90.3, wall1.CalculateArea());
  ASSERT_FLOAT_EQ(90.3, wall2.CalculateArea());
}

TEST(oop, pass_objects_to_function) {
  Student student1(88.0), student2(56.0);
  ASSERT_FLOAT_EQ(72, CalculateAverage(student1, student2));
}

TEST(oop, return_an_object_from_a_function) {
  Student s = CreateStudent();
  ASSERT_FLOAT_EQ(85.75, s.CalculateAverage());
}

TEST(oop, unary_operator_overloading) {
  Count count1;
  ASSERT_EQ(5, count1.GetValue());
  Count count2 = count1++;
  ASSERT_EQ(6, count2.GetValue());
  ASSERT_EQ(6, count1.GetValue());
  ++count1;
  ASSERT_EQ(7, count1.GetValue());
}

TEST(oop, binary_operator_overloading) {
  Complex complex1, complex2, result;
  complex1.SetData(9.5, 1.20);
  complex2.SetData(1.2, 0.9);
  result = complex1 + complex2;
  ASSERT_EQ("real: 10.70, image: 2.10.", result.GetInfo());
}

TEST(oop, complex) {
  Complex complex;
  ASSERT_EQ("real: 0.00, image: 0.00.", complex.GetInfo());
}