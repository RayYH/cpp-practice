#ifndef CPP_PRACTICE_SRC_CORE_OOP_ROOM_HPP_
#define CPP_PRACTICE_SRC_CORE_OOP_ROOM_HPP_

class Room {
 private:
  double length_;
  double breadth_;
  double height_;

 public:
  double CalculateArea();
  double CalculateVolume();
  void SetData(double length, double breadth, double height);
};

#endif //CPP_PRACTICE_SRC_CORE_OOP_ROOM_HPP_
