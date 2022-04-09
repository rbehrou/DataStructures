#ifndef _SINGLY_LINKED_LIST_HPP_
#define _SINGLY_LINKED_LIST_HPP_

// Node class
#include "Node.hpp"

// SinglyLinkedList class
template <typename T>
class SinglyLinkedList
{
private:
    // counter for the
    int size;
    // create a head node
    Node<T> *head;

public:
    // class constructor
    SinglyLinkedList();

    // class destructor
    ~SinglyLinkedList();

    // clear the linked list, O(n)
    void Clear();

    // add a node to the linked list O(n)
    void InsertNode(const T val);

    // delete a node from the linked list O(n)
    void DeleteNode(const T val);

    // delete node at the given index O(n))
    void DeleteNodeAt(int index);

    // return the size of linked list
    int Size() const;

    // check if the linked list is empty
    bool isEmpty() const;

    // print the content of linked list
    void PrintList();
};

#include "SinglyLinkedList.tpp"

#endif // _SINGLY_LINKED_LIST_HPP_
