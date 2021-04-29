#include <stdio.h>

void funcA(int);
void funcB(int);

int main()
{
    int a = 10;
    funcA(a);
}

void funcA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funcB(n - 1);
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funcA(n / 2);
    }
}