#include "complex.hpp"

std::string Complex::GetInfo() {
  char buffer[50];
  sprintf(buffer, "real: %.2f, image: %.2f.", real_, imag_);
  return buffer;
}

// using & makes our code efficient by referencing the complex object
// instead of making a duplicate object inside the operator function.
// using const is considered a good practice because it prevents the
// operator function from modifying complex.
Complex Complex::operator+(const Complex &obj) {
  Complex temp;
  temp.real_ = real_ + obj.real_;
  temp.imag_ = imag_ + obj.imag_;
  return temp;
}

void Complex::SetData(float real, float imag) {
  real_ = real;
  imag_ = imag;
}

// Two operators = and & are already overloaded by default in C++.
// There are 4 operators that cannot be overloaded in C++: :: . .* ?: