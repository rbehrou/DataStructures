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
    int pw = n - 1;
    for (int i = 0; i < n; ++i)
    {
        std::cout << A[i];
        if (i != n - 1)
        {
            std::cout << "x^" << pw;
            std::cout << " + ";
            pw -= 1;
        }
    }
    std::cout << std::endl;
};

// multiplying polynomials (naive divide and conquer algorithm)
std::vector<int> MultPolyNaiveDC(const std::vector<int> &A,
                                 const std::vector<int> &B,
                                 const int &n)
{
    // initialize the product array
    std::vector<int> R((2 * n) - 1, 0);
    // base case
    if (n == 1)
    {
        R[0] = A[0] * B[0];
        return R;
    }

    // divide the problem into four sub-problems
    int d = n / 2;

    // initialize
    std::vector<int> D0(d, 0);
    std::vector<int> E0(d, 0);
    std::vector<int> D1(d - n % 2, 0);
    std::vector<int> E1(d - n % 2, 0);

    // loop to fill out
    for (auto i = 0; i < d; ++i)
    {
        D0[i] = A[i + d];
        E0[i] = B[i + d];
        D1[i] = A[i];
        E1[i] = B[i];
    }

    // D_{1}E_{1}
    auto D1E1 = MultPolyNaiveDC(D1, E1, d);
    // D_{1}E_{0}
    auto D1E0 = MultPolyNaiveDC(D1, E0, d);
    // D_{0}E_{1}
    auto D0E1 = MultPolyNaiveDC(D0, E1, d);
    // D_{0}E_{0}
    auto D0E0 = MultPolyNaiveDC(D0, E0, d);

    // finalize
    for (auto i = 0; i < (n - 1); ++i)
    {
        R[i] += D1E1[i];
        R[i + d] += D1E0[i] + D0E1[i];
        R[i + (2 * d)] += D0E0[i];
    }

    // return
    return R;
}

int main()
{
    // initialize
    int MaxN = 4;
    int MaxM = MaxN;
    int MaxItr = 200;
    int Itr = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test cases
        // A(x) = 4x^{3} + 3x^{2} + 2x + 1
        std::vector<std::vector<int>> test_vecA{{4, 3, 2, 1}};
        // B(x) = x^{3} + 2x^{2} + 3x + 4
        std::vector<std::vector<int>> test_vecB{{1, 2, 3, 4}};
        // std::vector<std::vector<int>> test_vecA{{genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)},
        //                                         {genRand(MaxN, 100)}};
        // std::vector<std::vector<int>> test_vecB{{genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)},
        //                                         {genRand(MaxM, 100)}};

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
            auto c_vec = MultPolyNaiveDC(test_vecA[i], test_vecB[i], MaxN);
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