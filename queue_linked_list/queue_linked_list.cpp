#include "queue_linked_list.h"

namespace zw 
{
    //Destructor for our Queue
    template <class T> Queue<T>::~Queue()
    {
        //Current element pointer, starts at head
        ListElement<T> *current = head_; 
        //Temp element pointer which starts at head, allows us to store the current so we can update current and also delete the previous current 
        ListElement<T> *temp = head_ 

        //While we still have elements in our Queue
        while(current)
        {
            //Set temp to current
            temp = current; 
            //Current updates to next element 
            current = current->GetNext(); 
            //delete temp aka the previous current element 
            delete temp; 
        }
    }

    template <class T> void Queue<T>::Enqueue(T Value)
    {
        //Create new element to add to our Queue 
        auto toAdd = new ListElement<T>(value); 
        //Set data aka value supplied here by caller
        toAdd->SetData(value); 
        //Set the next to nullptr obviously as we always add to tail we know that there can't be a next that it points to
        toAdd->SetNext(nullptr);

        //If the Queue is empty we need to initialize differently. I.e. we need to set the head and tail pointers 
        if(Empty())
        {
            //Set both head and tail to point to the new element 
            head_ = tail_ = toAdd;  
        }
        else
        {
            //Sets the next toAdd (new node) 
            tail_->SetNext(toAdd); 
            //Then updates the tail_ to the new node which already has it's next pointer set to nullptr so this will work as intended! 
            tail_ = toAdd; 
        }

    }

    template <class T> const T Queue<T>::Dequeue()
    {
        //Case where the list is empty, aka head_ and tail_ are just nullptr 
        if(Empty())
        {
            std::cerr << "Cannot DeQueue; Queue is Empty. Must have >= 1 Element/Node to Dequeue."
            exit(EXIT_FAILURE); 
        }

        //Now store the value in a variable so we can return it
            //DeQueue starts with the head (FIFO) 
        T value = head_->GetData(); 

        ListElement<T> *temp = head_; 

        //If our head and our tail are the same then we need to update the tail as it may be empty (nullptr) so we handle this case 
        if(head_ == tail_)
        {
            //Update tail 
            tail_ = head_->GetNext; 
        }

        //Update head
        head_ = head_->GetNext(); 
        //Delete old head since it's been popped off like molly
        delete temp; 
        //Return the value which was stored at the head prior to the pop 
        return value; 
    }

    template <class T> bool Queue<T>::Empty() const
    {
        //If the head is a nullptr then it is obviously empty. 
        return head_ == nullptr; 
    }

    //Print Information about the Queue so that we can do error checking later if needed 
    template <class T> void Queue<T>::PrintDebug() const 
    {
        ListElement<T> *current = head_;

        std::cout << "Queue elements: ";

        while (current) 
        {
        std::cout << current->GetData() << " < ";
        current = current->GetNext();
        }

        std::cout << std::endl;
    }

}//end of namespace zw