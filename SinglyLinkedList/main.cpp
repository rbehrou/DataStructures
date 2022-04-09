#include <iostream>

// class header file
#include "SinglyLinkedList.hpp"

int main()
{
    // create the class object of linked list (int)
    SinglyLinkedList<int> tmpList;

    // add node to the list
    tmpList.InsertNode(1);
    tmpList.InsertNode(3);
    tmpList.InsertNode(5);
    tmpList.InsertNode(7);
    tmpList.InsertNode(9);

    // check the size and print the contents of list
    std::cout << "The size of linked list is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();

    // delete a node by value and then insert it (will insert to the end)
    tmpList.DeleteNode(5);
    tmpList.InsertNode(5);
    std::cout << "The size of linked list is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();

    // delete by the given index
    tmpList.DeleteNodeAt(1);
    std::cout << "The size of linked list is: " << tmpList.Size() << std::endl;
    tmpList.DeleteNodeAt(2);
    std::cout << "The size of linked list is: " << tmpList.Size() << std::endl;
    tmpList.DeleteNodeAt(3);
    std::cout << "The size of linked list is: " << tmpList.Size() << std::endl;

    // print the contents of list
    tmpList.PrintList();

    // clear SinglyLinkedList
    tmpList.Clear();

    // check if the SinglyLinkedList is empty
    if (tmpList.isEmpty())
        std::cout << "The linked list is empty!" << std::endl;
    else
        std::cout << "The linked list is NOT empty!" << std::endl;

    return 0;
}