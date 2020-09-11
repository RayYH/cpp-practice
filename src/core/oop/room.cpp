#include "room.hpp"

void Room::SetData(double length, double breadth, double height) {
  length_ = length;
  breadth_ = breadth;
  height_ = height;
}

double Room::CalculateArea() {
  return length_ * breadth_;
}

double Room::CalculateVolume() {
  return length_ * breadth_ * height_;
}
