#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <limits.h>
#include <vector>

// get number of required station (greedy algorithm)
int getNumRefillsGRD(const std::vector<double> &x, const double &L)
{
    // initialize
    auto n = x.size();
    auto CurrRefill = 0;
    auto NumRefills = 0;
    while (CurrRefill <= n)
    {
        auto LastRefill = CurrRefill;
        // traverse along the stations
        while (CurrRefill <= n && (x[CurrRefill + 1] - x[LastRefill]) <= L)
            CurrRefill += 1;
        // check for impossible case
        if (CurrRefill == LastRefill)
        {
            std::cout << "the setup for current configuration is impossible!" << std::endl;
            return 0;
        }
        if (CurrRefill <= n)
            NumRefills += 1;
    }
    // return total number of refills
    return NumRefills;
}

int main()
{
    // test cases
    std::vector<std::vector<double>> test_vec{{0.0, 200.0, 375.0, 550.0, 750.0, 950.0}};
    std::vector<double> l_vec {400.0};

    // loop over number of test cases and call the gcd
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (auto i = 0; i < test_vec.size(); ++i)
    {
        auto NumFills = getNumRefillsGRD(test_vec[i], l_vec[i]);
        std::cout << "The total number of fills is: " << NumFills << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    return 0;
}