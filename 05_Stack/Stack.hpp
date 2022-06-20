#ifndef _STACK_HPP_
#define _STACK_HPP_

// Node class
#include "Node.hpp"

// Stack class
template <typename T>
class Stack
{
private:
    // counter for the
    int size;
    // create a head node
    Node<T> *head;

public:
    // class constructor
    Stack();

    // add a node to the linked list, O(1)
    void push(const T data);

    // delete a node from the linked list, O(1)
    void pop();

    // delete node at the given index, O(1)
    T peak();

    // return the size of linked list
    int getsize() const;

    // check if the linked list is empty
    bool isempty() const;

    // print the content of linked list
    void print();
};

#include "Stack.tpp"

#endif // _STACK_HPP_
