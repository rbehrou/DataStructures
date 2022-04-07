#include <iostream>
#include <memory>
#include "DynamicArray.hpp"

int main()
{
    // call class object by default constructor
    DynamicArray<int> DefaultArray;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Class default constructor:" << std::endl;
    std::cout << "The size of the array is: " << DefaultArray.size() << std::endl;
    std::cout << "The max size of the array is: " << DefaultArray.maxsize() << std::endl;
    if (DefaultArray.isempty())
    {
        std::cout << "The array is empty." << std::endl;
    }
    else
    {
        std::cout << "The array is not empty." << std::endl;
    }
    std::cout << "The max size of the array is: " << DefaultArray.maxsize() << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

    // call class object with overwriting constructor
    auto Size = 8;
    auto MaxSize = 16;
    auto Value = 1.75;
    DynamicArray<double> OverArray(Size, MaxSize, Value);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Class overwriting constructor:" << std::endl;
    std::cout << "The size of the array is: " << OverArray.size() << std::endl;
    std::cout << "The max size of the array is: " << OverArray.maxsize() << std::endl;
    if (OverArray.isempty())
    {
        std::cout << "The array is empty." << std::endl;
    }
    else
    {
        std::cout << "The array is not empty." << std::endl;
    }
    OverArray.print();
    for (auto i = 0; i < OverArray.size(); ++i)
        std::cout << "The value at index " << i << " is: " << OverArray.get(i) << std::endl;
    auto set_val = 1.85;
    for (auto i = 0; i < OverArray.size(); ++i)
        OverArray.set(i, set_val);
    for (auto i = 0; i < OverArray.size(); ++i)
        std::cout << "The value at index " << i << " after set is: " << OverArray.get(i) << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

    // call class object with copy constructor
    DynamicArray<double> CopyArray(OverArray);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Class copy constructor:" << std::endl;
    std::cout << "The size of the array is: " << CopyArray.size() << std::endl;
    std::cout << "The max size of the array is: " << CopyArray.maxsize() << std::endl;
    if (CopyArray.isempty())
    {
        std::cout << "The array is empty." << std::endl;
    }
    else
    {
        std::cout << "The array is not empty." << std::endl;
    }
    CopyArray.print();
    for (auto i = 0; i < CopyArray.size(); ++i)
        std::cout << "The value at index " << i << " is: " << CopyArray.get(i) << std::endl;
    auto set_val_copy = 1.971;
    for (auto i = 0; i < CopyArray.size(); ++i)
        CopyArray.set(i, set_val_copy);
    for (auto i = 0; i < CopyArray.size(); ++i)
        std::cout << "The value at index " << i << " after set is: " << CopyArray.get(i) << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

    // call class object with overwriting constructor
    Size = 10;
    MaxSize = 20;
    Value = 1.243;
    DynamicArray<double> AddArray(Size, MaxSize, Value);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Class overwriting constructor:" << std::endl;
    std::cout << "The original size of the array is: " << AddArray.size() << std::endl;
    std::cout << "The original max size of the array is: " << AddArray.maxsize() << std::endl;
    if (AddArray.isempty())
    {
        std::cout << "The array is empty." << std::endl;
    }
    else
    {
        std::cout << "The array is not empty." << std::endl;
    }
    AddArray.print();
    for (auto i = 0; i < AddArray.size(); ++i)
        std::cout << "The value at index " << i << " is: " << AddArray.get(i) << std::endl;
    set_val_copy = 1.471;
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    AddArray.add(set_val_copy);
    std::cout << "The new size of the array is: " << AddArray.size() << std::endl;
    std::cout << "The new max size of the array is: " << AddArray.maxsize() << std::endl;
    for (auto i = 0; i < AddArray.size(); ++i)
        std::cout << "The value at index " << i << " after add is: " << AddArray.get(i) << std::endl;
    for (auto i = AddArray.size() - 2; i >= 10; i--)
    {
        std::cout << "Removing element with value of: " << AddArray.get(i) << " at index " << i << std::endl;
        AddArray.remove(i);
    }
    std::cout << "The new size of the array before insert is: " << AddArray.size() << std::endl;
    std::cout << "The new max size of the array before insert is: " << AddArray.maxsize() << std::endl;
    // insert
    AddArray.insert(10, set_val_copy);
    AddArray.insert(11, set_val_copy);
    AddArray.insert(12, set_val_copy);
    AddArray.insert(13, set_val_copy);
    AddArray.insert(14, set_val_copy);
    AddArray.insert(15, set_val_copy);
    std::cout << "The new size of the array after insert is: " << AddArray.size() << std::endl;
    std::cout << "The new max size of the array after insert is: " << AddArray.maxsize() << std::endl;
    AddArray.print();
    std::cout << "-------------------------------------------------------------" << std::endl;

    return 0;
}
