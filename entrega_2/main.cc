#include <string>

#include "system.h"
#include "functions.h"

int main() {

  Info_Dorf();
  std::string user_file{"../users.txt"};
  System system{user_file, ""};
  
  Register_Login(system);
  
  return 0;
}

