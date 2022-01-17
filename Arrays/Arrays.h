#include <memory>
using namespace std; 
#ifndef PRACTICE_CPP_ARRAY_H
#define PRACTICE_CPP_ARRAY_H

namespace zw {

    static const int kMinCapacity = 16; 
    static const int kGrowthFactor = 2; 
    static const int kShrinkFactor = 4; 

class ZVector
{
    public: 
    ZVector(int capacity); 
    ZVector (const ZVector &other) = default; 
    ~ZVector(); //Destructor for the Vector 
    //Return number of items stored in the vector
    int GetSize() const; 
    //Bool return whether or not vector is empty 
    bool IsEmpty() const; 
    //Return capacity of vector
    int GetCapacity() const; 
    //Public info printout to aid in debugging 
    void DebugString() const; 
    //Append given valeu to end of Vector
    void Push(int value); 
    //Returns the value stored at given index
    int GetValueAt(int index) const; 
    //Returns last item in vector and removes it 
    int Pop(); 
    //Inserts given valeu at given index, shifting current and trailing items to the right 
    void Insert(int index, int value); 
    //Prepends the given value to vector, shift trailing items to right 
    void Prepend(int value); 
    //Deletes item at index, shift all trailing elements left 
    void Delete(int index);
    //Removes all instances of value from the vector
    void Remove(int value); 
    //Looks for value and returns first index with that value, -1 if not found
    int Find(int value) const; 

    private: 
    //Actual capacity that can be accommodated before a resize is required
    int capacity_{kMinCapacity}; 
    //Number of items currently stored
    int size_{0}; 
    //Storate array where ints are stored 
    unique_ptr<int[]> data_; 
    //Determines the array size (in terms of power of growth factor) required to accommodate the given capacity
    int DetermineCapacity(int capacity) const; 
    //Checks to see if resizing required for the given capacity and grows or shrinks the vector as needed
    void ResizeForSize(int candidate_size);
    //Increases the capacity of the vector
    void IncreaseSize(); 
    //Decrease the capacity of the vector
    void DecreaseSize(); 


}; //end of ZVector






} // namespace zw 



#endif