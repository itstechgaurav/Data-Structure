#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        func(n - 1); // calling the recursive function again
    }
}

int main()
{
    int x = 3;
    func(x); return 0;
}
