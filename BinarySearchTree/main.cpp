#include <iostream>

// class header file
#include "BinarySearchTree.hpp"

int main()
{
    // create the class object of the binary search tree (int)
    BinarySearchTree<int> bst;

    // insert data
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);

    // inorder
    bst.inorder();

    return 0;
}