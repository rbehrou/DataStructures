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

        // https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Use current time as seed for random generator
        // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/#:~:text=The%20rand()%20function%20is,numbers%20each%20time%20it%20runs.
        srand(time(0));
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

// brute-force recursive call (time complexity is O(2^n))
int Knapsack01Recursive(const std::vector<int> &profits, const std::vector<int> &weights, const int &capacity, const int &index)
{
    // base case
    if (index >= profits.size() || capacity <= 0)
        return 0;

    // initialize
    auto prof_1 = 0;

    // if weights[index] <= capacity for the current index, add it and recursively decrease the capacity
    if (weights[index] <= capacity)
    {
        prof_1 = profits[index] + Knapsack01Recursive(profits, weights, capacity - weights[index], index + 1);
    }

    // otherwise skip and increase the index by 1
    auto prof_2 = Knapsack01Recursive(profits, weights, capacity, index + 1);

    // return max profit
    return std::max(prof_1, prof_2);
}

// brute-force method
int Knapsack01(const std::vector<int> &profits, const std::vector<int> &weights, const int &capacity)
{
    assert(profits.size() == weights.size());
    return Knapsack01Recursive(profits, weights, capacity, 0);
}

// Top-down Dynamic Programming with Memoization
int Knapsack01DPTopDownRecursive(std::vector<std::vector<int>> &memo, const std::vector<int> &profits, const std::vector<int> &weights, const int &capacity, const int &index)
{
    // base case
    if (index >= profits.size() || capacity <= 0)
        return 0;

    // if we have already solved a similar problem, return the result from memory
    if (memo[index][capacity] != -1)
        return memo[index][capacity];

    // initialize
    auto prof_1 = 0;

    // if weights[index] <= capacity for the current index, add it and recursively decrease the capacity
    if (weights[index] <= capacity)
    {
        prof_1 = profits[index] + Knapsack01DPTopDownRecursive(memo, profits, weights, capacity - weights[index], index + 1);
    }

    // otherwise skip and increase the index by 1
    auto prof_2 = Knapsack01DPTopDownRecursive(memo, profits, weights, capacity, index + 1);

    // return max profit
    memo[index][capacity] = std::max(prof_1, prof_2);
    return memo[index][capacity];
}

// We can use memoization to overcome the overlapping sub-problems
// Top-down Dynamic Programming with Memoization
int Knapsack01DPTopDown(const std::vector<int> &profits, const std::vector<int> &weights, const int &capacity)
{
    assert(profits.size() == weights.size());
    std::vector<std::vector<int>> memo(profits.size(), std::vector<int>(capacity + 1, -1));
    return Knapsack01DPTopDownRecursive(memo, profits, weights, capacity, 0);
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
        std::vector<int> weights = genRand(MaxN, MaxRand);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::vector<int> profits = genRand(MaxN, MaxRand);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::vector<int> capacity = genRand(1, MaxRand);

        // check the sizes
        if (weights.size() > profits.size())
            weights.resize(profits.size());
        else
            profits.resize(weights.size());

        // print vector
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "The weights vector: " << std::endl;
        printVec(weights);
        std::cout << "The profits vector: " << std::endl;
        printVec(profits);
        // call knapsack01 function
        auto max_profit_r = Knapsack01(profits, weights, capacity[0]);
        // call knapsack01TopDown function
        auto max_profit_topdown = Knapsack01DPTopDown(profits, weights, capacity[0]);
        // print
        std::cout << "The maximum profit for capacity of: " << capacity[0] << " with recursive: " << max_profit_r << " with dp top-down: " << max_profit_topdown << std::endl;
        
        // update
        Itr += 1;
    }

    // return
    return 0;
}
