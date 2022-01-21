#include "list_element.h"

#include <stdlib.h>
#include <iostream>

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

namespace zw {

template <class T>
class LinkedList {
 public:
  explicit LinkedList() : head_(nullptr) {} //explicit usage to ensure it is called how we want
  ~LinkedList();  //Destructor
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete; //Overloaded assignment operator?
  // Returns the number of data elements in list.
  int Size() const;
  // Adds an item to the front of the list
  void PushFront(T value);
  // Returns true if list is empty
  bool Empty() const;
  // Returns the value of the nth item, indexed starting at 0
  const T &ValueAt(int index) const;
  // Prints the data stored in the list
  void PrintDebug() const;
  // Remove front item, returning its value
  const T PopFront();
  // Pushes the item on the end of the list
  void PushBack(T value);
  // Removes end item and returns its value
  const T PopBack();
  // Returns value of front item.
  const T Front();
  // Returns the value of the end item.
  const T Back();
  // Insert value at index, so current item at that index is
  // pointed to by new item at index. Indexes start at 0.
  void Insert(int index, T value);
  // Erase node at the given index. Indexes start at 0.
  void Erase(int index);
  // Returns the value of the node at nth position from the end of the list.
  // Last position would be 1, second to last is 2, etc.
  const T ValueNFromEnd(int n);
  // Reverses the items stored in the list
  void Reverse();
  // removes the first item in the list with the given value
  void RemoveValue(T value);

 private:
  ListElement<T> *head_;
};

}  // namespace zw

#endif  // PROJECT_LINKEDLIST_H