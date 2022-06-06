# Naive divide and conquer:

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

Therefore, the

 $$A(x) \times B(x) = (D_{1}x^{n/2} + D_{0})(E_{1}x^{n/2} + E_{0})$$

 $$= (D_{1}E_{1})x^{n} + (D_{1}E_{0}+D_{0}E_{1})x^{n/2} + D_{0}E_{0}$$

 # Example:

 $$A(x) = 4x^{3} + 3x^{2} + 2x + 1$$

 $$B(x) = x^{3} + 2x^{2} + 3x + 4$$

 Then,

 $$D_{1} = 4x + 3, \qquad D_{0} = 2x + 1$$

 $$E_{1} = x + 2, \qquad E_{0} = 3x + 4$$

 $$D_{1}E_{1} = 4x^{2} + 11x + 6$$

 $$D_{1}E_{0} = 12x^{2} + 25x + 12$$

 $$D_{0}E_{1} = 2x^{2} + 5x + 2$$

 $$D_{0}E_{0} = 6x^{2} + 11x + 4$$

 Finally:

  $$AB = (D_{1}E_{1})x^{4} + (D_{1}E_{0}+D_{0}E_{1})x^{2} + D_{0}E_{0}$$

  $$= (4x^{2} + 11x + 6)x^{4} + (12x^{2} + 25x + 12+2x^{2} + 5x + 2)x^{2} + 6x^{2} + 11x + 4$$

  $$= 4x^{6} + 11x^{5} + 20x^{4} + 30x^{3} + 20x^{2} + 11x + 4$$


