#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>

// helper function to generate vector random nubmer
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

// array linear search (divide and conquer algorithm)
int LinearSearch(const std::vector<int> &A, const int &low, const int &up, const int &key)
{
    // check the edge cases
    if (up < low)
    {
        std::cout << "Index not found!, low: " << low << ", up: " << up << std::endl;
        return 0;
    }
    if (A[low] == key)
        return low;
    // recursion
    return LinearSearch(A, low + 1, up, key);
}

int main()
{
    // initialize
    int MaxSize = 50;

    // test cases
    std::vector<std::vector<int>> test_vec{{genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)},
                                           {genRand(MaxSize, 10000)}};
    std::vector<int> key_vec{1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize),
                             1 + (rand() % MaxSize)};

    // loop over number of test cases
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (auto i = 0; i < test_vec.size(); ++i)
    {
        auto index = LinearSearch(test_vec[i], 0, MaxSize, test_vec[i][key_vec[i]]);
        if (test_vec[i][key_vec[i]] == test_vec[i][index])
            std::cout << "The key: " << test_vec[i][key_vec[i]] << " was found at index: " << index << std::endl;
        else
            std::cout << "ERROR: the index for the key: " << test_vec[i][key_vec[i]] << " at iteration: " << i << " not found!" << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}