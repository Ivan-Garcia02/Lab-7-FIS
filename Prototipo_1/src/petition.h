#ifndef PETITION_H
#define PETITION_H

#include <string>
#include "user.h" 
#include <iostream>   

class Petition {
 public:
  Petition(std::string titulo, std::string descripcion, int firmas, int  usuario) 
  : titulo_{titulo}, descripcion_{descripcion}, firmas_{firmas}, usuario_{usuario} {}

  /// getters
  std::string get_titulo() {return titulo_;}
  std::string get_descripcion() {return descripcion_;}
  int get_firmas() {return firmas_;}
  int get_usuario() {return usuario_;}

  /// funciones
  void inc_firmar() {firmas_ = firmas_ + 1;}

  /// overload
  friend std::ostream& operator<<(std::ostream& os, const Petition& pet);
  
 private:   
  std::string titulo_;
  std::string descripcion_;
  int firmas_;
  int usuario_;
};


#endif