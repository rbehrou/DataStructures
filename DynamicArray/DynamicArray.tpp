// Class default constructor
template <typename T>
DynamicArray<T>::DynamicArray() : mArr(new T[1]), mSize(0), mMaxSize(1) {}

// Class constructor
template <typename T>
DynamicArray<T>::DynamicArray(const int aSize, const int aMaxSize, const T aValue)
    : mArr(new T[aMaxSize]), mSize(aSize), mMaxSize(aMaxSize)
{
    for (auto i = 0; i < mSize; ++i)
        mArr[i] = aValue;
}

// Class copy constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &aArr)
    : mArr(aArr.mSize ? new T[aArr.mSize] : nullptr), mSize(aArr.mSize), mMaxSize(aArr.mMaxSize)
{
    if (mArr)
        std::copy(aArr.mArr, aArr.mArr + mSize, mArr);
}

// Class default destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if (mArr)
        delete[] mArr;
}

// Class get function
template <typename T>
T DynamicArray<T>::get(const int index) const
{
    if (index < mSize && index >= 0)
        return mArr[index];
    else
        throw("get: Index out of bounds!");
}

// Class set function
template <typename T>
void DynamicArray<T>::set(int index, T data)
{
    if (index < mSize && index >= 0)
        mArr[index] = data;
    else
        throw("set: Index out of bounds!");
}

// Class add function
template <typename T>
void DynamicArray<T>::add(T data)
{
    if (mSize == mMaxSize)
    {
        mMaxSize = mMaxSize * 2;
        T *newArr = new T[mMaxSize];
        std::copy(mArr, mArr + mSize, newArr);
        delete[] mArr;
        mArr = newArr;
    }
    mArr[mSize] = data;
    mSize++;
}

// Class insert function
template <typename T>
void DynamicArray<T>::insert(int index, T data)
{
    if (index < mSize && index >= 0)
    {
        if (mSize == mMaxSize)
            mMaxSize = mMaxSize * 2;
        T *newArr = new T[mMaxSize];

        for (int i = 0, j = 0; i < mSize; i++, j++)
        {
            if (i == index)
            {
                newArr[j] = data;
                j++;
            }
            newArr[j] = mArr[i];
        }

        delete[] mArr;
        mArr = newArr;
        mSize++;
    }
    else
        throw("insert: Index out of bounds!");
}

// Class remove function
template <typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < mSize && index >= 0)
    {
        T *newArr = new T[mMaxSize];
        for (int i = 0, j = 0; i < mSize; i++, j++)
        {
            if (i == index)
                i++;
            if (i < mSize)
            // data at the jth location is equal to the data at the i++ location
            {
                newArr[j] = mArr[i];
            }
        }
        delete[] mArr;
        mArr = newArr;
        mSize--;
    }
    else
        throw("remove: Index out of bounds!");
}

// Class size function
template <typename T>
int DynamicArray<T>::size()
{
    return mSize;
}

// Class max size function
template <typename T>
int DynamicArray<T>::maxsize()
{
    return mMaxSize;
}

// Class is empty function
template <typename T>
bool DynamicArray<T>::isempty()
{
    return mSize == 0;
}

// Class print function
template <typename T>
void DynamicArray<T>::print()
{
    std::cout << "Array: " << std::endl;
    for (auto i = 0; i < mSize; ++i)
    {
        std::cout << mArr[i] << std::endl;
    }
}
