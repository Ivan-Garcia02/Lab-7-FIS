/**
 * @file hashtable.h
 * @author Ramiro Difonti Dome
 * @brief 
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef HASH_H
#define HASH_H

#include "dispersionfunction.h"
#include "sequence.h"

template<class Key>
class HashTable {
 public:
  /// constructor
  HashTable(unsigned, DispersionFunction<Key>*, 
            unsigned blockSize = 0, ExplorationFunction<Key>* fe = nullptr);
  bool search(const Key& k) const;
  bool insert(const Key& k);
 private:
  unsigned tableSize_;
  Sequence<Key>** table_;
  unsigned blockSize_;
  ExplorationFunction<Key> *fe_;
  DispersionFunction<Key> *fd_;
};
/// constructor
template<class Key>
HashTable<Key>::HashTable(unsigned tableSize,  
          DispersionFunction<Key>* fd,
          unsigned blockSize,
          ExplorationFunction<Key>* fe) :
          tableSize_{tableSize}, fd_{fd}, fe_{fe},
          blockSize_{blockSize} {
  table_ = new Sequence<Key>*[tableSize_];
  /// Eleccion si el metodo de dispersion es abierto o cerrado
  if(fe_ == nullptr) {
    for (unsigned i{0}; i < tableSize_; i++) {
      table_[i] = new List<Key>();
    }
  } else {
    for (unsigned i{0}; i < tableSize_; i++) {
      table_[i] = new Block<Key>(blockSize_);
    }
  }
  return;   
}
template<class Key>
bool HashTable<Key>::search(const Key& k) const {
  unsigned position = fd_->Position(k);
  unsigned i = 1;
  unsigned init = position;
  /// Esto principalmente es para la dispersion cerrada
  /// si esta lleno un bloque, y no esta el elemento, salta al siguiente
  /// hasta que encuentre el elemento, o un espacio vacio
  while(table_[position]->isFull() && !table_[position]->search(k)) {
    position = init + fe_->Function(k, i++);
    if(position >= tableSize_) {
      i = 1;
      init = 0;
      position = 0;
    }
  }
  return table_[position]->search(k);
}
template<class Key>
bool HashTable<Key>::insert(const Key& k) {
  unsigned position = fd_->Position(k);
  unsigned i = 1;
  unsigned init = position;
  /// Esto principalmente es para la dispersion cerrada
  /// si esta lleno un bloque, y no esta el elemento, salta al siguiente
  /// hasta que encuentre el elemento, o un espacio vacio
  while(table_[position]->isFull() && !table_[position]->search(k)) {
    position = init + fe_->Function(k, i++);
    if(position >= tableSize_) {
      i = 1;
      init = 0;
      position = 0;
    }
  }
  /// si no esta encontrado lo añade
  if (table_[position]->search(k)) {
    return false;
  } else {
    return table_[position]->insert(k);
  }
}

#endif