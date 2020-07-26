#include "string_container.hpp"
#include "string_container_operations.hpp"

bool CheckStringContainer(StringContainer &stringContainer) {
  if (!stringContainer.IsValid("KanoTest")) {
    return false;
  }
  stringContainer.GetNumber();
  stringContainer.GetNumber();
  stringContainer.GetNumber();
  return true;
}
