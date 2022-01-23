#include <assert.h>
#include <stdlib.h>  // abs
#include <iostream>
#include <string>
#include "hash_object.h"

#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

namespace zw {
class HashTable {
 public:
  // our user-defined constructor
  explicit HashTable(const int size);
  //Destructor (need to implement in the hash_table.cpp file)
  ~HashTable();
  //No copy constructor i.e. delete
  HashTable(const HashTable &) = delete;
  //No assignment operator constructor i.e. delete
  HashTable &operator=(const HashTable &) = delete;

  // Add the given key and object to hash table. If key exists, update the value.
  void Add(HashObject *object);
  // Returns true if the given key exists in the table
  bool Exists(const std::string key);
  // Returns the value associated with the given key, or NULL if it doesn't
  // exist
  const std::string Get(const std::string key);
  // Removes the value associated with key from the table.
  void Remove(const std::string key);
  // Outputs the content of the hash table for debugging purposes.
  void PrintDebug();

 private:
  //size of the hash table
  int size_;
  //Pointer to data, held in hash_object.h 
  HashObject *data_;

  int Hash(const std::string key);
};
}//end of namespace zw

#endif  // PROJECT_HASH_TABLE_H