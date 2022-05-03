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
int System::UserPos(const std::string& username) const {
  for (int i = 0; i < users_.size(); i++) {
    if(users_.at(i).GetUsername() == username) {
      return i;
    }
  }
  return -1;
}
bool System::EmailExist(const std::string& email) const {
  for (int i = 0; i < users_.size(); i++) {
    if(users_.at(i).GetEmail() == email) {
      return false;
    }
  }
  return true;
}
void System::CreateUser(void) {
  std::string username{""};
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> username;
  int pos = UserPos(username);

  if (pos != -1) {
  
  }
}
bool System::Login(const std::string& username, const std::string& password) const {
  int pos = UserPos(username);
  if (pos != -1) {
    if (GetUsers().at(pos).CheckPassword(password)) {
      return true;
    }
  }
  return false;
}