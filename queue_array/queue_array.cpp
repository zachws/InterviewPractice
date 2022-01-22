#include "queue_array.h"

namespace zw 
{
    template <class T> void Queue<T>::Enqueue(T value)
    {
        //If our Queue is full we cannot Enqueue. The Queue is FULL when N-1 Array elements are initialized (Always 1 empty element for Queue in Array implementation)
        if(Full())
        {   
            //Print Error message to user
            std::cerr << "Unable to Enqueue; Queue is full. Cannot add any more items until more are Dequeued" << std::endl; 
            //Exit with failure code
            exit(EXIT_FAILURE); 
        }

        //insert_ is the location in which we need to insert so we insert here
        data_[insert_] = value; 
        //Since we've inserted at our insert_ location we must increment to preven data being overwritten
        insert_++; 
    }

    template <class T> const T Queue<T>::Dequeue()
    {
        //Case where the Queue is empty thus we cannot Dequeue
        if(Empty())
        {
            std::cerr << "Unable to Dequeue; Queue is empty. Cannot Dequeue any more items until more are Enqueued" << std::endl; 
            exit(EXIT_FAILURE); 
        }

        //We need to get the value first to return before we remove (set array int to 0)
        T value = data_[pop_]; 
        // Set to 0 aka empty and free to be Enqueued in
        data_[pop_] = 0; 
        //Update pop_ 
        pop_++; 
        //Return value that was popped. TODO: I don't think this handles the value wrapping back to 0 so I should test this before I try to change the implementation. 
        return value; 

    }

    template <class T> bool Queue<T>::Empty() const 
    {
        //When our read/write are equal aka insert_/pop_ then we know the queue is empty since we can only allocate N-1 of the Array indices to prevent issues with this. 
        return insert_ == pop_; 
    }

    template <class T> bool Queue<T>::Full() const
    {
        //Can also be implemented this way: if(front == 0 && rear == MAX_SIZE - 1) 
        //This is how circular arrays are handled   https://en.wikipedia.org/wiki/Circular_buffer & https://stackoverflow.com/questions/3866356/when-is-a-queue-full
        return pop_ == (insert_ + 1) % kQueuePositions; 
    }

}//end namespace zw 