#include <iostream>

// class header file
#include "DoublyLinkedList.hpp"

int main()
{
    // create the class object of the doubly linked list (int)
    DoublyLinkedList<int> tmpList;

    // insert at the end of the list
    tmpList.InsertEnd(1);
    tmpList.InsertEnd(3);
    tmpList.InsertEnd(5);

    // insert at the beginning of the list
    tmpList.InsertFirst(7);
    tmpList.InsertFirst(9);
    tmpList.InsertFirst(11);

    // insert at the end of the list
    tmpList.InsertEnd(13);
    tmpList.InsertEnd(15);
    tmpList.InsertEnd(17);

    // check the size and print list
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "The size of the list is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;

    // Insert at certain location
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.InsertAt(0, 19);
    std::cout << "The size of the list after inserting at first is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.InsertAt(10, 21);
    std::cout << "The size of the list after inserting at the end is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.InsertAt(10, 23);
    std::cout << "The size of the list after inserting at the end is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.DeleteFirst();
    tmpList.DeleteFirst();
    std::cout << "The size of the list after deleting the head node is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.DeleteEnd();
    tmpList.DeleteEnd();
    std::cout << "The size of the list after deleting the tail node is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.DeleteAt(0);
    tmpList.DeleteAt(6);
    std::cout << "The size of the list after deleting is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    tmpList.DeleteAt(3);
    tmpList.DeleteAt(3);
    tmpList.DeleteAt(3);
    std::cout << "The size of the list after deleting is: " << tmpList.Size() << std::endl;
    tmpList.PrintList();
    std::cout << "---------------------------------------------------" << std::endl;

    return 0;
}