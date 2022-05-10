#include <iostream>

#include "graphics.h"

void ChooseOption (bool option) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                      ELIJA OPCION                      ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body{""};
  if (option) {
    body =     "║ 1. Registrar usuario                                   ║\n║                                                        ║\n";
    body += "║ \033[7m2. Iniciar sesion\033[0m                                      ║\n";
  } else {
    body =     "║ \033[7m1. Registrar usuario\033[0m                                   ║\n║                                                        ║\n";
    body += "║ 2. Iniciar sesion                                      ║\n";
  }

  std::cout << body;             
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Passwd (const std::string& password) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ contraseña: ";
  body += password;
  for (int i = password.size(); i < 43; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║ confirme contraseña:                                   ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void ConfirmPasswd (const std::string& password, const std::string& confirm) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ contraseña: ";
  body += password;
  for (int i = password.size(); i < 43; i++) {
    body += " ";
  }
  body += "║\n║                                                        ║\n";
  
  std::cout << body;
  body = "║ confirme contraseña: ";
  body += confirm;
  for (int i = confirm.size(); i < 34; i++) {
    body += " ";
  }
  body += "║\n";
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Name (const std::string& name) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ nombre: ";
  body += name;
  for (int i = name.size(); i < 47; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║ apellido:                                              ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Surname (const std::string& name, const std::string& surname) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ nombre: ";
  body += name;
  for (int i = name.size(); i < 47; i++) {
    body += " ";
  }
  body += "║\n║                                                        ║\n";
  std::cout << body;
  body = "║ apellido: ";
  body += surname;
  for (int i = surname.size(); i < 45; i++) {
    body += " ";
  }
  body += "║\n";
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Email (const std::string& email) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ email: ";
  body += email;
  for (int i = email.size(); i < 48; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Username (const std::string& username) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ usuario: ";
  body += username;
  for (int i = username.size(); i < 46; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void RegisterError(const std::string& error) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n"
               "║                         ERROR                          ║\n"
               "║                                                        ║\n";
  std::string body = "║ ";
  body += error;
  for (int i = error.size(); i < 55; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n"; 
}
void User (const std::string& username) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    INICIO DE SESION                    ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string name = "║ usuario: ";
  name += username;
  for (int i = username.size(); i < 46; i++) {
    name += " ";
  }
  name += "║\n";
  
  std::cout << name;
  std::cout << "║                                                        ║\n"
               "║ contraseña:                                            ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Password (const std::string& username, const std::string& password) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    INICIO DE SESION                    ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string name = "║ usuario: ";
  name += username;
  for (int i = username.size(); i < 46; i++) {
    name += " ";
  }
  name += "║\n";
  std::string passwd =  "║                                                        ║\n║ contraseña: ";
  passwd += password;
  for (int i = password.size(); i < 43; i++) {
    passwd += " ";
  }
  passwd += "║\n";
  
  std::cout << name << passwd; 
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void ErrorLogin (void) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n"
               "║                    INICIO DE SESION                    ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n"
               "║                         ERROR                          ║\n"
               "║                                                        ║\n"
               "║            Usuario o contraseña incorrectos            ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void init_keyboard() {
  tcgetattr(0, &initial_settings);
  new_settings = initial_settings;
  new_settings.c_lflag &= ~ICANON;
  new_settings.c_lflag &= ~ECHO;
  new_settings.c_lflag &= ~ISIG;
  new_settings.c_cc[VMIN]=1;
  new_settings.c_cc[VTIME]=0;
  tcsetattr(0, TCSANOW, &new_settings);
  return;
}
void close_keyboard() {
  tcsetattr(0, TCSANOW, &initial_settings);
  return;
}
int kbhit () {
  char ch;
  int nread;
  if (peek_character != -1) {
    return 1;
  }                     
  new_settings.c_cc[VMIN] = 0;
  tcsetattr(0, TCSANOW, &new_settings);
  nread=read (0, &ch, 1);
  new_settings.c_cc[VMIN]=13;
  tcsetattr(0, TCSANOW, &new_settings);

  if (nread == 1){
    peek_character = ch;
    return 1;                             
  }
  return 0;
}
int readch() {
  char ch;
  if (peek_character != 1) {
    ch=peek_character;
    peek_character=-1;
    return ch;
  }
  read (0, &ch, 1);
  return ch;
}
