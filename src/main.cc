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
bool CheckEmail(const std::string&);
bool CheckUsername(const std::string&);
bool CheckName(const std::string&);
bool CheckPassword(std::string&);


int main() {

  Info_Dorf();
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
  std::system("clear");
  if(opc) {
    Login(system);
  } else {
    Register(system);
  }
  std::cout << "Sesion iniciada correctamente" << std::endl;
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

  /// Siguiente fase
  int pos = system.UserPos(username);
  // system.GetUsers().at(pos).ManagePetitions();
}

void Register(const System& system) {
  std::string username, password, name, email;
  std::cout << "Introduzca el correo electrónico: ";
  std::cin >> email;
  while(!CheckEmail(email) || system.EmailExist(email)) {
    if (!CheckEmail(email)) {
      std::cerr << "Email no valido, ";
    } else {
      std::cerr << "Email ya registrado, ";
    }
    std::cerr << "introduzcalo de nuevo: ";
    std::cin >> email;
  }
  std::cout << "Introduzca el nombre del usuario: ";
  std::cin >> username;
  while(!CheckUsername(username) || system.UserPos(username) != -1) {
    if (!CheckUsername(username)) {
      std::cerr << "Nombre de usuario no valido, ";
    } else {
      std::cerr << "Nombre de usuario ya registrado, ";
    }
    std::cerr << "introduzcalo de nuevo: ";
    std::cin >> username;
  }
  std::cout << "Introduzca su nombre y su primer apellido: ";
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  while(!CheckName(name)) {
    std::cerr << "Nombre no valido, introduzcalo de nuevo: ";
    std::getline(std::cin, name);
  }
  std::cout << "Introduzca la contraseña: ";
  std::cin >> password;
  while(!CheckPassword(password)) {
    std::cerr << "Contraseña no valida, introduzcala de nuevo: ";
    std::cin >> password;
  }
  /// añadir a la base de datos
  std::string add = "echo " + username + ":" + password + ":" + name + ":" + email + " >> ../users.txt";
  std::system(add.c_str());

  /// Siguiente fase
  int pos = system.UserPos(username);
  // system.GetUsers().at(pos).ManagePetitions();
}

bool CheckEmail(const std::string& email) {
  int i{0};
  while (i < email.size() && email.at(i) != '@') {
    if(!isalnum(email.at(i))) {
      return false;
    }
    ++i;
  }
  if (i == email.size()) {
    return false;
  }
  if (i == 0 || (email.at(++i) == '.')) {
    return false;
  }
  while (i < email.size() && email.at(i) != '.') {
    if(!isalpha(email.at(i))) {
      return false;
    }
    ++i;
  }
  if (i == email.size()) {
    return false;
  }
  ++i;
  while (i < email.size()) {
    if(!isalpha(email.at(i))) {
      return false;
    }
    ++i;    
  }
  return true;
}

bool CheckUsername(const std::string& username) {
  for (int i = 0; i < username.size(); i++) {
    if (!isalnum(username.at(i))) {
      return false;
    }
  }
  return true;
}

bool CheckName(const std::string& name) {
  int i{0};
  while (i < name.size() && name.at(i) != ' ') {
    if(!isalpha(name.at(i))) {
      return false;
    }
    ++i;
  }
  if (i == name.size()) {
    return false;
  }
  ++i;
  while (i < name.size()) {
    if(!isalpha(name.at(i))) {
      return false;
    }
    ++i;    
  }
  return true;
}

bool CheckPassword(std::string& password) {
  while (password.size() < 4) {
    std::cout << "Introduzca una contraseña de un minimo de 4 caracteres: ";
    std::cin >> password;
  }
  for (int i = 0; i < password.size(); i++) {
    if (!isalnum(password.at(i))) {
      return false;
    }
  }
  std::cout << "Confirme la contraseña: ";
  std::string confirm;
  std::cin >> confirm;
  return confirm == password;
}
