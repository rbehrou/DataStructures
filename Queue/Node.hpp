#ifndef _NODE_HPP_
#define _NODE_HPP_

// The Queue class forward declaration
template <typename T>
class Queue;

// The Node class
template <typename T>
class Node
{
private:
    T data;
    Node *next;
    Node *prev;

public:
    // class Queue can access the private members of class Node
    friend class Queue<T>;
    // class default constructor
    Node() : data(0), next(nullptr) {}
    // class constructor
    Node(T _data, Node<T> *_next, Node<T> *_prev) : data(_data), next(_next), prev(_prev) {}
};

#endif // _NODE_HPP_
