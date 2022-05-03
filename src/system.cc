#include "system.h"

#include <fstream>

System::System(const std::string& users, const std::string& petitions) {
  std::ifstream user_file{users};
  std::ifstream petitions_file{petitions};
  std::string line{""};
  
  /// Crear vectores de usuarios

  while (getline(user_file, line)) {
    int i{0};
    std::string name{""}, username{""}, password{""}, email{""};
    username.push_back(line.at(i));
    while (line.at(++i) != ':') {
      username.push_back(line.at(i));
    }
    password.push_back(line.at(++i));
    while (line.at(++i) != ':') {
      password.push_back(line.at(i));
    }
    name.push_back(line.at(++i));
    while (line.at(++i) != ':') {
      name.push_back(line.at(i));
    }
    email.push_back(line.at(++i));
    while (++i < line.size()) {
      email.push_back(line.at(i));
    }
    User user(username, password, name, email);
    users_.push_back(user);
  }
}
int System::UserPos(const std::string& username) {
  for (int i = 0; i < users_.size(); i++) {
    if(users_.at(i).GetUsername() == username) {
      return i;
    }
  }
  return -1;
}
void System::CreateUser(void) {
  std::string name{""};
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> name;

}
bool System::Login(void) {
  std::string username, password;
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> username;
  std::cout << "Introduzca la contraseña: ";
  std::cin >> password;
  int pos = UserPos(username);

  if (pos != -1) {
    if (users_.at(pos).CheckPassword(password)) {
      
    }
  }
  return false;
}