#include <stdio.h>

int power(int m, int n)
{
    return n > 0 ? m * power(m, n - 1) : 1;
}

int main()
{
    int m = 2, n = 4;
    printf("%d^%d: %d", m, n, power(m, n));
    return 0;
}