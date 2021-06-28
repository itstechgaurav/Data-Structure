#include <stdio.h>

int print_fibonacci(int n)
{

    if (n == 0)
    {
        printf("%d ", n);
        return print_fibonacci(n + 1);
    }
    else if (n == 1)
    {
        printf("%d ", n);
        return print_fibonacci(n);
    }
    else
    {
        int res = print_fibonacci(n - 2) + print_fibonacci(n - 1);
        printf("%d ", res);
        return res;
    }
}

int main()
{
    int n = 13;
    print_fibonacci(n);
    return 0;
}