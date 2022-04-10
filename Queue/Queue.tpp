// class default constructor
template <typename T>
Queue<T>::Queue() : size(0), head(nullptr), tail(nullptr) {}

// enqueue to the tail of queue
template <typename T>
void Queue<T>::enqueue(const T data)
{
    // create a new temp node
    Node<T> *temp = new Node<T>(data, nullptr, nullptr);
    // check if the head is nullptr or not
    if (tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        // assign the next node of temp to the head node
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    // increase the size
    size++;
}

// dequeue from the head of queue
template <typename T>
void Queue<T>::dequeue()
{
    // create a new temp node
    Node<T> *temp = new Node<T>;
    // check if the head node is nullptr or not
    if (isempty())
    {
        throw("dequeue: the head node is nullptr!");
    }
    else
    {
        // assign the head node to temp
        temp = head;
        // shift the head node to the next node to release the head node
        head = head->next;
        // assign the prev pointer to the temp
        head->prev = temp;
        // delete the temp node
        delete temp;
        // decrease the size
        size--;
    }
}

// return the size of queue
template <typename T>
int Queue<T>::getsize() const
{
    return size;
}

// check if the queue is empty
template <typename T>
bool Queue<T>::isempty() const
{
    return getsize() == 0;
}

// print the contents of queue
template <typename T>
void Queue<T>::print()
{
    Node<T> *trav = head;
    // traverse through the queue
    while (trav != nullptr)
    {
        std::cout << "The node value is: " << trav->data << std::endl;
        // advance to the node
        trav = trav->next;
    }
}
