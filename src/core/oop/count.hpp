#ifndef CPP_PRACTICE_SRC_CORE_OOP_COUNT_HPP_
#define CPP_PRACTICE_SRC_CORE_OOP_COUNT_HPP_

class Count {
 private:
  int value_ = 5;

 public:
  Count() {}
  void operator++();    // Overload ++ when used as prefix
  Count operator++(int); // Overload ++ when used as postfix
  int GetValue() const;
};

#endif //CPP_PRACTICE_SRC_CORE_OOP_COUNT_HPP_
