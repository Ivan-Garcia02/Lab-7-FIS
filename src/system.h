#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "user.h"

class System {
 public:
  System(const std::string&, const std::string&);
  void CreateUser(void);
  int UserPos(const std::string&) const;
  bool Login(const std::string&, const std::string&) const;
  std::vector<User> GetUsers(void) const {return users_;}
 private:
  std::vector<User> users_;
  //std::vector<Petition> petitions_;
};

#endif