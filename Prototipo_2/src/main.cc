#include <string>

#include "system.h"
#include "functions.h"

int main() {

  Info_Dorf();
  std::string user_file{"../BaseData/users.txt"};
  std::string petitions_file{"../BaseData/PETITIONS/petition_general.txt"};

  System system{user_file, petitions_file};
  Register_Login(system);

  return 0;
}