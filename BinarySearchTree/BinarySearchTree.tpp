// class default constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

// insert a value into the BST
template <typename T>
Node<T> *BinarySearchTree<T>::insert(const T data, Node<T> *node)
{
    // check if the list is empty
    if (node == nullptr)
    {
        // set a root node
        node = new Node<T>;
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (data < node->data)
    {
        // insert to the left (recursion)
        node->left = insert(data, node->left);
    }
    else if (data > node->data)
    {
        // insert to the right (recursion)
        node->right = insert(data, node->right);
    }
    // return node
    return node;
}

// add value to the tree
template <typename T>
void BinarySearchTree<T>::insert(const T data)
{
    // recursion to the root node
    root = insert(data, root);
}

// inorder (private)
template <typename T>
void BinarySearchTree<T>::inorder(Node<T> *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

// inorder (public)
template <typename T>
void BinarySearchTree<T>::inorder()
{
    inorder(root);
    std::cout << std::endl;
}
