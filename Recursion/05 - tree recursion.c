#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        func(n - 1); // first recursive call
        func(n - 1); // second recursive call
    }
}

int main()
{
    int a = 3;
    func(a);
}