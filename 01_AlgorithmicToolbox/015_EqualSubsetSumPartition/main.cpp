#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>
#include <numeric> // std::iota
#include <cassert>
#include <time.h>

// helper function to generate a vector of random integer
std::vector<int> genRand(const int &MaxSize, const int &MaxRand)
{
    // Use current time as seed for random generator
    // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
    srand(time(0));

    // generate random vector of integer and sort it
    std::vector<int> vec(MaxSize);
    for (auto i = 0; i < MaxSize; ++i)
    {
        // generate a random integer
        vec[i] = rand() % MaxRand;
    }
    // sort vector
    std::sort(vec.begin(), vec.end());
    // remove duplication
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // return
    return vec;
}

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
}

// brute-force recursive call
bool PartitionSetRecursive(const std::vector<int> &set, const int &sum, const int &index)
{
    // base case
    if (sum == 0)
        return true;

    // base case
    if (index >= set.size() || sum <= 0)
        return false;

    // if set[index] <= half_sum for the current index, add it and recursively decrease the half_sum
    if (set[index] <= sum)
    {
        if (PartitionSetRecursive(set, sum - set[index], index + 1))
        {
            return true;
        }
    }

    // otherwise skip and increase the index by 1
    return PartitionSetRecursive(set, sum, index + 1);
}

// brute-force method
bool PartitionSet(const std::vector<int> &set)
{
    // base case
    if (set.empty())
        return false;
    // initialize
    auto sum = 0;
    // compute sum
    for (auto i = 0; i < set.size(); ++i)
        sum += set[i];
    // if the sum is odd number return false because we cannot partition
    if (sum % 2 != 0)
        return false;
    // call the recursive method
    return PartitionSetRecursive(set, sum / 2, 0);
}

// dynamic programming with top-down memorization
bool PartitionSetTopDownRecursive(const std::vector<int> &set, std::vector<std::vector<int>> &memo, const int &sum, const int &index)
{
    // base case
    if (sum == 0)
        return true;

    // base case
    if (index >= set.size() || sum <= 0)
        return false;

    // if we have already solved a similar problem, return the result from memory
    if (memo[index][sum] != -1)
        return memo[index][sum];

    // if set[index] <= half_sum for the current index, add it and recursively decrease the half_sum
    if (memo[index][sum] == -1)
    {
        if (set[index] <= sum)
        {
            if (PartitionSetTopDownRecursive(set, memo, sum - set[index], index + 1))
            {
                memo[index][sum] = 1;
                return true;
            }
        }

        // otherwise skip and increase the index by 1
        memo[index][sum] = PartitionSetTopDownRecursive(set, memo, sum, index + 1) ? 1 : 0;
    }

    // return final
    return memo[index][sum] == 1 ? true : false;
}

// dynamic programming with top-down memorization
bool PartitionSetTopDown(const std::vector<int> &set)
{
    // base case
    if (set.empty())
        return false;
    // initialize
    auto sum = 0;
    // compute sum
    for (auto i = 0; i < set.size(); ++i)
        sum += set[i];
    // if the sum is odd number return false because we cannot partition
    if (sum % 2 != 0)
        return false;
    // initialize memo vector
    std::vector<std::vector<int>> memo(set.size(), std::vector<int>(sum / 2 + 1, -1));
    // call the recursive method
    return PartitionSetTopDownRecursive(set, memo, sum / 2, 0);
}

// Bottom-up Dynamic Programming with Tabulation
bool PartitionSetBottomUp(const std::vector<int> &set)
{
    // base case
    if (set.empty())
        return false;
    // initialize
    auto sum = 0;
    // compute sum
    for (auto i = 0; i < set.size(); ++i)
        sum += set[i];
    // if the sum is odd number return false because we cannot partition
    if (sum % 2 != 0)
        return false;
    // get the half of sum
    sum /= 2;
    // initialize dp_bu vector
    std::vector<std::vector<bool>> dp_bu(set.size(), std::vector<bool>(sum + 1));

    // initialize
    auto num_p = set.size();

    // pupulate for sum of zero (first column)
    for (auto i = 0; i < num_p; ++i)
    {
        dp_bu[i][0] = true;
    }

    // if we have only one member in the set, we will take it if it is not more than the sum
    for (auto s = 0; s <= sum; ++s)
    {
        // first row
        dp_bu[0][s] = ((set[0] == s) ? true : false);
    }

    // process all sub-arrays for all the capacities, from index (1,1)
    for (auto i = 1; i < num_p; ++i)
    {
        for (auto s = 1; s <= sum; ++s)
        {
            // if we can get the sum 's' without the number at index 'i'
            if (dp_bu[i - 1][s])
            {
                dp_bu[i][s] = dp_bu[i - 1][s];
            }
            // else if we can find a subset to get the remaining sum
            else if (set[i] <= s)
            {
                dp_bu[i][s] = dp_bu[i - 1][s - set[i]];
            }
        }
    }

    // the answer is at the bottom-right corner.
    return dp_bu[num_p - 1][sum];
}

// main function
int main()
{
    // initialize
    int MaxN = 20;
    int MaxRand = 20;
    int MaxItr = 5;
    int Itr = 0;

    // create a while loop (try to break the code)
    while (Itr < MaxItr)
    {
        // test case
        std::vector<int> set = genRand(MaxN, MaxRand);
        // std::vector<int> set = {1, 2, 3, 4};
        // std::vector<int> set = {1, 1, 3, 4, 7};

        // print vector
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "The set vector: " << std::endl;
        printVec(set);

        // call the brute-force recursive method
        auto equal_recursive = PartitionSet(set);
        // print
        if (equal_recursive)
            std::cout << "Brute-force recursive method                            ---------->>>>>>>>>> the given set can be partitioned into two subsets with equal sum." << std::endl;
        else
            std::cout << "Brute-force recursive method                            ---------->>>>>>>>>> the given set cannot be partitioned into two subsets with equal sum." << std::endl;

        // call the top-down recursive method
        auto equal_topdown = PartitionSetTopDown(set);
        // print
        if (equal_topdown)
            std::cout << "Dynamic programming - top-down with memorization method ---------->>>>>>>>>> the given set can be partitioned into two subsets with equal sum." << std::endl;
        else
            std::cout << "Dynamic programming - top-down with memorization method ---------->>>>>>>>>> the given set cannot be partitioned into two subsets with equal sum." << std::endl;

        // call the top-down recursive method
        auto equal_bottomup = PartitionSetBottomUp(set);
        // print
        if (equal_bottomup)
            std::cout << "Dynamic programming - bottom-up with tabulation method  ---------->>>>>>>>>> the given set can be partitioned into two subsets with equal sum." << std::endl;
        else
            std::cout << "Dynamic programming - bottom-up with tabulation method  ---------->>>>>>>>>> the given set cannot be partitioned into two subsets with equal sum." << std::endl;

        // https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // update
        Itr += 1;
    }

    // return
    return 0;
}
