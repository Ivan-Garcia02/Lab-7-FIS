#include "system.h"

#include <fstream>

System::System(const std::string& users, const std::string& petitions) {
  std::ifstream user_file{users};
  std::ifstream petitions_file{petitions};
  std::string line{""};
  
  /// Crear vectores de usuarios

  while (getline(user_file, line)) {
    int i{0};
    int j{0};
    std::string name{""}, username{""}, password{""}, email{""}, number{""};
    std::vector<int> petitions_firmadas, petitions_creadas;
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
    while (line.at(++i) != ':') {
      email.push_back(line.at(i));
    }

    while (line.at(++i) != ':') {
      if (line.at(i) == ',') {
        petitions_firmadas.push_back(std::stoi(number));
        number.clear();
      } else if (line.at(i+1) == ':') {
        number.push_back(line.at(i));
        petitions_firmadas.push_back(std::stoi(number));
        number.clear();
      } else {
        number.push_back(line.at(i));
      }
    }
    while (++i < line.size()) {
      if (line.at(i) == ',') {
        petitions_creadas.push_back(std::stoi(number));
        number.clear();
      } else if (i+1 == line.size()) {
        number.push_back(line.at(i));
        petitions_creadas.push_back(std::stoi(number));
        number.clear();
      } else {
        number.push_back(line.at(i));
      }
    }

    User user(username, password, name, email, petitions_firmadas, petitions_creadas);
    users_.push_back(user);
  }

  /// Crear vectores de peticiones
  
  std::string petition {""};
  while (getline(petitions_file, petition)) {
    std::string petition_file_str{"../BaseData/PETITIONS/"};
    petition_file_str = petition_file_str + petition;
    std::ifstream petition_name{petition_file_str}; 
    while (getline(petition_name, line)) { 
      int i{0};
      std::string titulo{""}, descripcion{""}, dueno{""}, firmas{""};
      titulo.push_back(line.at(i));
      while (line.at(++i) != ':') {
        titulo.push_back(line.at(i));
      }
      descripcion.push_back(line.at(++i));
      while (line.at(++i) != ':') {
        descripcion.push_back(line.at(i));
      }
      dueno.push_back(line.at(++i));
      while (line.at(++i) != ':') {
        dueno.push_back(line.at(i));
      }
      firmas.push_back(line.at(++i));
      while (++i < line.size()) {
        firmas.push_back(line.at(i));
      }
      Petition peticion(titulo, descripcion, std::stoi(firmas), std::stoi(dueno));
      petitions_.push_back(peticion);
    }
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
      return true;
    }
  }
  return false;
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

void System::Register(const std::string& username, const std::string& password, const std::string& email, const std::string& name, 
                      const std::vector<int>& petition_firmadas, const std::vector<int>& petition_creadas) {
  User user(username, password, name, email, petition_firmadas, petition_creadas);
  users_.push_back(user);
}



void System::ShowPetitions(int pos) {
  int number_peticion {-1};
  while (number_peticion != 0) {
    std::cout << std::endl;
    std::cout << "Peticiones: " << std::endl;
    for (int i {0}; i < petitions_.size(); i++) {
      std::cout << "(" << i + 1  << ") " << petitions_[i].get_titulo() << std::endl;
    }
  
    std::cout << "Indica el numero de la peticion a ver, o introducir 0 para volver atras: ";
    std::cin >> number_peticion;
    std::cout << std::endl;
    
    // FIRMAR PETICIONES
    if (number_peticion != 0 && number_peticion <= petitions_.size()) {
      std::cout << petitions_[number_peticion - 1] << std::endl;
      
      // FIRMAR PETICIONES
      char firmar;
      std::cout << std::endl;
      std::cout << "¿Quieres firmarla? (s/n) ->"; 
      std::cin >> firmar;
      std::cout << std::endl;
      if (firmar == 's') {
        if (users_[pos].CheckPetitionSing(number_peticion - 1) != false) {
          users_[pos].SingPetition(number_peticion - 1);
          petitions_[number_peticion - 1].inc_firmar();
          std::cout << "Acabas de firmar esta peticion" << std::endl;
        } 
        else {
          std::cout << "Ya habias firmado esta peticion" << std::endl;
        }
      std::cout << std::endl;
      }
      std::cout << "Pulsa una tecla para continuar: ";
      std::string esperar;
      std::getline(std::cin, esperar);
      std::getline(std::cin, esperar);
      system("clear");
    }
  }
}



void System::ShowMyPetitions(int pos) {
  int number_peticion {-1};
  if (users_[pos].GetPetitionsCreadas().empty()) {
    std::cout << "No hay ninguna peticion creada" << std::endl;
    std::cout << "Pulsa una tecla para continuar: ";
    std::string esperar;
    std::getline(std::cin, esperar);
    std::getline(std::cin, esperar);
    system("clear");
  } 
  else {
    while (number_peticion != 0) {
      std::cout << std::endl;
      std::cout << "Peticiones: " << std::endl;
      std::vector<int> peticiones_user = users_[pos].GetPetitionsCreadas();
      for (int i {0}; i < peticiones_user.size(); i++) {
        std::cout << "(" << peticiones_user[i]  << ") " << petitions_[peticiones_user[i]-1].get_titulo() << std::endl;
      }
    
      std::cout << "Indica el numero de la peticion a ver, o introducir 0 para volver atras: ";
      std::cin >> number_peticion;
      std::cout << std::endl;
      
      
      if (number_peticion != 0 && number_peticion <= petitions_.size()) {
        std::cout << petitions_[number_peticion-1] << std::endl;
      }
      std::cout << "Pulsa una tecla para continuar: ";
      std::string esperar;
      std::getline(std::cin, esperar);
      std::getline(std::cin, esperar);
      system("clear");
    } 
  }
}



void System::CreatePetition(int user) {
  std::string titulo;
  std::cout << "Introducir titulo de la peticion: ";
  getline(std::cin, titulo);
  getline(std::cin, titulo);

  std::string descripcion;
  std::cout << "Introducir descripcion de la peticion: ";
  getline(std::cin, descripcion);
  std::cout << std::endl;

  int PID = petitions_.size() + 1;
  /// añadir a la base de datos
  std::string add = "echo peticion" + std::to_string(PID) + ".txt" + " >> ../BaseData/PETITIONS/petition_general.txt";
  std::system(add.c_str());

  add = "echo " + titulo + ":" + descripcion + ":" + std::to_string(user) + ":0" + " >> ../BaseData/PETITIONS/peticion" + std::to_string(PID) + ".txt";
  std::system(add.c_str());
  petitions_.push_back(Petition(titulo, descripcion, 0, user));

  users_[user].CreatePetition(PID);
  
}