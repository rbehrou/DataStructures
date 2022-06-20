#ifndef _NODE_HPP_
#define _NODE_HPP_

// The Stack class forward declaration
template <typename T>
class Stack;

// The Node class
template <typename T>
class Node
{
private:
    T data;
    Node *next;

public:
    // class Stack can access the private members of class Node
    friend class Stack<T>;
    // class default constructor
    Node() : data(0), next(nullptr) {}
    // class constructor
    Node(T _data, Node<T> *_next) : data(_data), next(_next) {}
};

#endif // _NODE_HPP_
