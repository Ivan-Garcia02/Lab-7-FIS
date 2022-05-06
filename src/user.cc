#include "user.h"

/// Peticiones
void User::CreatePetition(int PID){
  petitions_creadas_.push_back(PID);
}