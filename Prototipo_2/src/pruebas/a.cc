#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>

static struct termios initial_settings, new_settings;
static int peek_character=-1;
void init_keyboard();
void close_keyboard();
int kbhit ();
int readch();

void Email (const std::string& email) {
  std::cout << "╔════════════════════════════════════════════════════════╗\n" 
               "║                    REGISTRAR USUARIO                   ║\n"
               "╠════════════════════════════════════════════════════════╣\n"
               "║                                                        ║\n";
  std::string body = "║ email: ";
  body += email;
  for (int i = email.size(); i < 46; i++) {
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
int main() {
  int ch = 0;
  std::string username{""}, password{""};
  User(username);
  init_keyboard();
    while(ch != '\n'){
      if(kbhit ()){
        ch=readch();        
          //if (ch == 127) {
            //username.pop_back();
            printf("you hit%d\n", ch);
            if ( ch == 65 ) {
              std::cout << "arriba" << std::endl;
            }
            if ( ch == 66 ) {
              std::cout << "abajo" << std::endl;
            }          
        }   
      }
    close_keyboard();
}