#ifndef CPP_PRACTICE_SRC_CORE_OOP_COMPLEX_HPP_
#define CPP_PRACTICE_SRC_CORE_OOP_COMPLEX_HPP_

#include <iostream>
using namespace std;

class Complex {
 private:
  float real_ = 0, imag_ = 0;
 public:
  std::string GetInfo();
  Complex operator+(const Complex &obj);
  void SetData(float real, float imag);
};

#endif //CPP_PRACTICE_SRC_CORE_OOP_COMPLEX_HPP_
