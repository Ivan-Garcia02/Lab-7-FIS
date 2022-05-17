#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "user.h"
#include "petition.h"

class System {
 public:
  System(const std::string&, const std::string&, const std::string&);
  int UserPos(const std::string&) const;
  bool EmailExist(const std::string&) const;
  bool Login(const std::string&, const std::string&) const;
  void Register(const std::string&, const std::string&, const std::string&, const std::string&, const std::vector<int>&, const std::vector<int>& );
  std::vector<User> GetUsers(void) const {return users_;}
  std::vector<Petition> GetPetitions() const {return petitions_;}
  int& GetCantidadDonada() {return cantidad_donada_;}

  void ShowPetitions(int pos);
  void CreatePetition(int user);
  void ShowMyPetitions(int pos);
  
  void DonatePetition(int PID);
  void SharePetition(int PID);

 private:
  std::vector<User> users_;
  std::vector<Petition> petitions_;
  int cantidad_donada_;
};

#endif