#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>

// helper function to generate vector of random integer
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

std::vector<int> Merge(std::vector<int> &v1, std::vector<int> &v2)
{

    // v3 is the output vector
    // it will store the merged vector obtained by merging v1 and v2
    std::vector<int> v3;

    // initialize
    auto i = 0;
    auto j = 0;
    auto n = v1.size();
    auto m = v2.size();

    // traverse each elemenst of v1 and v2
    while (i < n && j < m)
    {

        // comparing v1[i] and v2[j]
        // if v1[i] is smaller than v2[j]
        // push v1[i] to v3 and increment i
        // if v2[j] is smaller than v1[i]
        // push v2[j] to v3 and increment j
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i]);
            ++i;
        }
        else
        {
            v3.push_back(v2[j]);
            ++j;
        }
    }

    // push the remaining elements in v1 to v3
    while (i < n)
    {
        v3.push_back(v1[i]);
        ++i;
    }

    // push the remaining elements in v2 to v3
    while (j < m)
    {
        v3.push_back(v2[j]);
        ++j;
    }

    return v3;
};

// merge sort
std::vector<int> MergeSort(const std::vector<int> &A)
{
    // initialize
    auto n = A.size();
    // base case
    if (n == 1)
        return A;

    // get the mid size
    auto m = n / 2;
    // get the sliced vectors
    auto left_slice = slice(A, 0, m);
    auto right_slice = slice(A, m, n);
    // for the left half
    auto B = MergeSort(left_slice);
    // for the right half
    auto C = MergeSort(right_slice);
    // merge two vectors
    auto D = Merge(B, C);
    // return
    return D;
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
            // call the sorting algorithm
            auto merged_vec = MergeSort(test_vecA[i]);
            // print vector
            std::cout << "The vector AFTER sorting: " << std::endl;
            printVec(merged_vec);
            std::cout << "-------------------------------------------------------------" << std::endl;
            // check
            for (auto j = 1; j < merged_vec.size(); ++j)
            {
                if (merged_vec[j] < merged_vec[j-1])
                    throw std::invalid_argument("the sorting algorithm is not right!");
            }
        }

        // update
        Itr += 1;
    }

    // return
    return 0;
}
