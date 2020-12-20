#include "c_my_string.hpp"

CMyString::~CMyString(void) {
  delete[] m_pData;
}

CMyString::CMyString(const CMyString &str) {
  int length = strlen(str.m_pData);
  m_pData = new char[length + 1];
  strcpy(m_pData, str.m_pData);
}

CMyString::CMyString(char const *pData) {
  if (pData == nullptr) {
    m_pData = new char[1];
    m_pData[0] = '\0';
  } else {
    int length = strlen(pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, pData);
  }
}

CMyString &CMyString::operator=(const CMyString &str) {
  if (this == &str) {
    return *this;
  }

  delete[] m_pData;
  m_pData = nullptr;

  m_pData = new char[strlen(str.m_pData) + 1];
  strcpy(m_pData, str.m_pData);

  return *this;
}

void CMyString::Print() {
  printf("%s", m_pData);
}
