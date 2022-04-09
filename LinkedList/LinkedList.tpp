// class constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), curr(nullptr), temp(nullptr) {}

// class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    if (head)
    {
        Node<T> *tmp = head;
        while (tmp != 0)
        {
            Node<T> *next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = 0;
    }
}

// add a node to the linked list
template <typename T>
void LinkedList<T>::AddNode(const T val)
{
    // create a new node
    Node<T> *newNode = new Node<T>;
    // set the next element in the node to nullptr and add val
    newNode->next = nullptr;
    newNode->data = val;

    // check if head is nullptr o not
    if (head != nullptr)
    {
        // set current node to head
        curr = head;
        // traverse the current node
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        // point new node to the end of the current
        curr->next = newNode;
    }
    // otherwise set the new node to head
    else
    {
        head = newNode;
    }
}

// delete a node to the linked list
template <typename T>
void LinkedList<T>::DeleteNode(const T val)
{
    Node<T> *DelNode = new Node<T>;
    DelNode = nullptr;
    temp = head;
    curr = head;
    // traverse through the list and make sure the val is not in node
    while (curr != nullptr && curr->data != val)
    {
        // store curr
        temp = curr;
        // advance curr
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        std::cout << "The value: " << val << "was not in the list." << std::endl;
        // delete the Node
        delete DelNode;
    }
    else
    {
        // otherwise we found the node to get deleted
        DelNode = curr;
        // advance curr
        curr = curr->next;
        // link the next node in temp to curr
        temp->next = curr;
        // if the delete node is the head
        if (DelNode == head)
        {
            // advance head
            head = head->next;
            temp = nullptr;
        }
        // delete the Node
        delete DelNode;
        std::cout << "The value: " << val << " was deleted." << std::endl;
    }
}

// print the contents of linked list
template <typename T>
void LinkedList<T>::PrintList()
{
    curr = head;
    // traverse
    while (curr != nullptr)
    {
        std::cout << "The node value is: " << curr->data << std::endl;
        // advance current
        curr = curr->next;
    }
}
