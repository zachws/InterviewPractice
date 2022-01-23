#include <iostream>
#include "list_element.h"

#ifndef PROJECT_QUEUE_LINKED_LIST_H
#define PROJECT_QUEUE_LINKED_LIST_H

namespace zw 
{
template <class T> class Queue 
{
 public:
    explicit Queue() : head_(nullptr), tail_(nullptr) {}
    ~Queue();
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;
    // Adds value to queue.
    void Enqueue(T value);
    // Removes least recently added item from queue, returning its value.
    const T Dequeue();
    // Returns true if queue is empty.
    bool Empty() const;
    // Outputs the items in the queue, least recently added first.
    void PrintDebug() const;

 private:
    ListElement<T> *head_;
    ListElement<T> *tail_;
};

}//end namespace zw 

#endif //PROJECT_QUEUE_LINKED_LIST_H
