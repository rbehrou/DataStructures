#ifndef _NODE_HPP_
#define _NODE_HPP_

// The LinkedList class forward declaration
template <typename T>
class LinkedList;

// The Node class
template <typename T>
class Node
{
public:
    // class LinkedList can access the private members of class Node
    friend class LinkedList<T>;
    // class constructor
    Node() : data(0), next(nullptr) {}
    // class constructor
    Node(const T _data, const Node<T> *_next) : data(_data), next(_next) {}

private:
    T data;
    Node *next;
};

#endif
