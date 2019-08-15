#include <stdio.h>
#define SWAP(x, y) x^=(y^=(x^=y))

inline int gcd(int n, int m)
{
    while (n)
    {
        m %= n;
        SWAP(m, n);
    }
    return m;
}

long long getK(int a, int b)
{
    if (a < b)
    {
        return a ? getK(b, a) + 1 : -b;
    }
    else
    {
        int tmp = a / b;
        long long res = getK(a - b * tmp, b);
        return res > 0 ? res << tmp : -res << (tmp - 1);
    }
}

int main()
{
    int a, b, g;
    while (scanf(" %d %d", &a, &b) == 2)
    {
        while ((g = gcd(a, b)) > 1)
            a /= g, b /= g;
        printf("%lld\n", getK(a, b));
    }
    return 0;
}