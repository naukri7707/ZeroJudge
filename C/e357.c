#include <stdio.h>

int F(int x)
{
    if (x & 1)
        return x == 1 ? 1 : F(x - 1) + F(x + 1);
    else
        return F(x / 2);
}

int main()
{
    int n;
    scanf(" %d", &n);
    printf("%d", F(n));
    return 0;
}