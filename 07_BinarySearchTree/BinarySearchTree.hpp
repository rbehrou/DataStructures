#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

// Node class
#include "Node.hpp"

// BinarySearchTree class
template <typename T>
class BinarySearchTree
{
private:
    // create the root node
    Node<T> *root;

    // insert a value into the BST
    Node<T> *insert(const T data, Node<T> *node);

    // inorder
    void inorder(Node<T> *node);

public:
    // class constructor
    BinarySearchTree();

    // insert value to the tree
    void insert(const T data);

    // inorder
    void inorder();
};

#include "BinarySearchTree.tpp"

#endif // _BINARY_SEARCH_TREE_HPP_
