#include <stdio.h>
#define SWAP(x, y) x^=(y^=(x^=y))

inline int gcd(int m, int n)
{
    while (n)
    {
        m %= n;
        SWAP(m, n);
    }
    return m;
}

int main()
{
    int  x1, x2, y1, y2, g, a, b, c, d;
    while (scanf(" %d %d %d %d", &x1, &x2, &y1, &y2) == 4)
    {
        a = (y1 - x1) * (y1 - x1);
        b = (y2 - x2);
        g = gcd(a, b);
        b /= g;
        a /= g;
        c = -2 * b * x1;
        d = b * x1 * x1 + a * x2;
        printf("%dy = %dx^2 + %dx + %d\n", a, b, c, d);
    }
    return 0;
}