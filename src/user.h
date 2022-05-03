#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
 public:
  User(std::string username, std::string password, std::string name, std::string email, std::vector<bool> petitions)
       : username_{username}, password_{password}, name_{name}, email_{email}, petitions_{petitions} {}
  void SetPetitions(std::vector<bool> petitions) {petitions_ = petitions; return;}
 private:
  std::string username_;
  std::string password_;
  std::string name_;
  std::string email_;
  std::vector<bool> petitions_;

};

#endif