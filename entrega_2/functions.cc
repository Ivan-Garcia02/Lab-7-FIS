#include <iostream>
#include <string>

#include "functions.h"

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
  
  ChooseOption(false);
  int ch = 0;
  bool option{false};
  init_keyboard();
  while(ch != '\n'){
    if(kbhit ()){
      ch=readch(); 
      if (ch == 65) {
        option = false;
      } else if (ch == 66) {
        option = true;
      } 
      std::system("clear");
      ChooseOption(option); 
    }
  }
  close_keyboard();

  std::system("clear");
  if(option) {
    Login(system);
  } else {
    Register(system);
  }
  std::cout << "Sesion iniciada correctamente" << std::endl;
}
void Login(const System& system) {
  int ch = 0;
  std::string username{""}, password{""};
  User(username);
  init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
        AddWord(ch, username);
        std::system("clear");
        User(username); 
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
    User(username);
    init_keyboard();
      while(ch != '\n'){
        if(kbhit ()){
          ch=readch();        
          AddWord(ch, username);
          std::system("clear");
          User(username); 
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
  // system.GetUsers().at(pos).ManagePetitions();
}
void Register(const System& system) {
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
