#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

#include "system.h"
#include "graphics.h"

void Info_Dorf();
void Register_Login(System&);
void Login(System&);
void Register(System&);
bool CheckEmail(const std::string&);
bool CheckUsername(const std::string&);
bool CheckName(const std::string&);
int CheckPassword(const std::string&, const std::string&);
void AddWord(int, std::string&);

/// La funcion show_menu se cambio la implementancion a la clase user por el nombre ManagePetitions 
void show_menu(System&, int);

void ActualizarBaseDatos(System&);
void historia();

#endif