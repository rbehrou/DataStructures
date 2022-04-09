#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

// Node class
#include "Node.hpp"

// LinkedList class
template <typename T>
class LinkedList
{
private:
    // create head, current, and temp node pointers
    Node<T> *head;
    Node<T> *curr;
    Node<T> *temp;

public:
    // class constructor
    LinkedList();

    // class destructor
    ~LinkedList();

    // add a node to the linked list
    void AddNode(const T val);

    // delete a node from the linked list
    void DeleteNode(const T val);

    // print the content of linked list
    void PrintList();
};

#include "LinkedList.tpp"

#endif
