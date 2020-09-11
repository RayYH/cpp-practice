#include "count.hpp"

int Count::GetValue() const {
  return value_;
}

void Count::operator++() {
  ++value_;
}

Count Count::operator++(int) {
  Count temp;
  temp.value_ = ++value_;
  return temp;
}