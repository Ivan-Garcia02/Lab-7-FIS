#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
//#include <term.h>
//#include <curses.h>
#include <unistd.h>
#include <vector>

#include "petition.h"


/// READ KEYBOARD

static struct termios initial_settings, new_settings;
static int peek_character=-1;
void init_keyboard();
void close_keyboard();
int kbhit ();
int readch();

/// GRAPHICS

void Passwd (const std::string&);
void ConfirmPasswd (const std::string&, const std::string&);
void Name (const std::string&);
void Surname (const std::string&, const std::string&);
void Email (const std::string&);
void Username (const std::string&);
void RegisterError(const std::string&);
void UserCreate (const std::string&);
void Password (const std::string&, const std::string&);
void ErrorLogin (void);
void ChooseOption(int);
void Menu(int);
void GraphicPetitions(const std::vector<Petition>&, int);
void IndividualPetition(const Petition&, int);
void SignPetition(const Petition&, const std::string&);
void CreatePetName(const std::string&);
void CreatePetDesc(const std::string&);
void WaitCreatePet(void);
void EmptyMyPet(void);
int ShowMyPet(std::vector<Petition>&, std::vector<int>&, int);
void History(void);
#endif