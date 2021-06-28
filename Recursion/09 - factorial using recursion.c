#include <stdio.h>

int factorial(int n)
{
    return n > 1 ? n * factorial(n - 1) : 1;
}

int main()
{
    int n = 5;
    printf("Factorial of %d is: %d", n, factorial(n));
    return 0;
}