#include <cstdlib>
#include <iostream>

#include "linkedlistfunctions.h"
#include "linkedlistfunctions.cpp"

// for stdlib experiments:
#include <forward_list> //Allows for fast insertion/removal of elements in linked list. Source: https://en.cppreference.com/w/cpp/container/forward_list
#include <list>         //Need the list inclusion/import 

//Main function! 
int main(int argc, char * argv[])
{
    //Main test taken from https://github.com/jwasham/practice-cpp/blob/master/linked_lists/main.cc to prevent writing these simple arbitrary test cases to ensure my code does indeed work as intended. 

    //TODO: Implement test cases to familiarize myself with writing automated test cases in C++.  Examples: https://github.com/jwasham/practice-cpp/blob/master/linked_lists/tests/list_tests.cc

    zw::LinkedList<int> ilist{};
    ilist.PushFront(4);
    ilist.PushFront(9);

    std::cout << "Size of int list is: " << ilist.Size() << std::endl;

    zw::LinkedList<std::string> strlist{};
    strlist.PushFront("string 1");
    strlist.PushFront("another");
    strlist.PushFront("and another");
    std::cout << "Size of string list is: " << strlist.Size() << std::endl;

    std::cout << "Hello friends - look in tests directory." << std::endl;

    return EXIT_SUCCESS; 
}