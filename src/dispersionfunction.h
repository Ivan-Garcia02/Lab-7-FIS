/**
 * @file dispersionfunction.h
 * @author Ramiro Difonti Dome
 * @brief 
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DISPERSION_H
#define DISPERSION_H

template<class Key>
class DispersionFunction {
 public:
  /// DispersionFunction(const unsigned n) : 
  /// Devuelve posicion de la tabla donde insertar / buscar
  /// virtual unsigned operator()(const Key& k) const = 0;
  virtual unsigned Position(const Key& k) const = 0 ;
};

/// Dispersion por modulo
template<class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n) : tablesize_{n} {}
  unsigned Position(const Key& k) const {return k % tablesize_; }
 private:
  unsigned tablesize_;
};

/// Dispersion por suma de los digitos
template<class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n) : tablesize_{n} {}
  unsigned Position(const Key& k) const {
    Key sum{0}, valor{k};
    while(valor > 0) {
      Key digito = valor % 10;
      sum += digito;
      valor /= 10;
    }
    return sum % tablesize_; 
  }
 private:
  unsigned tablesize_;
};

/// Dispersion pseudo aleatoria
template<class Key>
class fdRandom: public DispersionFunction<Key> {
 public:
  fdRandom(const unsigned n): tablesize_(n){}
  unsigned Position(const Key& k) const {
    srand(k);  
    return rand() % tablesize_;
  }
 private:
  unsigned tablesize_;
};

#endif