// class default constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

// clear the doubly linked list, O(n)
template <typename T>
void DoublyLinkedList<T>::Clear()
{
    // initialize node
    Node<T> *trav = head;
    // traverse through
    while (trav != nullptr)
    {
        // assign the next node to a temp node
        Node<T> *temp = trav->next;
        // delete the current node
        delete trav;
        // set the traverse node to the next node
        trav = temp;
    }
    head = nullptr;
    tail = nullptr;
    trav = nullptr;
    size = 0;
}

// Insert an element to the tail of the doubly linked list, O(1)
template <typename T>
void DoublyLinkedList<T>::InsertEnd(const T data)
{
    // check if the list is empty
    if (isEmpty())
    {
        // set both heat and tail to the same data
        head = new Node<T>(data, nullptr, nullptr);
        tail = head;
    }
    else
    {
        // add the node to the tail of the list
        tail->next = new Node<T>(data, nullptr, tail);
        // set the new tail to tail->next
        tail = tail->next;
    }
    // increase the size
    size++;
}

// Insert an element to the head of the doubly linked list, O(1)
template <typename T>
void DoublyLinkedList<T>::InsertFirst(const T data)
{
    // check if the list is empty
    if (isEmpty())
    {
        // set both heat and tail to the same data
        head = new Node<T>(data, nullptr, nullptr);
        tail = head;
    }
    else
    {
        // add the node before the head node
        head->prev = new Node<T>(data, head, nullptr);
        // set the new head to head->prev
        head = head->prev;
    }
    // increase the size
    size++;
}

// Insert an element at the given index, O(n)
template <typename T>
void DoublyLinkedList<T>::InsertAt(const int index, const T data)
{
    if (index == 0)
    {
        // insert at the head
        InsertFirst(data);
        return;
    }
    if (index == size)
    {
        // insert at the tail
        InsertEnd(data);
        return;
    }
    if (index < 0 || index > size)
    {
        throw("InsertAt: index out of bound!");
    }
    else
    {
        // assign the head node to temp
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; ++i)
        {
            temp = temp->next;
        }
        // add the node to the tail of the list
        Node<T> *newNode = new Node<T>(data, temp->next, temp);
        temp->next->prev = newNode;
        temp->next = newNode;
        // increase the size
        size++;
    }
}

// Remove an element from the head of the linked list, O(1)
template <typename T>
void DoublyLinkedList<T>::DeleteFirst()
{
    // create trav node
    Node<T> *trav = head;
    // check if the list is empty
    if (isEmpty())
    {
        throw("DeleteFirst: the list is empty!");
        return;
    }
    else
    {
        // shift the head node to the next node
        head = head->next;
        // set the previous node of the head node to nullptr
        head->prev = nullptr;
        delete trav;
        size--;
        return;
    }
}

// Remove an element from the tail of the linked list, O(1)
template <typename T>
void DoublyLinkedList<T>::DeleteEnd()
{
    // create trav node
    Node<T> *trav = tail;
    // check if the list is empty
    if (isEmpty())
    {
        throw("DeleteEnd: the list is empty!");
        return;
    }
    else
    {
        // shift the tail node to the previous node
        tail = tail->prev;
        // set the next node of the tail node to nullptr
        tail->next = nullptr;
        delete trav;
        size--;
        return;
    }
}

// delete node at the given index, O(n)
// 0-based index
template <typename T>
void DoublyLinkedList<T>::DeleteAt(int index)
{
    // create trav1 and trav2 nodes
    Node<T> *trav1 = nullptr;
    Node<T> *trav2 = head;
    // return with an error if the list is empty
    if (isEmpty())
    {
        throw("DeleteAt: the list is empty!");
        return;
    }

    // check if the given index is out of bound
    if ((size-1) < index)
    {
        throw("DeleteAt: Index out of bounds!");
        return;
    }

    // deleting the head node
    if (index == 0)
    {
        DeleteFirst();
        return;
    }

    // deleting the head node
    if (index == (size-1))
    {
        DeleteEnd();
        return;
    }

    // traverse through the list to find the node to be deleted
    while (index-- > 0)
    {
        // update the trav1 node
        trav1 = trav2;

        // advance the trav2 node
        trav2 = trav2->next;
    }

    // change the next pointer of trav1 to trav2->next (skip trav2)
    trav1->next = trav2->next;
    trav2->next->prev = trav1;

    // delete the traverse node
    delete trav2;
    size--;
}

// return the size of linked list
template <typename T>
int DoublyLinkedList<T>::Size() const
{
    return size;
}

// check if the linked list is empty
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return Size() == 0;
}

// print the contents of linked list
template <typename T>
void DoublyLinkedList<T>::PrintList()
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
