#include "system.h"

#include <fstream>

System::System(const std::string& users, const std::string& petitions) {
  std::ifstream user_file{users};
  std::ifstream petitions_file{petitions};
  std::string line{""};
  std::vector<User> vec_users;
  while (getline(user_file, line)) {
    int i{0};
    std::string name{""}, username{""}, password{""}, email{""};
    while (line.at(i) != ':') {
      username.push_back(line.at(i));
      ++i;
    }
    while (line.at(i) != ':') {
      password.push_back(line.at(i));
      ++i;
    }
    while (line.at(i) != ':') {
      name.push_back(line.at(i));
      ++i;
    }
    while (i < line.size()) {
      email.push_back(line.at(i));
      ++i;
    }
    User user(username, password, name, email);
    vec_users.push_back(user);
  }
}
void System::CreateUser(void) {
  std::string name{""};
  std::cout << "Introduzca el nombre de usuario: ";
  std::cin >> name;

}