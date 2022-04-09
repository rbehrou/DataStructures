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
    void add(const T data);
    /*
    Pushes forward all objects in front of the given index,
    then sets the data at the given index, O(n)
    */
    void insert(const int index, const T data);
    /*
    Sets the given index of mArr as data, O(1)
    */
    void set(const int index, const T data);
    /*
    Removes the object at the given index and pushes all the array contents back, O(n)
    */
    void remove(const int index);
    /*
    Get the size of array, O(1)
    */
    int size() const;
    /*
    Get the max size of array, O(1)
    */
    int maxsize() const;
    /*
    Check if the array is empty, O(1)
    */
    bool isempty() const;
    /*
    Print array
    */
    void print() const;
};

#include "DynamicArray.tpp"

#endif // _DYNAMIC_ARRAY_HPP_
