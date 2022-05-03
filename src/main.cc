#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

#include "system.h"

void Info_Dorf();
void Register_Login(const System&);
void Login(const System&);
void Register(const System&);
int main() {

  // Info_Dorf();
  std::string user_file{"../users.txt"};
  System system{user_file, ""};
  
  Register_Login(system);

  return 0;
}

void Info_Dorf() {
  std::string texto;
  std::string linea;
  std::string intro_file{"../info_intro.txt"};
  std::ifstream archivo(intro_file);

  while (getline(archivo, linea)) {
    texto = texto + linea + "\n";
  }
  archivo.close();

  for (auto i : texto) {
      std::cout << i;
  }
  sleep(5);
  system("clear");
}

void Register_Login(const System& system) {
  bool opc{0};
  std::cout << "\t" << "Registrar (0):" << "\n" << "\t" << "Iniciar Sesion (1):" << std::endl;
  std::cout << "Elija una opcion: ";
  std::cin >> opc;
  while (opc != true && opc != false) {
    std::cerr << "Opcion incorrecta. Introduzcala de nuevo: ";
    std::cin >> opc;
  }

  if(opc) {
    Login(system);
  } else {
    Register(system);
  }
}

void Login(const System& system) {
  std::string username, password;
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> username;
  std::cout << "Introduzca la contraseña: ";
  std::cin >> password;

  while (!system.Login(username, password)) {
    std::cerr << "Usuario o contraseña incorrectas, vuelva a intentarlo." << std::endl;
    std::cout << "Introduzca el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduzca la contraseña: ";
    std::cin >> password;
  }
}

void Register(const System& system) {


}