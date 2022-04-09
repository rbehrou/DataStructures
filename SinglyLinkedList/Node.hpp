#ifndef _NODE_HPP_
#define _NODE_HPP_

// The SinglyLinkedList class forward declaration
template <typename T>
class SinglyLinkedList;

// The Node class
template <typename T>
class Node
{
private:
    T data;
    Node *next;

public:
    // class SinglyLinkedList can access the private members of class Node
    friend class SinglyLinkedList<T>;
    // class default constructor
    Node() : data(0), next(nullptr) {}
    // class constructor
    Node(const T _data, const Node<T> *_next) : data(_data), next(_next) {}
};

#endif // _NODE_HPP_
