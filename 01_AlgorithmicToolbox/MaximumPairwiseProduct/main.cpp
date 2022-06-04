#include <iostream>
#include <vector>

// call to pairwiseproduct function
long long getPairWiseProduct(const std::vector<int> &nums)
{
    long long max_i = 0;
    long long max_j = 0;
    for (auto i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > max_i)
        {
            max_j = max_i;
            max_i = static_cast<long long>(nums[i]);
        }
        else if (nums[i] > max_j)
        {
            max_j = static_cast<long long>(nums[i]);
        }
    }
    // return the result
    return max_i * max_j;
}

int main()
{
    // get the number of integer in the vector
    int n = 0;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    // call the function
    auto res = getPairWiseProduct(nums);
    std::cout << res << std::endl;

    return 0;
}