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
    sort(vec.begin(), vec.end());
    return vec;
};

void printPoly(const std::vector<int> &A)
{
    // size
    auto n = A.size();
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << A[i];
        if (i != 0)
        {
            std::cout << "x^" << i;
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
};

// multiplying polynomials (naive divide and conquer algorithm)
std::vector<int> MultPolyNaiveDC(const std::vector<int> &A, const std::vector<int> &B)
{
    // initialize the product array
    auto n = A.size();
    auto m = B.size();
    auto np = n + m - 1;
    std::vector<int> Cp(np, 0);
    // create a loop
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
        {
            Cp[i + j] += A[i] * B[j];
        }
    }
    // return the product
    return Cp;
}

int main()
{
    // initialize
    int MaxN = 10;
    int MaxM = 8;
    int MaxItr = 100;
    int Itr = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test cases
        std::vector<std::vector<int>> test_vecA{{genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)},
                                                {genRand(MaxN, 100)}};
        std::vector<std::vector<int>> test_vecB{{genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)},
                                                {genRand(MaxM, 100)}};

        // loop over number of test cases
        for (auto i = 0; i < test_vecA.size(); ++i)
        {
            // print ploy
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "The A polynomial is: " << std::endl;
            printPoly(test_vecA[i]);
            std::cout << "The B polynomial is: " << std::endl;
            printPoly(test_vecB[i]);
            // call product poly
            auto c_vec = MultPolyNaive(test_vecA[i], test_vecB[i]);
            // print ploy
            std::cout << "The C polynomial is: " << std::endl;
            printPoly(c_vec);
            std::cout << "-------------------------------------------------------------" << std::endl;
        }

        // update
        Itr += 1;
    }

    // return
    return 0;
}