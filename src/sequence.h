#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

#include "dispersionfunction.h"

/// clase node
/// esta clase la utilizo para los nodos de las listas
/// cuando la tecnica de dispersion es abierta
template<class Key>
class Node {
 public:
  // Constructor
  Node(const int& data) : data_(data), next_(NULL) {}
  /// obtener y establecer el nodo siguiente
  Node* GetNext(void) const { return next_; }
  void SetNext(Node* next) { next_ = next; }
  /// obtener el valor del nodo
  int GetData(void) { return data_; }

 private:
  Node* next_;
  Key data_; 
};

template<class Key>
class Sequence {
 public:
  /// metodos para buscar e insertar en una secuencia
  virtual bool insert(const Key&) = 0;
  virtual bool search(const Key&) const = 0;
  /// se utiliza principalmente en la tecnica de dispersion cerrada
  virtual bool isFull(void) const = 0;
  
};

template<class Key>
class List : public Sequence<Key> {
 public:
  /// constructor
  List(void) : head_(NULL) {}
  bool insert(const Key&);
  bool search(const Key&) const;
  bool isFull(void) const {return false;}
 private:
  Node<Key>* head_;
};

template<class Key>
class Block : public Sequence<Key> {
 public:
  /// constructores
  Block(void) {}
  Block(unsigned blocksize) : blocksize_{blocksize}, position_{0} {
    bloque_ = new Key[blocksize_];
  }
  bool insert(const Key&);
  bool search(const Key&) const;
  bool isFull(void) const;

 private:
  unsigned blocksize_;
  unsigned position_;
  Key* bloque_;
};

//////////// DEFINICION ///////////////

/// Metodo para insertar en una lista
template<class Key>
bool List<Key>::insert(const Key& llave) {

  Node<Key>* node = new Node<Key>(llave);
  if(!search(llave)) {
    node->SetNext(head_);
    head_ = node;
    return true;
  }
  return false;
}

/// Metodo para buscar en una lista
template<class Key>
bool List<Key>::search(const Key& llave) const {
  Node<Key>* aux = head_;
  while ((aux != NULL)) {
    if (aux->GetData() == llave) {
      return true;
    }
    aux = aux->GetNext();
  }
  return false;
}
/// Metodo para insertar en un bloque
template<class Key>
bool Block<Key>::insert(const Key& llave) {
  if(!search(llave)) {
    bloque_[position_++] = llave;
    return true;
  }
  return false;
}
/// Metodo para buscar en un bloque
template<class Key>
bool Block<Key>::search(const Key& llave) const {
  for (unsigned i{0}; i < blocksize_; i++) {
    if(bloque_[i] == llave) {
      return true;
    }
  }
  return false;
}
/// Metodo para saber sin un bloque esta lleno
template<class Key>
bool Block<Key>::isFull() const {
  if(position_ >= blocksize_) {
    return true;
  }
  return false;
}
#endif