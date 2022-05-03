#include <iostream>
#include <fstream>
#include <string>

#include "system.h"
#include "user.h"

System::System(const std::string& users, const std::string& petitions) {
  std::ifstream user_file{users};
  std::string line{""};

  while (getline(user_file, line)) {
    
  }
}
void System::CreateUser(void) {
  std::string name{""};
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> name;

}