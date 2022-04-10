#include <iostream>

// class header file
#include "Stack.hpp"

int main()
{
    // create the class object of stack (int)
    Stack<int> stack;

    // add node to the list
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.push(9);

    // check the size and print the contents of stack
    std::cout << "The size of stack is: " << stack.getsize() << std::endl;
    stack.print();

    // pop nodes
    stack.pop();
    stack.pop();
    std::cout << "The size of stack is: " << stack.getsize() << std::endl;
    stack.print();
    std::cout << "The peak node of stack is: " << stack.peak() << std::endl;

    // check if the stack is empty
    if (stack.isempty())
        std::cout << "The stack is empty!" << std::endl;
    else
        std::cout << "The stack is NOT empty!" << std::endl;

    return 0;
}