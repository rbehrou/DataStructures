#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>

// helper function to generate vector of sorted random nubmer
std::vector<int> genRand(const int &MaxSize, const int &MaxRand)
{
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

// selection sort
void SelectionSort(std::vector<int> &x)
{
    // loop
    for (auto i = 0; i < x.size(); ++i)
    {
        auto mid = i;
        for (auto j = i + 1; j < x.size(); ++j)
        {
            if (x[j] < x[mid])
            {
                mid = j;
            }
        }
        // swap two indices
        std::swap(x[i], x[mid]);
    }
}

int main()
{
    // initialize
    int MaxN = 50;
    int MaxRand = 100;
    int MaxItr = 50;
    int Itr = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test cases
        std::vector<std::vector<int>> test_vecA{{genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)},
                                                {genRand(MaxN, MaxRand)}};
        // loop over number of test cases
        for (auto i = 0; i < test_vecA.size(); ++i)
        {
            // print vector
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "The vector BEFORE sorting: " << std::endl;
            printVec(test_vecA[i]);
            // call the sorting function
            SelectionSort(test_vecA[i]);
            // print vector
            std::cout << "The vector AFTER sorting: " << std::endl;
            printVec(test_vecA[i]);
            std::cout << "-------------------------------------------------------------" << std::endl;
        }

        // update
        Itr += 1;
    }

    // return
    return 0;
}