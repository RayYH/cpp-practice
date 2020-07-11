#include <string>
#include "string_container.hpp"

StringContainer::StringContainer() {}

bool StringContainer::IsValid(std::string str) {
    return str.find("Kano") == 0;
}

int StringContainer::GetNumber() {
    return 5;
}
