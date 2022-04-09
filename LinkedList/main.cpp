#include <iostream>

// 
#include "LinkedList.hpp"

int main()
{
    // create the class object
    LinkedList<int> tmpList;

    // add node to the list
    tmpList.AddNode(3);
    tmpList.AddNode(5);
    tmpList.AddNode(7);

    // print list contents
    tmpList.PrintList();

    // delete node
    tmpList.DeleteNode(5);

    // print list contents
    tmpList.PrintList();

    return 0;
}