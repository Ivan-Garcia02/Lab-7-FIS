#ifndef PETITION_H
#define PETITION_H

#include <string>
#include "user.h" 
#include <iostream>   

class Petition {
 public:
  Petition(std::string titulo, std::string descripcion, int firmas, std::string usuario, int donation) 
  : titulo_{titulo}, descripcion_{descripcion}, firmas_{firmas}, usuario_{usuario} ,donation_{donation} {}

  /// getters
  std::string get_titulo() const {return titulo_;}
  std::string get_descripcion() const {return descripcion_;}
  int get_firmas() const {return firmas_;}
  int get_donation() const {return donation_;}
  std::string get_usuario() const {return usuario_;}

  /// funciones
  void inc_firmar() {firmas_ = firmas_ + 1;}
  void set_donation(int new_donation) {donation_ = new_donation;}

  /// overload
  friend std::ostream& operator<<(std::ostream& os, const Petition& pet);
  
 private:   
  std::string titulo_;
  std::string descripcion_;
  int firmas_;
  int donation_;
  std::string usuario_;
};


#endif