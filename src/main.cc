#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

#include "system.h"

void Info_Dorf();
void Register_Login();

int main() {

  // Info_Dorf();
  std::string user_file{"../users.txt"};
  System system{user_file, ""};

  //Register_Login();


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

void Register_Login() {
  int opc{0};
  std::cout << "\t" << "Registrar (1):" << "\n" << "\t" << "Iniciar Sesion (2):" << std::endl;
  std::cout << "Elija una opcion: ";
  std::cin >> opc;

}