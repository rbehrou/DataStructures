#include <iostream>
#include <vector>

// Fibonacci numbers (Slow method)
int FibonacciRecurs(const int &n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return FibonacciRecurs(n - 1) + FibonacciRecurs(n - 2);
    }
}

// Fibonacci numbers (Fast method)
unsigned long long FibonacciFast(const int &n)
{
    // safeguard
    if ( n > 93)
    {
        std::cout << "C++ unsigned long long cannot handle int greater than 2^64." << std::endl;
        return 0;
    }
    // create an array
    std::vector<unsigned long long> F(n+1);
    // fill firts two elements
    F[0] = static_cast<unsigned long long>(0);
    F[1] = static_cast<unsigned long long>(1);
    std::cout << "i: " << 0 << ", F[i]: " << F[0] << std::endl;
    std::cout << "i: " << 1 << ", F[i]: " << F[1] << std::endl;
    // loop over the rest
    for (auto i = 2; i <= n; ++i)
    {
        F[i] = static_cast<unsigned long long>(F[i - 1]) + static_cast<unsigned long long>(F[i - 2]);
        std::cout << "i: " << i << ", F[i]: " << F[i] << std::endl;
    }

    // return the final number
    return F[n];
}

int main()
{
    // get the number from user
    int n;
    std::cin >> n;

    // call the Fibonacci function
    // link to test: https://www.wolframalpha.com/input?i=fib%281000%29
    auto fib = FibonacciFast(n);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "The Fibonacci number for n = " << n << " is: " << fib << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;

    return 0;
}