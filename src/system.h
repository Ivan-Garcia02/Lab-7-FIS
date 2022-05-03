#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

#include "hashtable.h"

class System {
 public:
  System(const std::string&, const std::string&);
  void CreateUser(void);

 private:
  HashTable users_;
  HashTable petitions_;
};

#endif