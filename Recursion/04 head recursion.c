#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        func(n - 1); // first recursive call statement in the func
        printf("%d\n", n);
    }
}

int main()
{
    int a = 5;
    func(a); // 1 2 3 4 5 - printing will be in reverse order
}