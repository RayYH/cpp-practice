#ifndef CPP_PRACTICE_SRC_CORE_OOP_WALL_HPP_
#define CPP_PRACTICE_SRC_CORE_OOP_WALL_HPP_

class Wall {
 private:
  double length_;
  double height_;

 public:
  Wall(double length, double height);
  Wall(Wall &obj);
  double CalculateArea();
};

#endif //CPP_PRACTICE_SRC_CORE_OOP_WALL_HPP_
