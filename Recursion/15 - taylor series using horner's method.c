#include <stdio.h>

double taylor_series(int x, int n)
{
    // this is also the static approch but this will not require any third variable
    static double sum = 1;
    if (n == 0)
        return sum;

    sum = 1 + ((x * sum) / n);
    return taylor_series(x, n - 1);
}

int main()
{
    int x = 2, n = 4;
    printf("Taylor series sum: %lf", taylor_series(x, n));
}