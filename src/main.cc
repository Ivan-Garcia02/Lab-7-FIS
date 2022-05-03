#include <iostream>
#include <string>

#include "system.h"

int main() {
  std::string user_file{"../users.txt"};
  System system{user_file, ""};
  return 0;
}