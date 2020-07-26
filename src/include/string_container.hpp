#ifndef CPP_PRACTICE_STRING_CONTAINER_HPP
#define CPP_PRACTICE_STRING_CONTAINER_HPP

#include <string>

class StringContainer {
 public:
  StringContainer();

  virtual bool IsValid(std::string str);

  virtual int GetNumber();
};

#endif //CPP_PRACTICE_STRING_CONTAINER_HPP
