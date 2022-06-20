#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

// Node class
#include "Node.hpp"

// Queue class
template <typename T>
class Queue
{
private:
    // counter for the
    int size;
    // create the head and tail nodes
    Node<T> *head;
    Node<T> *tail;

public:
    // class constructor
    Queue();

    // add a node to the linked list, O(1)
    void enqueue(const T data);

    // delete a node from the linked list, O(1)
    void dequeue();

    // return the size of linked list
    int getsize() const;

    // check if the linked list is empty
    bool isempty() const;

    // print the content of linked list
    void print();
};

#include "Queue.tpp"

#endif // _QUEUE_HPP_
