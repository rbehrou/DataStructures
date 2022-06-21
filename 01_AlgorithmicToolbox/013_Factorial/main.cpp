#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>
#include <numeric> // std::iota
#include <fstream>

// helper function to generate a vector of random integer
std::vector<int> genRand(const int &MaxSize, const int &MaxRand)
{
    // https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // generate random vector of integer and sort it
    std::vector<int> vec(MaxSize);
    for (auto i = 0; i < MaxSize; ++i)
    {
        // generate a random integer
        vec[i] = rand() % MaxRand;

        // Use current time as seed for random generator
        // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
        srand(time(0));
    }
    // return
    return vec;
};

// Factorial (slow brute-force recursive method)
unsigned long long FactorialRecurs(const int &n)
{
    // for n = 0 (base case)
    if (n == 0)
        return 1;

    // safeguard
    if (n > 19)
        throw std::runtime_error("results for unsigned long long int with n > 19 is out of bound.");

    // recursion
    return n * FactorialRecurs(n - 1);
}

// Factorial using dynamic programming with top-down with memoization
unsigned long long computeFactorialDPTopDown(std::vector<unsigned long long> &F, const int &n)
{
    // for n = 0 (base case)
    if (n == 0)
        return 1;

    // memorization: if we have already solved this subproblem, simply return the result from the cache
    if (F[n] != 0)
        return F[n];

    // recursion
    F[n] = n * computeFactorialDPTopDown(F, n - 1);
    // return the final number
    return F[n];
}

// Factorial using dynamic programming with top-down with memoization
// https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0
unsigned long long FactorialDPTopDown(const int &n)
{
    // safeguard
    if (n > 19)
        throw std::runtime_error("results for unsigned long long int with n > 19 is out of bound.");

    // create an array
    std::vector<unsigned long long> F(n + 1, 0);
    // return in recursion
    return computeFactorialDPTopDown(F, n);
}

// Factorial (Fast method using dynamic programming, Bottom-up with Tabulation)
// https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0
unsigned long long FactorialDPBottomUp(const int &n)
{
    // for n = 0 (base case)
    if (n == 0)
        return 1;

    // safeguard
    if (n > 19)
        throw std::runtime_error("results for unsigned long long int with n > 19 is out of bound.");

    // create an array
    std::vector<unsigned long long> F(n + 1);
    // fill the firts two elements
    F[0] = static_cast<unsigned long long>(1);
    // loop over the rest of n
    for (auto i = 1; i <= n; ++i)
    {
        F[i] = static_cast<unsigned long long>(i) * static_cast<unsigned long long>(F[i - 1]);
    }

    // return the final number
    return F[n];
}

int main()
{
    // initialize
    int MaxN = 1;
    int MaxRand = 19; // max Factorial that can be handled with unsigned long long int
    int MaxItr = 1;
    int Itr = 0;
    unsigned long long fact = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test case
        // std::vector<int> test_vec = genRand(MaxN, MaxRand);
        std::vector<int> test_vec(20);
        std::vector<unsigned long long int> time_recursive;
        std::vector<unsigned long long int> time_dptopdown;
        std::vector<unsigned long long int> time_dpbottomup;
        std::iota(test_vec.begin(), test_vec.end(), 0); // test_vec will become: [0..20]

        for (auto i = 0; i < test_vec.size(); ++i)
        {
            std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
            // print n
            std::cout << "n: " << test_vec[i] << std::endl;
            // ------------------------------------------------------------------------
            // get the starting timepoint
            auto start = std::chrono::high_resolution_clock::now();
            fact = FactorialRecurs(test_vec[i]);
            // get the ending timepoint
            auto stop = std::chrono::high_resolution_clock::now();
            // use duration cast method
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            time_recursive.push_back(duration.count());
            std::cout << "Recursive method                   : the Factorial for n = " << test_vec[i] << " is: " << fact << ", and time: " << duration.count() << " nanoseconds." << std::endl;

            // ------------------------------------------------------------------------
            // get the starting timepoint
            start = std::chrono::high_resolution_clock::now();
            fact = FactorialDPTopDown(test_vec[i]);
            // get the ending timepoint
            stop = std::chrono::high_resolution_clock::now();
            // use duration cast method
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            time_dptopdown.push_back(duration.count());
            std::cout << "DP top-down with memoization method: the Factorial for n = " << test_vec[i] << " is: " << fact << ", and time: " << duration.count() << " nanoseconds." << std::endl;

            // ------------------------------------------------------------------------
            // get the starting timepoint
            start = std::chrono::high_resolution_clock::now();
            fact = FactorialDPBottomUp(test_vec[i]);
            // get the ending timepoint
            stop = std::chrono::high_resolution_clock::now();
            // use duration cast method
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            time_dpbottomup.push_back(duration.count());
            std::cout << "DP bottom-up with tabulation method: the Factorial for n = " << test_vec[i] << " is: " << fact << ", and time: " << duration.count() << " nanoseconds." << std::endl;
        }

        // write into file
        std::ofstream recursive_file;
        recursive_file.open("time_recursive.txt");
        for (const auto &e : time_recursive)
            recursive_file << e << "\n";
        recursive_file.close();

        std::ofstream dptopdown_file;
        dptopdown_file.open("time_dptopdown.txt");
        for (const auto &e : time_dptopdown)
            dptopdown_file << e << "\n";
        dptopdown_file.close();

        std::ofstream dpbottomup_file;
        dpbottomup_file.open("time_dpbottomup.txt");
        for (const auto &e : time_dpbottomup)
            dpbottomup_file << e << "\n";
        dpbottomup_file.close();

        // update
        Itr += 1;
    }

    // return
    return 0;
}
