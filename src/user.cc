#include "user.h"


bool User::operator==(const User& user) {
  return (this->GetUsername() == user.GetUsername());
}
int User::GetUid(void) const {
  int result{0};
  for (int i = 0; i < GetUsername().size(); i++) {
    result += GetUsername().at(i);
  }
  return result;
}