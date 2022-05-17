#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>

class User {
 public:
  User(const std::string& username, const std::string& password, const std::string& name,
       const std::string& email, const std::vector<int>& petitions_firmadas, const std::vector<int>& petitions_creadas)
       : username_{username}, password_{password}, name_{name}, email_{email}, petitions_firmadas_{petitions_firmadas}, petitions_creadas_{petitions_creadas} {}
  
  /// getters
  std::string GetUsername(void) const {return username_;}
  std::string GetEmail(void) const {return email_;}
  std::string GetName(void) const {return name_;}
  std::string GetPassword(void) const {return password_;}
  std::vector<int> GetPetitionsFirmadas(void) const {return petitions_firmadas_;}
  std::vector<int> GetPetitionsCreadas(void) const {return petitions_creadas_;}

  int GetPetitionsFirmadas(int i) const {return petitions_firmadas_[i];}
  int GetPetitionsCreadas(int i) const {return petitions_creadas_[i];}

  void SetPetitionsFirmadas(int petitions) {petitions_firmadas_.push_back(petitions);}
  void SetPetitionsCreadas(int petitions) {petitions_creadas_.push_back(petitions);}

  /// Comprobar contraseña
  bool CheckPassword(const std::string& password) {return (password == this->password_);}
  void ManagePetitions(void);

  /// Peticiones
  void CreatePetition(int PID);
  void SingPetition(int PID);
  bool CheckPetitionSing(int PID);

 private:
  std::string username_;
  std::string password_;
  std::string name_;
  std::string email_;
  std::vector<int> petitions_firmadas_;
  std::vector<int> petitions_creadas_;
};

#endif