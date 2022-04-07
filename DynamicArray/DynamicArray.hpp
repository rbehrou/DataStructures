#ifndef _DYNAMIC_ARRAY_HPP_
#define _DYNAMIC_ARRAY_HPP_

template <typename T>
class DynamicArray
{
private:
    T *mArr;      // the memory pointer to the array
    int mSize;    // number of elements currently being stored in the array
    int mMaxSize; // memory size (MaxSize) reserved for the array
public:
    /*
    Default constructor
    */
    DynamicArray();
    /*
    The constructor
    */
    DynamicArray(const int aSize, const int aMaxSize, const T aValue);
    /*
    Class copy constructor
    */
    DynamicArray(const DynamicArray &aArr);
    /*
    Default destructor
    */
    ~DynamicArray();
    /*
    Get value of the array at the given index, O(1)
    */
    T get(const int index) const;
    /*
    Add a new data to the end of current array, O(1)
    */
    void add(T data);
    /*
    Pushes forward all objects in front of the given index,
    then sets the data at the given index, O(n)
    */
    void insert(int index, T data);
    /*
    Sets the given index of mArr as data, O(1)
    */
    void set(int index, T data);
    /*
    Removes the object at the given index and pushes all the array contents back, O(n)
    */
    void remove(int index);
    /*
    Get the size of array, O(1)
    */
    int size();
    /*
    Get the max size of array, O(1)
    */
    int maxsize();
    /*
    Check if the array is empty, O(1)
    */
    bool isempty();
    /*
    Print array
    */
    void print();
};

#include "DynamicArray.tpp"

#endif
