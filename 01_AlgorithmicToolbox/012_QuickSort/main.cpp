#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>

// helper function to generate vector of random integer
std::vector<int> genRand(const int &MaxSize, const int &MaxRand)
{
    // https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    // Use current time as seed for random generator
    // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
    srand(time(0));

    // generate random vector of integer and sort it
    std::vector<int> vec(MaxSize);
    for (auto i = 0; i < MaxSize; ++i)
    {
        vec[i] = rand() % MaxRand;
    }
    return vec;
};

// helper function to print vector
void printVec(const std::vector<int> &x)
{
    std::cout << "[" << x[0];
    for (int i = 1; i < x.size(); ++i)
    {
        std::cout << ", ";
        std::cout << x[i];
    }
    std::cout << "]" << std::endl;
};

// helper function to slice vector
std::vector<int> slice(std::vector<int> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    std::vector<int> vec(first, last);
    return vec;
};

// last element is taken as pivot
int Partition(std::vector<int> &A, const int &left, const int &right)
{
    // pivot
    auto pivot = right;
    auto j = left;
    for (auto i = left; i < right; ++i)
    {
        if (A[i] < A[pivot])
        {
            std::swap(A[i], A[j]);
            ++j;
        }
    }
    std::swap(A[j], A[pivot]);
    return j;
}

// quick sort
void QuickSort(std::vector<int> &A, const int &left, const int &right)
{
    // safeguard
    if (left < right)
    {
        // get the partition (A[m] is in the final position)
        auto m = Partition(A, left, right);
        // recursive call to the left part
        QuickSort(A, left, m - 1);
        // recursive call to the right part
        QuickSort(A, m + 1, right);
    }
}

int main()
{
    // initialize
    int MaxN = 50;
    int MaxRand = 100;
    int MaxItr = 200;
    int Itr = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test case
        std::vector<int> test_vecA = genRand(MaxN, MaxRand);
        // print vector
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "The vector BEFORE sorting: " << std::endl;
        printVec(test_vecA);
        // call the sorting algorithm
        QuickSort(test_vecA, 0, test_vecA.size() - 1);
        // print vector
        std::cout << "The vector AFTER sorting: " << std::endl;
        printVec(test_vecA);
        std::cout << "-------------------------------------------------------------" << std::endl;
        // check
        for (auto j = 1; j < test_vecA.size(); ++j)
        {
            if (test_vecA[j] < test_vecA[j - 1])
                throw std::invalid_argument("the sorting algorithm is not right!");
        }

        // update
        Itr += 1;
    }

    // return
    return 0;
}