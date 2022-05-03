#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "user.h"

class System {
 public:
  System(const std::string&, const std::string&);
  void CreateUser(void);
  bool UserExist(const std::string&);
  void Login(void);
  bool CheckPassword(const std::string&);
  
 private:
  std::vector<User> users_;
  //std::vector<Petition> petitions_;
};

#endif