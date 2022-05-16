#include <iostream>

#include "graphics.h"

void History(void) {
  std::cout << "╔═════════════════════════════════════════════════════════╗\n" 
               "║        NUESTRA HISTORIA NOS HACE SER COMO SOMOS         ║\n"
               "║                  DEMOCRACIA EN ACCIÓN                   ║\n"
               "╠═════════════════════════════════════════════════════════╣\n"
               "║                                                         ║\n"
               "║ Dorf nace de la necesidad de poder dotar de voz y hacer ║\n"
               "║ partícipe en la toma de decisiones a la ciudadanía.     ║\n"
               "║ Una manera sencilla y directa de hacer llegar las       ║\n"
               "║ inquietudes y reclamaciones de los habitantes a sus     ║\n"
               "║ respectivas administraciones.                           ║\n"
               "║ El objetivo de la plataforma es ser la voz del          ║\n"
               "║ ciudadano, por ello nace Dorf (pueblo, en alemán).      ║\n"
               "║                                                         ║\n"
               "║        Pulsa cualquier tecla para continuar...          ║\n"
               "║                                                         ║\n"
               "╚═════════════════════════════════════════════════════════╝\n";
}
void WaitCreatePet() {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                     CREAR PETICION                     ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n"
               "║            Peticion creada correctamente               ║\n"
               "║                                                        ║\n"
               "║        Pulsa cualquier tecla para continuar...         ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void CreatePetDesc(const std::string& desc) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                     CREAR PETICION                     ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ Descripcion: ";
  if (desc.size() <= 41) {
    body += desc;
    for (int i = desc.size(); i < 42; i++) {
      body += " ";
    }
    body += "║\n";
    
  } else {
    int i{0}, limit{41}, line{54}, j{0}, stop{line}, n{1};
    for (i = 0; i < limit; i++) {
      body += desc.at(i);
      if (i == 39 && desc.at(i + 1) != ' ') body += '-', --limit;
    }
    body += " ║\n║ ";
    while (i < desc.size()) {
      if (j == 0 && desc.at(i) == ' ')
        ++stop;
      else {
        body += desc.at(i);
        if (j == stop - 2 && desc.size() >= ((line * n) + 41) && desc.at(i + 1) != ' ')
          ++j, body += "-";
      }
      ++i, ++j;
      if (j == stop) ++n, j = 0, body += " ║\n║ ";
    }
    for (int i = j ; i < 55; i++) {
      body += " ";
    }
    body += "║\n";
  }
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void CreatePetName(const std::string& tittle) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                     CREAR PETICION                     ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ Titulo: ";
  body += tittle;
  for (int i = tittle.size(); i < 47; i++) {
    body += " ";
  }
  body += "║\n";
  
  std::cout << body;
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void SignPetition(const Petition& petition, const std::string& message) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n║";
  int mid{(55 - int(petition.get_titulo().size())) / 2};
  for (int i = 0; i < mid; i++) {
    std::cout << " ";
  }
  std::cout << petition.get_titulo();
  for (int i = mid + petition.get_titulo().size(); i <= 55; i++) {
    std::cout << " ";
  }
  std::cout << "║\n╠════════════════════════════════════════════════════════╣\n"
                  "║                                                        ║\n║";
  mid = (55 - message.size()) / 2;
  for (int i = 0; i < mid; i++) {
    std::cout << " ";
  }
  std::cout << message;
  for (int i = mid + message.size(); i <= 55; i++) {
    std::cout << " ";
  }
  std::cout << "║\n║                                                        ║\n"
               "║        Pulsa cualquier tecla para continuar...         ║\n"
               "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void IndividualPetition(const Petition& petition, int option) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n║";
  int mid{(55 - int(petition.get_titulo().size())) / 2};
  for (int i = 0; i < mid; i++) {
    std::cout << " ";
  }
  std::cout << petition.get_titulo();
  for (int i = mid + petition.get_titulo().size(); i <= 55; i++) {
    std::cout << " ";
  }
  std::cout << "║\n╠════════════════════════════════════════════════════════╣\n"
                  "║                                                        ║\n";
  std::cout << "║ Autor: " + petition.get_usuario();
  for (int i = petition.get_usuario().size(); i <= 47; i++) {
    std::cout << " ";
  }
  std::cout << "║\n║                                                        ║\n";
  std::cout << "║ Nº de firmas: " + std::to_string(petition.get_firmas());
  int size{0}, n_firmas{petition.get_firmas()};
  if (n_firmas == 0) 
    size = 1;
  else
    while (n_firmas > 0) ++size, n_firmas/= 10;
  for (int i = size; i <= 40; i++) {
    std::cout << " ";
  }
  std::cout << "║\n║                                                        ║\n";
  std::string desc = petition.get_descripcion();
  std::string body = "║ Descripcion: ";
  if (desc.size() <= 41) {
    body += desc;
    for (int i = desc.size(); i < 42; i++) {
      body += " ";
    }
    body += "║\n";
    
  } else {
    int i{0}, limit{41}, line{54}, j{0}, stop{line}, n{1};
    for (i = 0; i < limit; i++) {
      body += desc.at(i);
      if (i == 39 && desc.at(i + 1) != ' ') body += '-', --limit;
    }
    body += " ║\n║ ";
    int push_space{55};
    while (i < desc.size()) {
      if (j == 0 && desc.at(i) == ' ')
        ++stop; 
      else {
        body += desc.at(i);
        if (j == stop - 2 && desc.size() >= ((line * n) + 41) && desc.at(i + 1) != ' ')
          ++j, body += "- ║\n║ ", j = 0, ++n, ++push_space;
        else if (j == stop - 2 && desc.at(i + 1) == ' ')
          ++j, body += "  ║\n║ ", j = 0, ++n, ++push_space, ++i;
      }
      if (j == stop) ++n, j = 0, body += " ║\n║ ";
      ++i, ++j;

    }
    for (int i = j ; i < push_space; i++) {
      body += " ";
    }
    body += "║\n";
  }
  std::cout << body;
  std::cout << "║                                                        ║\n";
  std::cout << "║                   ¿Quiere firmarla?                    ║\n║                                                        ║\n";
  if (option == 0)
    std::cout << "║                 \033[7mSi\033[0m                 No                  ║\n";
  else
    std::cout << "║                 Si                 \033[7mNo\033[0m                  ║\n";
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void GraphicPetitions (const std::vector<Petition>& petitions, int option) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                      ELIJA OPCION                      ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body{""};
  if (option == 0) {
    body =  "║ \033[7m0. Volver atrás programa\033[0m                               ║\n";
  } else {
    body =  "║ 0. Volver atrás programa                               ║\n";
  }
  for (int i = 0; i < petitions.size(); i++) {
    body += "║                                                        ║\n";
    if (option == (i + 1))
      body = body + "║ " + "\033[7m" + std::to_string(i + 1) + ". " + petitions.at(i).get_titulo() + "\033[0m";
    else
      body = body + "║ " + std::to_string(i + 1) + ". " + petitions.at(i).get_titulo();
    for (int j = petitions.at(i).get_titulo().size(); j < 52; j++) {
      body += " ";
    }
    body += "║\n";
  }
  std::cout << body;             
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void Menu (int option) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                      ELIJA OPCION                      ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body{""};
  if (option == 0) {
    body =  "║ \033[7m0. Cerrar sesion\033[0m                                       ║\n";
    body += "║                                                        ║\n";
    body += "║ 1. Ver listado de peticiones                           ║\n";
    body += "║                                                        ║\n";
    body += "║ 2. Crear peticion                                      ║\n";
    body += "║                                                        ║\n";
    body += "║ 3. Ver mis peticiones                                  ║\n";
    body += "║                                                        ║\n";
    body += "║ 4. Historia de la empresa                              ║\n";
  } else if (option == 1) {
    body =  "║ 0. Cerrar sesion                                       ║\n";
    body += "║                                                        ║\n";
    body += "║ \033[7m1. Ver listado de peticiones\033[0m                           ║\n";
    body += "║                                                        ║\n";
    body += "║ 2. Crear peticion                                      ║\n";
    body += "║                                                        ║\n";
    body += "║ 3. Ver mis peticiones                                  ║\n";
    body += "║                                                        ║\n";
    body += "║ 4. Historia de la empresa                              ║\n";
  } else if (option == 2) {
    body =  "║ 0. Cerrar sesion                                       ║\n";
    body += "║                                                        ║\n";
    body += "║ 1. Ver listado de peticiones                           ║\n";
    body += "║                                                        ║\n";
    body += "║ \033[7m2. Crear peticion\033[0m                                      ║\n";
    body += "║                                                        ║\n";
    body += "║ 3. Ver mis peticiones                                  ║\n";
    body += "║                                                        ║\n";
    body += "║ 4. Historia de la empresa                              ║\n";
  } else if (option == 3) {
    body =  "║ 0. Cerrar sesion                                       ║\n";
    body += "║                                                        ║\n";
    body += "║ 1. Ver listado de peticiones                           ║\n";
    body += "║                                                        ║\n";
    body += "║ 2. Crear peticion                                      ║\n";
    body += "║                                                        ║\n";
    body += "║ \033[7m3. Ver mis peticiones\033[0m                                  ║\n";
    body += "║                                                        ║\n";
    body += "║ 4. Historia de la empresa                              ║\n";
  } else {
    body =  "║ 0. Cerrar sesion                                       ║\n";
    body += "║                                                        ║\n";
    body += "║ 1. Ver listado de peticiones                           ║\n";
    body += "║                                                        ║\n";
    body += "║ 2. Crear peticion                                      ║\n";
    body += "║                                                        ║\n";
    body += "║ 3. Ver mis peticiones                                  ║\n";
    body += "║                                                        ║\n";
    body += "║ \033[7m4. Historia de la empresa\033[0m                              ║\n";
  }

  std::cout << body;             
  std::cout << "║                                                        ║\n"
               "║                                                        ║\n"
               "╚════════════════════════════════════════════════════════╝\n";
}
void ChooseOption (int option) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                      ELIJA OPCION                      ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body{""};
  if (option == 1) {
    body =  "║ 1. Registrar usuario                                   ║\n║                                                        ║\n";
    body += "║ \033[7m2. Iniciar sesion\033[0m                                      ║\n";
    body += "║                                                        ║\n║ 3. Salir                                               ║\n";
  } else if (option == 0) {
    body =  "║ \033[7m1. Registrar usuario\033[0m                                   ║\n║                                                        ║\n";
    body += "║ 2. Iniciar sesion                                      ║\n";
    body += "║                                                        ║\n║ 3. Salir                                               ║\n";
  } else {
    body =  "║ 1. Registrar usuario                                   ║\n║                                                        ║\n";
    body += "║ 2. Iniciar sesion                                      ║\n";
    body += "║                                                        ║\n║ \033[7m3. Salir\033[0m                                               ║\n";
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
void UserCreate (const std::string& username) {
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
