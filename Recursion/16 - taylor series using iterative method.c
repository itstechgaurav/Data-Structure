#include <stdio.h>

float taylor_series(int x, int n)
{
    float sum = 1;
    if (n == 0)
        return 1;

    while (n > 0)
    {
        sum = 1 + (((float)x / n) * sum);
        n--;
    }
    return sum;
}

int main()
{
    int x = 2, n = 4;
    printf("Taylor series sum: %f", taylor_series(x, n));
}