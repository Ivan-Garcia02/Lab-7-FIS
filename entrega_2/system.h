#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "user.h"
#include "petition.h"

class System {
 public:
  System(const std::string&, const std::string&);
  int UserPos(const std::string&) const;
  bool EmailExist(const std::string&) const;
  bool Login(const std::string&, const std::string&) const;
  void Register(const std::string&, const std::string&, const std::string&, const std::string&, const std::vector<int>&, const std::vector<int>& );
  std::vector<User> GetUsers(void) const {return users_;}
  std::vector<Petition> GetPetitions() const {return petitions_;}
  
  void ShowPetitions(int pos);
  void CreatePetition(int user);
  void ShowMyPetitions(int pos);
  
 private:
  std::vector<User> users_;
  std::vector<Petition> petitions_;
};

#endif