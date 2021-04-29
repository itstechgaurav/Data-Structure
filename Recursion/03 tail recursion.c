#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        func(n - 1);
    }
}

int main()
{
    int a = 5;
    func(a); // 5 4 3 2 1 - printing will be in order
}