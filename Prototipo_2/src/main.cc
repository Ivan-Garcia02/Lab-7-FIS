#include <string>

#include "system.h"
#include "functions.h"

int main() {

  //Info_Dorf();
  std::string user_file{"../BaseData/users.txt"};
  std::string petitions_file{"../BaseData/PETITIONS/petition_general.txt"};
  std::string donations_file{"../BaseData/Donaciones.txt"};

  System system{user_file, petitions_file, donations_file};
  Register_Login(system);

  return 0;
}