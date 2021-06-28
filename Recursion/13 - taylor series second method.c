#include <stdio.h>

float taylor_series(int x, int n)
{
    static int p = 1, b = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        float res = taylor_series(x, n - 1);
        p = p * x;
        b = b * n;
        return res + ((float)p / b);
    }
}

int main()
{
    int x = 2, n = 5;
    printf("Tayler series sum: %f", taylor_series(x, n));
    return 0;
}