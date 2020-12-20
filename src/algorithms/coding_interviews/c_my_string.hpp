#ifndef CPP_PRACTICE_SRC_ALGORITHMS_CODING_INTERVIEWS_C_MY_STRING_HPP_
#define CPP_PRACTICE_SRC_ALGORITHMS_CODING_INTERVIEWS_C_MY_STRING_HPP_

#include "cstdio"
#include "cstring"

class CMyString {
 public:
  CMyString(char const *pData = nullptr);
  CMyString(const CMyString &str);
  ~CMyString(void);

  CMyString &operator=(const CMyString &str);

  void Print();

 private:
  char *m_pData;
};

#endif //CPP_PRACTICE_SRC_ALGORITHMS_CODING_INTERVIEWS_C_MY_STRING_HPP_
