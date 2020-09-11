#include "wall.hpp"

Wall::Wall(double length, double height) {
  length_ = length;
  height_ = height;
}

Wall::Wall(Wall &obj) {
  length_ = obj.length_;
  height_ = obj.height_;
}

double Wall::CalculateArea() {
  return length_ * height_;
}