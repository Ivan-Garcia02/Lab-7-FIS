#include <fstream>

#include "system.h"
#include "graphics.h"
#include "functions.h"
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
      int user{std::stoi(dueno)};
      Petition peticion(titulo, descripcion, std::stoi(firmas), users_.at(user).GetName());
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
bool System::Login(const std::string& username, const std::string& password) const {
  int pos = UserPos(username);
  if (pos != -1) {
    if (GetUsers().at(pos).CheckPassword(password)) {
      return true;
    }
  }
  return false;
}
void System::ShowPetitions(int pos) {
  GraphicPetitions(petitions_, 0);
  int ch = 0;
  int option{0};
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch(); 
      if (ch == 65) {
        --option;
      } else if (ch == 66) {
        ++option;
      }
      if(option < 0) option = 0;
      if(option > petitions_.size()) option = petitions_.size();
      std::system("clear");
      GraphicPetitions(petitions_, option); 
    }
  }
  close_keyboard();
  
  std::system("clear");
  if (option == 0) show_menu(*this, pos);
  IndividualPetition(petitions_.at(option - 1), 0);
  ch = 0;
  int sign{0};
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch(); 
      if (ch == 68) {
        --sign;
      } else if (ch == 67) {
        ++sign;
      }
      if(sign < 0) sign = 0;
      if(sign > 1) sign = 1;
      std::system("clear");
      IndividualPetition(petitions_.at(option - 1), sign); 
    }
  }
  close_keyboard();
  std::system("clear");
  if (sign == 0) {
    if (users_[pos].CheckPetitionSing(option - 1) != false) {
      users_[pos].SingPetition(option - 1);
      petitions_.at(option - 1).inc_firmar();
      SignPetition(petitions_.at(option - 1), "Acabas de firmar esta peticion");
    } 
    else {
      SignPetition(petitions_.at(option - 1), "Ya habias firmado esta peticion");
    }
  } else {
    SignPetition(petitions_.at(option - 1), "");
  }
  ch = 0;
  init_keyboard();
  while(ch == 0){
    if(kbhit ()){
      ch=readch(); 
    }
  }
  close_keyboard();
  std::system("clear");
  ShowPetitions(pos);
}
void System::ShowMyPetitions(int pos) {
// MENSAJE NO HAY PETICIONES
  if (users_[pos].GetPetitionsCreadas().empty()) {
    EmptyMyPet();
    int ch{0};
    init_keyboard();
    while (ch == 0) {
      if (kbhit()) {
        ch = readch();
      }
    }
    close_keyboard();
    std::system("clear");
    show_menu(*this, pos);
  } 
  // MOSTRAR PETICIONES
  else {

    std::vector<int> peticiones_user = users_[pos].GetPetitionsCreadas();
    ShowMyPet(petitions_, peticiones_user, 0);
    int ch = 0;
    int option{0}, choose{0};
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch(); 
        if (ch == 65) {
          --option;
        } else if (ch == 66) {
          ++option;
        }
        if(option < 0) option = 0;
        if(option > peticiones_user.size()) option = peticiones_user.size();
        std::system("clear");
        choose = ShowMyPet(petitions_, peticiones_user, option); 
      }
    }
    close_keyboard();
    std::system("clear");
    if (option == 0) show_menu(*this, pos);
    IndividualPetition(petitions_.at(choose), 0);
    ch = 0;
    int sign{0};
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch(); 
        if (ch == 68) {
          --sign;
        } else if (ch == 67) {
          ++sign;
        }
        if(sign < 0) sign = 0;
        if(sign > 1) sign = 1;
        std::system("clear");
        IndividualPetition(petitions_.at(choose), sign); 
      }
    }
    close_keyboard();
    std::system("clear");
    if (sign == 0) {
      if (users_[pos].CheckPetitionSing(choose) != false) {
        users_[pos].SingPetition(choose);
        petitions_.at(choose).inc_firmar();
        SignPetition(petitions_.at(choose), "Acabas de firmar esta peticion");
      } 
      else {
        SignPetition(petitions_.at(choose), "Ya habias firmado esta peticion");
      }
    } else {
      SignPetition(petitions_.at(choose), "");
    }
    ch = 0;
    init_keyboard();
    while(ch == 0){
      if(kbhit ()){
        ch=readch(); 
      }
    }
    close_keyboard();
    std::system("clear");
    ShowMyPetitions(pos);
    // while (number_peticion != 0) {
    //   std::cout << std::endl;
    //   std::cout << "Peticiones: " << std::endl;
    //   // std::vector<int> peticiones_user = users_[pos].GetPetitionsCreadas();
    //   for (int i {0}; i < peticiones_user.size(); i++) {
    //     std::cout << "(" << peticiones_user[i]  << ") " << petitions_[peticiones_user[i]-1].get_titulo() << std::endl;
    //   }
    
    //   std::cout << "Indica el numero de la peticion a ver, o introducir 0 para volver atras: ";
    //   std::cin >> number_peticion;
    //   std::cout << std::endl;
      
      
      // if (number_peticion != 0 && number_peticion <= petitions_.size()) {
      //   //std::cout << petitions_[number_peticion-1] << std::endl;
      // }
      // std::cout << "Pulsa una tecla para continuar: ";
      // std::string esperar;
      // std::getline(std::cin, esperar);
      // std::getline(std::cin, esperar);
      // system("clear");
  }
}
// }
void System::CreatePetition(int user) {
  std::string titulo{""}, descripcion{""};

  /// INTRODUCIR TITULO
  std::system("clear");
  CreatePetName(titulo);
  int ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, titulo);
      std::system("clear");
      CreatePetName(titulo);
    }
  }
  close_keyboard();

  /// INTRODUCIR DESCRIPCION
  std::system("clear");
  CreatePetDesc(descripcion);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, descripcion);
      std::system("clear");
      CreatePetDesc(descripcion);
    }
  }
  close_keyboard();

  int PID = petitions_.size() + 1;
  /// añadir a la base de datos
  std::string add = "echo peticion" + std::to_string(PID) + ".txt" + " >> ../BaseData/PETITIONS/petition_general.txt";
  std::system(add.c_str());

  add = "echo " + titulo + ":" + descripcion + ":" + std::to_string(user) + ":0" + " >> ../BaseData/PETITIONS/peticion" + std::to_string(PID) + ".txt";
  std::system(add.c_str());
  petitions_.push_back(Petition(titulo, descripcion, 0, this->GetUsers().at(user).GetName()));

  users_[user].CreatePetition(PID);
  ch = 0;
  std::system("clear");
  WaitCreatePet();
  init_keyboard();
  while(ch == 0){
    if(kbhit ()){
      ch=readch(); 
    }
  }
  close_keyboard();
  std::system("clear");
  show_menu(*this, user); 
}