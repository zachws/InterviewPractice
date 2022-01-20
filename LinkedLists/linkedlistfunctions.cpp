#include "linkedlistfunctions.h"

namespace zw  {
//Forward declaration of what we want to do. 

//void stdlib_forward_list_test(); TODO: IMPLEMENT THIS LATER
//void stdlib_doubly_linked_list_test();  TODO: IMPLEMENT THIS LATER

//Destructor
template <class T> LinkedList<T>::~LinkedList() {
  ListElement<T> *current = head_;
  ListElement<T> *next = nullptr;

  while (current) {
    next = current->GetNext();
    delete current;
    current = next;
  }
}


//Get the size of the linked list (i.e. how many elements)
//Defined as const as we don't want to write any new data but simply return a counter of how many items there are within our list
//Returns an int which is the number of elements within the list 
template <class T> int LinkedList<T>::Size() const 
{
    int counter = 0; 

    auto current = head_; //Start at the head since it is a linked list 
    //While current is not equal to NULL or nullptr (i.e. while there are still elements in the linked list)
    while(current)
    {
        current = current->GetNext(); 
        counter++; 
    }

    return counter; 
}


//Pushes value to front of Linked list, updates head to this new element, and updates old head to the next pointer of this element, everything else will line up properly. 
template <class T> void LinkedList<T>::PushFront(T value)
{
    //Create new node (aka an element of our List) with the given value supplied to this function
    auto *node = new ListElement<T>{value}; 

    //Set the pointer of the node to the original head of the list (as this head now becomes the second item in the linked list)
    node->SetNext(head_); 
    //The new head is the node we just created since we are pushing it to the front 
    head_ = node; 
}

//Return a boolean for whether or not our linked list structure is empty. 
template <class T> bool LinkedList<T>::Empty() const 
{
    //Boolean expression, if the head is a null pointer then obviously there is no second element assuming we initialized the linked list properly 
    return head_ == nullptr; 
}

//Gets the value at a given index 
template <class T> const T &LinkedList<T>::ValueAt(int index) const
{

    //Set the current node visited pointer to the head as we must start at the beginning of a linked list by nature 
    ListElement<T> *current = head_; 
    //Keep going until we get to the index we need OR the index is out of bounds (i.e. invalid index request), which is then handled by the case below this for loop
    for(int i = 0; i < index && current != nullptr; i++)
    {
        current = current->GetNext(); 
    }

    
    if (current == nullptr)
    {
        std::cerr << "Index out of bounds." << std::endl; 
        exit(EXIT_FAILURE);         
    }

    return current->GetData(); 

}


//For debugging for self-use/printing needs 
template <class T> void LinkedList<T>::PrintDebug() const 
{
  ListElement<T> *current = head_;

  std::cout << std::endl;

  while (current != nullptr) 
  {
    std::cout << current->GetData() << " --> ";
    current = current->GetNext();
  }
    std::cout << std::endl;
}

//Removes the first element from the list and returns the value that was held within that list element/object
template <class T> const T LinkedList<T>::PopFront()
{
    //Case where user attempts to Pop an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    //We want to take an element from the list, get it's value and it's next pointer to update accordingly. 
    ListElement <T> *node = head_; 
    //This is the value we return which was stored at the head_ pointer before we popped it off 
    T value = node->GetValue(); 

    //Set the head to the next pointer (i.e. the second item before we popped this)
    head_ = head_->GetNext();

    delete node; 

    return value; 
}


template <class T> void LinkedList<T>::PushBack(T value)
{
    //create element (object) to push to the back of the linked list
    auto *node = new ListElement<T> {value}; 
    //Set the nodes next pointer to null pointer since it is the end of the list and the end of the list always points NULL to determine where it ends. 
    node->SetNext(nullptr); 

    //Case where the list is not initialized (aka the head is a null pointer thus this becomes the head)
    if (head_ == nullptr)
    {
        head_ = node; 
        //Return from this function as we are done 
        return; 
    }

    //Use the current variable to keep track of where we are in the linked list
    ListElement<T> *current = head_; 

    //Keep looking until we find the current end of the list PRIOR to this insertion so we can update the pointer of the previous last element to point to the new last element 
    while(current->GetNext())
    {
        current = current->GetNext(); 
    }

    //Since we are at the end of the list prior to this insertion we simply update the OLD last pointer to point to the new last element  
    current->SetNext(node); 

}

//Remove the last element of our linked list, update 2nd last pointer to null as it is now the last element, and return the value that was stored at the last element prior to popping. 
template <class T> const T LinkedList<T>::PopBack()
{
    //Case where user attempts to Pop an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    //Current element we are looking at     
    auto *current = head_; 
    //Initialize as null as there is no previous element to the head of course 
    ListElement<T> *lastElem = nullptr; 
    //Loop until we get to the last element of the list 
    while(current->GetNext())
    {
        //Set previous pointer to the current which will now change to the next element thus it is the previous
        lastElem = current; 
        //update current element to the next element 
        current = current->GetNext();
    } 

    //Get the value in the last node. 
    T value =  current->GetValue(); 

    //Check if the previous is a null pointer (aka we had only 1 element (the head) and we popped it so it should now be an empty linked list)
    if(lastElem == nullptr)
    {
        head_ = nullptr; 
    }
    //Otherwise we had >= 2 elements in the linked list and thus the last element is now updated (as it was the second last now it is the last)
    else
    {
        lastElem->SetNext(nullptr); 
    }

    //Tidy up memory by deleting helper variables for this function which we won't need anymore
    delete current; 

    //Return the value of the last element (which is now removed from the linked list but we stored the value so it's GUCCI)
    return value; 

}


//Returns the value at the head of the list aka front 
template <class T> const T LinkedList<T>::Front()
{
    //Case where user attempts to access an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    //Return the value stored at head since we've ensured it is initialized with the prior check. 
    return head_->GetValue(); 
    

}

//Get the value at the back of the linked list
template <class T>const T LinkedList<T>::Back()
{
    //Case where user attempts to accesss an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    //Current element we are looking at     
    auto *current = head_; 

    //Traverse through linked list until we reach the end. This also handles initial case as it will not enter the while loop if the head_->GetNext() is a null pointer (aka the case where the head is the only item in the linked list)
    while(current->GetNext())
    {
        //Update current as we traverse through list
        current = current->GetNext(); 
    }

    //Hold value in variable so we can free memory
    T value = current->GetData(); 
    //Free memory used by current
    delete current; 
    //Return the value we want. 
    return value; 

}

//This inserts a new element at a user defined index within the linked list. 
template <class T> void LinkedList<T>::Insert(int index, T value) 
{
    auto *current = head_; 
    ListElement <T> *previous = nullptr;  
    //Check if the index is valid before creating an object to preserve memory usage 
    int i;  //Declare i so we can use it out of for loop scope to check if the index is valid after this for loop 
    for(i = 0; i < index && current; ++i)
    {
        //Set/update previous pointer 
        previous = current; 
        //Set current to the next element as we are no longer interested in the previous current as we have not yet reached the index in which we wish to insert the new value into the linked list
        current = current->GetNext();
    }

    //Now we should be at our index to insert assuming the index is not out of bounds so we check first 
    if(i != index)
    {
        std::cerr << "Index out of bounds" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    //create element (object) to push to the requested index within the linked list
    auto *node = new ListElement<T> {value}; 

    //Case where the previous is nullptr aka the head of the list is the only element and we want to insert at the head 
    if(previous == nullptr )
    {
        //Set the node to point to the original head (now the second element in the list)
        node->SetNext(head_);
        //Update the head to the node pointer of the newly inserted head node 
        head_ = node; 
    }
    else
    {
        //Set the newly inserted node's next pointer to the previous nodes next pointer as this placed in between 2 existing nodes/elments/objects of our list
        node->SetNext(previous->GetNext()); 
        //Set previous node pointer to now point at this node instead of the node it was originally pointing at (as it has moved)
        previous->SetNext(node); 
    }

}



template <class T> void LinkedList<T>::Erase(int index) 
{
    //Case where user attempts to accesss an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    auto *current = head_; 
    ListElement<T> *previous = nullptr; 

    //Need to use this counter out of the for loop scope so defined prior 
    int i; 
    for (i = 0; i < index && current; ++i)
    {
        previous = current; 
        current = current->GetNext(); 
    }
}

//Returns the value at the node of the Nth position from the end
template <class T> const T LinkedList<T>::ValueNFromEnd(int n)
{
    //Case where user attempts to accesss an element that does not exist as the list is empty , check if n < 1 cause if n is 0 then there cannot be an nth from the end as the end is the head 
    if (n < 1 || head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    auto *current = head_; 
    //Initialize this to the head_ as the head COULD be the nth way from the end
    auto *match = head_; 

    //We will need to loop twice through the list (second loop depends on where the nth is from the end and first loop is to count the number of elements to determine the second loops end condition)
    int i;  //This is the count of the amount of elements in this list 
    for(i = 0; i < n && current; ++i)
    {
        //Keep updating current to get to the end of the list and thus we can determine number of elements until the end 
        current = current->GetNext(); 
    }

    //Case where we can't actually obtian this value as it is out of bounds (List is actually smaller than n, let alone n away from end)
    if (i != n)
    {
        std::cerr << "Index out of bounds." << std::endl;
        exit(EXIT_FAILURE);
    }

    //Since i is equal to n that means that our match will start at the beginning and current will be left off to where n needs to be, thus match starts at the head and keeps getting next until the current reaches the end and thus we are the amount away that is required
    while(current)
    {
        match = match->GetNext(); 
        current = current->GetNext(); 
    }

    return match->GetData(); 
}

//This function reverses a linked list 
template <class T> void LinkedList<T>::Reverse() 
{
  ListElement<T> *previous = nullptr;
  ListElement<T> *current = head_;
  ListElement<T> *next;

  //While we still have elements; 
  while(current != nullptr )
  {
    //Set the next node as the current's next (this is essentially to hold the next value so that it is not lost when we update the current in the next line)
    next = current->GetNext();
    //Set the current's next node to previous (as this will point the pointers in the opposite direction)
    current = SetNext(previous); 
    //Update the previous pointer to the current pointer 
    previous = current; 
    //Update the current to the next element that needs to be reversed (switch pointer direction)
    current = next; 
  }

  //Now we set the head since current will be a null pointer and current is the next element and thus if current points to nothing it is the end of the list at this point (aka the new head of the list since it was reversed )
  head_ = previous; 

}

//removes the first item in the list with this value
template <class T> void LinkedList<T>::RemoveValue(T value) 
{
    //Case where user attempts to accesss an element that does not exist as the list is empty 
    if (head_ == nullptr)
    {
        std::cerr << "List is empty" << std::endl; 
        exit(EXIT_FAILURE); 
    }
    auto *current = head_; 
    ListElement<T> *previous = nullptr; 

    while(current)
    {
        if(current->GetValue() == value)
        {
            //If the value we are trying to remove is at the head of the list
            if(previous == nullptr)
            {
                head_ = current->GetNext(); 
            }
            //Else the value is in the list but not at the head 
            else
            {
                //The previous now must point 2 elements away as we deleted the element in the middle, so we set the previous next pointer to the current (just deleted) next pointer! yay 
                previous->SetNext(current->GetNext());
            }
            //Free memory as we are done
            delete current;
            //Break out of function as we have removed the intended element and updated pointers accordingly. 
            break; 
        }
        //update previous pointer
        previous = current; 
        //update current pointer
        current = current->GetNext(); 
    }
}














} // end of namespace zw 


