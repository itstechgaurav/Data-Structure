#include <stdio.h>

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else
    {
        return m * power(m * m, n / 2);
    }
}

int main()
{
    int m = 5, n = 5;
    printf("%d^%d: %d", m, n, power(m, n));
    return 0;
}