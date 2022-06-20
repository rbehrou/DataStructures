// class default constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : size(0), head(nullptr) {}

// class destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    if (head)
    {
        Node<T> *trav = head;
        while (trav != nullptr)
        {
            Node<T> *temp = trav->next;
            delete trav;
            trav = temp;
        }
        head = nullptr;
    }
}

// clear the linked list, O(n)
template <typename T>
void SinglyLinkedList<T>::Clear()
{
    Node<T> *trav = head;
    while (trav != nullptr)
    {
        Node<T> *temp = trav->next;
        delete trav;
        trav = temp;
    }
    head = nullptr;
    size = 0;
}

// add a node to the linked list
// the insertion is done at the end of the list
template <typename T>
void SinglyLinkedList<T>::InsertNode(const T val)
{
    // create a new node
    Node<T> *newNode = new Node<T>;
    // set the next element in the node to nullptr and add val
    newNode->next = nullptr;
    newNode->data = val;

    // check if head is nullptr o not
    if (head != nullptr)
    {
        // set traverse node to head
        Node<T> *trav = head;
        // traverse the current node
        while (trav->next != nullptr)
        {
            trav = trav->next;
        }
        // point new node to the end of the current
        trav->next = newNode;
    }
    // otherwise set the new node to head
    else
    {
        head = newNode;
    }
    // increase the size
    size++;
}

// delete a particular value (node) to the linked list
// always the first value in the list
template <typename T>
void SinglyLinkedList<T>::DeleteNode(const T val)
{
    Node<T> *DelNode = new Node<T>;
    Node<T> *trav = head;
    Node<T> *temp = head;
    DelNode = nullptr;
    // traverse through the list and make sure the val is not in node
    while (trav != nullptr && trav->data != val)
    {
        // store trav
        temp = trav;
        // advance trav
        trav = trav->next;
    }
    if (trav == nullptr)
    {
        std::cout << "The value: " << val << "was not in the list." << std::endl;
        // delete the Node
        delete DelNode;
    }
    else
    {
        // otherwise we found the node to get deleted
        DelNode = trav;
        // advance trav
        trav = trav->next;
        // link the next node in temp to trav
        temp->next = trav;
        // if the delete node is the head
        if (DelNode == head)
        {
            // advance head
            head = head->next;
            temp = nullptr;
        }
        // delete the Node
        delete DelNode;
        std::cout << "A node with a value of: " << val << " was deleted." << std::endl;
    }
    // decrease the size
    size--;
}

// delete node at the given index
template <typename T>
void SinglyLinkedList<T>::DeleteNodeAt(int index)
{
    // create trav and temp list
    Node<T> *trav = head;
    Node<T> *temp = nullptr;
    // return nothing if the head is empty
    if (head == nullptr)
    {
        std::cout << "The linked list is empty." << std::endl;
        return;
    }

    // check if the given index is out of bound
    if (size < index)
    {
        throw("DeleteNodeAt: Index out of bounds!");
        return;
    }

    // Deleting the head.
    if (index == 1)
    {
        // remove head
        head = head->next;
        delete trav;
        size--;
        return;
    }

    // traverse through the list to find the node to be deleted
    while (index-- > 1)
    {
        // update temp
        temp = trav;

        // advance the trav node
        trav = trav->next;
    }

    // change the next pointer of the previous node to the trav->next
    temp->next = trav->next;

    // delete the traverse node
    delete trav;
    size--;
}

// return the size of linked list
template <typename T>
int SinglyLinkedList<T>::Size() const
{
    return size;
}

// check if the linked list is empty
template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
    return Size() == 0;
}

// print the contents of linked list
template <typename T>
void SinglyLinkedList<T>::PrintList()
{
    Node<T> *trav = head;
    // traverse through the linked list
    while (trav != nullptr)
    {
        std::cout << "The node value is: " << trav->data << std::endl;
        // advance to the node
        trav = trav->next;
    }
}
