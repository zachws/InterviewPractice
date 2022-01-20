#include <iostream> 
#include <cstddef>  //This ensures that we can use NULL for our node, otherwise we would set the node as 0 or as nullptr 

//Here we use a Node class to make our lives easier by coupling important data together. 
class Node {
    public:
        //Each node has a int value and a node which points to the next element in the linked list
        int data; 
        Node *next; 
};

//Print out contents of linked list by starting at the head until we reach a NULL pointer which means there are no more elements after that element
void printLinkedList(Node* head)
{
    while (head != NULL)
    {
        std::cout << head->data << " "; 
        head = head->next; 
    }
}

//We will create a singly linked list with 3 nodes 
int main () 
{
    //Initialize node pointers to null to begin (allows us to know if the list is actually occupied with elements and to initialize pointers ONLY when necessecary)
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 

    //Initialize object for each node that we have (allocates memory on heap), these are our pointers to blocks of memory
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 

    //Assign data to nodes 
    head->data = 1; 
    head->next = second; 

    second->data = 2; 
    second->next = third; 

    third->data = 3; 
    third->next = NULL; //Since this is our last element we leave the pointer NULL to know it is indeed the end of the singly linked list. 

    //Call print linked list function to ensure this was done properly 
    printLinkedList(head); 

    return 0; 
}