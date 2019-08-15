#include <stdio.h>

long long getK(int a, int b)
{
    if (b < a)
    {
        int shift = a / b;
        a %= b;
        return a ? (getK(b, a) + 1) << shift : 1LL << (shift - 1);
    }
    else
    {
        return a == b ? 1 : getK(b, a) + 1;
    }
}

int main()
{
    int a, b;
    while (scanf(" %d %d", &a, &b) == 2)
    {
        printf("%lld\n", getK(a, b));
    }
    return 0;
}