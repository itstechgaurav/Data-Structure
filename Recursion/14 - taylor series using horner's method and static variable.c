#include <stdio.h>

float taylor_series(int x, int n)
{
    static int i = 0;
    if (n == 0)
        return 1;
    i++;
    return 1.0f + (((float)x / i) * (i <= n ? taylor_series(x, n) : 1));
}

int main()
{
    int x = 2, n = 10;
    printf("Taylor series sum: %f", taylor_series(x, n));
}