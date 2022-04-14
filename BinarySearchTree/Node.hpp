#ifndef _NODE_HPP_
#define _NODE_HPP_

// The BinarySearchTree class forward declaration
template <typename T>
class BinarySearchTree;

// The Node class
template <typename T>
class Node
{
private:
    T data;
    Node *left;
    Node *right;

public:
    // class BinarySearchTree can access the private members of class Node
    friend class BinarySearchTree<T>;
    // class default constructor
    Node() : data(0), left(nullptr), right(nullptr) {}
    // class constructor
    Node(T _data, Node<T> *_left, Node<T> *_right) : data(_data), left(_left), right(_right) {}
};

#endif // _NODE_HPP_
