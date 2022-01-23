#ifndef PROJECT_HASH_OBJECT_H
#define PROJECT_HASH_OBJECT_H

#include <string> //for std::string

namespace zw {

class HashObject {
 public:
 //Default constructor
  HashObject() {}
  //Default destructor
  ~HashObject() {}
  //no copy constructor i.e. delete
  HashObject(const HashObject &) = delete;
  //Default assignment/operator constructor
  HashObject &operator=(const HashObject &) = default;
  //Returns key_ for caller
  std::string &GetKey() { return key_; }
  //Returns value_ for caller
  std::string &GetValue() { return value_; }
  //Set Dummy Key and Value (Node)
  void SetAsDummy() {
    key_ = GetDummyKey();
    value_ = "";
  }
  //Setter for the key_ 
  void SetKey(const std::string key) { key_ = key; }
  //Setter for the _value
  void SetValue(const std::string value) { value_ = value; }    
  //Shows whether key is Dummy or not I think 
  static const std::string GetDummyKey() { return "<Dummy>"; }
  //Returns the string that the key is infact null 
  static const std::string GetNullKey() { return "<Null>"; }

 private:
  std::string key_;
  std::string value_;
};

}  // namespace jw

#endif  // PROJECT_HASH_OBJECT_H