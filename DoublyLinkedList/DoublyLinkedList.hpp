#ifndef _DOUBLY_LINKED_LIST_HPP_
#define _DOUBLY_LINKED_LIST_HPP_

// Node class
#include "Node.hpp"

// DoublyLinkedList class
template <typename T>
class DoublyLinkedList
{
private:
    // counter
    int size;
    // create the head and tail nodes
    Node<T> *head;
    Node<T> *tail;

public:
    // class constructor
    DoublyLinkedList();

    // clear the linked list, O(n)
    void Clear();

    // Insert an element to the tail of the linked list, O(1)
    void InsertEnd(const T data);

    // Insert an element to the tail of the linked list, O(1)
    void InsertFirst(const T data);

    // Insert an element at the given index, O(n)
    void InsertAt(const int index, const T data);

    // Remove an element from the head of the linked list, O(1)
    void DeleteFirst();

    // Remove an element from the tail of the linked list, O(1)
    void DeleteEnd();

    // Delete node at the given index, O(n)
    void DeleteAt(int index);

    // return the size of linked list
    int Size() const;

    // check if the linked list is empty
    bool isEmpty() const;

    // print the content of linked list
    void PrintList();
};

#include "DoublyLinkedList.tpp"

#endif // _DOUBLY_LINKED_LIST_HPP_
