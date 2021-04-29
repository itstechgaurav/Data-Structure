#include <stdio.h>

int func(int n)
{
    static int x;
    if (n > 0)
    {
        x++;
        return func(n - 1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    printf("Total: %d\n", func(a));
    return 0;
}