#include <iostream>

// class header file
#include "Queue.hpp"

int main()
{
    // create the class object of queue (int)
    Queue<int> queue;

    // add node to the list
    queue.enqueue(1);
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(9);

    // check the size and print the contents of queue
    std::cout << "The size of queue is: " << queue.getsize() << std::endl;
    queue.print();

    // remove node to the list
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    // check the size and print the contents of queue
    std::cout << "The size of queue is: " << queue.getsize() << std::endl;
    queue.print();

    // check if the queue is empty
    if (queue.isempty())
        std::cout << "The queue is empty!" << std::endl;
    else
        std::cout << "The queue is NOT empty!" << std::endl;

    return 0;
}