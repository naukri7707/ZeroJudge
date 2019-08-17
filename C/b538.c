#include <stdio.h>
#define SWAP(x, y) x^=(y^=(x^=y))

int gcd(int m, int n)
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
    int a, b, c, d, e, f, g;
    char op;
    while (scanf(" %d %d %d %d %c", &a, &b, &c, &d, &op) == 5)
    {
        switch (op)
        {
        case '+':
            e = a * d + c * b;
            f = b * d;
            break;
        case '-':
            e = a * d - c * b;
            f = b * d;
            break;
        case '*':
            e = a * c;
            f = b * d;
            break;
        case '/':
            e = a * d;
            f = b * c;
            break;
        default:
            break;
        }
        g = gcd(e, f);
        e /= g, f /= g;
        if (f < 0)
        {
            e = -e;
            f = -f;
        }
        if (f == 1)
            printf("%d\n", e);
        else
            printf("%d/%d\n", e, f);
    }
    return 0;
}