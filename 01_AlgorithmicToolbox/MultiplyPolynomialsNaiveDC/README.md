# Question:

Given two $n-1$ degree polynomials: 

$$A(x) = a_{n-1}x^{n-1} + a_{n-2}x^{n-2} + \cdots + a_{1}x^{1} + a_{0}x^{0}$$

$$B(x) = b_{n-1}x^{n-1} + b_{n-2}x^{n-2} + \cdots + b_{1}x^{1} + b_{0}x^{0}$$

For the naive divide and conquer algorithm lets divide $A(x)$ as follows:

$$A(x) = D_{1}(x) x^{n/2} + D_{0}(x)$$ 

where

$$D_{1}(x) = a_{n-1}x^{n/2-1} + a_{n-2}x^{n/2-2} + \cdots + a_{n/2}$$

$$D_{0}(x) = a_{n/2-1}x^{n/2-1} + a_{n/2-2}x^{n/2-2} + \cdots + a_{0}$$

In the same manner, let:

$$B(x) = E_{1}(x) x^{n/2} + E_{0}(x)$$ 

where

$$E_{1}(x) = b_{n-1}x^{n/2-1} + b_{n-2}x^{n/2-2} + \cdots + b_{n/2}$$

$$E_{0}(x) = b_{n/2-1}x^{n/2-1} + b_{n/2-2}x^{n/2-2} + \cdots + b_{0}$$

The $$A(x) \times B(x)$$ product will be:


