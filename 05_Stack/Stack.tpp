// class default constructor
template <typename T>
Stack<T>::Stack() : size(0), head(nullptr) {}

// push a new item to the top of stack
template <typename T>
void Stack<T>::push(const T data)
{
    // create a new temp node
    Node<T> *temp = new Node<T>(data, nullptr);
    // assign the next node of temp to the head node
    temp->next = head;
    // make the temp node as a top of stack
    head = temp;
    // increase the size
    size++;
}

// pup an item from the top of stack
template <typename T>
void Stack<T>::pop()
{
    // create a new temp node
    Node<T> *temp = new Node<T>;
    // check if the head node is nullptr or not
    if (isempty())
    {
        throw("pop: the head node is nullptr!");
    }
    else
    {
        // assign the head node to temp
        temp = head;
        // shift the head node to the next node to release the head node
        head = head->next;
        // delete the temp node
        delete temp;
        // decrease the size
        size--;
    }
}

// show the item on the top of stack
template <typename T>
T Stack<T>::peak()
{
    if (!isempty())
        return head->data;
    else
        throw("peak: the head node is nullptr!");
}

// return the size of stack
template <typename T>
int Stack<T>::getsize() const
{
    return size;
}

// check if the stack is empty
template <typename T>
bool Stack<T>::isempty() const
{
    return getsize() == 0;
}

// print the contents of stack
template <typename T>
void Stack<T>::print()
{
    Node<T> *trav = head;
    // traverse through the stack
    while (trav != nullptr)
    {
        std::cout << "The node value is: " << trav->data << std::endl;
        // advance to the node
        trav = trav->next;
    }
}
