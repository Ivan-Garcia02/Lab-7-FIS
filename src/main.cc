#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

#include "system.h"

void Info_Dorf();
int Register_Login(System&);
int Login(System&);
int Register(System&);
bool CheckEmail(const std::string&);
bool CheckUsername(const std::string&);
bool CheckName(const std::string&);
bool CheckPassword(std::string&);
void Show_menu(System&, int);
void ActualizarBaseDatos(System&);
void historia();


int main() {

  //Info_Dorf();
  std::string user_file{"../users.txt"};
  std::string petitions_file{"../PETITIONS/petition_general.txt"};
  System system{user_file, petitions_file};
  
  int user_pos = Register_Login(system);
  if (user_pos == -1) {
    return 1;
  }
  Show_menu(system, user_pos);

  ActualizarBaseDatos(system);

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

int Register_Login(System& system) {
  bool opc{0};
  std::cout << "\t" << "Registrar (0):" << "\n" << "\t" << "Iniciar Sesion (1):" << std::endl;
  std::cout << "Elija una opcion: ";
  std::cin >> opc;
  while (opc != true && opc != false) {
    std::cerr << "Opcion incorrecta. Introduzcala de nuevo: ";
    std::cin >> opc;
  }
  std::system("clear");
  int pos {0};
  if(opc) {
    pos = Login(system);
  } else {
    pos = Register(system);
  }
  std::cout << "Sesion iniciada correctamente" << std::endl;
  return pos;
}

int Login(System& system) {
  std::string username, password;
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> username;
  std::cout << "Introduzca la contraseña: ";
  std::cin >> password;
  int i{1};
  while (!system.Login(username, password)) {
    if (i == 4) {
      return -1;
    }
    std::cerr << "Usuario o contraseña incorrectas, vuelva a intentarlo." << std::endl;
    std::cout << "Introduzca el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Introduzca la contraseña: ";
    std::cin >> password;
    i++;
  }

  /// Siguiente fase
  int pos = system.UserPos(username);
  // system.GetUsers().at(pos).ManagePetitions();
  return pos;
}

int Register(System& system) {
  std::string username, password, name, email;
  std::vector<int> petition_fimardas, petition_creadas; 
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
  std::string add = "echo " + username + ":" + password + ":" + name + ":" + email +  ":" + ":" + ">> ../users.txt";
  std::system(add.c_str());
  system.Register(username, password,email ,name ,petition_fimardas, petition_creadas);
  
  /// Siguiente fase
  int pos = system.UserPos(username);
  // system.GetUsers().at(pos).ManagePetitions();
  return pos;
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


void Show_menu(System& system, int pos) {
  int opc{-1};
  while (opc != 0) {
    std::system("sleep 1");
    std::system("clear");
    std::cout << "\t" << "Cerrar Programa (0)" << std::endl;
    std::cout << "\t" << "Ver listado de peticiones (1)" << std::endl;
    std::cout << "\t" << "Crear peticion (2)" << std::endl;
    std::cout << "\t" << "Ver mis peticiones (3)" << std::endl;
    std::cout << "\t" << "Historia de la empresa (4)" << std::endl;
    std::cout << "Elija una opcion: ";
    std::cin >> opc;
    std::cout << std::endl;
    switch (opc)
    {
    case 1:
      system.ShowPetitions(pos);
      break;
    case 2:
      system.CreatePetition(pos);
      break;
    case 3:
      system.ShowMyPetitions(pos);
      break;
    case 4:
      historia();
      break;
    default:
      break;
    }
  }
}


void ActualizarBaseDatos(System& system) {
  std::string peticiones_firmadas, peticiones_creadas;

  std::string add = "rm ../users.txt";
  std::system(add.c_str());

  // Actualizar fichero de usuarios
  for (int i {0}; i < system.GetUsers().size(); i++) {
    User user_aux = system.GetUsers()[i];
    
    for (int j {0}; j < user_aux.GetPetitionsFirmadas().size(); j++) {
      peticiones_firmadas += std::to_string(user_aux.GetPetitionsFirmadas(j));
      if (j + 1 != user_aux.GetPetitionsFirmadas().size()) {
        peticiones_firmadas.push_back(',');
      }
    }

    for (int j {0}; j < user_aux.GetPetitionsCreadas().size(); j++) {
      peticiones_creadas += std::to_string(user_aux.GetPetitionsCreadas(j));
      if (j + 1 != user_aux.GetPetitionsCreadas().size()) {
        peticiones_creadas.push_back(',');  std::cout << std::endl;
      }
    }

    add = "echo " + user_aux.GetUsername() + ":" + user_aux.GetPassword() + ":" + user_aux.GetName() + ":" + user_aux.GetEmail() + ":" + peticiones_firmadas + ":" + peticiones_creadas + ">> ../users.txt";
    std::system(add.c_str());

    peticiones_creadas.clear();
    peticiones_firmadas.clear();
  }

  // Actualizar peticiones
  for (int i {0}; i < system.GetPetitions().size(); i++) {
    Petition petition_aux = system.GetPetitions()[i];

    add = "echo " + petition_aux.get_titulo() + ":" + petition_aux.get_descripcion() + ":" + std::to_string(petition_aux.get_usuario()) + ":" + std::to_string(petition_aux.get_firmas()) + "> ../PETITIONS/peticion" + std::to_string(i + 1) + ".txt";
    std::system(add.c_str());
  }

}


void historia() {

  std::string texto;
  std::string linea;
  std::string intro_file{"../info_empresa.txt"};
  std::ifstream archivo(intro_file);

  while (getline(archivo, linea)) {
    texto = texto + linea + "\n";
  }
  archivo.close();

  for (auto i : texto) {
      std::cout << i;
  }
  char esperar;
  std::cout << "Introducir algo para continuar: ";
  std::cin >> esperar;
}