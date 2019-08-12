#include <stdio.h>

int n, a;
long long b, c;

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        while (n--)
        {
            scanf(" %d %lld %lld", &a, &b, &c);
            printf("%lld\n", a == 1 ? b + c : a == 2 ? b - c : a == 3 ? b * c : b / c);
        }
    }
    return 0;
}