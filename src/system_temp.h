#ifndef SYSTEM_H
#define SYSTEM_H

#include "user.h"

class System {
 public:
  bool CreateUser(void);


  bool UserExist(const std::string&);
  void Login(void);
  bool CheckPassword(const std::string&);

 private:
  std::vector<std::string> users_;

};

#endif