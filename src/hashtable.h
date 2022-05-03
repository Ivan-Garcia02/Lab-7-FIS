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

class HashTable {
 public:
  /// constructor
  HashTable(unsigned, DispersionFunction*);
  bool search(const int& k) const;
  bool insert(const int& k);
 private:
  unsigned tableSize_;
  Sequence** table_;
  unsigned blockSize_;
  DispersionFunction *fd_;
};
/// constructor

HashTable::HashTable(unsigned tableSize,  
          DispersionFunction* fd) :
          tableSize_{tableSize}, fd_{fd} {
  table_ = new Sequence*[tableSize_];
  /// Eleccion si el metodo de dispersion es abierto o cerrado

  for (unsigned i{0}; i < tableSize_; i++) {
    table_[i] = new List();
  }
  return;   
}
bool HashTable::search(const int& k) const {
  unsigned position = fd_->Position(k);
  return table_[position]->search(k);
}

bool HashTable::insert(const int& k) {
  unsigned position = fd_->Position(k);
  /// si no esta encontrado lo añade
  if (table_[position]->search(k)) {
    return false;
  } else {
    return table_[position]->insert(k);
  }
}

#endif