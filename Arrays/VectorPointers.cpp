#include <iostream>
#include <vector> 
//Vector.empty() is O(1) and vector.size() == 0 could be O(n) if used on a std::list thus should try to use .empty always to prevent runtime slowdowns 

int findValueIndex(std::vector<int> * myVect, int valToFind)
{
    //Initialize Index to -1 
    int index_location = -1; 

    for(int i = 0; i < (*myVect).size(); i++)
    {
        if((*myVect)[i] == valToFind)
        {
            index_location = i; 
            return index_location;
        }
    }

    return index_location; 
}

//removes all instances of a given int as given by the user
void removeAllInstances(std::vector<int> * myVect, int toRemove)
{
    auto it = (*myVect).begin(); 
    while(it != (*myVect).end())
    {
        if (*it == toRemove)
        {
            it = (*myVect).erase(it); 
        }
        else
        {
            ++it; 
        }
    }
}

//Prepends an item to the start of a vector via the insert function 
void prependVector(std::vector<int> * myVect, int toPrepend)
{
    //Need to use iterator to use insert so we just set our iterator to the start of the vector since we are pre-pending. 
    std::vector<int>::iterator it;
    it = (*myVect).begin(); 
    (*myVect).insert(it, toPrepend); 
}

//Prints the size of the vector (i.e. how many items it can hold)
void printVectSize(std::vector<int> * myVect)
{
    std::cout << "The size of the vector is: " << (*myVect).size() << std::endl; 
}

//Simple print using for loop 
void print1DStandard(const std::vector<int> * myVect)
{
    for(int i = 0; i < (*myVect).size(); i++)
    {
        std::cout << "Index: " << i << ", Value at Index: " << (*myVect)[i] << std::endl; 
    }
}

//Prints odd indexed items from the vector provided, this is to utilize pointers 
void print1DPointersOdd(std::vector<int> * myVect)
{
    //Print odd indicies 
    for(int i = 1; i < (*myVect).size(); i++)
    {
        std::cout << "Index: " << i << ", Value at Index: " << (*myVect)[i] << std::endl; 
    }
}

//Formatted print for whether or not the vector is empty 
std::string print_is_empty(std::vector<int> toCheck)
{
    if(toCheck.empty())
    {
        return "true";
    }

    return "false"; 
}

//Creates a 1D vector which is just the values 1-10 for testing purposes git
std::vector<int> * create_1D()
{
    //Just create 1D Vector with given values 
    static std::vector<int> myVect; 
    std::cout << "Vector is empty: " << print_is_empty(myVect) << std::endl;
    myVect = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Vector is empty: " << print_is_empty(myVect) << std::endl;
    return &myVect; 
}

/**
int * create_2D()
{

}

void print2DStandard()
{

}

void print2DPointer()
{

}
**/




int main () 
{
    
    //Create 1D vector 
    std::vector<int> * OneDPoint; 
    OneDPoint = create_1D(); 

    //Print 1D Vector Standard (For Loop)
    print1DStandard(OneDPoint); 

    //Print 1D Vector with Pointers


    //Print size of 1D Vector
    printVectSize(OneDPoint); 

    std::cout << "Finding index of memory holding value 4 is: " << findValueIndex(OneDPoint, 4) << std::endl; 

    std::cout << "Capacity (Num elements it can hold) of vector is: " << (*OneDPoint).capacity() << std::endl; 

    prependVector(OneDPoint, 15); 

    print1DStandard(OneDPoint);

    removeAllInstances(OneDPoint, 10); 

    print1DStandard(OneDPoint);

    std::vector<int> duplicates = {1,1,3,2,4,5,1}; 

     print1DStandard(&duplicates);
     std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"; 
    removeAllInstances(&duplicates, 1);
    print1DStandard(&duplicates);


    //Create 2D vector

    //Print 2D Vector Standard (Nested For Loop)

    //Print 2D Vector Specific Locations (Using Formula) 


   


    return 0; 
}