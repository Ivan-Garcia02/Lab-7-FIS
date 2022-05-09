#include "user.h"

/// Peticiones
void User::CreatePetition(int PID){
  petitions_creadas_.push_back(PID);
}

void User::SingPetition(int PID) {
  petitions_firmadas_.push_back(PID);
}

bool User::CheckPetitionSing(int PID) {
  for (int i {0}; i < petitions_firmadas_.size(); i++) {
    if (petitions_firmadas_[i] == PID) {
      return false;
    }
  }
  return true;
}