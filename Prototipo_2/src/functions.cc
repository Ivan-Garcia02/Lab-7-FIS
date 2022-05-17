#include <iostream>
#include <string>

#include "functions.h"
#include "system.h"
#include "graphics.h"

void AddWord(int ch, std::string& word) {  
  if (ch != '\n') {
    if (ch == 127) {
      if (word.size() > 0)
        word.pop_back();
    } else {
      word.push_back(ch);
    }
  }
}
void Info_Dorf() {
  std::string texto;
  std::string linea;
  std::string intro_file{"../BaseData/info_intro.txt"};
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
void Register_Login(System& system) {
  
  ChooseOption(0);
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
      if(option > 2) option = 2;
      std::system("clear");
      ChooseOption(option); 
    }
  }
  close_keyboard();

  std::system("clear");
  if (option == 1) {
    Login(system);
  } else if (option == 0){
    Register(system);
  } else {
    ActualizarBaseDatos(system);
    exit(EXIT_SUCCESS);
  }
}
void Login(System& system) {
  int ch = 0;
  std::string username{""}, password{""};
  UserCreate(username);
  init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, username);
        std::system("clear");
        UserCreate(username); 
      }
    }
    std::string aster{""};
    ch = 0;
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        if (ch != '\n') {
          if (ch == 127) {
            if (password.size() > 0) {
              password.pop_back();
              aster.pop_back();
            }
          } else {
            password.push_back(ch);
            aster.push_back('*');
          }
          std::system("clear");
          Password(username, aster);
        }   
      }
    }
  close_keyboard();

  while (!system.Login(username, password)) {
    std::system("clear");
    ErrorLogin();
    sleep(3);
    std::system("clear");
    int ch = 0;
    username ="", password = "";
    UserCreate(username);
    init_keyboard();
      while(ch != '\n'){
        if(kbhit ()){
          ch=readch();        
          AddWord(ch, username);
          std::system("clear");
          UserCreate(username); 
        }
      }
      std::string aster{""};
      ch = 0;
      while(ch != '\n'){
        if(kbhit ()){
          ch=readch();        
          if (ch != '\n') {
            if (ch == 127) {
              if (password.size() > 0) {
                password.pop_back();
                aster.pop_back();
              }
            } else {
              password.push_back(ch);
              aster.push_back('*');
            }
            std::system("clear");
            Password(username, aster);
          }   
        }
      }
    close_keyboard();    
  }

  /// Siguiente fase
  int pos = system.UserPos(username);
  show_menu(system, pos);
  return;
}
void Register(System& system) {
  std::string username{""}, password{""}, confirm{""}, name{""}, surname{""}, email{""};

  /// INTRODUCIR EMAIL
  std::system("clear");
  Email(email);
  int ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, email);
      std::system("clear");
      Email(email);
    }
  }
  close_keyboard();
  while(!CheckEmail(email) || system.EmailExist(email)) {
    
    std::system("clear");
    if (!CheckEmail(email)) {
      RegisterError("Email no valido, introduzcalo de nuevo.");
    } else {
      RegisterError("Email ya registrado, introduzcalo de nuevo.");
    }
    sleep(3);
    std::system("clear");
    ch = 0;
    email = "";
    Email(email);
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, email);
        std::system("clear");
        Email(email);
      }
    }
    close_keyboard();
  }
  /// INTRODUCIR USUARIO
  std::system("clear");
  Username(username);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, username);
      std::system("clear");
      Username(username);
    }
  }
  close_keyboard();
  while(!CheckUsername(username) || system.UserPos(username) != -1) {
    std::system("clear");
    if (!CheckUsername(username)) {
      RegisterError("Nombre de usuario no valido,introduzcalo de nuevo.");
    } else {
      RegisterError("Nombre de usuario ya registrado,introduzcalo de nuevo.");
    }
    sleep(3);
    std::system("clear");
    ch = 0;
    username = "";
    Username(username);
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, username);
        std::system("clear");
        Username(username);
      }
    }
    close_keyboard();
  }
  /// INTRODUCIR NOMBRE Y APELLIDO
  std::system("clear");
  Name(name);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, name);
      std::system("clear");
      Name(name);
    }
  }
  ch = 0;
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, surname);
      std::system("clear");
      Surname(name, surname);
    }
  }
  close_keyboard();
  name = name + " " + surname;
  while(!CheckName(name)) {
    std::system("clear");
    RegisterError("Nombre no valido, introduzcalo de nuevo.");
    sleep(3);
    std::system("clear");
    name = "";
    surname = "";
    Name(name);
    ch = 0;
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, name);
        std::system("clear");
        Name(name);
      }
    }
    ch = 0;
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, surname);
        std::system("clear");
        Surname(name, surname);
      }
    }
    close_keyboard();
    name = name + " " + surname;
  }
  /// INTRODUCIR CONTRASEÑA
  std::system("clear");
  std::string aster{""}, aster2{""};
  Passwd(aster);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      if (ch != '\n') {
        if (ch == 127) {
          if (password.size() > 0) {
            password.pop_back();
            aster.pop_back();
          }
        } else {
          password.push_back(ch);
          aster.push_back('*');
        }
        std::system("clear");
        Passwd(aster);
      }
    }
  }
  ch = 0;
  std::system("clear");
  ConfirmPasswd(aster, aster2);
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      if (ch != '\n') {
        if (ch == 127) {
          if (confirm.size() > 0) {
            confirm.pop_back();
            aster2.pop_back();
          }
        } else {
          confirm.push_back(ch);
          aster2.push_back('*');
        }
        std::system("clear");
        ConfirmPasswd(aster, aster2);
      }
    }
  }
  close_keyboard();

  while(CheckPassword(password, confirm) != 0) {
    std::system("clear");
    if (CheckPassword(password, confirm) == 1) {
      RegisterError("Contraseña muy corta, introduzcala de nuevo.           ");
    } else if (CheckPassword(password, confirm) == 2) {
      RegisterError("Contraseña no valida, introduzcala de nuevo.           ");
    } else {
      RegisterError("Las contraseñas no coinciden, introduzcala de nuevo.   ");
    }
    sleep(3);
    std::system("clear");
    ch = 0;
    password = "", aster = "";
    confirm = "", aster2 = "";
    Passwd(aster);
    init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        if (ch != '\n') {
          if (ch == 127) {
            if (password.size() > 0) {
              password.pop_back();
              aster.pop_back();
            }
          } else {
            password.push_back(ch);
            aster.push_back('*');
          }
          std::system("clear");
          Passwd(aster);
        }
      }
    }
    ch = 0;
    std::system("clear");
    ConfirmPasswd(aster, aster2);
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        if (ch != '\n') {
          if (ch == 127) {
            if (confirm.size() > 0) {
              confirm.pop_back();
              aster2.pop_back();
            }
          } else {
            confirm.push_back(ch);
            aster2.push_back('*');
          }
          std::system("clear");
          ConfirmPasswd(aster, aster2);
        }
      }
    }
    close_keyboard();
  }
  /// añadir a la base de datos
  std::string add = "echo " + username + ":" + password + ":" + name + ":" + email + ":" + ":" + " >> ../BaseData/users.txt";
  std::system(add.c_str());

  /// Necesidad de recargar el sistema
  std::string user_file{"../BaseData/users.txt"};
  std::string petitions_file{"../BaseData/PETITIONS/petition_general.txt"};
  std::string donations_file{"../BaseData/Donaciones.txt"};
  System reload{user_file, petitions_file, donations_file};
  system = reload;
  
  /// Siguiente fase
  system.GetUsers();
  int pos = system.UserPos(username);
  show_menu(system, pos);
  return;
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
int CheckPassword(const std::string& password, const std::string& confirm) {
  while (password.size() < 4) {
    return 1;
  }
  for (int i = 0; i < password.size(); i++) {
    if (!isalnum(password.at(i))) {
      return 2;
    }
  }
  if (confirm != password)
    return 3;
  return 0;
}
void show_menu(System& system, int pos) {
  Menu(0);
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
      if(option > 5) option = 5;
      std::system("clear");
      Menu(option); 
    }
  }
  close_keyboard();
  std::system("clear");
  if (option == 0) {
    ActualizarBaseDatos(system);
    Register_Login(system);
  } else if (option == 1) {
    system.ShowPetitions(pos);
  } else if (option == 2) {
    system.CreatePetition(pos);
    std::string user_file{"../BaseData/users.txt"};
    std::string petitions_file{"../BaseData/PETITIONS/petition_general.txt"};
    std::string donations_file{"../BaseData/Donaciones.txt"};
    System update{user_file, petitions_file, donations_file};
    system = update;
  } else if (option == 3) {
    system.ShowMyPetitions(pos);
  } else if (option == 4) {
    historia();
  } else {
    DONATE(system);
    show_menu(system, pos);
  }
}
void ActualizarBaseDatos(System& system) {
  std::string peticiones_firmadas, peticiones_creadas;

  std::string add = "rm ../BaseData/users.txt";
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

    add = "echo " + user_aux.GetUsername() + ":" + user_aux.GetPassword() + ":" + user_aux.GetName() + ":" + user_aux.GetEmail() + ":" + peticiones_firmadas + ":" + peticiones_creadas + ">> ../BaseData/users.txt";
    std::system(add.c_str());

    peticiones_creadas.clear();
    peticiones_firmadas.clear();
  }

  // Actualizar peticiones
  for (int i {0}; i < system.GetPetitions().size(); i++) {
    Petition petition_aux = system.GetPetitions()[i];
    int j;
    for (j = 0; j < system.GetUsers().size(); j++) {
      if (system.GetUsers().at(j).GetName() == petition_aux.get_usuario()) break;
    }
    add = "echo " + petition_aux.get_titulo() + ":" + petition_aux.get_descripcion() + ":" + std::to_string(j) + ":" + std::to_string(petition_aux.get_firmas()) + ":" + std::to_string(petition_aux.get_donation()) + "> ../BaseData/PETITIONS/peticion" + std::to_string(i + 1) + ".txt";
    std::system(add.c_str());
  }

  // Actualizar donaciones
  add = "echo " + std::to_string(system.GetCantidadDonada()) + "> ../BaseData/Donaciones.txt";
  std::system(add.c_str());

}
void historia() {
  std::system("clear");
  History();
  int ch = 0;
  init_keyboard();
  while(ch == 0){
    if(kbhit ()){
      ch=readch(); 
    }
  }
  close_keyboard();
  std::system("clear");
}


void DONATE(System& system) {
  std::string money{""}, tarjeta{""}, fecha{""}, cvv{""};

  /// INTRODUCIR cantidad
  std::system("clear");
  Cantidad(money);
  int ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, money);
      std::system("clear");
      Cantidad(money);
    }
  }
  close_keyboard();
  

  /// INTRODUCIR tarjeta
  std::system("clear");
  Tarjeta(tarjeta);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, tarjeta);
      std::system("clear");
      Tarjeta(tarjeta);
    }
  }
  close_keyboard();

  /// INTRODUCIR fecha
  std::system("clear");
  Fecha(fecha);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, fecha);
      std::system("clear");
      Fecha(fecha);
    }
  }
  close_keyboard();

  /// INTRODUCIR CVV
  std::system("clear");
  CVV(cvv);
  ch = 0;
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch();        
      AddWord(ch, cvv);
      std::system("clear");
      CVV(cvv);
    }
  }
  close_keyboard();

  system.GetCantidadDonada() =  system.GetCantidadDonada() + std::stoi(money);
  MensajeDonacion(system.GetCantidadDonada(), money);
  sleep (3);
  std::system("clear");
}