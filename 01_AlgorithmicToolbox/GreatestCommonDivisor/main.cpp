#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>

// create a typedef
typedef unsigned long long int UINT64;

// helper function to generate random integer
// http://stackoverflow.com/questions/22883840/c-get-random-number-from-0-to-max-long-long-integer
UINT64 genRand(const UINT64 &begin = 0, const UINT64 &end = 100)
{
    // Use current time as seed for random generator
    // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
    srand(time(0));
    
    return begin >= end ? 0 : begin + (UINT64)rand() * ((end - begin) / RAND_MAX);
};

// Greatest common divisor (recursion)
UINT64 gcd(const UINT64 &a, const UINT64 &b)
{
    // safeguard
    if (b == 0)
    {
        return a;
    }
    // compute the reminder
    UINT64 r = a % b;

    // recursion
    return gcd(b, r);
};

int main()
{
    // test cases
    std::vector<std::vector<UINT64>> test_vec{{genRand(0, UINT_MAX), genRand(0, UINT_MAX)},
                                              {genRand(0, UINT_MAX), genRand(0, UINT_MAX)},
                                              {genRand(0, UINT_MAX), genRand(0, UINT_MAX)},
                                              {genRand(0, UINT_MAX), genRand(0, UINT_MAX)},
                                              {genRand(0, UINT_MAX), genRand(0, UINT_MAX)},
                                              {genRand(0, ULONG_MAX), genRand(0, ULONG_MAX)},
                                              {genRand(0, ULONG_MAX), genRand(0, ULONG_MAX)},
                                              {genRand(0, ULONG_MAX), genRand(0, ULONG_MAX)},
                                              {genRand(0, ULONG_MAX), genRand(0, ULONG_MAX)},
                                              {genRand(0, ULONG_MAX), genRand(0, ULONG_MAX)},
                                              {genRand(0, ULLONG_MAX), genRand(0, ULLONG_MAX)},
                                              {genRand(0, ULLONG_MAX), genRand(0, ULLONG_MAX)},
                                              {genRand(0, ULLONG_MAX), genRand(0, ULLONG_MAX)},
                                              {genRand(0, ULLONG_MAX), genRand(0, ULLONG_MAX)},
                                              {genRand(0, ULLONG_MAX), genRand(0, ULLONG_MAX)}};

    // loop over number of test cases and call the gcd
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (auto i = 0; i < test_vec.size(); ++i)
    {
        auto d = gcd(test_vec[i][0], test_vec[i][1]);
        std::cout << "The greatest common divisor for (" << test_vec[i][0] << ", " << test_vec[i][1] << ") is: " << d << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}