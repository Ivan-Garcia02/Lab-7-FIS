#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
 public:
  User(const std::string& username, const std::string& password, const std::string& name,
       const std::string& email)
       : username_{username}, password_{password}, name_{name}, email_{email}, petitions_{false} {}
  void SetPetitions(std::vector<bool> petitions) {petitions_ = petitions; return;}
  std::string GetUsername(void) const {return username_;}
  bool CheckPassword(const std::string& password) {return (password == this->password_);}
  int GetUid(void) const;
  bool operator==(const User&);
 private:
  std::string username_;
  std::string password_;
  std::string name_;
  std::string email_;
  std::vector<bool> petitions_;

};

#endif