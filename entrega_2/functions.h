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
void Register_Login(const System&);
void Login(const System&);
void Register(const System&);
bool CheckEmail(const std::string&);
bool CheckUsername(const std::string&);
bool CheckName(const std::string&);
int CheckPassword(const std::string&, const std::string&);
void AddWord(int, std::string&);

#endif