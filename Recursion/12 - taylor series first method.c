#include <stdio.h>

int factorial(int n)
{
    return n > 1 ? n * factorial(n - 1) : 1;
}

int power(int m, int n)
{
    return n > 0 ? m * power(m, n - 1) : 1;
}

double taylor_series(int x, int n)
{

    printf("Fact of %d is: %d\n", n, factorial(n));
    printf("power of %d is: %d\n", x, power(x, n));
    return taylor_series(x, n - 1) + (power(x, n) / factorial(n));
}

int main()
{
    int x = 2, n = 4;
    printf("Taylor series sum: %lf", taylor_series(x, n));
    return 0;
}