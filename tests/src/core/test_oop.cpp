#include "gtest/gtest.h"
#include "core/oop/room.hpp"
#include "core/oop/room.cpp"
#include "core/oop/wall.hpp"
#include "core/oop/wall.cpp"
#include "core/oop/student.hpp"
#include "core/oop/student.cpp"

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