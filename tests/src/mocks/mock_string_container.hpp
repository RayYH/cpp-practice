#ifndef CPP_PRACTICE_MOCK_STRING_CONTAINER_HPP
#define CPP_PRACTICE_MOCK_STRING_CONTAINER_HPP

#include "gmock/gmock.h"
#include "string_container.hpp"

class MockStringContainer : public StringContainer {
 public:
  MOCK_METHOD1(IsValid, bool(std::string));
  MOCK_METHOD0(GetNumber, int());
};

#endif //CPP_PRACTICE_MOCK_STRING_CONTAINER_HPP
