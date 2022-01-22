#include <iostream>

#ifndef PROJECT_QUEUE_ARRAY_H
#define PROJECT_QUEUE_ARRAY_H


namespace zw {


template <class T> class Queue
{

    static const int kQueueCapacity = 5;
    static const int kQueuePositions = kQueueCapacity + 1;

public:
    //our User-defined constructor
    explicit Queue() : insert_(0), pop_(0) {}
    //default destructor
    ~Queue() = default;
    //Delete/disable default copy constructor 
    Queue(const Queue &) = delete;
    //Delete/dsiable default assignment/operator constructor
    Queue &operator=(const Queue &) = delete;
    // Adds value to queue.
    void Enqueue(T value);
    // Removes least recently added item from queue, returning its value.
    const T Dequeue();
    // Returns true if queue is empty.
    bool Empty() const;
    // Returns true if queue cannot accept another enqueue.
    bool Full() const;

private:
    int insert_;
    int pop_;
    T data_[kQueuePositions];
};



};




}//end namespace zw 

#endif  // PROJECT_QUEUE_ARRAY_H