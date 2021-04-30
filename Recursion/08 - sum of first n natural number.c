#include <stdio.h>

int getNaturalNoSum(int n)
{
    return n > 0 ? n + getNaturalNoSum(n - 1) : 0;
}

int main()
{
    int n = 8;
    printf("Sum of first %d numbers: %d", n, getNaturalNoSum(n));
}