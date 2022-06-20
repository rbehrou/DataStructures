#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>

// helper function to generate vector of sorted random nubmer
std::vector<int> genRand(const int &MaxSize, const int &MaxRand)
{
    // Use current time as seed for random generator
    // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
    srand(time(0));

    // generate random vector of integer and sort it
    std::vector<int> vec(MaxSize);
    vec[0] = 0;
    for (auto i = 1; i < MaxSize; ++i)
    {
        vec[i] = rand() % MaxRand;
    }
    sort(vec.begin(), vec.end());
    return vec;
};

// get number of required station (greedy algorithm)
int getNumRefillsGRD(const std::vector<int> &x, const int &L)
{
    // initialize
    auto n = x.size();
    auto CurrRefill = 0;
    auto NumRefills = 0;
    while (CurrRefill < n)
    {
        auto LastRefill = CurrRefill;
        // traverse along the stations and update
        while (CurrRefill < n && (x[CurrRefill + 1] - x[LastRefill]) <= L)
            CurrRefill += 1;
        // check for impossible case
        if (CurrRefill == LastRefill)
        {
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "CurrRefill: " << CurrRefill << ", LastRefill: " << LastRefill << ", NumRefills: " << NumRefills << std::endl;
            std::cout << "L is: " << L << std::endl;
            for (auto j = 0; j < x.size(); ++j)
            {
                std::cout << x[j] << std::endl;
            }
            std::cout << "the setup for current configuration is impossible!" << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            return 0;
        }
        if (CurrRefill < n)
            NumRefills += 1;
    }
    // return total number of refills
    return NumRefills;
}

int main()
{
    // test cases
    std::vector<std::vector<int>> test_vec{{genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)},
                                           {genRand(10, 1000)}};
    std::vector<int> l_vec{250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100),
                           250 + (rand() % 100)};

    // loop over number of test cases and call the gcd
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (auto i = 0; i < test_vec.size(); ++i)
    {
        auto NumFills = getNumRefillsGRD(test_vec[i], l_vec[i]);
        std::cout << "The total number of refill is: " << NumFills << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}
