#include <iostream>
#include <string>
#include "user.h"
#include "system_temp.h"



void System::Login(void) {
  std::string username, password;
  if (UserExist(GetUsername())) {
    std::cout << "Introduzca el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduzca la contraseña: ";
    std::cin >> password;
    if (CheckPassword(password)) {
      
    }
  }
}
