#include <iostream>
#include <string>
#include "user.h"
#include "system_temp.h"



void System::Login(void) {
  std::string username, password;
  std::cin >> username;
  if (UserExist(username)) {
    std::cout << "Introduzca el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduzca la contraseña: ";
    std::cin >> password;
    if (CheckPassword(password)) {
      
    }
  }
}
