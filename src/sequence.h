#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

#include "dispersionfunction.h"

/// clase node
/// esta clase la utilizo para los nodos de las listas
/// cuando la tecnica de dispersion es abierta
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
  int data_; 
};

class Sequence {
 public:
  /// metodos para buscar e insertar en una secuencia
  virtual bool insert(const int&) = 0;
  virtual bool search(const int&) const = 0;
  /// se utiliza principalmente en la tecnica de dispersion cerrada
  virtual bool isFull(void) const = 0;
  
};

class List : public Sequence {
 public:
  /// constructor
  List(void) : head_(NULL) {}
  bool insert(const int&);
  bool search(const int&) const;
  bool isFull(void) const {return false;}
 private:
  Node* head_;
};

//////////// DEFINICION ///////////////

/// Metodo para insertar en una lista
bool List::insert(const int& llave) {

  Node* node = new Node(llave);
  if(!search(llave)) {
    node->SetNext(head_);
    head_ = node;
    return true;
  }
  return false;
}

/// Metodo para buscar en una lista
bool List::search(const int& llave) const {
  Node* aux = head_;
  while ((aux != NULL)) {
    if (aux->GetData() == llave) {
      return true;
    }
    aux = aux->GetNext();
  }
  return false;
}

#endif